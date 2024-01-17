////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/mpu6000_state.cpp                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/mpu6000_state.h"
using autogen::timestamped::mpu6000_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

mpu6000_state::mpu6000_state(autogen::topic::mpu6000_state::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::mpu6000_state() {
  // No-op.
}
mpu6000_state::mpu6000_state(autogen::topic::mpu6000_state::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::mpu6000_state(s) {
  // No-op.
}
mpu6000_state::~mpu6000_state() {
  // No-op.
}
mpu6000_state::topic_t mpu6000_state::topic_index() const {
  return mc_topic;
}
string mpu6000_state::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
mpu6000_state::ts_t& mpu6000_state::timestamp() {
  return m_timestamp;
}
const mpu6000_state::ts_t& mpu6000_state::timestamp() const {
  return m_timestamp;
}
void mpu6000_state::clear() {
  m_timestamp = 0;
  clear_content();
}
string mpu6000_state::print() const {
  std::ostringstream ss;

  ss << type_label() << ","
     << topic_label() << ","
     << std::setbase(10)
     << std::fixed
     << std::noshowpos
     << std::setprecision(0)
     << std::setfill('0')
     << std::setw(12)
     << timestamp() << ","
     << print_content();
  return ss.str();
}
mpu6000_state& mpu6000_state::operator=(const autogen::state::mpu6000_state& rhs) {
  autogen::state::mpu6000_state::operator=(rhs);
  return *this;
}
mpu6000_state& mpu6000_state::operator=(const mpu6000_state& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::mpu6000_state::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
