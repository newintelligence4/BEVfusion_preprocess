
#ifndef VELOCITY_PUBSUB__VELOCITY_PUBSUB_NODE_HPP_
#define VELOCITY_PUBSUB__VELOCITY_PUBSUB_NODE_HPP_

#include "rclcpp/rclcpp.hpp"  
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "c_auto_vehicle_msgs/msg/velocity_report.hpp"

class SampleVelocity : public rclcpp::Node
{
  public:
    explicit SampleVelocity(const rclcpp::NodeOptions &options = rclcpp::NodeOptions());

    ~SampleVelocity() {};

  protected:
    void topic_callback(const sensor_msgs::msg::PointCloud2::SharedPtr msg);

 
    // ROS2 subscriber and related topic name
    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr subscription_;
    std::string param_topic_pointcloud_in;
    
    // ROS2 publisher and related topic name 
    rclcpp::Publisher<c_auto_vehicle_msgs::msg::VelocityReport>::SharedPtr publisher_;
    std::string param_topic_pointcloud_out;
    
};

#endif //VELOCITY_PUBSUB__VELOCITY_PUBSUB_NODE_HPP_