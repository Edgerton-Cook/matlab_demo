////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/led_module_data.cpp                                               //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/led_module_data.h"
using autogen::timestamped::led_module_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

led_module_data::led_module_data(autogen::topic::led_module_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::led_module_data() {
  // No-op.
}
led_module_data::~led_module_data() {
  // No-op.
}
led_module_data::topic_t led_module_data::topic_index() const {
  return mc_topic;
}
string led_module_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
led_module_data::ts_t& led_module_data::timestamp() {
  return m_timestamp;
}
const led_module_data::ts_t& led_module_data::timestamp() const {
  return m_timestamp;
}
void led_module_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string led_module_data::print() const {
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
led_module_data& led_module_data::operator=(const autogen::packet::led_module_data& rhs) {
  autogen::packet::led_module_data::operator=(rhs);
  return *this;
}
led_module_data& led_module_data::operator=(const led_module_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::led_module_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
