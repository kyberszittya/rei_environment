// Copyright 2020 Hajdu Csaba
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

#include <rei_node_library/ReiNodeLibrary.hpp>

namespace rei
{

namespace node
{

/**
 * Method implementation
 * CLASS: InterfaceBehaviorNode
 * */

InterfaceBehaviorNode::InterfaceBehaviorNode()
:  control_mode(NodeControlMode::INITIALIZING)
{}

// Abstract class, define virtual destructor
InterfaceBehaviorNode::~InterfaceBehaviorNode()
{}

void InterfaceBehaviorNode::initialization(const bool debug, const bool enable_behavior)
{
  if (!initPre()) {
    throw ExceptionPreInitialization();
  }
  if (enable_behavior) {
    if (!initBehaviorModel()) {
      throw ExceptionBehaviorModelInitialization();
    }
    if (!assignBehaviorActions()) {
      throw ExceptionBehaviorActionAssignment();
    }
    if (!initSysGuards()) {
      throw ExceptionSysGuardInitialization();
    }
    control_mode = NodeControlMode::BEHAVIOR_ON;
  } else {
    control_mode = NodeControlMode::BEHAVIOR_BYPASSED;
  }
  if (!initMiddleware(debug, enable_behavior)) {
    throw ExceptionMiddlewareInitialization();
  }
  if (!initPost()) {
    throw ExceptionPostInitialization();
  }
}

/**
 * END of method implementation CLASS: InterfaceBehaviorNode
 * */


}  // namespace node

}  // namespace rei
