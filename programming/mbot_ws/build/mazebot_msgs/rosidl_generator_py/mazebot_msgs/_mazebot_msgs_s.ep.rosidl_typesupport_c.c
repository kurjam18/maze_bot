// generated from rosidl_generator_py/resource/_idl_pkg_typesupport_entry_point.c.em
// generated code does not contain a copyright notice
#include <Python.h>

static PyMethodDef mazebot_msgs__methods[] = {
  {NULL, NULL, 0, NULL}  /* sentinel */
};

static struct PyModuleDef mazebot_msgs__module = {
  PyModuleDef_HEAD_INIT,
  "_mazebot_msgs_support",
  "_mazebot_msgs_doc",
  -1,  /* -1 means that the module keeps state in global variables */
  mazebot_msgs__methods,
  NULL,
  NULL,
  NULL,
  NULL,
};

#include <stdbool.h>
#include <stdint.h>
#include "rosidl_runtime_c/visibility_control.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "mazebot_msgs/msg/detail/lidar_scan_processed__type_support.h"
#include "mazebot_msgs/msg/detail/lidar_scan_processed__struct.h"
#include "mazebot_msgs/msg/detail/lidar_scan_processed__functions.h"

static void * mazebot_msgs__msg__lidar_scan_processed__create_ros_message(void)
{
  return mazebot_msgs__msg__LidarScanProcessed__create();
}

static void mazebot_msgs__msg__lidar_scan_processed__destroy_ros_message(void * raw_ros_message)
{
  mazebot_msgs__msg__LidarScanProcessed * ros_message = (mazebot_msgs__msg__LidarScanProcessed *)raw_ros_message;
  mazebot_msgs__msg__LidarScanProcessed__destroy(ros_message);
}

ROSIDL_GENERATOR_C_IMPORT
bool mazebot_msgs__msg__lidar_scan_processed__convert_from_py(PyObject * _pymsg, void * ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * mazebot_msgs__msg__lidar_scan_processed__convert_to_py(void * raw_ros_message);


ROSIDL_GENERATOR_C_IMPORT
const rosidl_message_type_support_t *
ROSIDL_GET_MSG_TYPE_SUPPORT(mazebot_msgs, msg, LidarScanProcessed);

int8_t
_register_msg_type__msg__lidar_scan_processed(PyObject * pymodule)
{
  int8_t err;

  PyObject * pyobject_create_ros_message = NULL;
  pyobject_create_ros_message = PyCapsule_New(
    (void *)&mazebot_msgs__msg__lidar_scan_processed__create_ros_message,
    NULL, NULL);
  if (!pyobject_create_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "create_ros_message_msg__msg__lidar_scan_processed",
    pyobject_create_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_create_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_destroy_ros_message = NULL;
  pyobject_destroy_ros_message = PyCapsule_New(
    (void *)&mazebot_msgs__msg__lidar_scan_processed__destroy_ros_message,
    NULL, NULL);
  if (!pyobject_destroy_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "destroy_ros_message_msg__msg__lidar_scan_processed",
    pyobject_destroy_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_destroy_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_from_py = NULL;
  pyobject_convert_from_py = PyCapsule_New(
    (void *)&mazebot_msgs__msg__lidar_scan_processed__convert_from_py,
    NULL, NULL);
  if (!pyobject_convert_from_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_from_py_msg__msg__lidar_scan_processed",
    pyobject_convert_from_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_from_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_to_py = NULL;
  pyobject_convert_to_py = PyCapsule_New(
    (void *)&mazebot_msgs__msg__lidar_scan_processed__convert_to_py,
    NULL, NULL);
  if (!pyobject_convert_to_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_to_py_msg__msg__lidar_scan_processed",
    pyobject_convert_to_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_to_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_type_support = NULL;
  pyobject_type_support = PyCapsule_New(
    (void *)ROSIDL_GET_MSG_TYPE_SUPPORT(mazebot_msgs, msg, LidarScanProcessed),
    NULL, NULL);
  if (!pyobject_type_support) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "type_support_msg__msg__lidar_scan_processed",
    pyobject_type_support);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_type_support);
    // previously added objects will be removed when the module is destroyed
    return err;
  }
  return 0;
}

// already included above
// #include <stdbool.h>
// already included above
// #include <stdint.h>
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_runtime_c/action_type_support_struct.h"
#include "mazebot_msgs/msg/detail/mazebot_field_orientation__type_support.h"
#include "mazebot_msgs/msg/detail/mazebot_field_orientation__struct.h"
#include "mazebot_msgs/msg/detail/mazebot_field_orientation__functions.h"

static void * mazebot_msgs__msg__mazebot_field_orientation__create_ros_message(void)
{
  return mazebot_msgs__msg__MazebotFieldOrientation__create();
}

static void mazebot_msgs__msg__mazebot_field_orientation__destroy_ros_message(void * raw_ros_message)
{
  mazebot_msgs__msg__MazebotFieldOrientation * ros_message = (mazebot_msgs__msg__MazebotFieldOrientation *)raw_ros_message;
  mazebot_msgs__msg__MazebotFieldOrientation__destroy(ros_message);
}

ROSIDL_GENERATOR_C_IMPORT
bool mazebot_msgs__msg__mazebot_field_orientation__convert_from_py(PyObject * _pymsg, void * ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * mazebot_msgs__msg__mazebot_field_orientation__convert_to_py(void * raw_ros_message);


ROSIDL_GENERATOR_C_IMPORT
const rosidl_message_type_support_t *
ROSIDL_GET_MSG_TYPE_SUPPORT(mazebot_msgs, msg, MazebotFieldOrientation);

int8_t
_register_msg_type__msg__mazebot_field_orientation(PyObject * pymodule)
{
  int8_t err;

  PyObject * pyobject_create_ros_message = NULL;
  pyobject_create_ros_message = PyCapsule_New(
    (void *)&mazebot_msgs__msg__mazebot_field_orientation__create_ros_message,
    NULL, NULL);
  if (!pyobject_create_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "create_ros_message_msg__msg__mazebot_field_orientation",
    pyobject_create_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_create_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_destroy_ros_message = NULL;
  pyobject_destroy_ros_message = PyCapsule_New(
    (void *)&mazebot_msgs__msg__mazebot_field_orientation__destroy_ros_message,
    NULL, NULL);
  if (!pyobject_destroy_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "destroy_ros_message_msg__msg__mazebot_field_orientation",
    pyobject_destroy_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_destroy_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_from_py = NULL;
  pyobject_convert_from_py = PyCapsule_New(
    (void *)&mazebot_msgs__msg__mazebot_field_orientation__convert_from_py,
    NULL, NULL);
  if (!pyobject_convert_from_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_from_py_msg__msg__mazebot_field_orientation",
    pyobject_convert_from_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_from_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_to_py = NULL;
  pyobject_convert_to_py = PyCapsule_New(
    (void *)&mazebot_msgs__msg__mazebot_field_orientation__convert_to_py,
    NULL, NULL);
  if (!pyobject_convert_to_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_to_py_msg__msg__mazebot_field_orientation",
    pyobject_convert_to_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_to_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_type_support = NULL;
  pyobject_type_support = PyCapsule_New(
    (void *)ROSIDL_GET_MSG_TYPE_SUPPORT(mazebot_msgs, msg, MazebotFieldOrientation),
    NULL, NULL);
  if (!pyobject_type_support) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "type_support_msg__msg__mazebot_field_orientation",
    pyobject_type_support);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_type_support);
    // previously added objects will be removed when the module is destroyed
    return err;
  }
  return 0;
}

// already included above
// #include <stdbool.h>
// already included above
// #include <stdint.h>
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_runtime_c/action_type_support_struct.h"
#include "mazebot_msgs/msg/detail/mazebot_neighboring_fields_wall_detection__type_support.h"
#include "mazebot_msgs/msg/detail/mazebot_neighboring_fields_wall_detection__struct.h"
#include "mazebot_msgs/msg/detail/mazebot_neighboring_fields_wall_detection__functions.h"

static void * mazebot_msgs__msg__mazebot_neighboring_fields_wall_detection__create_ros_message(void)
{
  return mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__create();
}

static void mazebot_msgs__msg__mazebot_neighboring_fields_wall_detection__destroy_ros_message(void * raw_ros_message)
{
  mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection * ros_message = (mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection *)raw_ros_message;
  mazebot_msgs__msg__MazebotNeighboringFieldsWallDetection__destroy(ros_message);
}

ROSIDL_GENERATOR_C_IMPORT
bool mazebot_msgs__msg__mazebot_neighboring_fields_wall_detection__convert_from_py(PyObject * _pymsg, void * ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * mazebot_msgs__msg__mazebot_neighboring_fields_wall_detection__convert_to_py(void * raw_ros_message);


ROSIDL_GENERATOR_C_IMPORT
const rosidl_message_type_support_t *
ROSIDL_GET_MSG_TYPE_SUPPORT(mazebot_msgs, msg, MazebotNeighboringFieldsWallDetection);

int8_t
_register_msg_type__msg__mazebot_neighboring_fields_wall_detection(PyObject * pymodule)
{
  int8_t err;

  PyObject * pyobject_create_ros_message = NULL;
  pyobject_create_ros_message = PyCapsule_New(
    (void *)&mazebot_msgs__msg__mazebot_neighboring_fields_wall_detection__create_ros_message,
    NULL, NULL);
  if (!pyobject_create_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "create_ros_message_msg__msg__mazebot_neighboring_fields_wall_detection",
    pyobject_create_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_create_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_destroy_ros_message = NULL;
  pyobject_destroy_ros_message = PyCapsule_New(
    (void *)&mazebot_msgs__msg__mazebot_neighboring_fields_wall_detection__destroy_ros_message,
    NULL, NULL);
  if (!pyobject_destroy_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "destroy_ros_message_msg__msg__mazebot_neighboring_fields_wall_detection",
    pyobject_destroy_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_destroy_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_from_py = NULL;
  pyobject_convert_from_py = PyCapsule_New(
    (void *)&mazebot_msgs__msg__mazebot_neighboring_fields_wall_detection__convert_from_py,
    NULL, NULL);
  if (!pyobject_convert_from_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_from_py_msg__msg__mazebot_neighboring_fields_wall_detection",
    pyobject_convert_from_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_from_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_to_py = NULL;
  pyobject_convert_to_py = PyCapsule_New(
    (void *)&mazebot_msgs__msg__mazebot_neighboring_fields_wall_detection__convert_to_py,
    NULL, NULL);
  if (!pyobject_convert_to_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_to_py_msg__msg__mazebot_neighboring_fields_wall_detection",
    pyobject_convert_to_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_to_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_type_support = NULL;
  pyobject_type_support = PyCapsule_New(
    (void *)ROSIDL_GET_MSG_TYPE_SUPPORT(mazebot_msgs, msg, MazebotNeighboringFieldsWallDetection),
    NULL, NULL);
  if (!pyobject_type_support) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "type_support_msg__msg__mazebot_neighboring_fields_wall_detection",
    pyobject_type_support);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_type_support);
    // previously added objects will be removed when the module is destroyed
    return err;
  }
  return 0;
}

PyMODINIT_FUNC
PyInit_mazebot_msgs_s__rosidl_typesupport_c(void)
{
  PyObject * pymodule = NULL;
  pymodule = PyModule_Create(&mazebot_msgs__module);
  if (!pymodule) {
    return NULL;
  }
  int8_t err;

  err = _register_msg_type__msg__lidar_scan_processed(pymodule);
  if (err) {
    Py_XDECREF(pymodule);
    return NULL;
  }

  err = _register_msg_type__msg__mazebot_field_orientation(pymodule);
  if (err) {
    Py_XDECREF(pymodule);
    return NULL;
  }

  err = _register_msg_type__msg__mazebot_neighboring_fields_wall_detection(pymodule);
  if (err) {
    Py_XDECREF(pymodule);
    return NULL;
  }

  return pymodule;
}
