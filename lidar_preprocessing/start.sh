#!/bin/bash

echo "please play the bag file"

./tf.sh &

gnome-terminal -- ros2 launch three_lidar launch.py

gnome-terminal -- ros2 launch concat preprocessing.launch.py

