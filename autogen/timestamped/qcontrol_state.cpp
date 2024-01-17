////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/qcontrol_state.cpp                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/qcontrol_state.h"
using autogen::timestamped::qcontrol_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

qcontrol_state::qcontrol_state(autogen::topic::qcontrol_state::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::qcontrol_state() {
  // No-op.
}
qcontrol_state::qcontrol_state(autogen::topic::qcontrol_state::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::qcontrol_state(s) {
  // No-op.
}
qcontrol_state::~qcontrol_state() {
  // No-op.
}
qcontrol_state::topic_t qcontrol_state::topic_index() const {
  return mc_topic;
}
string qcontrol_state::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
qcontrol_state::ts_t& qcontrol_state::timestamp() {
  return m_timestamp;
}
const qcontrol_state::ts_t& qcontrol_state::timestamp() const {
  return m_timestamp;
}
void qcontrol_state::clear() {
  m_timestamp = 0;
  clear_content();
}
string qcontrol_state::print() const {
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
qcontrol_state& qcontrol_state::operator=(const autogen::state::qcontrol_state& rhs) {
  autogen::state::qcontrol_state::operator=(rhs);
  return *this;
}
qcontrol_state& qcontrol_state::operator=(const qcontrol_state& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::qcontrol_state::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
