// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef RCLCPP__NODE_INTERFACES__NODE_CLOCK_HPP_
#define RCLCPP__NODE_INTERFACES__NODE_CLOCK_HPP_

#include "rclcpp/callback_group.hpp"
#include "rclcpp/clock.hpp"
#include "rclcpp/macros.hpp"
#include "rclcpp/node_interfaces/node_base_interface.hpp"
#include "rclcpp/node_interfaces/node_clock_interface.hpp"
#include "rclcpp/node_interfaces/node_parameters_interface.hpp"
#include "rclcpp/node_interfaces/node_topics_interface.hpp"
#include "rclcpp/time_source.hpp"
#include "rclcpp/visibility_control.hpp"

namespace rclcpp
{
namespace node_interfaces
{

/// Implementation of the NodeClock part of the Node API.
class NodeClock : public NodeClockInterface
{
public:
  RCLCPP_SMART_PTR_ALIASES_ONLY(NodeClock)

  RCLCPP_PUBLIC
  explicit NodeClock(
    rclcpp::node_interfaces::NodeBaseInterface * node_base,
    rclcpp::node_interfaces::NodeTopicsInterface * node_topics,
    rclcpp::node_interfaces::NodeParametersInterface * node_parameters);

  RCLCPP_PUBLIC
  virtual
  ~NodeClock();

  /// Get a clock which will be kept up to date by the node..
  RCLCPP_PUBLIC
  virtual
  rclcpp::Clock::SharedPtr
  get_clock(rcl_clock_type_t clock_type = RCL_ROS_TIME);

private:
  RCLCPP_DISABLE_COPY(NodeClock)

  rclcpp::node_interfaces::NodeBaseInterface * node_base_;
  rclcpp::node_interfaces::NodeTopicsInterface * node_topics_;
  rclcpp::node_interfaces::NodeParametersInterface * node_parameters_;

  
  
  rclcpp::Clock::SharedPtr ros_clock_;
  rclcpp::Clock::SharedPtr system_clock_;
  rclcpp::Clock::SharedPtr steady_clock_;
  
  rclcpp::TimeSource time_source_;
  
};

}  // namespace node_interfaces
}  // namespace rclcpp

#endif  // RCLCPP__NODE_INTERFACES__NODE_CLOCK_HPP_
