#define BOOST_BIND_NO_PLACEHOLDERS

#include <memory>
#include "iostream"
#include <string>
#include <stdio.h>
#include <iterator>
#include <algorithm>

#include "code/code_node.hpp"

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>

#include "sensor_msgs/msg/point_cloud2.hpp"
#include "std_msgs/msg/header.hpp"
#include "c_auto_vehicle_msgs/msg/velocity_report.hpp"

using std::placeholders::_1;
    
SampleVelocity::SampleVelocity(const rclcpp::NodeOptions& options) : Node("velocity_pubsub",options) 
{
      
  declare_parameter<std::string>("topic_pointcloud_in","/left_lidar");
  declare_parameter<std::string>("topic_pointcloud_out", "/vehicle/status/velocity_status");
  
  param_topic_pointcloud_in = get_parameter("topic_pointcloud_in").as_string();
  param_topic_pointcloud_out = get_parameter("topic_pointcloud_out").as_string();
  
  publisher_ = this->create_publisher<c_auto_vehicle_msgs::msg::VelocityReport>(param_topic_pointcloud_out,10);
  subscription_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
  param_topic_pointcloud_in, 10, std::bind(&SampleVelocity::topic_callback, this, _1));

  RCLCPP_INFO(this->get_logger(), "\n"
  "Node:       velocity_pubsub\n"
  "Subscribes: Pointcloud2 message: %s\n"
  "Publishes:  Pointcloud2 message: %s \n"
  "Details:    No filter applied in this example.\n"
  "Running...", param_topic_pointcloud_in.c_str(),param_topic_pointcloud_out.c_str());

}

void SampleVelocity::topic_callback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
{
  unsigned int num_points = msg->width;
  float count = 50.0;
  //RCLCPP_INFO(this->get_logger(), "The number of points in the input pointcloud is %i", num_points);

  c_auto_vehicle_msgs::msg::VelocityReport message;
  message.header.frame_id = msg->header.frame_id;
  message.header.stamp = msg->header.stamp;
  RCLCPP_INFO(this->get_logger(), " %f", msg->header.stamp);
  message.longitudinal_velocity = count;    
  message.lateral_velocity = count;  
  message.heading_rate = count;   

  // Publish to ROS2 network
  publisher_->publish(message);
}
