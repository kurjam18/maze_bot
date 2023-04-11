// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from mazebot_msgs:msg/MazebotNeighboringFieldsWallDetection.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "mazebot_msgs/msg/detail/mazebot_neighboring_fields_wall_detection__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace mazebot_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MazebotNeighboringFieldsWallDetection_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection(_init);
}

void MazebotNeighboringFieldsWallDetection_fini_function(void * message_memory)
{
  auto typed_message = static_cast<mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection *>(message_memory);
  typed_message->~MazebotNeighboringFieldsWallDetection();
}

size_t size_function__MazebotNeighboringFieldsWallDetection__front(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__MazebotNeighboringFieldsWallDetection__front(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__MazebotNeighboringFieldsWallDetection__front(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__MazebotNeighboringFieldsWallDetection__front(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int8_t *>(
    get_const_function__MazebotNeighboringFieldsWallDetection__front(untyped_member, index));
  auto & value = *reinterpret_cast<int8_t *>(untyped_value);
  value = item;
}

void assign_function__MazebotNeighboringFieldsWallDetection__front(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int8_t *>(
    get_function__MazebotNeighboringFieldsWallDetection__front(untyped_member, index));
  const auto & value = *reinterpret_cast<const int8_t *>(untyped_value);
  item = value;
}

size_t size_function__MazebotNeighboringFieldsWallDetection__rear(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__MazebotNeighboringFieldsWallDetection__rear(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__MazebotNeighboringFieldsWallDetection__rear(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__MazebotNeighboringFieldsWallDetection__rear(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int8_t *>(
    get_const_function__MazebotNeighboringFieldsWallDetection__rear(untyped_member, index));
  auto & value = *reinterpret_cast<int8_t *>(untyped_value);
  value = item;
}

void assign_function__MazebotNeighboringFieldsWallDetection__rear(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int8_t *>(
    get_function__MazebotNeighboringFieldsWallDetection__rear(untyped_member, index));
  const auto & value = *reinterpret_cast<const int8_t *>(untyped_value);
  item = value;
}

size_t size_function__MazebotNeighboringFieldsWallDetection__left(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__MazebotNeighboringFieldsWallDetection__left(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__MazebotNeighboringFieldsWallDetection__left(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__MazebotNeighboringFieldsWallDetection__left(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int8_t *>(
    get_const_function__MazebotNeighboringFieldsWallDetection__left(untyped_member, index));
  auto & value = *reinterpret_cast<int8_t *>(untyped_value);
  value = item;
}

void assign_function__MazebotNeighboringFieldsWallDetection__left(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int8_t *>(
    get_function__MazebotNeighboringFieldsWallDetection__left(untyped_member, index));
  const auto & value = *reinterpret_cast<const int8_t *>(untyped_value);
  item = value;
}

size_t size_function__MazebotNeighboringFieldsWallDetection__right(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__MazebotNeighboringFieldsWallDetection__right(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__MazebotNeighboringFieldsWallDetection__right(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__MazebotNeighboringFieldsWallDetection__right(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int8_t *>(
    get_const_function__MazebotNeighboringFieldsWallDetection__right(untyped_member, index));
  auto & value = *reinterpret_cast<int8_t *>(untyped_value);
  value = item;
}

void assign_function__MazebotNeighboringFieldsWallDetection__right(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int8_t *>(
    get_function__MazebotNeighboringFieldsWallDetection__right(untyped_member, index));
  const auto & value = *reinterpret_cast<const int8_t *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MazebotNeighboringFieldsWallDetection_message_member_array[5] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "front",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection, front),  // bytes offset in struct
    nullptr,  // default value
    size_function__MazebotNeighboringFieldsWallDetection__front,  // size() function pointer
    get_const_function__MazebotNeighboringFieldsWallDetection__front,  // get_const(index) function pointer
    get_function__MazebotNeighboringFieldsWallDetection__front,  // get(index) function pointer
    fetch_function__MazebotNeighboringFieldsWallDetection__front,  // fetch(index, &value) function pointer
    assign_function__MazebotNeighboringFieldsWallDetection__front,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "rear",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection, rear),  // bytes offset in struct
    nullptr,  // default value
    size_function__MazebotNeighboringFieldsWallDetection__rear,  // size() function pointer
    get_const_function__MazebotNeighboringFieldsWallDetection__rear,  // get_const(index) function pointer
    get_function__MazebotNeighboringFieldsWallDetection__rear,  // get(index) function pointer
    fetch_function__MazebotNeighboringFieldsWallDetection__rear,  // fetch(index, &value) function pointer
    assign_function__MazebotNeighboringFieldsWallDetection__rear,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "left",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection, left),  // bytes offset in struct
    nullptr,  // default value
    size_function__MazebotNeighboringFieldsWallDetection__left,  // size() function pointer
    get_const_function__MazebotNeighboringFieldsWallDetection__left,  // get_const(index) function pointer
    get_function__MazebotNeighboringFieldsWallDetection__left,  // get(index) function pointer
    fetch_function__MazebotNeighboringFieldsWallDetection__left,  // fetch(index, &value) function pointer
    assign_function__MazebotNeighboringFieldsWallDetection__left,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "right",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection, right),  // bytes offset in struct
    nullptr,  // default value
    size_function__MazebotNeighboringFieldsWallDetection__right,  // size() function pointer
    get_const_function__MazebotNeighboringFieldsWallDetection__right,  // get_const(index) function pointer
    get_function__MazebotNeighboringFieldsWallDetection__right,  // get(index) function pointer
    fetch_function__MazebotNeighboringFieldsWallDetection__right,  // fetch(index, &value) function pointer
    assign_function__MazebotNeighboringFieldsWallDetection__right,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MazebotNeighboringFieldsWallDetection_message_members = {
  "mazebot_msgs::msg",  // message namespace
  "MazebotNeighboringFieldsWallDetection",  // message name
  5,  // number of fields
  sizeof(mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection),
  MazebotNeighboringFieldsWallDetection_message_member_array,  // message members
  MazebotNeighboringFieldsWallDetection_init_function,  // function to initialize message memory (memory has to be allocated)
  MazebotNeighboringFieldsWallDetection_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MazebotNeighboringFieldsWallDetection_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MazebotNeighboringFieldsWallDetection_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace mazebot_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection>()
{
  return &::mazebot_msgs::msg::rosidl_typesupport_introspection_cpp::MazebotNeighboringFieldsWallDetection_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mazebot_msgs, msg, MazebotNeighboringFieldsWallDetection)() {
  return &::mazebot_msgs::msg::rosidl_typesupport_introspection_cpp::MazebotNeighboringFieldsWallDetection_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
