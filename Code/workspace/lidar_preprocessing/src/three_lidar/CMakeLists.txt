cmake_minimum_required(VERSION 3.5)
project(three_lidar)

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

add_executable(back src/back_lidar/back_lidar_node.cpp src/back_lidar/back_lidar.cpp)
add_executable(left src/left_lidar/left_lidar_node.cpp src/left_lidar/left_lidar.cpp)
add_executable(right src/right_lidar/right_lidar_node.cpp src/right_lidar/right_lidar.cpp)

target_link_libraries( back
  ${Boost_SYSTEM_LIBRARY}
  ${PCL_LIBRARIES}
)
target_link_libraries( left
  ${Boost_SYSTEM_LIBRARY}
  ${PCL_LIBRARIES}
)
target_link_libraries( right
  ${Boost_SYSTEM_LIBRARY}
  ${PCL_LIBRARIES}
)
set(SET_TARGET
  rclcpp std_msgs 
  sensor_msgs
  pcl_conversions
  velocity_msg
)

ament_target_dependencies(
  back
  ${SET_TARGET}
)
ament_target_dependencies(
  left
  ${SET_TARGET}
)
ament_target_dependencies(
  right
  ${SET_TARGET}
)
install(TARGETS
  back
  DESTINATION lib/${PROJECT_NAME}
)
install(TARGETS
  left
  DESTINATION lib/${PROJECT_NAME}
)
install(TARGETS
  right
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

if(BUILD_TESTING)
  find_package(launch_testing_ament_cmake)    
endif()

ament_package()
