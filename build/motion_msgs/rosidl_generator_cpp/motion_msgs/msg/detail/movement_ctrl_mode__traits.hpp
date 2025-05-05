// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motion_msgs:msg/MovementCtrlMode.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_MODE__TRAITS_HPP_
#define MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_MODE__TRAITS_HPP_

#include "motion_msgs/msg/detail/movement_ctrl_mode__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<motion_msgs::msg::MovementCtrlMode>()
{
  return "motion_msgs::msg::MovementCtrlMode";
}

template<>
inline const char * name<motion_msgs::msg::MovementCtrlMode>()
{
  return "motion_msgs/msg/MovementCtrlMode";
}

template<>
struct has_fixed_size<motion_msgs::msg::MovementCtrlMode>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<motion_msgs::msg::MovementCtrlMode>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<motion_msgs::msg::MovementCtrlMode>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_MODE__TRAITS_HPP_
