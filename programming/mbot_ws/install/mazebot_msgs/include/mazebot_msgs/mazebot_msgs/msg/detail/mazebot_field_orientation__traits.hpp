// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mazebot_msgs:msg/MazebotFieldOrientation.idl
// generated code does not contain a copyright notice

#ifndef MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_FIELD_ORIENTATION__TRAITS_HPP_
#define MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_FIELD_ORIENTATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mazebot_msgs/msg/detail/mazebot_field_orientation__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'laser_scan'
#include "sensor_msgs/msg/detail/laser_scan__traits.hpp"

namespace mazebot_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MazebotFieldOrientation & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: laser_scan
  {
    out << "laser_scan: ";
    to_flow_style_yaml(msg.laser_scan, out);
    out << ", ";
  }

  // member: front_distance
  {
    out << "front_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.front_distance, out);
    out << ", ";
  }

  // member: rear_distance
  {
    out << "rear_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_distance, out);
    out << ", ";
  }

  // member: left_distance
  {
    out << "left_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.left_distance, out);
    out << ", ";
  }

  // member: right_distance
  {
    out << "right_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.right_distance, out);
    out << ", ";
  }

  // member: front_angle_deg
  {
    out << "front_angle_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.front_angle_deg, out);
    out << ", ";
  }

  // member: rear_angle_deg
  {
    out << "rear_angle_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_angle_deg, out);
    out << ", ";
  }

  // member: left_angle_deg
  {
    out << "left_angle_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.left_angle_deg, out);
    out << ", ";
  }

  // member: right_angle_deg
  {
    out << "right_angle_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.right_angle_deg, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MazebotFieldOrientation & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: laser_scan
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "laser_scan:\n";
    to_block_style_yaml(msg.laser_scan, out, indentation + 2);
  }

  // member: front_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "front_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.front_distance, out);
    out << "\n";
  }

  // member: rear_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rear_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_distance, out);
    out << "\n";
  }

  // member: left_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.left_distance, out);
    out << "\n";
  }

  // member: right_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.right_distance, out);
    out << "\n";
  }

  // member: front_angle_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "front_angle_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.front_angle_deg, out);
    out << "\n";
  }

  // member: rear_angle_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rear_angle_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_angle_deg, out);
    out << "\n";
  }

  // member: left_angle_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_angle_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.left_angle_deg, out);
    out << "\n";
  }

  // member: right_angle_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_angle_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.right_angle_deg, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MazebotFieldOrientation & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace mazebot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use mazebot_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mazebot_msgs::msg::MazebotFieldOrientation & msg,
  std::ostream & out, size_t indentation = 0)
{
  mazebot_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mazebot_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const mazebot_msgs::msg::MazebotFieldOrientation & msg)
{
  return mazebot_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mazebot_msgs::msg::MazebotFieldOrientation>()
{
  return "mazebot_msgs::msg::MazebotFieldOrientation";
}

template<>
inline const char * name<mazebot_msgs::msg::MazebotFieldOrientation>()
{
  return "mazebot_msgs/msg/MazebotFieldOrientation";
}

template<>
struct has_fixed_size<mazebot_msgs::msg::MazebotFieldOrientation>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::LaserScan>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<mazebot_msgs::msg::MazebotFieldOrientation>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::LaserScan>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<mazebot_msgs::msg::MazebotFieldOrientation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_FIELD_ORIENTATION__TRAITS_HPP_
