cmake_minimum_required(VERSION 3.14)
project(autoware_point_types)

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

include_directories(
  include
  SYSTEM
  ${PCL_INCLUDE_DIRS}
)

if(BUILD_TESTING)
  ament_add_ros_isolated_gtest(test_autoware_point_types
    test/test_point_types.cpp
  )
  target_include_directories(test_autoware_point_types
    PRIVATE include
  )
  ament_target_dependencies(test_autoware_point_types
    point_cloud_msg_wrapper
  )
endif()

#ament_package()
