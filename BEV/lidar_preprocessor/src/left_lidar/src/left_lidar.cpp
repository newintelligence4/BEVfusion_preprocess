#define BOOST_BIND_NO_PLACEHOLDERS

#include <memory>
#include "iostream"
#include <string>
#include <stdio.h>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <vector>
#include <time.h>
#include "left_lidar/left_lidar_node.hpp"

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>

#include "sensor_msgs/msg/point_cloud2.hpp"
#include "std_msgs/msg/header.hpp"

#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/passthrough.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/common/transforms.h>
#include "velocity_msg/msg/num.hpp"  

#include <pcl/sample_consensus/model_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/filters/extract_indices.h>


using std::placeholders::_1;
#define PI 3.14159265359

pcl::PCLPointCloud2 adaptive_roi(const pcl::PCLPointCloud2 cloud, int velocity);
pcl::PCLPointCloud2 ground_removal(const pcl::PCLPointCloud2 cloud);
pcl::PCLPointCloud2 downsample(const pcl::PCLPointCloud2 cloud);

double get_cos(double x, double y);
double get_tan(double x, double y, double z);
double get_limit(int vel);
float theta_r = 270*M_PI/180;
   
int speed = 0;

LEFT_PREPROCESSING::LEFT_PREPROCESSING(const rclcpp::NodeOptions& options) : Node("left_lidar",options) 
{
      
  declare_parameter<std::string>("topic_pointcloud_in","/left_lidar");
  declare_parameter<std::string>("topic_pointcloud_out", "/points_raw1");
  
  param_topic_pointcloud_in = get_parameter("topic_pointcloud_in").as_string();
  param_topic_pointcloud_out = get_parameter("topic_pointcloud_out").as_string();
  
  publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>(param_topic_pointcloud_out,2);
  subscription_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
  param_topic_pointcloud_in, 10, std::bind(&LEFT_PREPROCESSING::topic_callback, this, _1));

  RCLCPP_INFO(this->get_logger(), "\n"
  "Node:       left_lidar\n"
  "Subscribes: Pointcloud2 message: %s\n"
  "Publishes:  Pointcloud2 message: %s \n"
  "Running...", param_topic_pointcloud_in.c_str(),param_topic_pointcloud_out.c_str());

  declare_parameter<std::string>("topic_velocity_in","topic");
  param_topic_velocity_in = get_parameter("topic_velocity_in").as_string();
  subscription_v = this->create_subscription<velocity_msg::msg::Num>(          
  param_topic_velocity_in, 10, std::bind(&LEFT_PREPROCESSING::velocity_callback, this, _1));

}
void LEFT_PREPROCESSING::velocity_callback(const velocity_msg::msg::Num::SharedPtr vel)
{
  speed = vel->num;
}
void LEFT_PREPROCESSING::topic_callback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
{
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZI>);
  pcl::fromROSMsg(*msg, *cloud);
  /////// Transform Matrix
  Eigen::Matrix4f transform_1 = Eigen::Matrix4f::Identity();
  transform_1 (0,0) = std::cos (theta_r);
  transform_1 (0,1) = -sin(theta_r);
  transform_1 (1,0) = sin (theta_r);
  transform_1 (1,1) = std::cos (theta_r);

  pcl::transformPointCloud (*cloud, *cloud, transform_1); 

  int num_neigbor_points = 10;
  double std_multiplier = 1.0;

  // pcl::StatisticalOutlierRemoval<pcl::PointXYZI> sor;
  // sor.setInputCloud (cloud);
  // sor.setMeanK (num_neigbor_points);
  // sor.setStddevMulThresh (std_multiplier);
  // sor.filter (*cloud);                 


  pcl::PCLPointCloud2 cloud_transformed;
  pcl::toPCLPointCloud2(*cloud, cloud_transformed);

  //Optional
  //pcl::PCLPointCloud2 removaled = ground_removal(cloud_transformed);
  //pcl::PCLPointCloud2 downsampled = downsample(removaled);
  
  //Adaptive ROI
  pcl::PCLPointCloud2 cloud_ROI = adaptive_roi(cloud_transformed, speed);
  sensor_msgs::msg::PointCloud2 output;

  pcl_conversions::fromPCL(cloud_ROI,output);  
  //std::cerr << "Filtered: "<< cloud_ROI.width * cloud_ROI.height << " data points ("<< pcl::getFieldsList(cloud_ROI)<<")."<<std::endl;
  output.header.frame_id = msg->header.frame_id;
  output.header.stamp = msg->header.stamp;
  publisher_->publish(output);
}


pcl::PCLPointCloud2 adaptive_roi(const pcl::PCLPointCloud2 cloud, int velocity)
{
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_new (new pcl::PointCloud<pcl::PointXYZI>);
  pcl::fromPCLPointCloud2(cloud, *cloud_new);

  //// KDTREE
  pcl::PointCloud<pcl::PointXYZI>::Ptr boundery (new pcl::PointCloud<pcl::PointXYZI>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr input(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::copyPointCloud(*cloud_new, *input);

  pcl::KdTreeFLANN<pcl::PointXYZ> kdtree;
  std::vector<int> idxes;
  std::vector<float> sqr_dists;
  double road_x = 2.5;
  double road_y = -5.0;
  pcl::PointXYZ query(road_x, road_y, 0.0);

  float times = 1.8;
  float radius = round(velocity * times);

  
  kdtree.setInputCloud(input);
  kdtree.radiusSearch(query, radius, idxes, sqr_dists);
  for (const auto& idx: idxes){
    boundery->points.push_back(cloud_new->points[idx]);
  }

  // ROI - Angle
  pcl::PassThrough<pcl::PointXYZI> pass;

  pass.setInputCloud(boundery);
  pass.setFilterFieldName("x");
  pass.setFilterLimits(-10.5, road_x);
  pass.filter(*boundery);

  for(unsigned int j=0; j<boundery->points.size(); j++)
  {
    double angle_h = get_cos((boundery->points[j].y - road_y) , (boundery->points[j].x - road_x));
    double angle_v = get_tan(boundery->points[j].x, boundery->points[j].y, boundery->points[j].z);
    
    if( angle_h < 4)
    {
        boundery->points[j].x = 0;
        boundery->points[j].y = 0;
        boundery->points[j].z = 0;
    }
    if(angle_h > 150)
    {
        boundery->points[j].x = 0;
        boundery->points[j].y = 0;
        boundery->points[j].z = 0;
    }
    if((boundery->points[j].x - road_x) > 0)
    {
        boundery->points[j].x = 0;
        boundery->points[j].y = 0;
        boundery->points[j].z = 0;
    }
    if(angle_v > get_limit(velocity))
    {
        boundery->points[j].x = 0;
        boundery->points[j].y = 0;
        boundery->points[j].z = 0;
    }
  }
  std::cerr << "Limit angle: "<< get_limit(velocity) << std::endl; 
  pass.setInputCloud(boundery);
  pass.setFilterFieldName("x");
  pass.setFilterLimits(0.0, 0.0);
  pass.setFilterLimitsNegative(true);
  pass.filter(*boundery);

  pcl::PCLPointCloud2 cloud_ROI;
  pcl::toPCLPointCloud2(*boundery, cloud_ROI);

  return cloud_ROI;
}

pcl::PCLPointCloud2 ground_removal(const pcl::PCLPointCloud2 cloud)
{
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_new (new pcl::PointCloud<pcl::PointXYZI>);
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_ground_removal (new pcl::PointCloud<pcl::PointXYZI>);
  pcl::fromPCLPointCloud2(cloud, *cloud_new);

  pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
  pcl::PointIndices::Ptr outliers(new pcl::PointIndices);

  pcl::SACSegmentation<pcl::PointXYZI> seg;

  seg.setOptimizeCoefficients (true); // Optional

  seg.setModelType(pcl::SACMODEL_PLANE);
  seg.setMethodType(pcl::SAC_RANSAC);
  seg.setDistanceThreshold(0.9);

  seg.setInputCloud (cloud_new);
  seg.segment(*inliers, *coefficients);

  pcl::ExtractIndices<pcl::PointXYZI> extract_indices;
  extract_indices.setInputCloud(cloud_new);
  extract_indices.setIndices(inliers);
  extract_indices.setNegative(false);
  extract_indices.filter(*cloud_ground_removal);

  pcl::PCLPointCloud2 output;
  pcl::toPCLPointCloud2(*cloud_ground_removal, output);

  return output;
}

pcl::PCLPointCloud2 downsample(const pcl::PCLPointCloud2 cloud)
{
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_new (new pcl::PointCloud<pcl::PointXYZI>);
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZI>);

  pcl::fromPCLPointCloud2(cloud, *cloud_new);

  pcl::VoxelGrid<pcl::PointXYZI> vox;

  vox.setInputCloud(cloud_new);
  vox.setLeafSize(0.15, 0.15, 0.15);
  vox.filter(*cloud_filtered); // with SOR -> *cloud_new

  // int num_neigbor_points = 10;
  // double std_multiplier = 1.0;

  // pcl::StatisticalOutlierRemoval<pcl::PointXYZI> sor;
  // sor.setInputCloud (cloud_new);
  // sor.setMeanK (num_neigbor_points);
  // sor.setStddevMulThresh (std_multiplier);
  // sor.filter (*cloud_filtered); 


  pcl::PCLPointCloud2 cloud_out;
  pcl::toPCLPointCloud2(*cloud_filtered, cloud_out);
  
  return cloud_out;
}

double get_cos(double x, double y)
{
  double r;
  double theta;

  r = sqrt((x*x)+(y*y));
  theta = acos(x/r)*180/PI;
  return theta;
}     
double get_tan(double x, double y, double z)
{
  double r;
  double theta;

  r = sqrt((x*x)+(y*y));
  theta = atan(z/r)*180/PI;
  return theta;
}
double get_limit(int vel){
  double limit;
  int slow = vel - 80;
  if (slow < -20){
    limit = 22.5;
  }
  else{
    limit = 5.7 - ((0.2)*slow);
  }
  return limit;
}  