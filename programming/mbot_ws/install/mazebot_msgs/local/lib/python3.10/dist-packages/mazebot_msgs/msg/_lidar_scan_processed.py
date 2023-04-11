# generated from rosidl_generator_py/resource/_idl.py.em
# with input from mazebot_msgs:msg/LidarScanProcessed.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LidarScanProcessed(type):
    """Metaclass of message 'LidarScanProcessed'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mazebot_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mazebot_msgs.msg.LidarScanProcessed')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__lidar_scan_processed
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__lidar_scan_processed
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__lidar_scan_processed
            cls._TYPE_SUPPORT = module.type_support_msg__msg__lidar_scan_processed
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__lidar_scan_processed

            from sensor_msgs.msg import LaserScan
            if LaserScan.__class__._TYPE_SUPPORT is None:
                LaserScan.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LidarScanProcessed(metaclass=Metaclass_LidarScanProcessed):
    """Message class 'LidarScanProcessed'."""

    __slots__ = [
        '_header',
        '_laser_scan',
        '_front_distance',
        '_rear_distance',
        '_left_distance',
        '_right_distance',
        '_left_angle_deg',
        '_right_angle_deg',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'laser_scan': 'sensor_msgs/LaserScan',
        'front_distance': 'float',
        'rear_distance': 'float',
        'left_distance': 'float',
        'right_distance': 'float',
        'left_angle_deg': 'float',
        'right_angle_deg': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'LaserScan'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from sensor_msgs.msg import LaserScan
        self.laser_scan = kwargs.get('laser_scan', LaserScan())
        self.front_distance = kwargs.get('front_distance', float())
        self.rear_distance = kwargs.get('rear_distance', float())
        self.left_distance = kwargs.get('left_distance', float())
        self.right_distance = kwargs.get('right_distance', float())
        self.left_angle_deg = kwargs.get('left_angle_deg', float())
        self.right_angle_deg = kwargs.get('right_angle_deg', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.laser_scan != other.laser_scan:
            return False
        if self.front_distance != other.front_distance:
            return False
        if self.rear_distance != other.rear_distance:
            return False
        if self.left_distance != other.left_distance:
            return False
        if self.right_distance != other.right_distance:
            return False
        if self.left_angle_deg != other.left_angle_deg:
            return False
        if self.right_angle_deg != other.right_angle_deg:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def laser_scan(self):
        """Message field 'laser_scan'."""
        return self._laser_scan

    @laser_scan.setter
    def laser_scan(self, value):
        if __debug__:
            from sensor_msgs.msg import LaserScan
            assert \
                isinstance(value, LaserScan), \
                "The 'laser_scan' field must be a sub message of type 'LaserScan'"
        self._laser_scan = value

    @builtins.property
    def front_distance(self):
        """Message field 'front_distance'."""
        return self._front_distance

    @front_distance.setter
    def front_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'front_distance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'front_distance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._front_distance = value

    @builtins.property
    def rear_distance(self):
        """Message field 'rear_distance'."""
        return self._rear_distance

    @rear_distance.setter
    def rear_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rear_distance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'rear_distance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._rear_distance = value

    @builtins.property
    def left_distance(self):
        """Message field 'left_distance'."""
        return self._left_distance

    @left_distance.setter
    def left_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'left_distance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'left_distance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._left_distance = value

    @builtins.property
    def right_distance(self):
        """Message field 'right_distance'."""
        return self._right_distance

    @right_distance.setter
    def right_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'right_distance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'right_distance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._right_distance = value

    @builtins.property
    def left_angle_deg(self):
        """Message field 'left_angle_deg'."""
        return self._left_angle_deg

    @left_angle_deg.setter
    def left_angle_deg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'left_angle_deg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'left_angle_deg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._left_angle_deg = value

    @builtins.property
    def right_angle_deg(self):
        """Message field 'right_angle_deg'."""
        return self._right_angle_deg

    @right_angle_deg.setter
    def right_angle_deg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'right_angle_deg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'right_angle_deg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._right_angle_deg = value
