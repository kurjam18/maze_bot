// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mazebot_msgs:msg/MazebotNeighboringFieldsWallDetection.idl
// generated code does not contain a copyright notice

#ifndef MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_NEIGHBORING_FIELDS_WALL_DETECTION__BUILDER_HPP_
#define MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_NEIGHBORING_FIELDS_WALL_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mazebot_msgs/msg/detail/mazebot_neighboring_fields_wall_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mazebot_msgs
{

namespace msg
{

namespace builder
{

class Init_MazebotNeighboringFieldsWallDetection_right
{
public:
  explicit Init_MazebotNeighboringFieldsWallDetection_right(::mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection & msg)
  : msg_(msg)
  {}
  ::mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection right(::mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection::_right_type arg)
  {
    msg_.right = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection msg_;
};

class Init_MazebotNeighboringFieldsWallDetection_left
{
public:
  explicit Init_MazebotNeighboringFieldsWallDetection_left(::mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection & msg)
  : msg_(msg)
  {}
  Init_MazebotNeighboringFieldsWallDetection_right left(::mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection::_left_type arg)
  {
    msg_.left = std::move(arg);
    return Init_MazebotNeighboringFieldsWallDetection_right(msg_);
  }

private:
  ::mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection msg_;
};

class Init_MazebotNeighboringFieldsWallDetection_rear
{
public:
  explicit Init_MazebotNeighboringFieldsWallDetection_rear(::mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection & msg)
  : msg_(msg)
  {}
  Init_MazebotNeighboringFieldsWallDetection_left rear(::mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection::_rear_type arg)
  {
    msg_.rear = std::move(arg);
    return Init_MazebotNeighboringFieldsWallDetection_left(msg_);
  }

private:
  ::mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection msg_;
};

class Init_MazebotNeighboringFieldsWallDetection_front
{
public:
  explicit Init_MazebotNeighboringFieldsWallDetection_front(::mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection & msg)
  : msg_(msg)
  {}
  Init_MazebotNeighboringFieldsWallDetection_rear front(::mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection::_front_type arg)
  {
    msg_.front = std::move(arg);
    return Init_MazebotNeighboringFieldsWallDetection_rear(msg_);
  }

private:
  ::mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection msg_;
};

class Init_MazebotNeighboringFieldsWallDetection_header
{
public:
  Init_MazebotNeighboringFieldsWallDetection_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MazebotNeighboringFieldsWallDetection_front header(::mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MazebotNeighboringFieldsWallDetection_front(msg_);
  }

private:
  ::mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection>()
{
  return mazebot_msgs::msg::builder::Init_MazebotNeighboringFieldsWallDetection_header();
}

}  // namespace mazebot_msgs

#endif  // MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_NEIGHBORING_FIELDS_WALL_DETECTION__BUILDER_HPP_
