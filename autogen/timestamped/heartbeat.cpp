////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/heartbeat.cpp                                                     //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/heartbeat.h"
using autogen::timestamped::heartbeat;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

heartbeat::heartbeat(autogen::topic::heartbeat::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::heartbeat() {
  // No-op.
}
heartbeat::~heartbeat() {
  // No-op.
}
heartbeat::topic_t heartbeat::topic_index() const {
  return mc_topic;
}
string heartbeat::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
heartbeat::ts_t& heartbeat::timestamp() {
  return m_timestamp;
}
const heartbeat::ts_t& heartbeat::timestamp() const {
  return m_timestamp;
}
void heartbeat::clear() {
  m_timestamp = 0;
  clear_content();
}
string heartbeat::print() const {
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
heartbeat& heartbeat::operator=(const autogen::packet::heartbeat& rhs) {
  autogen::packet::heartbeat::operator=(rhs);
  return *this;
}
heartbeat& heartbeat::operator=(const heartbeat& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::heartbeat::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
