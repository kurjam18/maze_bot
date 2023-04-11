# generated from rosidl_generator_py/resource/_idl.py.em
# with input from mazebot_msgs:msg/MazebotNeighboringFieldsWallDetection.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'front'
# Member 'rear'
# Member 'left'
# Member 'right'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MazebotNeighboringFieldsWallDetection(type):
    """Metaclass of message 'MazebotNeighboringFieldsWallDetection'."""

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
                'mazebot_msgs.msg.MazebotNeighboringFieldsWallDetection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__mazebot_neighboring_fields_wall_detection
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__mazebot_neighboring_fields_wall_detection
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__mazebot_neighboring_fields_wall_detection
            cls._TYPE_SUPPORT = module.type_support_msg__msg__mazebot_neighboring_fields_wall_detection
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__mazebot_neighboring_fields_wall_detection

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


class MazebotNeighboringFieldsWallDetection(metaclass=Metaclass_MazebotNeighboringFieldsWallDetection):
    """Message class 'MazebotNeighboringFieldsWallDetection'."""

    __slots__ = [
        '_header',
        '_front',
        '_rear',
        '_left',
        '_right',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'front': 'int8[4]',
        'rear': 'int8[4]',
        'left': 'int8[4]',
        'right': 'int8[4]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int8'), 4),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int8'), 4),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int8'), 4),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('int8'), 4),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        if 'front' not in kwargs:
            self.front = numpy.zeros(4, dtype=numpy.int8)
        else:
            self.front = numpy.array(kwargs.get('front'), dtype=numpy.int8)
            assert self.front.shape == (4, )
        if 'rear' not in kwargs:
            self.rear = numpy.zeros(4, dtype=numpy.int8)
        else:
            self.rear = numpy.array(kwargs.get('rear'), dtype=numpy.int8)
            assert self.rear.shape == (4, )
        if 'left' not in kwargs:
            self.left = numpy.zeros(4, dtype=numpy.int8)
        else:
            self.left = numpy.array(kwargs.get('left'), dtype=numpy.int8)
            assert self.left.shape == (4, )
        if 'right' not in kwargs:
            self.right = numpy.zeros(4, dtype=numpy.int8)
        else:
            self.right = numpy.array(kwargs.get('right'), dtype=numpy.int8)
            assert self.right.shape == (4, )

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
        if all(self.front != other.front):
            return False
        if all(self.rear != other.rear):
            return False
        if all(self.left != other.left):
            return False
        if all(self.right != other.right):
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
    def front(self):
        """Message field 'front'."""
        return self._front

    @front.setter
    def front(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int8, \
                "The 'front' numpy.ndarray() must have the dtype of 'numpy.int8'"
            assert value.size == 4, \
                "The 'front' numpy.ndarray() must have a size of 4"
            self._front = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'front' field must be a set or sequence with length 4 and each value of type 'int' and each integer in [-128, 127]"
        self._front = numpy.array(value, dtype=numpy.int8)

    @builtins.property
    def rear(self):
        """Message field 'rear'."""
        return self._rear

    @rear.setter
    def rear(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int8, \
                "The 'rear' numpy.ndarray() must have the dtype of 'numpy.int8'"
            assert value.size == 4, \
                "The 'rear' numpy.ndarray() must have a size of 4"
            self._rear = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'rear' field must be a set or sequence with length 4 and each value of type 'int' and each integer in [-128, 127]"
        self._rear = numpy.array(value, dtype=numpy.int8)

    @builtins.property
    def left(self):
        """Message field 'left'."""
        return self._left

    @left.setter
    def left(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int8, \
                "The 'left' numpy.ndarray() must have the dtype of 'numpy.int8'"
            assert value.size == 4, \
                "The 'left' numpy.ndarray() must have a size of 4"
            self._left = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'left' field must be a set or sequence with length 4 and each value of type 'int' and each integer in [-128, 127]"
        self._left = numpy.array(value, dtype=numpy.int8)

    @builtins.property
    def right(self):
        """Message field 'right'."""
        return self._right

    @right.setter
    def right(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.int8, \
                "The 'right' numpy.ndarray() must have the dtype of 'numpy.int8'"
            assert value.size == 4, \
                "The 'right' numpy.ndarray() must have a size of 4"
            self._right = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'right' field must be a set or sequence with length 4 and each value of type 'int' and each integer in [-128, 127]"
        self._right = numpy.array(value, dtype=numpy.int8)
