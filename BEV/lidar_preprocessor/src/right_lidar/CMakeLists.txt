#  Copyright (c) 2022 Jonas Mahler

#  This file is part of right_lidar.

#  right_lidar is free software: you can redistribute it and/or modify it under the terms 
#  of the GNU General Public License as published by the Free Software Foundation, 
#  either version 3 of the License, or (at your option) any later version.

#  right_lidar is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
#  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
#  See the GNU General Public License for more details.

#  You should have received a copy of the GNU General Public License along 
#  with right_lidar. If not, see <https://www.gnu.org/licenses/>. 

cmake_minimum_required(VERSION 3.5)
project(right_lidar)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(pcl_msgs REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(PCL 1.10 REQUIRED)
find_package(velocity_msg REQUIRED)

include_directories(${PCL_INCLUDE_DIRS} include)
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# add_executable(ransac_node src/ransac_node.cpp src/ransac.cpp)

# target_link_libraries( ransac_node
#   ${Boost_SYSTEM_LIBRARY}
#   ${PCL_LIBRARIES}
# )

# ament_target_dependencies(
#   ransac_node
#   rclcpp std_msgs 
#   sensor_msgs
#   pcl_msgs
#   pcl_conversions
# )

# install(TARGETS
#   ransac_node
#   DESTINATION lib/${PROJECT_NAME}
# )

# add_executable(roi_h_node src/roi_h_node.cpp src/roi_h.cpp)

# target_link_libraries( roi_h_node
#   ${Boost_SYSTEM_LIBRARY}
#   ${PCL_LIBRARIES}
# )

# ament_target_dependencies(
#   roi_h_node
#   rclcpp std_msgs 
#   sensor_msgs
#   pcl_conversions
#   velocity_msg
#   xyzit_msg
# )

# install(TARGETS
#   roi_h_node
#   DESTINATION lib/${PROJECT_NAME}
# )
add_executable(right_lidar_node src/right_lidar_node.cpp src/right_lidar.cpp)

target_link_libraries( right_lidar_node
  ${Boost_SYSTEM_LIBRARY}
  ${PCL_LIBRARIES}
)

ament_target_dependencies(
  right_lidar_node
  rclcpp std_msgs 
  sensor_msgs
  pcl_conversions
  velocity_msg
)

install(TARGETS
  right_lidar_node
  DESTINATION lib/${PROJECT_NAME}
)
# Files for testing
install(FILES
  test/cube1_record_1.yaml test/cube1_record_2.yaml test/right_lidar_launch.testing.py 
  DESTINATION lib/${PROJECT_NAME}
)

# Rviz2 config for visualization
install(FILES config/right_lidar.rviz 
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  #find_package(ament_lint_auto REQUIRED)
  #ament_lint_auto_find_test_dependencies()
  find_package(launch_testing_ament_cmake)    
  add_launch_test(test/right_lidar_launch.testing.py)
endif()

ament_package()
