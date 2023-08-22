// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from velocity_msg:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef VELOCITY_MSG__MSG__DETAIL__NUM__STRUCT_H_
#define VELOCITY_MSG__MSG__DETAIL__NUM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Num in the package velocity_msg.
typedef struct velocity_msg__msg__Num
{
  int64_t num;
} velocity_msg__msg__Num;

// Struct for a sequence of velocity_msg__msg__Num.
typedef struct velocity_msg__msg__Num__Sequence
{
  velocity_msg__msg__Num * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} velocity_msg__msg__Num__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VELOCITY_MSG__MSG__DETAIL__NUM__STRUCT_H_
