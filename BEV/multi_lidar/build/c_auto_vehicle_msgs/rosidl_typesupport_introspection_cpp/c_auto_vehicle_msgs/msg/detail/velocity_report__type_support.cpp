// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from c_auto_vehicle_msgs:msg/VelocityReport.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "c_auto_vehicle_msgs/msg/detail/velocity_report__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace c_auto_vehicle_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void VelocityReport_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) c_auto_vehicle_msgs::msg::VelocityReport(_init);
}

void VelocityReport_fini_function(void * message_memory)
{
  auto typed_message = static_cast<c_auto_vehicle_msgs::msg::VelocityReport *>(message_memory);
  typed_message->~VelocityReport();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember VelocityReport_message_member_array[4] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(c_auto_vehicle_msgs::msg::VelocityReport, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "longitudinal_velocity",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(c_auto_vehicle_msgs::msg::VelocityReport, longitudinal_velocity),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "lateral_velocity",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(c_auto_vehicle_msgs::msg::VelocityReport, lateral_velocity),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "heading_rate",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(c_auto_vehicle_msgs::msg::VelocityReport, heading_rate),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers VelocityReport_message_members = {
  "c_auto_vehicle_msgs::msg",  // message namespace
  "VelocityReport",  // message name
  4,  // number of fields
  sizeof(c_auto_vehicle_msgs::msg::VelocityReport),
  VelocityReport_message_member_array,  // message members
  VelocityReport_init_function,  // function to initialize message memory (memory has to be allocated)
  VelocityReport_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t VelocityReport_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VelocityReport_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace c_auto_vehicle_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<c_auto_vehicle_msgs::msg::VelocityReport>()
{
  return &::c_auto_vehicle_msgs::msg::rosidl_typesupport_introspection_cpp::VelocityReport_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, c_auto_vehicle_msgs, msg, VelocityReport)() {
  return &::c_auto_vehicle_msgs::msg::rosidl_typesupport_introspection_cpp::VelocityReport_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
