////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/qcontrol_cmd.cpp                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/qcontrol_cmd.h"
using autogen::timestamped::qcontrol_cmd;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

qcontrol_cmd::qcontrol_cmd(autogen::topic::qcontrol_cmd::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::qcontrol_cmd() {
  // No-op.
}
qcontrol_cmd::~qcontrol_cmd() {
  // No-op.
}
qcontrol_cmd::topic_t qcontrol_cmd::topic_index() const {
  return mc_topic;
}
string qcontrol_cmd::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
qcontrol_cmd::ts_t& qcontrol_cmd::timestamp() {
  return m_timestamp;
}
const qcontrol_cmd::ts_t& qcontrol_cmd::timestamp() const {
  return m_timestamp;
}
void qcontrol_cmd::clear() {
  m_timestamp = 0;
  clear_content();
}
string qcontrol_cmd::print() const {
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
qcontrol_cmd& qcontrol_cmd::operator=(const autogen::packet::qcontrol_cmd& rhs) {
  autogen::packet::qcontrol_cmd::operator=(rhs);
  return *this;
}
qcontrol_cmd& qcontrol_cmd::operator=(const qcontrol_cmd& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::qcontrol_cmd::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
