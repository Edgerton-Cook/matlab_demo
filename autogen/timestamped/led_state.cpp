////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/led_state.cpp                                                     //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/led_state.h"
using autogen::timestamped::led_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

led_state::led_state(autogen::topic::led_state::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::led_state() {
  // No-op.
}
led_state::led_state(autogen::topic::led_state::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::led_state(s) {
  // No-op.
}
led_state::~led_state() {
  // No-op.
}
led_state::topic_t led_state::topic_index() const {
  return mc_topic;
}
string led_state::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
led_state::ts_t& led_state::timestamp() {
  return m_timestamp;
}
const led_state::ts_t& led_state::timestamp() const {
  return m_timestamp;
}
void led_state::clear() {
  m_timestamp = 0;
  clear_content();
}
string led_state::print() const {
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
led_state& led_state::operator=(const autogen::state::led_state& rhs) {
  autogen::state::led_state::operator=(rhs);
  return *this;
}
led_state& led_state::operator=(const led_state& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::led_state::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
