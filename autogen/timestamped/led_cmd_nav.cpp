////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/led_cmd_nav.cpp                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/led_cmd_nav.h"
using autogen::timestamped::led_cmd_nav;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

led_cmd_nav::led_cmd_nav(autogen::topic::led_cmd_nav::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::led_cmd_nav() {
  // No-op.
}
led_cmd_nav::~led_cmd_nav() {
  // No-op.
}
led_cmd_nav::topic_t led_cmd_nav::topic_index() const {
  return mc_topic;
}
string led_cmd_nav::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
led_cmd_nav::ts_t& led_cmd_nav::timestamp() {
  return m_timestamp;
}
const led_cmd_nav::ts_t& led_cmd_nav::timestamp() const {
  return m_timestamp;
}
void led_cmd_nav::clear() {
  m_timestamp = 0;
  clear_content();
}
string led_cmd_nav::print() const {
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
led_cmd_nav& led_cmd_nav::operator=(const autogen::packet::led_cmd_nav& rhs) {
  autogen::packet::led_cmd_nav::operator=(rhs);
  return *this;
}
led_cmd_nav& led_cmd_nav::operator=(const led_cmd_nav& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::led_cmd_nav::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
