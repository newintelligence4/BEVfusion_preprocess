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

include_directories(${PCL_INCLUDE_DIRS} include)
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(code_node src/code_node.cpp src/code.cpp)

target_link_libraries( code_node
  ${Boost_SYSTEM_LIBRARY}
  ${PCL_LIBRARIES}
)

ament_target_dependencies(
  code_node
  rclcpp std_msgs 
  sensor_msgs
  pcl_conversions
  c_auto_vehicle_msgs
)

install(TARGETS
  code_node
  DESTINATION lib/${PROJECT_NAME}
)




ament_package()
