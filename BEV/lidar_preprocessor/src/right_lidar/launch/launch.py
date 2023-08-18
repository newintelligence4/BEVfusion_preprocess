#  Copyright (c) 2022 Jonas Mahler

#  This file is part of lidar_preprocessing.

#  lidar_preprocessing is free software: you can redistribute it and/or modify it under the terms 
#  of the GNU General Public License as published by the Free Software Foundation, 
#  either version 3 of the License, or (at your option) any later version.

#  lidar_preprocessing is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
#  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
#  See the GNU General Public License for more details.

#  You should have received a copy of the GNU General Public License along 
#  with lidar_preprocessing. If not, see <https://www.gnu.org/licenses/>. 

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='right_lidar',
            executable='ransac_node',
            name='ransac_node',
            parameters= [
            {'frame_id': 'lidar'},
            {'topic_pointcloud_in': 'os1_cloud_node/points'},
            {'topic_pointcloud_out': 'bf_lidar/point_cloud_ransac'}],
        )
    ])
