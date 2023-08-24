#!/bin/bash

echo "please play the bag file"

function velocity_pub(){
    cd ../simple_topics && rs
    ros2 launch velocity_pubsub launch.py &
}

./tf.sh &

cd ../simple_topics/ && rs && ros2 launch velocity_pubsub launch.py & 

cd ../lidar_preprocessing/ && ros2 launch three_lidar launch.py & 

ros2 launch concat preprocessing.launch.py &


