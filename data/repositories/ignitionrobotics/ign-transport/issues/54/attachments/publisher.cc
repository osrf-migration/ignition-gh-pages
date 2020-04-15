/*
 * Copyright (C) 2014 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include <atomic>
#include <chrono>
#include <csignal>
#include <iostream>
#include <string>
#include <thread>
#include <ignition/msgs.hh>
#include <ignition/transport.hh>

//////////////////////////////////////////////////
int main(int argc, char **argv)
{
  // Create a transport node and advertise a topic.
  ignition::transport::Node node;
  std::string topic = "/foo";

  auto pubId = node.Advertise<ignition::msgs::StringMsg>(topic);
  auto pubId1 = node.Advertise<ignition::msgs::Int32>(topic);
  if (!pubId)
  {
    std::cerr << "Error advertising topic [" << topic << "]" << std::endl;
    return -1;
  }

  if (!pubId1)
  {
    std::cerr << "Error advertising topic [" << topic << "]" << std::endl;
    return -1;
  }

  // Prepare the message.
  ignition::msgs::StringMsg msg;
  ignition::msgs::Int32 msg1;
  msg.set_data("HELLO");
  msg1.set_data(12);

  node.Publish(pubId, msg);
  node.Publish(pubId1, msg1);

  return 0;
}
