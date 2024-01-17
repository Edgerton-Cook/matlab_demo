////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/qcontrol_mode.cpp                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/qcontrol_mode.h"
using autogen::timestamped::qcontrol_mode;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

qcontrol_mode::qcontrol_mode(autogen::topic::qcontrol_mode::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::qcontrol_mode() {
  // No-op.
}
qcontrol_mode::qcontrol_mode(autogen::topic::qcontrol_mode::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::qcontrol_mode(s) {
  // No-op.
}
qcontrol_mode::~qcontrol_mode() {
  // No-op.
}
qcontrol_mode::topic_t qcontrol_mode::topic_index() const {
  return mc_topic;
}
string qcontrol_mode::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
qcontrol_mode::ts_t& qcontrol_mode::timestamp() {
  return m_timestamp;
}
const qcontrol_mode::ts_t& qcontrol_mode::timestamp() const {
  return m_timestamp;
}
void qcontrol_mode::clear() {
  m_timestamp = 0;
  clear_content();
}
string qcontrol_mode::print() const {
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
qcontrol_mode& qcontrol_mode::operator=(const autogen::state::qcontrol_mode& rhs) {
  autogen::state::qcontrol_mode::operator=(rhs);
  return *this;
}
qcontrol_mode& qcontrol_mode::operator=(const qcontrol_mode& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::qcontrol_mode::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
