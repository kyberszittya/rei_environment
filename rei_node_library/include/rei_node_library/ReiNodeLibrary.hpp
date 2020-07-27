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

#ifndef REI_NODE_LIBRARY__REINODELIBRARY_HPP_
#define REI_NODE_LIBRARY__REINODELIBRARY_HPP_

#include "rei_node_library/visibility_control.h"
#include "rei_node_exceptions.hpp"

namespace rei   // namespace rei
{

namespace node  // namespace node
{

// TODO(kyberszittya): we shall be cool with hybrid automatas wouldn't we?
// Let's make that library right away
enum class NodeControlMode
{
  INITIALIZING,
  BEHAVIOR_ON,
  BEHAVIOR_BYPASSED,
  WAITING,
  ERROR
};

class InterfaceBehaviorNode
{
private:
  NodeControlMode control_mode;

public:
  InterfaceBehaviorNode();

  virtual ~InterfaceBehaviorNode() = 0;


  /**
   * DESCRIPTION:
   * Initialize node and attach to middleware in descendant methods.
   * */
  void initialization(const bool debug, const bool enable_behavior);
  /**
   * REGION: Abstract initialization functions
   * */
  /**
   * Abstract method
   * DESCRIPTION:
   * Initialization steps before the middleware initialization.
   * RETURNS: initialization success (TRUE/FLASE)
   * */
  virtual bool initPre() = 0;
  /**
   * Abstract method
   * DESCRIPTION:
   * Initialization of the behavior model based on the input specification or in a non-volatile case on a generated specific behavior.
   * RETURNS: initialization success (TRUE/FALSE)
   * */
  virtual bool initBehaviorModel() = 0;
  /**
   * Abstract method
   * DESCRIPTION:
   * Assignment of behavior actions related to the underlying behavior.
   * RETURNS: initialization success (TRUE/FALSE)
   * */
  virtual bool assignBehaviorActions() = 0;
  /**
   * Abstract method
   * DESCRIPTION:
   * Initialization of system and behavior guards.
   * RETURNS: initialization success (TRUE/FALSE)
   * */
  virtual bool initSysGuards() = 0;
  /**
   * Abstract method
   * DESCRIPTION:
   * Initialization of middleware of choice. Presumably generated based on a network model.
   * RETURNS: initialization success (TRUE/FALSE)
   * */
  virtual bool initMiddleware(const bool debug, const bool enable_behavior) = 0;
  /**
   * Abstract method
   * DESCRIPTION:
   * Initialization class after middleware initialization.
   * RETURNS: initialization success (TRUE/FALSE)
   * */
  virtual bool initPost() = 0;
  /**
   * ENDREGION: Abstract initialization functions
   * */
};

}  // namespace node

}  // namespace rei

namespace rei_node_library  // namespace rei_node_library
{

class Reinodelibrary
{
public:
  Reinodelibrary();

  virtual ~Reinodelibrary();
};

}  // namespace rei_node_library

#endif  // REI_NODE_LIBRARY__REINODELIBRARY_HPP_
