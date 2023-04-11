// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mazebot_msgs:msg/MazebotNeighboringFieldsWallDetection.idl
// generated code does not contain a copyright notice

#ifndef MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_NEIGHBORING_FIELDS_WALL_DETECTION__TRAITS_HPP_
#define MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_NEIGHBORING_FIELDS_WALL_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mazebot_msgs/msg/detail/mazebot_neighboring_fields_wall_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace mazebot_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MazebotNeighboringFieldsWallDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: front
  {
    if (msg.front.size() == 0) {
      out << "front: []";
    } else {
      out << "front: [";
      size_t pending_items = msg.front.size();
      for (auto item : msg.front) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: rear
  {
    if (msg.rear.size() == 0) {
      out << "rear: []";
    } else {
      out << "rear: [";
      size_t pending_items = msg.rear.size();
      for (auto item : msg.rear) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: left
  {
    if (msg.left.size() == 0) {
      out << "left: []";
    } else {
      out << "left: [";
      size_t pending_items = msg.left.size();
      for (auto item : msg.left) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: right
  {
    if (msg.right.size() == 0) {
      out << "right: []";
    } else {
      out << "right: [";
      size_t pending_items = msg.right.size();
      for (auto item : msg.right) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MazebotNeighboringFieldsWallDetection & msg,
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

  // member: front
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.front.size() == 0) {
      out << "front: []\n";
    } else {
      out << "front:\n";
      for (auto item : msg.front) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: rear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.rear.size() == 0) {
      out << "rear: []\n";
    } else {
      out << "rear:\n";
      for (auto item : msg.rear) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left.size() == 0) {
      out << "left: []\n";
    } else {
      out << "left:\n";
      for (auto item : msg.left) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right.size() == 0) {
      out << "right: []\n";
    } else {
      out << "right:\n";
      for (auto item : msg.right) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MazebotNeighboringFieldsWallDetection & msg, bool use_flow_style = false)
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
  const mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  mazebot_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mazebot_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection & msg)
{
  return mazebot_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection>()
{
  return "mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection";
}

template<>
inline const char * name<mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection>()
{
  return "mazebot_msgs/msg/MazebotNeighboringFieldsWallDetection";
}

template<>
struct has_fixed_size<mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_NEIGHBORING_FIELDS_WALL_DETECTION__TRAITS_HPP_
