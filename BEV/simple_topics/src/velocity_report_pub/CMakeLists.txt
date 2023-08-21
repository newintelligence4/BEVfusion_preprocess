cmake_minimum_required(VERSION 3.5)
project(velocity_pubsub)

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
find_package(pcl_conversions REQUIRED)
find_package(PCL 1.10 REQUIRED)
find_package(c_auto_vehicle_msgs REQUIRED)
find_package(velocity_msg REQUIRED)

include_directories(${PCL_INCLUDE_DIRS} include)
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(auto_velocity src/code_node.cpp src/code.cpp)
add_executable(int_velocity src/publisher_member_function.cpp)

ament_target_dependencies(
  int_velocity 
  rclcpp 
  velocity_msg
)

target_link_libraries( auto_velocity
  ${Boost_SYSTEM_LIBRARY}
  ${PCL_LIBRARIES}
)

ament_target_dependencies(
  auto_velocity
  rclcpp std_msgs 
  sensor_msgs
  pcl_conversions
  c_auto_vehicle_msgs
)

install(TARGETS
  auto_velocity
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS
  int_velocity
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
