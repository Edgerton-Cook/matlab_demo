////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/fm_local_data.cpp                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/fm_local_data.h"
using autogen::timestamped::fm_local_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

fm_local_data::fm_local_data(autogen::topic::fm_local_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::fm_local_data() {
  // No-op.
}
fm_local_data::~fm_local_data() {
  // No-op.
}
fm_local_data::topic_t fm_local_data::topic_index() const {
  return mc_topic;
}
string fm_local_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
fm_local_data::ts_t& fm_local_data::timestamp() {
  return m_timestamp;
}
const fm_local_data::ts_t& fm_local_data::timestamp() const {
  return m_timestamp;
}
void fm_local_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string fm_local_data::print() const {
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
fm_local_data& fm_local_data::operator=(const autogen::packet::fm_local_data& rhs) {
  autogen::packet::fm_local_data::operator=(rhs);
  return *this;
}
fm_local_data& fm_local_data::operator=(const fm_local_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::fm_local_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////