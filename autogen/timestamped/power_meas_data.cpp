////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/power_meas_data.cpp                                               //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/power_meas_data.h"
using autogen::timestamped::power_meas_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

power_meas_data::power_meas_data(autogen::topic::power_meas_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::power_meas_data() {
  // No-op.
}
power_meas_data::~power_meas_data() {
  // No-op.
}
power_meas_data::topic_t power_meas_data::topic_index() const {
  return mc_topic;
}
string power_meas_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
power_meas_data::ts_t& power_meas_data::timestamp() {
  return m_timestamp;
}
const power_meas_data::ts_t& power_meas_data::timestamp() const {
  return m_timestamp;
}
void power_meas_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string power_meas_data::print() const {
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
power_meas_data& power_meas_data::operator=(const autogen::packet::power_meas_data& rhs) {
  autogen::packet::power_meas_data::operator=(rhs);
  return *this;
}
power_meas_data& power_meas_data::operator=(const power_meas_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::power_meas_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
