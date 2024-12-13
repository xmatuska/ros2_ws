// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from matuska_interface:srv/TeachPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "matuska_interface/srv/teach_position.hpp"


#ifndef MATUSKA_INTERFACE__SRV__DETAIL__TEACH_POSITION__BUILDER_HPP_
#define MATUSKA_INTERFACE__SRV__DETAIL__TEACH_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "matuska_interface/srv/detail/teach_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace matuska_interface
{

namespace srv
{

namespace builder
{

class Init_TeachPosition_Request_velocity
{
public:
  Init_TeachPosition_Request_velocity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::matuska_interface::srv::TeachPosition_Request velocity(::matuska_interface::srv::TeachPosition_Request::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::matuska_interface::srv::TeachPosition_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::matuska_interface::srv::TeachPosition_Request>()
{
  return matuska_interface::srv::builder::Init_TeachPosition_Request_velocity();
}

}  // namespace matuska_interface


namespace matuska_interface
{

namespace srv
{

namespace builder
{

class Init_TeachPosition_Response_message
{
public:
  explicit Init_TeachPosition_Response_message(::matuska_interface::srv::TeachPosition_Response & msg)
  : msg_(msg)
  {}
  ::matuska_interface::srv::TeachPosition_Response message(::matuska_interface::srv::TeachPosition_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::matuska_interface::srv::TeachPosition_Response msg_;
};

class Init_TeachPosition_Response_result
{
public:
  Init_TeachPosition_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TeachPosition_Response_message result(::matuska_interface::srv::TeachPosition_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return Init_TeachPosition_Response_message(msg_);
  }

private:
  ::matuska_interface::srv::TeachPosition_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::matuska_interface::srv::TeachPosition_Response>()
{
  return matuska_interface::srv::builder::Init_TeachPosition_Response_result();
}

}  // namespace matuska_interface


namespace matuska_interface
{

namespace srv
{

namespace builder
{

class Init_TeachPosition_Event_response
{
public:
  explicit Init_TeachPosition_Event_response(::matuska_interface::srv::TeachPosition_Event & msg)
  : msg_(msg)
  {}
  ::matuska_interface::srv::TeachPosition_Event response(::matuska_interface::srv::TeachPosition_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::matuska_interface::srv::TeachPosition_Event msg_;
};

class Init_TeachPosition_Event_request
{
public:
  explicit Init_TeachPosition_Event_request(::matuska_interface::srv::TeachPosition_Event & msg)
  : msg_(msg)
  {}
  Init_TeachPosition_Event_response request(::matuska_interface::srv::TeachPosition_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_TeachPosition_Event_response(msg_);
  }

private:
  ::matuska_interface::srv::TeachPosition_Event msg_;
};

class Init_TeachPosition_Event_info
{
public:
  Init_TeachPosition_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TeachPosition_Event_request info(::matuska_interface::srv::TeachPosition_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_TeachPosition_Event_request(msg_);
  }

private:
  ::matuska_interface::srv::TeachPosition_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::matuska_interface::srv::TeachPosition_Event>()
{
  return matuska_interface::srv::builder::Init_TeachPosition_Event_info();
}

}  // namespace matuska_interface

#endif  // MATUSKA_INTERFACE__SRV__DETAIL__TEACH_POSITION__BUILDER_HPP_
