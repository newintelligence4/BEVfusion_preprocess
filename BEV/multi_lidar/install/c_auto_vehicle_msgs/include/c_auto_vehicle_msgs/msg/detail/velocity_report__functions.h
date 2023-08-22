// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from c_auto_vehicle_msgs:msg/VelocityReport.idl
// generated code does not contain a copyright notice

#ifndef C_AUTO_VEHICLE_MSGS__MSG__DETAIL__VELOCITY_REPORT__FUNCTIONS_H_
#define C_AUTO_VEHICLE_MSGS__MSG__DETAIL__VELOCITY_REPORT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "c_auto_vehicle_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "c_auto_vehicle_msgs/msg/detail/velocity_report__struct.h"

/// Initialize msg/VelocityReport message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * c_auto_vehicle_msgs__msg__VelocityReport
 * )) before or use
 * c_auto_vehicle_msgs__msg__VelocityReport__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_c_auto_vehicle_msgs
bool
c_auto_vehicle_msgs__msg__VelocityReport__init(c_auto_vehicle_msgs__msg__VelocityReport * msg);

/// Finalize msg/VelocityReport message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_auto_vehicle_msgs
void
c_auto_vehicle_msgs__msg__VelocityReport__fini(c_auto_vehicle_msgs__msg__VelocityReport * msg);

/// Create msg/VelocityReport message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * c_auto_vehicle_msgs__msg__VelocityReport__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_auto_vehicle_msgs
c_auto_vehicle_msgs__msg__VelocityReport *
c_auto_vehicle_msgs__msg__VelocityReport__create();

/// Destroy msg/VelocityReport message.
/**
 * It calls
 * c_auto_vehicle_msgs__msg__VelocityReport__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_auto_vehicle_msgs
void
c_auto_vehicle_msgs__msg__VelocityReport__destroy(c_auto_vehicle_msgs__msg__VelocityReport * msg);

/// Check for msg/VelocityReport message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_auto_vehicle_msgs
bool
c_auto_vehicle_msgs__msg__VelocityReport__are_equal(const c_auto_vehicle_msgs__msg__VelocityReport * lhs, const c_auto_vehicle_msgs__msg__VelocityReport * rhs);

/// Copy a msg/VelocityReport message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_auto_vehicle_msgs
bool
c_auto_vehicle_msgs__msg__VelocityReport__copy(
  const c_auto_vehicle_msgs__msg__VelocityReport * input,
  c_auto_vehicle_msgs__msg__VelocityReport * output);

/// Initialize array of msg/VelocityReport messages.
/**
 * It allocates the memory for the number of elements and calls
 * c_auto_vehicle_msgs__msg__VelocityReport__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_auto_vehicle_msgs
bool
c_auto_vehicle_msgs__msg__VelocityReport__Sequence__init(c_auto_vehicle_msgs__msg__VelocityReport__Sequence * array, size_t size);

/// Finalize array of msg/VelocityReport messages.
/**
 * It calls
 * c_auto_vehicle_msgs__msg__VelocityReport__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_auto_vehicle_msgs
void
c_auto_vehicle_msgs__msg__VelocityReport__Sequence__fini(c_auto_vehicle_msgs__msg__VelocityReport__Sequence * array);

/// Create array of msg/VelocityReport messages.
/**
 * It allocates the memory for the array and calls
 * c_auto_vehicle_msgs__msg__VelocityReport__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_auto_vehicle_msgs
c_auto_vehicle_msgs__msg__VelocityReport__Sequence *
c_auto_vehicle_msgs__msg__VelocityReport__Sequence__create(size_t size);

/// Destroy array of msg/VelocityReport messages.
/**
 * It calls
 * c_auto_vehicle_msgs__msg__VelocityReport__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_auto_vehicle_msgs
void
c_auto_vehicle_msgs__msg__VelocityReport__Sequence__destroy(c_auto_vehicle_msgs__msg__VelocityReport__Sequence * array);

/// Check for msg/VelocityReport message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_auto_vehicle_msgs
bool
c_auto_vehicle_msgs__msg__VelocityReport__Sequence__are_equal(const c_auto_vehicle_msgs__msg__VelocityReport__Sequence * lhs, const c_auto_vehicle_msgs__msg__VelocityReport__Sequence * rhs);

/// Copy an array of msg/VelocityReport messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_auto_vehicle_msgs
bool
c_auto_vehicle_msgs__msg__VelocityReport__Sequence__copy(
  const c_auto_vehicle_msgs__msg__VelocityReport__Sequence * input,
  c_auto_vehicle_msgs__msg__VelocityReport__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // C_AUTO_VEHICLE_MSGS__MSG__DETAIL__VELOCITY_REPORT__FUNCTIONS_H_
