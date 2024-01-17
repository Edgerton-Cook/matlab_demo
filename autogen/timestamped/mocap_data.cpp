////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/mocap_data.cpp                                                    //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/mocap_data.h"
using autogen::timestamped::mocap_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

mocap_data::mocap_data(autogen::topic::mocap_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::mocap_data() {
  // No-op.
}
mocap_data::~mocap_data() {
  // No-op.
}
mocap_data::topic_t mocap_data::topic_index() const {
  return mc_topic;
}
string mocap_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
mocap_data::ts_t& mocap_data::timestamp() {
  return m_timestamp;
}
const mocap_data::ts_t& mocap_data::timestamp() const {
  return m_timestamp;
}
void mocap_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string mocap_data::print() const {
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
mocap_data& mocap_data::operator=(const autogen::packet::mocap_data& rhs) {
  autogen::packet::mocap_data::operator=(rhs);
  return *this;
}
mocap_data& mocap_data::operator=(const mocap_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::mocap_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
