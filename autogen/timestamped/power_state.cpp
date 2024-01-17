////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/power_state.cpp                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/power_state.h"
using autogen::timestamped::power_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

power_state::power_state(autogen::topic::power_state::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::power_state() {
  // No-op.
}
power_state::power_state(autogen::topic::power_state::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::power_state(s) {
  // No-op.
}
power_state::~power_state() {
  // No-op.
}
power_state::topic_t power_state::topic_index() const {
  return mc_topic;
}
string power_state::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
power_state::ts_t& power_state::timestamp() {
  return m_timestamp;
}
const power_state::ts_t& power_state::timestamp() const {
  return m_timestamp;
}
void power_state::clear() {
  m_timestamp = 0;
  clear_content();
}
string power_state::print() const {
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
power_state& power_state::operator=(const autogen::state::power_state& rhs) {
  autogen::state::power_state::operator=(rhs);
  return *this;
}
power_state& power_state::operator=(const power_state& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::power_state::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
