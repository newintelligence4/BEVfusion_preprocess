cmake_minimum_required(VERSION 3.5)
project(concat)

if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(pcl_conversions REQUIRED)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED)
find_package(PCL 1.10 REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(pcl_ros REQUIRED)
find_package(c_auto_vehicle_msgs REQUIRED)

#find_package(OpenMP)
#find_package(CGAL REQUIRED COMPONENTS Core)

include_directories(
  ${PCL_INCLUDE_DIRS} 
  include
  SYSTEM
  ${Boost_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  #${GRID_MAP_INCLUDE_DIR}
)

add_library(pointcloud_preprocessor_filter_base SHARED
  src/filter.cpp
)

target_include_directories(pointcloud_preprocessor_filter_base PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:include/${PROJECT_NAME}>"
)

ament_target_dependencies( pointcloud_preprocessor_filter_base
  message_filters
  pcl_conversions
  rclcpp
  sensor_msgs
  tf2_ros
  #tier4_autoware_utils
  pcl_ros
  c_auto_vehicle_msgs
)

ament_auto_add_library(pointcloud_preprocessor_filter SHARED
  src/concatenate_data/concatenate_data_nodelet.cpp
)

target_link_libraries( pointcloud_preprocessor_filter
  pointcloud_preprocessor_filter_base
  ${Boost_SYSTEM_LIBRARY}
  ${OpenCV_LIBRARIES}
  ${PCL_LIBRARIES}
)
# ========== Concatenate data ==========
rclcpp_components_register_node(pointcloud_preprocessor_filter
  PLUGIN "pointcloud_preprocessor::PointCloudConcatenateDataSynchronizerComponent"
  EXECUTABLE concatenate_data_node)

install(
  TARGETS pointcloud_preprocessor_filter_base EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(
  DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}
)
install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)
# link_directories(${PCL_LIBRARY_DIRS})
# add_definitions(${PCL_DEFINITIONS})


# add_executable(filter src/filter.cpp)


ament_export_targets(export_${PROJECT_NAME})


# Rviz2 config for visualization
#install(FILES config/concat.rviz 
#  DESTINATION lib/${PROJECT_NAME}
#)

if(BUILD_TESTING)
 find_package(ament_lint_auto REQUIRED)
 ament_lint_auto_find_test_dependencies()
#  find_package(launch_testing_ament_cmake)    
#  add_launch_test(test/concat_launch.testing.py)
endif()

ament_auto_package(INSTALL_TO_SHARE
  launch
)
