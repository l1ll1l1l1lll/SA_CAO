// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motion_msgs:msg/MovementCtrlData.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_DATA__TRAITS_HPP_
#define MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_DATA__TRAITS_HPP_

#include "motion_msgs/msg/detail/movement_ctrl_data__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<motion_msgs::msg::MovementCtrlData>()
{
  return "motion_msgs::msg::MovementCtrlData";
}

template<>
inline const char * name<motion_msgs::msg::MovementCtrlData>()
{
  return "motion_msgs/msg/MovementCtrlData";
}

template<>
struct has_fixed_size<motion_msgs::msg::MovementCtrlData>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<motion_msgs::msg::MovementCtrlData>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<motion_msgs::msg::MovementCtrlData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_DATA__TRAITS_HPP_
