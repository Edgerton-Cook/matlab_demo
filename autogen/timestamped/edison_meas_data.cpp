////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/edison_meas_data.cpp                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/edison_meas_data.h"
using autogen::timestamped::edison_meas_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

edison_meas_data::edison_meas_data(autogen::topic::edison_meas_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::edison_meas_data() {
  // No-op.
}
edison_meas_data::~edison_meas_data() {
  // No-op.
}
edison_meas_data::topic_t edison_meas_data::topic_index() const {
  return mc_topic;
}
string edison_meas_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
edison_meas_data::ts_t& edison_meas_data::timestamp() {
  return m_timestamp;
}
const edison_meas_data::ts_t& edison_meas_data::timestamp() const {
  return m_timestamp;
}
void edison_meas_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string edison_meas_data::print() const {
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
edison_meas_data& edison_meas_data::operator=(const autogen::packet::edison_meas_data& rhs) {
  autogen::packet::edison_meas_data::operator=(rhs);
  return *this;
}
edison_meas_data& edison_meas_data::operator=(const edison_meas_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::edison_meas_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
