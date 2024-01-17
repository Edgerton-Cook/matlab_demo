////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/power_calib_data.cpp                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/power_calib_data.h"
using autogen::timestamped::power_calib_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

power_calib_data::power_calib_data(autogen::topic::power_calib_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::parameter::power_calib_data() {
  // No-op.
}
power_calib_data::power_calib_data(autogen::topic::power_calib_data::TOPIC_T topic, const string& filename) :
  network::timestamped(topic),
  autogen::parameter::power_calib_data(filename) {
  // No-op.
}
power_calib_data::~power_calib_data() {
  // No-op.
}
power_calib_data::topic_t power_calib_data::topic_index() const {
  return mc_topic;
}
string power_calib_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
power_calib_data::ts_t& power_calib_data::timestamp() {
  return m_timestamp;
}
const power_calib_data::ts_t& power_calib_data::timestamp() const {
  return m_timestamp;
}
void power_calib_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string power_calib_data::print() const {
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
power_calib_data& power_calib_data::operator=(const autogen::parameter::power_calib_data& rhs) {
  autogen::parameter::power_calib_data::operator=(rhs);
  return *this;
}
power_calib_data& power_calib_data::operator=(const power_calib_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::parameter::power_calib_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
