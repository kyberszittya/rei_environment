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

#ifndef REI_NODE_LIBRARY__REI_NODE_EXCEPTIONS_HPP_
#define REI_NODE_LIBRARY__REI_NODE_EXCEPTIONS_HPP_

#include <exception>

/// REGION: node initialization exception definitions

namespace rei
{

namespace node
{

class ExceptionPreInitialization : public std::exception
{
  const char * what() const throw();
};

class ExceptionBehaviorModelInitialization : public std::exception
{
  const char * what() const throw();
};

class ExceptionBehaviorActionAssignment : public std::exception
{
  const char * what() const throw();
};

class ExceptionSysGuardInitialization : public std::exception
{
  const char * what() const throw();
};

class ExceptionMiddlewareInitialization : public std::exception
{
  const char * what() const throw();
};

class ExceptionPostInitialization : public std::exception
{
  const char * what() const throw();
};

}  // namespace node

}  // namespace rei

/// ENDREGION: node initialization exception definitions

#endif  // REI_NODE_LIBRARY__REI_NODE_EXCEPTIONS_HPP_
