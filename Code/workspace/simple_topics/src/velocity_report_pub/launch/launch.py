from launch import LaunchDescription
from launch_ros.actions import Node
#from launch_ros.descriptions import ComposableNode

def generate_launch_description():
    ns = "velocity_publisher"
    pkg = "velocity_pubsub"
    
    cpp_pubsub = Node(
            package=pkg,
            executable='int_velocity',
            name='int_velocity_pub',
        )
    velocity_pubsub = Node(
            package=pkg,
            executable='auto_velocity',
            name='auto_velocity_pub',
            parameters= [
            {'frame_id': 'lidar_top'},
            {'topic_pointcloud_in': '/lidar_top'},
            {'topic_pointcloud_out': '/vehicle/status/velocity_status'}],
        )

    return LaunchDescription([
    	cpp_pubsub,
    	velocity_pubsub,
    ])
