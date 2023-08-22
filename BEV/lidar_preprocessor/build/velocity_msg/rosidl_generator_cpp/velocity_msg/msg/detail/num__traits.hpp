// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from velocity_msg:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef VELOCITY_MSG__MSG__DETAIL__NUM__TRAITS_HPP_
#define VELOCITY_MSG__MSG__DETAIL__NUM__TRAITS_HPP_

#include "velocity_msg/msg/detail/num__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<velocity_msg::msg::Num>()
{
  return "velocity_msg::msg::Num";
}

template<>
inline const char * name<velocity_msg::msg::Num>()
{
  return "velocity_msg/msg/Num";
}

template<>
struct has_fixed_size<velocity_msg::msg::Num>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<velocity_msg::msg::Num>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<velocity_msg::msg::Num>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VELOCITY_MSG__MSG__DETAIL__NUM__TRAITS_HPP_
