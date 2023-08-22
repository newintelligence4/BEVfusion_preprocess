from launch import LaunchDescription
from launch_ros.actions import Node
#from launch_ros.descriptions import ComposableNode

def generate_launch_description():
    ns = "concat_filter"
    pkg = "three_lidar"
    left_node = Node(
            package=pkg,
            executable='left',
            name='left_lidar',
            parameters= [
            {'frame_id': 'lidar_top'},
            {'topic_pointcloud_in': '/lidar_top'},
            {'topic_pointcloud_out': '/points_raw1'}],
        )
    right_node = Node(
            package=pkg,
            executable='right',
            name='right_lidar',
            parameters= [
            {'frame_id': 'lidar_top'},
            {'topic_pointcloud_in': '/lidar_top'},
            {'topic_pointcloud_out': '/points_raw2'}],
        )
    back_node= Node(
            package=pkg,
            executable='back',
            name='back_lidar',
            parameters= [
            {'frame_id': 'lidar_top'},
            {'topic_pointcloud_in': '/lidar_top'},
            {'topic_pointcloud_out': '/points_raw0'}],
        )
    #container = ComposableNodeContainer(
    #	name="lidar_preprocessing_container",
    #	namespace=ns,
    #	package=pkg,
    #	executable="component_container",
    #	composable_node_descriptions=[back_node, left_node, right_node],
    #	output="screen",
    #)
    return LaunchDescription([
    	back_node,
    	left_node,
    	right_node,
    ])
