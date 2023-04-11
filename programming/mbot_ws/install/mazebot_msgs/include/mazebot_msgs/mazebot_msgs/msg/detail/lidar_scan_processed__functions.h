// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from mazebot_msgs:msg/LidarScanProcessed.idl
// generated code does not contain a copyright notice

#ifndef MAZEBOT_MSGS__MSG__DETAIL__LIDAR_SCAN_PROCESSED__FUNCTIONS_H_
#define MAZEBOT_MSGS__MSG__DETAIL__LIDAR_SCAN_PROCESSED__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "mazebot_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "mazebot_msgs/msg/detail/lidar_scan_processed__struct.h"

/// Initialize msg/LidarScanProcessed message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mazebot_msgs__msg__LidarScanProcessed
 * )) before or use
 * mazebot_msgs__msg__LidarScanProcessed__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mazebot_msgs
bool
mazebot_msgs__msg__LidarScanProcessed__init(mazebot_msgs__msg__LidarScanProcessed * msg);

/// Finalize msg/LidarScanProcessed message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mazebot_msgs
void
mazebot_msgs__msg__LidarScanProcessed__fini(mazebot_msgs__msg__LidarScanProcessed * msg);

/// Create msg/LidarScanProcessed message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mazebot_msgs__msg__LidarScanProcessed__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mazebot_msgs
mazebot_msgs__msg__LidarScanProcessed *
mazebot_msgs__msg__LidarScanProcessed__create();

/// Destroy msg/LidarScanProcessed message.
/**
 * It calls
 * mazebot_msgs__msg__LidarScanProcessed__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mazebot_msgs
void
mazebot_msgs__msg__LidarScanProcessed__destroy(mazebot_msgs__msg__LidarScanProcessed * msg);

/// Check for msg/LidarScanProcessed message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mazebot_msgs
bool
mazebot_msgs__msg__LidarScanProcessed__are_equal(const mazebot_msgs__msg__LidarScanProcessed * lhs, const mazebot_msgs__msg__LidarScanProcessed * rhs);

/// Copy a msg/LidarScanProcessed message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mazebot_msgs
bool
mazebot_msgs__msg__LidarScanProcessed__copy(
  const mazebot_msgs__msg__LidarScanProcessed * input,
  mazebot_msgs__msg__LidarScanProcessed * output);

/// Initialize array of msg/LidarScanProcessed messages.
/**
 * It allocates the memory for the number of elements and calls
 * mazebot_msgs__msg__LidarScanProcessed__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mazebot_msgs
bool
mazebot_msgs__msg__LidarScanProcessed__Sequence__init(mazebot_msgs__msg__LidarScanProcessed__Sequence * array, size_t size);

/// Finalize array of msg/LidarScanProcessed messages.
/**
 * It calls
 * mazebot_msgs__msg__LidarScanProcessed__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mazebot_msgs
void
mazebot_msgs__msg__LidarScanProcessed__Sequence__fini(mazebot_msgs__msg__LidarScanProcessed__Sequence * array);

/// Create array of msg/LidarScanProcessed messages.
/**
 * It allocates the memory for the array and calls
 * mazebot_msgs__msg__LidarScanProcessed__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mazebot_msgs
mazebot_msgs__msg__LidarScanProcessed__Sequence *
mazebot_msgs__msg__LidarScanProcessed__Sequence__create(size_t size);

/// Destroy array of msg/LidarScanProcessed messages.
/**
 * It calls
 * mazebot_msgs__msg__LidarScanProcessed__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mazebot_msgs
void
mazebot_msgs__msg__LidarScanProcessed__Sequence__destroy(mazebot_msgs__msg__LidarScanProcessed__Sequence * array);

/// Check for msg/LidarScanProcessed message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mazebot_msgs
bool
mazebot_msgs__msg__LidarScanProcessed__Sequence__are_equal(const mazebot_msgs__msg__LidarScanProcessed__Sequence * lhs, const mazebot_msgs__msg__LidarScanProcessed__Sequence * rhs);

/// Copy an array of msg/LidarScanProcessed messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mazebot_msgs
bool
mazebot_msgs__msg__LidarScanProcessed__Sequence__copy(
  const mazebot_msgs__msg__LidarScanProcessed__Sequence * input,
  mazebot_msgs__msg__LidarScanProcessed__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MAZEBOT_MSGS__MSG__DETAIL__LIDAR_SCAN_PROCESSED__FUNCTIONS_H_
