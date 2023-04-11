// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from mazebot_msgs:msg/MazebotFieldOrientation.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "mazebot_msgs/msg/detail/mazebot_field_orientation__struct.h"
#include "mazebot_msgs/msg/detail/mazebot_field_orientation__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__laser_scan__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__laser_scan__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool mazebot_msgs__msg__mazebot_field_orientation__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[68];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("mazebot_msgs.msg._mazebot_field_orientation.MazebotFieldOrientation", full_classname_dest, 67) == 0);
  }
  mazebot_msgs__msg__MazebotFieldOrientation * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // laser_scan
    PyObject * field = PyObject_GetAttrString(_pymsg, "laser_scan");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__laser_scan__convert_from_py(field, &ros_message->laser_scan)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // front_distance
    PyObject * field = PyObject_GetAttrString(_pymsg, "front_distance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->front_distance = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rear_distance
    PyObject * field = PyObject_GetAttrString(_pymsg, "rear_distance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rear_distance = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // left_distance
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_distance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left_distance = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // right_distance
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_distance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->right_distance = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // front_angle_deg
    PyObject * field = PyObject_GetAttrString(_pymsg, "front_angle_deg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->front_angle_deg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rear_angle_deg
    PyObject * field = PyObject_GetAttrString(_pymsg, "rear_angle_deg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rear_angle_deg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // left_angle_deg
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_angle_deg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left_angle_deg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // right_angle_deg
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_angle_deg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->right_angle_deg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * mazebot_msgs__msg__mazebot_field_orientation__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MazebotFieldOrientation */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("mazebot_msgs.msg._mazebot_field_orientation");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MazebotFieldOrientation");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  mazebot_msgs__msg__MazebotFieldOrientation * ros_message = (mazebot_msgs__msg__MazebotFieldOrientation *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // laser_scan
    PyObject * field = NULL;
    field = sensor_msgs__msg__laser_scan__convert_to_py(&ros_message->laser_scan);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "laser_scan", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // front_distance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->front_distance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "front_distance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rear_distance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rear_distance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rear_distance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_distance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left_distance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_distance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_distance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->right_distance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_distance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // front_angle_deg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->front_angle_deg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "front_angle_deg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rear_angle_deg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rear_angle_deg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rear_angle_deg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_angle_deg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left_angle_deg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_angle_deg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_angle_deg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->right_angle_deg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_angle_deg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
