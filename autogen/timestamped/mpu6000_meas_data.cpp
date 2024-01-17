////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/mpu6000_meas_data.cpp                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/mpu6000_meas_data.h"
using autogen::timestamped::mpu6000_meas_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

mpu6000_meas_data::mpu6000_meas_data(autogen::topic::mpu6000_meas_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::mpu6000_meas_data() {
  // No-op.
}
mpu6000_meas_data::~mpu6000_meas_data() {
  // No-op.
}
mpu6000_meas_data::topic_t mpu6000_meas_data::topic_index() const {
  return mc_topic;
}
string mpu6000_meas_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
mpu6000_meas_data::ts_t& mpu6000_meas_data::timestamp() {
  return m_timestamp;
}
const mpu6000_meas_data::ts_t& mpu6000_meas_data::timestamp() const {
  return m_timestamp;
}
void mpu6000_meas_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string mpu6000_meas_data::print() const {
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
mpu6000_meas_data& mpu6000_meas_data::operator=(const autogen::packet::mpu6000_meas_data& rhs) {
  autogen::packet::mpu6000_meas_data::operator=(rhs);
  return *this;
}
mpu6000_meas_data& mpu6000_meas_data::operator=(const mpu6000_meas_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::mpu6000_meas_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
