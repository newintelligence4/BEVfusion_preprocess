// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from c_auto_vehicle_msgs:msg/VelocityReport.idl
// generated code does not contain a copyright notice
#include "c_auto_vehicle_msgs/msg/detail/velocity_report__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
c_auto_vehicle_msgs__msg__VelocityReport__init(c_auto_vehicle_msgs__msg__VelocityReport * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    c_auto_vehicle_msgs__msg__VelocityReport__fini(msg);
    return false;
  }
  // longitudinal_velocity
  msg->longitudinal_velocity = 0.0f;
  // lateral_velocity
  msg->lateral_velocity = 0.0f;
  // heading_rate
  msg->heading_rate = 0.0f;
  return true;
}

void
c_auto_vehicle_msgs__msg__VelocityReport__fini(c_auto_vehicle_msgs__msg__VelocityReport * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // longitudinal_velocity
  // lateral_velocity
  // heading_rate
}

bool
c_auto_vehicle_msgs__msg__VelocityReport__are_equal(const c_auto_vehicle_msgs__msg__VelocityReport * lhs, const c_auto_vehicle_msgs__msg__VelocityReport * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // longitudinal_velocity
  if (lhs->longitudinal_velocity != rhs->longitudinal_velocity) {
    return false;
  }
  // lateral_velocity
  if (lhs->lateral_velocity != rhs->lateral_velocity) {
    return false;
  }
  // heading_rate
  if (lhs->heading_rate != rhs->heading_rate) {
    return false;
  }
  return true;
}

bool
c_auto_vehicle_msgs__msg__VelocityReport__copy(
  const c_auto_vehicle_msgs__msg__VelocityReport * input,
  c_auto_vehicle_msgs__msg__VelocityReport * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // longitudinal_velocity
  output->longitudinal_velocity = input->longitudinal_velocity;
  // lateral_velocity
  output->lateral_velocity = input->lateral_velocity;
  // heading_rate
  output->heading_rate = input->heading_rate;
  return true;
}

c_auto_vehicle_msgs__msg__VelocityReport *
c_auto_vehicle_msgs__msg__VelocityReport__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  c_auto_vehicle_msgs__msg__VelocityReport * msg = (c_auto_vehicle_msgs__msg__VelocityReport *)allocator.allocate(sizeof(c_auto_vehicle_msgs__msg__VelocityReport), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(c_auto_vehicle_msgs__msg__VelocityReport));
  bool success = c_auto_vehicle_msgs__msg__VelocityReport__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
c_auto_vehicle_msgs__msg__VelocityReport__destroy(c_auto_vehicle_msgs__msg__VelocityReport * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    c_auto_vehicle_msgs__msg__VelocityReport__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
c_auto_vehicle_msgs__msg__VelocityReport__Sequence__init(c_auto_vehicle_msgs__msg__VelocityReport__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  c_auto_vehicle_msgs__msg__VelocityReport * data = NULL;

  if (size) {
    data = (c_auto_vehicle_msgs__msg__VelocityReport *)allocator.zero_allocate(size, sizeof(c_auto_vehicle_msgs__msg__VelocityReport), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = c_auto_vehicle_msgs__msg__VelocityReport__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        c_auto_vehicle_msgs__msg__VelocityReport__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
c_auto_vehicle_msgs__msg__VelocityReport__Sequence__fini(c_auto_vehicle_msgs__msg__VelocityReport__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      c_auto_vehicle_msgs__msg__VelocityReport__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

c_auto_vehicle_msgs__msg__VelocityReport__Sequence *
c_auto_vehicle_msgs__msg__VelocityReport__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  c_auto_vehicle_msgs__msg__VelocityReport__Sequence * array = (c_auto_vehicle_msgs__msg__VelocityReport__Sequence *)allocator.allocate(sizeof(c_auto_vehicle_msgs__msg__VelocityReport__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = c_auto_vehicle_msgs__msg__VelocityReport__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
c_auto_vehicle_msgs__msg__VelocityReport__Sequence__destroy(c_auto_vehicle_msgs__msg__VelocityReport__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    c_auto_vehicle_msgs__msg__VelocityReport__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
c_auto_vehicle_msgs__msg__VelocityReport__Sequence__are_equal(const c_auto_vehicle_msgs__msg__VelocityReport__Sequence * lhs, const c_auto_vehicle_msgs__msg__VelocityReport__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!c_auto_vehicle_msgs__msg__VelocityReport__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
c_auto_vehicle_msgs__msg__VelocityReport__Sequence__copy(
  const c_auto_vehicle_msgs__msg__VelocityReport__Sequence * input,
  c_auto_vehicle_msgs__msg__VelocityReport__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(c_auto_vehicle_msgs__msg__VelocityReport);
    c_auto_vehicle_msgs__msg__VelocityReport * data =
      (c_auto_vehicle_msgs__msg__VelocityReport *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!c_auto_vehicle_msgs__msg__VelocityReport__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          c_auto_vehicle_msgs__msg__VelocityReport__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!c_auto_vehicle_msgs__msg__VelocityReport__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
