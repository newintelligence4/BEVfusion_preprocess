# generated from rosidl_generator_py/resource/_idl.py.em
# with input from c_auto_vehicle_msgs:msg/VelocityReport.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VelocityReport(type):
    """Metaclass of message 'VelocityReport'."""

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
            module = import_type_support('c_auto_vehicle_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'c_auto_vehicle_msgs.msg.VelocityReport')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__velocity_report
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__velocity_report
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__velocity_report
            cls._TYPE_SUPPORT = module.type_support_msg__msg__velocity_report
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__velocity_report

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'LONGITUDINAL_VELOCITY__DEFAULT': 0.0,
            'LATERAL_VELOCITY__DEFAULT': 0.0,
            'HEADING_RATE__DEFAULT': 0.0,
        }

    @property
    def LONGITUDINAL_VELOCITY__DEFAULT(cls):
        """Return default value for message field 'longitudinal_velocity'."""
        return 0.0

    @property
    def LATERAL_VELOCITY__DEFAULT(cls):
        """Return default value for message field 'lateral_velocity'."""
        return 0.0

    @property
    def HEADING_RATE__DEFAULT(cls):
        """Return default value for message field 'heading_rate'."""
        return 0.0


class VelocityReport(metaclass=Metaclass_VelocityReport):
    """Message class 'VelocityReport'."""

    __slots__ = [
        '_header',
        '_longitudinal_velocity',
        '_lateral_velocity',
        '_heading_rate',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'longitudinal_velocity': 'float',
        'lateral_velocity': 'float',
        'heading_rate': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
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
        self.longitudinal_velocity = kwargs.get(
            'longitudinal_velocity', VelocityReport.LONGITUDINAL_VELOCITY__DEFAULT)
        self.lateral_velocity = kwargs.get(
            'lateral_velocity', VelocityReport.LATERAL_VELOCITY__DEFAULT)
        self.heading_rate = kwargs.get(
            'heading_rate', VelocityReport.HEADING_RATE__DEFAULT)

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
        if self.longitudinal_velocity != other.longitudinal_velocity:
            return False
        if self.lateral_velocity != other.lateral_velocity:
            return False
        if self.heading_rate != other.heading_rate:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
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

    @property
    def longitudinal_velocity(self):
        """Message field 'longitudinal_velocity'."""
        return self._longitudinal_velocity

    @longitudinal_velocity.setter
    def longitudinal_velocity(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'longitudinal_velocity' field must be of type 'float'"
        self._longitudinal_velocity = value

    @property
    def lateral_velocity(self):
        """Message field 'lateral_velocity'."""
        return self._lateral_velocity

    @lateral_velocity.setter
    def lateral_velocity(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lateral_velocity' field must be of type 'float'"
        self._lateral_velocity = value

    @property
    def heading_rate(self):
        """Message field 'heading_rate'."""
        return self._heading_rate

    @heading_rate.setter
    def heading_rate(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'heading_rate' field must be of type 'float'"
        self._heading_rate = value
