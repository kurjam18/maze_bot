// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mazebot_msgs:msg/MazebotNeighboringFieldsWallDetection.idl
// generated code does not contain a copyright notice

#ifndef MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_NEIGHBORING_FIELDS_WALL_DETECTION__STRUCT_HPP_
#define MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_NEIGHBORING_FIELDS_WALL_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection __attribute__((deprecated))
#else
# define DEPRECATED__mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection __declspec(deprecated)
#endif

namespace mazebot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MazebotNeighboringFieldsWallDetection_
{
  using Type = MazebotNeighboringFieldsWallDetection_<ContainerAllocator>;

  explicit MazebotNeighboringFieldsWallDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int8_t, 4>::iterator, int8_t>(this->front.begin(), this->front.end(), 0);
      std::fill<typename std::array<int8_t, 4>::iterator, int8_t>(this->rear.begin(), this->rear.end(), 0);
      std::fill<typename std::array<int8_t, 4>::iterator, int8_t>(this->left.begin(), this->left.end(), 0);
      std::fill<typename std::array<int8_t, 4>::iterator, int8_t>(this->right.begin(), this->right.end(), 0);
    }
  }

  explicit MazebotNeighboringFieldsWallDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    front(_alloc),
    rear(_alloc),
    left(_alloc),
    right(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int8_t, 4>::iterator, int8_t>(this->front.begin(), this->front.end(), 0);
      std::fill<typename std::array<int8_t, 4>::iterator, int8_t>(this->rear.begin(), this->rear.end(), 0);
      std::fill<typename std::array<int8_t, 4>::iterator, int8_t>(this->left.begin(), this->left.end(), 0);
      std::fill<typename std::array<int8_t, 4>::iterator, int8_t>(this->right.begin(), this->right.end(), 0);
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _front_type =
    std::array<int8_t, 4>;
  _front_type front;
  using _rear_type =
    std::array<int8_t, 4>;
  _rear_type rear;
  using _left_type =
    std::array<int8_t, 4>;
  _left_type left;
  using _right_type =
    std::array<int8_t, 4>;
  _right_type right;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__front(
    const std::array<int8_t, 4> & _arg)
  {
    this->front = _arg;
    return *this;
  }
  Type & set__rear(
    const std::array<int8_t, 4> & _arg)
  {
    this->rear = _arg;
    return *this;
  }
  Type & set__left(
    const std::array<int8_t, 4> & _arg)
  {
    this->left = _arg;
    return *this;
  }
  Type & set__right(
    const std::array<int8_t, 4> & _arg)
  {
    this->right = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection
    std::shared_ptr<mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection
    std::shared_ptr<mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MazebotNeighboringFieldsWallDetection_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->front != other.front) {
      return false;
    }
    if (this->rear != other.rear) {
      return false;
    }
    if (this->left != other.left) {
      return false;
    }
    if (this->right != other.right) {
      return false;
    }
    return true;
  }
  bool operator!=(const MazebotNeighboringFieldsWallDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MazebotNeighboringFieldsWallDetection_

// alias to use template instance with default allocator
using MazebotNeighboringFieldsWallDetection =
  mazebot_msgs::msg::MazebotNeighboringFieldsWallDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mazebot_msgs

#endif  // MAZEBOT_MSGS__MSG__DETAIL__MAZEBOT_NEIGHBORING_FIELDS_WALL_DETECTION__STRUCT_HPP_
