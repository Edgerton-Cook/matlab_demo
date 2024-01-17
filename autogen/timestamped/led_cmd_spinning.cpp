////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/led_cmd_spinning.cpp                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/led_cmd_spinning.h"
using autogen::timestamped::led_cmd_spinning;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

led_cmd_spinning::led_cmd_spinning(autogen::topic::led_cmd_spinning::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::led_cmd_spinning() {
  // No-op.
}
led_cmd_spinning::~led_cmd_spinning() {
  // No-op.
}
led_cmd_spinning::topic_t led_cmd_spinning::topic_index() const {
  return mc_topic;
}
string led_cmd_spinning::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
led_cmd_spinning::ts_t& led_cmd_spinning::timestamp() {
  return m_timestamp;
}
const led_cmd_spinning::ts_t& led_cmd_spinning::timestamp() const {
  return m_timestamp;
}
void led_cmd_spinning::clear() {
  m_timestamp = 0;
  clear_content();
}
string led_cmd_spinning::print() const {
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
led_cmd_spinning& led_cmd_spinning::operator=(const autogen::packet::led_cmd_spinning& rhs) {
  autogen::packet::led_cmd_spinning::operator=(rhs);
  return *this;
}
led_cmd_spinning& led_cmd_spinning::operator=(const led_cmd_spinning& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::led_cmd_spinning::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
