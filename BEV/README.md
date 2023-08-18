<<<<<<< HEAD
# BEVFusion
Adaptive Lidar Preprocessing for Single Lidar

The Simple **DEMO** Package for Single Lidar Adaptive ROI Preprocessing  

### I/O
input : `/left_lidar`
output : `/points_raw0`

### Usage
Play the Rosbag Data  
*Please remind to remap your topic to `/left_lidar`*  

Publish the Velocity Data using `cpp_pubsub`
```Shell
ros2 run cpp_pubsub talker
```
- This is the simple publish package for velocity data
- the output data's form is `Velocity_msg/msg/Num.msg`
  
Run the `back_lidar`
</br>
```Shell
ros2 run back_lidar back_lidar_node
```

### Result
<img src="./imgs/picture.png"/>

=======
# BEVfusion
Multiple Lidar preprocessor for BEVfusion
>>>>>>> 9a91decc9683cfd219a76606bd77dd22bc6f92c4
