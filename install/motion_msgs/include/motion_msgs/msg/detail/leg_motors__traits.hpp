// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motion_msgs:msg/LegMotors.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__LEG_MOTORS__TRAITS_HPP_
#define MOTION_MSGS__MSG__DETAIL__LEG_MOTORS__TRAITS_HPP_

#include "motion_msgs/msg/detail/leg_motors__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<motion_msgs::msg::LegMotors>()
{
  return "motion_msgs::msg::LegMotors";
}

template<>
inline const char * name<motion_msgs::msg::LegMotors>()
{
  return "motion_msgs/msg/LegMotors";
}

template<>
struct has_fixed_size<motion_msgs::msg::LegMotors>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<motion_msgs::msg::LegMotors>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<motion_msgs::msg::LegMotors>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOTION_MSGS__MSG__DETAIL__LEG_MOTORS__TRAITS_HPP_
