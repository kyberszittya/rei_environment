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

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <rei_node_library/ReiNodeLibrary.hpp>

using ::testing::Return;

class MockReiNode : public rei::node::InterfaceBehaviorNode
{
public:
  MOCK_METHOD(bool, initPre, (), (override));
  MOCK_METHOD(bool, initBehaviorModel, (), (override));
  MOCK_METHOD(bool, assignBehaviorActions, (), (override));
  MOCK_METHOD(bool, initSysGuards, (), (override));
  MOCK_METHOD(bool, initMiddleware, (bool, bool), (override));
  MOCK_METHOD(bool, initPost, (), (override));
};


TEST(TestBasicInteraction, TestValidInteractions)
{
  MockReiNode rei_node;
  // Set return values of functions
  ON_CALL(rei_node, initPre).WillByDefault(Return(true));
  ON_CALL(rei_node, initBehaviorModel).WillByDefault(Return(true));
  ON_CALL(rei_node, assignBehaviorActions).WillByDefault(Return(true));
  ON_CALL(rei_node, initSysGuards).WillByDefault(Return(true));
  ON_CALL(rei_node, initMiddleware).WillByDefault(Return(true));
  ON_CALL(rei_node, initPost).WillByDefault(Return(true));
  // Except call
  EXPECT_CALL(rei_node, initPre).Times(2);
  EXPECT_CALL(rei_node, initBehaviorModel).Times(2);
  EXPECT_CALL(rei_node, assignBehaviorActions).Times(2);
  EXPECT_CALL(rei_node, initSysGuards).Times(2);
  EXPECT_CALL(rei_node, initMiddleware).Times(2);
  EXPECT_CALL(rei_node, initPost).Times(2);
  rei_node.initialization(true, true);
  rei_node.initialization(false, true);
}

TEST(TestBasicInteraction, TestBypassBehavior)
{
  MockReiNode rei_node;
  // Set return values of functions
  ON_CALL(rei_node, initPre).WillByDefault(Return(true));
  ON_CALL(rei_node, initBehaviorModel).WillByDefault(Return(true));
  ON_CALL(rei_node, assignBehaviorActions).WillByDefault(Return(true));
  ON_CALL(rei_node, initSysGuards).WillByDefault(Return(true));
  ON_CALL(rei_node, initMiddleware).WillByDefault(Return(true));
  ON_CALL(rei_node, initPost).WillByDefault(Return(true));
  // Except call
  EXPECT_CALL(rei_node, initPre).Times(2);
  EXPECT_CALL(rei_node, initBehaviorModel).Times(0);
  EXPECT_CALL(rei_node, assignBehaviorActions).Times(0);
  EXPECT_CALL(rei_node, initSysGuards).Times(0);
  EXPECT_CALL(rei_node, initMiddleware).Times(2);
  EXPECT_CALL(rei_node, initPost).Times(2);
  rei_node.initialization(true, false);
  rei_node.initialization(false, false);
}
