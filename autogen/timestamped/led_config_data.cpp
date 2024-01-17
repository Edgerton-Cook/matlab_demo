////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/led_config_data.cpp                                               //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/led_config_data.h"
using autogen::timestamped::led_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

led_config_data::led_config_data(autogen::topic::led_config_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::parameter::led_config_data() {
  // No-op.
}
led_config_data::led_config_data(autogen::topic::led_config_data::TOPIC_T topic, const string& filename) :
  network::timestamped(topic),
  autogen::parameter::led_config_data(filename) {
  // No-op.
}
led_config_data::~led_config_data() {
  // No-op.
}
led_config_data::topic_t led_config_data::topic_index() const {
  return mc_topic;
}
string led_config_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
led_config_data::ts_t& led_config_data::timestamp() {
  return m_timestamp;
}
const led_config_data::ts_t& led_config_data::timestamp() const {
  return m_timestamp;
}
void led_config_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string led_config_data::print() const {
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
led_config_data& led_config_data::operator=(const autogen::parameter::led_config_data& rhs) {
  autogen::parameter::led_config_data::operator=(rhs);
  return *this;
}
led_config_data& led_config_data::operator=(const led_config_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::parameter::led_config_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
