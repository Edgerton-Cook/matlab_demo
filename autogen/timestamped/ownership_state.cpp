////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/ownership_state.cpp                                               //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/ownership_state.h"
using autogen::timestamped::ownership_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

ownership_state::ownership_state(autogen::topic::ownership_state::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::ownership_state() {
  // No-op.
}
ownership_state::ownership_state(autogen::topic::ownership_state::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::ownership_state(s) {
  // No-op.
}
ownership_state::~ownership_state() {
  // No-op.
}
ownership_state::topic_t ownership_state::topic_index() const {
  return mc_topic;
}
string ownership_state::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
ownership_state::ts_t& ownership_state::timestamp() {
  return m_timestamp;
}
const ownership_state::ts_t& ownership_state::timestamp() const {
  return m_timestamp;
}
void ownership_state::clear() {
  m_timestamp = 0;
  clear_content();
}
string ownership_state::print() const {
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
ownership_state& ownership_state::operator=(const autogen::state::ownership_state& rhs) {
  autogen::state::ownership_state::operator=(rhs);
  return *this;
}
ownership_state& ownership_state::operator=(const ownership_state& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::ownership_state::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
