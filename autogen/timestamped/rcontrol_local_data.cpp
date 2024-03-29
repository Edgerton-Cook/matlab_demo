////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/rcontrol_local_data.cpp                                           //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/rcontrol_local_data.h"
using autogen::timestamped::rcontrol_local_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

rcontrol_local_data::rcontrol_local_data(autogen::topic::rcontrol_local_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::rcontrol_local_data() {
  // No-op.
}
rcontrol_local_data::~rcontrol_local_data() {
  // No-op.
}
rcontrol_local_data::topic_t rcontrol_local_data::topic_index() const {
  return mc_topic;
}
string rcontrol_local_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
rcontrol_local_data::ts_t& rcontrol_local_data::timestamp() {
  return m_timestamp;
}
const rcontrol_local_data::ts_t& rcontrol_local_data::timestamp() const {
  return m_timestamp;
}
void rcontrol_local_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string rcontrol_local_data::print() const {
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
rcontrol_local_data& rcontrol_local_data::operator=(const autogen::packet::rcontrol_local_data& rhs) {
  autogen::packet::rcontrol_local_data::operator=(rhs);
  return *this;
}
rcontrol_local_data& rcontrol_local_data::operator=(const rcontrol_local_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::rcontrol_local_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
