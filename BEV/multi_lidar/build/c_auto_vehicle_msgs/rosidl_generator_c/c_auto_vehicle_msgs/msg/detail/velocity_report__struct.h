// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from c_auto_vehicle_msgs:msg/VelocityReport.idl
// generated code does not contain a copyright notice

#ifndef C_AUTO_VEHICLE_MSGS__MSG__DETAIL__VELOCITY_REPORT__STRUCT_H_
#define C_AUTO_VEHICLE_MSGS__MSG__DETAIL__VELOCITY_REPORT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

// Struct defined in msg/VelocityReport in the package c_auto_vehicle_msgs.
typedef struct c_auto_vehicle_msgs__msg__VelocityReport
{
  std_msgs__msg__Header header;
  float longitudinal_velocity;
  float lateral_velocity;
  float heading_rate;
} c_auto_vehicle_msgs__msg__VelocityReport;

// Struct for a sequence of c_auto_vehicle_msgs__msg__VelocityReport.
typedef struct c_auto_vehicle_msgs__msg__VelocityReport__Sequence
{
  c_auto_vehicle_msgs__msg__VelocityReport * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} c_auto_vehicle_msgs__msg__VelocityReport__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // C_AUTO_VEHICLE_MSGS__MSG__DETAIL__VELOCITY_REPORT__STRUCT_H_
