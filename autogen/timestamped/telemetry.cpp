////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/telemetry.cpp                                                     //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/telemetry.h"
using autogen::timestamped::telemetry;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

telemetry::telemetry(autogen::topic::telemetry::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::telemetry() {
  // No-op.
}
telemetry::~telemetry() {
  // No-op.
}
telemetry::topic_t telemetry::topic_index() const {
  return mc_topic;
}
string telemetry::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
telemetry::ts_t& telemetry::timestamp() {
  return m_timestamp;
}
const telemetry::ts_t& telemetry::timestamp() const {
  return m_timestamp;
}
void telemetry::clear() {
  m_timestamp = 0;
  clear_content();
}
string telemetry::print() const {
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
telemetry& telemetry::operator=(const autogen::packet::telemetry& rhs) {
  autogen::packet::telemetry::operator=(rhs);
  return *this;
}
telemetry& telemetry::operator=(const telemetry& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::telemetry::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
