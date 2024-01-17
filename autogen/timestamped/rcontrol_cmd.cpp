////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/rcontrol_cmd.cpp                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/rcontrol_cmd.h"
using autogen::timestamped::rcontrol_cmd;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

rcontrol_cmd::rcontrol_cmd(autogen::topic::rcontrol_cmd::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::rcontrol_cmd() {
  // No-op.
}
rcontrol_cmd::~rcontrol_cmd() {
  // No-op.
}
rcontrol_cmd::topic_t rcontrol_cmd::topic_index() const {
  return mc_topic;
}
string rcontrol_cmd::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
rcontrol_cmd::ts_t& rcontrol_cmd::timestamp() {
  return m_timestamp;
}
const rcontrol_cmd::ts_t& rcontrol_cmd::timestamp() const {
  return m_timestamp;
}
void rcontrol_cmd::clear() {
  m_timestamp = 0;
  clear_content();
}
string rcontrol_cmd::print() const {
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
rcontrol_cmd& rcontrol_cmd::operator=(const autogen::packet::rcontrol_cmd& rhs) {
  autogen::packet::rcontrol_cmd::operator=(rhs);
  return *this;
}
rcontrol_cmd& rcontrol_cmd::operator=(const rcontrol_cmd& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::rcontrol_cmd::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
