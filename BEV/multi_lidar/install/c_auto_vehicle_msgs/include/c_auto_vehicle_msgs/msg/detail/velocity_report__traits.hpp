// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from c_auto_vehicle_msgs:msg/VelocityReport.idl
// generated code does not contain a copyright notice

#ifndef C_AUTO_VEHICLE_MSGS__MSG__DETAIL__VELOCITY_REPORT__TRAITS_HPP_
#define C_AUTO_VEHICLE_MSGS__MSG__DETAIL__VELOCITY_REPORT__TRAITS_HPP_

#include "c_auto_vehicle_msgs/msg/detail/velocity_report__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<c_auto_vehicle_msgs::msg::VelocityReport>()
{
  return "c_auto_vehicle_msgs::msg::VelocityReport";
}

template<>
inline const char * name<c_auto_vehicle_msgs::msg::VelocityReport>()
{
  return "c_auto_vehicle_msgs/msg/VelocityReport";
}

template<>
struct has_fixed_size<c_auto_vehicle_msgs::msg::VelocityReport>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<c_auto_vehicle_msgs::msg::VelocityReport>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<c_auto_vehicle_msgs::msg::VelocityReport>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // C_AUTO_VEHICLE_MSGS__MSG__DETAIL__VELOCITY_REPORT__TRAITS_HPP_
