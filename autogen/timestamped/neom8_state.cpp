////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/neom8_state.cpp                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/neom8_state.h"
using autogen::timestamped::neom8_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

neom8_state::neom8_state(autogen::topic::neom8_state::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::neom8_state() {
  // No-op.
}
neom8_state::neom8_state(autogen::topic::neom8_state::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::neom8_state(s) {
  // No-op.
}
neom8_state::~neom8_state() {
  // No-op.
}
neom8_state::topic_t neom8_state::topic_index() const {
  return mc_topic;
}
string neom8_state::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
neom8_state::ts_t& neom8_state::timestamp() {
  return m_timestamp;
}
const neom8_state::ts_t& neom8_state::timestamp() const {
  return m_timestamp;
}
void neom8_state::clear() {
  m_timestamp = 0;
  clear_content();
}
string neom8_state::print() const {
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
neom8_state& neom8_state::operator=(const autogen::state::neom8_state& rhs) {
  autogen::state::neom8_state::operator=(rhs);
  return *this;
}
neom8_state& neom8_state::operator=(const neom8_state& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::neom8_state::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
