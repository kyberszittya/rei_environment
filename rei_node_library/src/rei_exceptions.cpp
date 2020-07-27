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

#include <rei_node_library/rei_node_exceptions.hpp>

namespace rei
{
namespace node
{
/// REGION: exception return messages
const char * ExceptionPreInitialization::what() const throw()
{
  return "Pre-middleware initialization failed";
}

const char * ExceptionBehaviorModelInitialization::what() const throw()
{
  return "Behavior model initialization failed";
}

const char * ExceptionBehaviorActionAssignment::what() const throw()
{
  return "Behavior action assignments failed";
}

const char * ExceptionSysGuardInitialization::what() const throw()
{
  return "System guard initialization failed";
}

const char * ExceptionMiddlewareInitialization::what() const throw()
{
  return "Middleware initialization failed";
}

const char * ExceptionPostInitialization::what() const throw()
{
  return "Post-middleware initialization failed";
}
/// ENDREGION: exception return messages

}   // namespace node

}   // namespace rei
