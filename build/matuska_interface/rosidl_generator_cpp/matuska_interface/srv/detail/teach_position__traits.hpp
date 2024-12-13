// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from matuska_interface:srv/TeachPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "matuska_interface/srv/teach_position.hpp"


#ifndef MATUSKA_INTERFACE__SRV__DETAIL__TEACH_POSITION__TRAITS_HPP_
#define MATUSKA_INTERFACE__SRV__DETAIL__TEACH_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "matuska_interface/srv/detail/teach_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace matuska_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const TeachPosition_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: velocity
  {
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TeachPosition_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TeachPosition_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace matuska_interface

namespace rosidl_generator_traits
{

[[deprecated("use matuska_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const matuska_interface::srv::TeachPosition_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  matuska_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use matuska_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const matuska_interface::srv::TeachPosition_Request & msg)
{
  return matuska_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<matuska_interface::srv::TeachPosition_Request>()
{
  return "matuska_interface::srv::TeachPosition_Request";
}

template<>
inline const char * name<matuska_interface::srv::TeachPosition_Request>()
{
  return "matuska_interface/srv/TeachPosition_Request";
}

template<>
struct has_fixed_size<matuska_interface::srv::TeachPosition_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<matuska_interface::srv::TeachPosition_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<matuska_interface::srv::TeachPosition_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace matuska_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const TeachPosition_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TeachPosition_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TeachPosition_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace matuska_interface

namespace rosidl_generator_traits
{

[[deprecated("use matuska_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const matuska_interface::srv::TeachPosition_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  matuska_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use matuska_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const matuska_interface::srv::TeachPosition_Response & msg)
{
  return matuska_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<matuska_interface::srv::TeachPosition_Response>()
{
  return "matuska_interface::srv::TeachPosition_Response";
}

template<>
inline const char * name<matuska_interface::srv::TeachPosition_Response>()
{
  return "matuska_interface/srv/TeachPosition_Response";
}

template<>
struct has_fixed_size<matuska_interface::srv::TeachPosition_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<matuska_interface::srv::TeachPosition_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<matuska_interface::srv::TeachPosition_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace matuska_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const TeachPosition_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TeachPosition_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TeachPosition_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace matuska_interface

namespace rosidl_generator_traits
{

[[deprecated("use matuska_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const matuska_interface::srv::TeachPosition_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  matuska_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use matuska_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const matuska_interface::srv::TeachPosition_Event & msg)
{
  return matuska_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<matuska_interface::srv::TeachPosition_Event>()
{
  return "matuska_interface::srv::TeachPosition_Event";
}

template<>
inline const char * name<matuska_interface::srv::TeachPosition_Event>()
{
  return "matuska_interface/srv/TeachPosition_Event";
}

template<>
struct has_fixed_size<matuska_interface::srv::TeachPosition_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<matuska_interface::srv::TeachPosition_Event>
  : std::integral_constant<bool, has_bounded_size<matuska_interface::srv::TeachPosition_Request>::value && has_bounded_size<matuska_interface::srv::TeachPosition_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<matuska_interface::srv::TeachPosition_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<matuska_interface::srv::TeachPosition>()
{
  return "matuska_interface::srv::TeachPosition";
}

template<>
inline const char * name<matuska_interface::srv::TeachPosition>()
{
  return "matuska_interface/srv/TeachPosition";
}

template<>
struct has_fixed_size<matuska_interface::srv::TeachPosition>
  : std::integral_constant<
    bool,
    has_fixed_size<matuska_interface::srv::TeachPosition_Request>::value &&
    has_fixed_size<matuska_interface::srv::TeachPosition_Response>::value
  >
{
};

template<>
struct has_bounded_size<matuska_interface::srv::TeachPosition>
  : std::integral_constant<
    bool,
    has_bounded_size<matuska_interface::srv::TeachPosition_Request>::value &&
    has_bounded_size<matuska_interface::srv::TeachPosition_Response>::value
  >
{
};

template<>
struct is_service<matuska_interface::srv::TeachPosition>
  : std::true_type
{
};

template<>
struct is_service_request<matuska_interface::srv::TeachPosition_Request>
  : std::true_type
{
};

template<>
struct is_service_response<matuska_interface::srv::TeachPosition_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MATUSKA_INTERFACE__SRV__DETAIL__TEACH_POSITION__TRAITS_HPP_
