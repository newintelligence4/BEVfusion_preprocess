# BEVfusion
### Multiple Lidar preprocessor for BEVfusion  
2023 Summer Internship Program at SKYAUTONET.  

This project has based on [Adaptive-ROI](https://github.com/newintelligence4/Adaptive-ROI-for-Lidar.git).  


## Dataset
- Rosbags

## Requirements

- `diagnostic_updater`
- `point_cloud_msg_wrapper`

Install 2 library ubove using `sudo apt install ros-foxy-`


## Build
It has 3 different directories for each function.
1. lidar-preprocessing  
: the basic preprocessing module in 3 direction
2. multi-lidar  
: the package for concatenate the 3 topics
3. simple-topics  
: the simple package for publish the topics velocity

## Run
Play the rosbags  

> input : `/lidar_top`  
> output: `/points_raw0`, `points_raw1`, `points_raw2`  

Publish the Velocity

```Shell
 ros2 launch velocity_pubsub launch.py
```

Run the Lidar Node
```Shell
ros2 launch three_lidar launch.py
```

Run the Concatenate Node
```Shell
ros2 launch concat preprocessing.launch.py
```


## Tools
- ROS2(foxy)
- C++
