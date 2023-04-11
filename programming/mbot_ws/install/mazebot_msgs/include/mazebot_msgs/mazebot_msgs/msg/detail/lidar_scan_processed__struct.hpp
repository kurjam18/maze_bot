// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mazebot_msgs:msg/LidarScanProcessed.idl
// generated code does not contain a copyright notice

#ifndef MAZEBOT_MSGS__MSG__DETAIL__LIDAR_SCAN_PROCESSED__STRUCT_HPP_
#define MAZEBOT_MSGS__MSG__DETAIL__LIDAR_SCAN_PROCESSED__STRUCT_HPP_

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
// Member 'laser_scan'
#include "sensor_msgs/msg/detail/laser_scan__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mazebot_msgs__msg__LidarScanProcessed __attribute__((deprecated))
#else
# define DEPRECATED__mazebot_msgs__msg__LidarScanProcessed __declspec(deprecated)
#endif

namespace mazebot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LidarScanProcessed_
{
  using Type = LidarScanProcessed_<ContainerAllocator>;

  explicit LidarScanProcessed_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    laser_scan(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->front_distance = 0.0f;
      this->rear_distance = 0.0f;
      this->left_distance = 0.0f;
      this->right_distance = 0.0f;
      this->left_angle_deg = 0.0f;
      this->right_angle_deg = 0.0f;
    }
  }

  explicit LidarScanProcessed_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    laser_scan(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->front_distance = 0.0f;
      this->rear_distance = 0.0f;
      this->left_distance = 0.0f;
      this->right_distance = 0.0f;
      this->left_angle_deg = 0.0f;
      this->right_angle_deg = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _laser_scan_type =
    sensor_msgs::msg::LaserScan_<ContainerAllocator>;
  _laser_scan_type laser_scan;
  using _front_distance_type =
    float;
  _front_distance_type front_distance;
  using _rear_distance_type =
    float;
  _rear_distance_type rear_distance;
  using _left_distance_type =
    float;
  _left_distance_type left_distance;
  using _right_distance_type =
    float;
  _right_distance_type right_distance;
  using _left_angle_deg_type =
    float;
  _left_angle_deg_type left_angle_deg;
  using _right_angle_deg_type =
    float;
  _right_angle_deg_type right_angle_deg;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__laser_scan(
    const sensor_msgs::msg::LaserScan_<ContainerAllocator> & _arg)
  {
    this->laser_scan = _arg;
    return *this;
  }
  Type & set__front_distance(
    const float & _arg)
  {
    this->front_distance = _arg;
    return *this;
  }
  Type & set__rear_distance(
    const float & _arg)
  {
    this->rear_distance = _arg;
    return *this;
  }
  Type & set__left_distance(
    const float & _arg)
  {
    this->left_distance = _arg;
    return *this;
  }
  Type & set__right_distance(
    const float & _arg)
  {
    this->right_distance = _arg;
    return *this;
  }
  Type & set__left_angle_deg(
    const float & _arg)
  {
    this->left_angle_deg = _arg;
    return *this;
  }
  Type & set__right_angle_deg(
    const float & _arg)
  {
    this->right_angle_deg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mazebot_msgs::msg::LidarScanProcessed_<ContainerAllocator> *;
  using ConstRawPtr =
    const mazebot_msgs::msg::LidarScanProcessed_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mazebot_msgs::msg::LidarScanProcessed_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mazebot_msgs::msg::LidarScanProcessed_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mazebot_msgs::msg::LidarScanProcessed_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mazebot_msgs::msg::LidarScanProcessed_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mazebot_msgs::msg::LidarScanProcessed_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mazebot_msgs::msg::LidarScanProcessed_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mazebot_msgs::msg::LidarScanProcessed_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mazebot_msgs::msg::LidarScanProcessed_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mazebot_msgs__msg__LidarScanProcessed
    std::shared_ptr<mazebot_msgs::msg::LidarScanProcessed_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mazebot_msgs__msg__LidarScanProcessed
    std::shared_ptr<mazebot_msgs::msg::LidarScanProcessed_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LidarScanProcessed_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->laser_scan != other.laser_scan) {
      return false;
    }
    if (this->front_distance != other.front_distance) {
      return false;
    }
    if (this->rear_distance != other.rear_distance) {
      return false;
    }
    if (this->left_distance != other.left_distance) {
      return false;
    }
    if (this->right_distance != other.right_distance) {
      return false;
    }
    if (this->left_angle_deg != other.left_angle_deg) {
      return false;
    }
    if (this->right_angle_deg != other.right_angle_deg) {
      return false;
    }
    return true;
  }
  bool operator!=(const LidarScanProcessed_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LidarScanProcessed_

// alias to use template instance with default allocator
using LidarScanProcessed =
  mazebot_msgs::msg::LidarScanProcessed_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mazebot_msgs

#endif  // MAZEBOT_MSGS__MSG__DETAIL__LIDAR_SCAN_PROCESSED__STRUCT_HPP_
