#!/bin/bash
echo "start TF"

ros2 run tf2_ros static_transform_publisher 0 0 0 0 0 0 /lidar_link /back_lidar_link & 

ros2 run tf2_ros static_transform_publisher 0 0 0 0 0 0 /lidar_link /left_lidar_link & 

ros2 run tf2_ros static_transform_publisher 0 0 0 0 0 0 /lidar_link /right_lidar_link

