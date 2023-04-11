// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mazebot_msgs:msg/MazebotFieldOrientation.idl
// generated code does not contain a copyright notice

#ifndef MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_FIELD_ORIENTATION__BUILDER_HPP_
#define MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_FIELD_ORIENTATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mazebot_msgs/msg/detail/mazebot_field_orientation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mazebot_msgs
{

namespace msg
{

namespace builder
{

class Init_MazebotFieldOrientation_right_angle_deg
{
public:
  explicit Init_MazebotFieldOrientation_right_angle_deg(::mazebot_msgs::msg::MazebotFieldOrientation & msg)
  : msg_(msg)
  {}
  ::mazebot_msgs::msg::MazebotFieldOrientation right_angle_deg(::mazebot_msgs::msg::MazebotFieldOrientation::_right_angle_deg_type arg)
  {
    msg_.right_angle_deg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mazebot_msgs::msg::MazebotFieldOrientation msg_;
};

class Init_MazebotFieldOrientation_left_angle_deg
{
public:
  explicit Init_MazebotFieldOrientation_left_angle_deg(::mazebot_msgs::msg::MazebotFieldOrientation & msg)
  : msg_(msg)
  {}
  Init_MazebotFieldOrientation_right_angle_deg left_angle_deg(::mazebot_msgs::msg::MazebotFieldOrientation::_left_angle_deg_type arg)
  {
    msg_.left_angle_deg = std::move(arg);
    return Init_MazebotFieldOrientation_right_angle_deg(msg_);
  }

private:
  ::mazebot_msgs::msg::MazebotFieldOrientation msg_;
};

class Init_MazebotFieldOrientation_rear_angle_deg
{
public:
  explicit Init_MazebotFieldOrientation_rear_angle_deg(::mazebot_msgs::msg::MazebotFieldOrientation & msg)
  : msg_(msg)
  {}
  Init_MazebotFieldOrientation_left_angle_deg rear_angle_deg(::mazebot_msgs::msg::MazebotFieldOrientation::_rear_angle_deg_type arg)
  {
    msg_.rear_angle_deg = std::move(arg);
    return Init_MazebotFieldOrientation_left_angle_deg(msg_);
  }

private:
  ::mazebot_msgs::msg::MazebotFieldOrientation msg_;
};

class Init_MazebotFieldOrientation_front_angle_deg
{
public:
  explicit Init_MazebotFieldOrientation_front_angle_deg(::mazebot_msgs::msg::MazebotFieldOrientation & msg)
  : msg_(msg)
  {}
  Init_MazebotFieldOrientation_rear_angle_deg front_angle_deg(::mazebot_msgs::msg::MazebotFieldOrientation::_front_angle_deg_type arg)
  {
    msg_.front_angle_deg = std::move(arg);
    return Init_MazebotFieldOrientation_rear_angle_deg(msg_);
  }

private:
  ::mazebot_msgs::msg::MazebotFieldOrientation msg_;
};

class Init_MazebotFieldOrientation_right_distance
{
public:
  explicit Init_MazebotFieldOrientation_right_distance(::mazebot_msgs::msg::MazebotFieldOrientation & msg)
  : msg_(msg)
  {}
  Init_MazebotFieldOrientation_front_angle_deg right_distance(::mazebot_msgs::msg::MazebotFieldOrientation::_right_distance_type arg)
  {
    msg_.right_distance = std::move(arg);
    return Init_MazebotFieldOrientation_front_angle_deg(msg_);
  }

private:
  ::mazebot_msgs::msg::MazebotFieldOrientation msg_;
};

class Init_MazebotFieldOrientation_left_distance
{
public:
  explicit Init_MazebotFieldOrientation_left_distance(::mazebot_msgs::msg::MazebotFieldOrientation & msg)
  : msg_(msg)
  {}
  Init_MazebotFieldOrientation_right_distance left_distance(::mazebot_msgs::msg::MazebotFieldOrientation::_left_distance_type arg)
  {
    msg_.left_distance = std::move(arg);
    return Init_MazebotFieldOrientation_right_distance(msg_);
  }

private:
  ::mazebot_msgs::msg::MazebotFieldOrientation msg_;
};

class Init_MazebotFieldOrientation_rear_distance
{
public:
  explicit Init_MazebotFieldOrientation_rear_distance(::mazebot_msgs::msg::MazebotFieldOrientation & msg)
  : msg_(msg)
  {}
  Init_MazebotFieldOrientation_left_distance rear_distance(::mazebot_msgs::msg::MazebotFieldOrientation::_rear_distance_type arg)
  {
    msg_.rear_distance = std::move(arg);
    return Init_MazebotFieldOrientation_left_distance(msg_);
  }

private:
  ::mazebot_msgs::msg::MazebotFieldOrientation msg_;
};

class Init_MazebotFieldOrientation_front_distance
{
public:
  explicit Init_MazebotFieldOrientation_front_distance(::mazebot_msgs::msg::MazebotFieldOrientation & msg)
  : msg_(msg)
  {}
  Init_MazebotFieldOrientation_rear_distance front_distance(::mazebot_msgs::msg::MazebotFieldOrientation::_front_distance_type arg)
  {
    msg_.front_distance = std::move(arg);
    return Init_MazebotFieldOrientation_rear_distance(msg_);
  }

private:
  ::mazebot_msgs::msg::MazebotFieldOrientation msg_;
};

class Init_MazebotFieldOrientation_laser_scan
{
public:
  explicit Init_MazebotFieldOrientation_laser_scan(::mazebot_msgs::msg::MazebotFieldOrientation & msg)
  : msg_(msg)
  {}
  Init_MazebotFieldOrientation_front_distance laser_scan(::mazebot_msgs::msg::MazebotFieldOrientation::_laser_scan_type arg)
  {
    msg_.laser_scan = std::move(arg);
    return Init_MazebotFieldOrientation_front_distance(msg_);
  }

private:
  ::mazebot_msgs::msg::MazebotFieldOrientation msg_;
};

class Init_MazebotFieldOrientation_header
{
public:
  Init_MazebotFieldOrientation_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MazebotFieldOrientation_laser_scan header(::mazebot_msgs::msg::MazebotFieldOrientation::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MazebotFieldOrientation_laser_scan(msg_);
  }

private:
  ::mazebot_msgs::msg::MazebotFieldOrientation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mazebot_msgs::msg::MazebotFieldOrientation>()
{
  return mazebot_msgs::msg::builder::Init_MazebotFieldOrientation_header();
}

}  // namespace mazebot_msgs

#endif  // MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_FIELD_ORIENTATION__BUILDER_HPP_
