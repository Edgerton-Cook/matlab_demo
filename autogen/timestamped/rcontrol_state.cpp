////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/rcontrol_state.cpp                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/rcontrol_state.h"
using autogen::timestamped::rcontrol_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

rcontrol_state::rcontrol_state(autogen::topic::rcontrol_state::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::rcontrol_state() {
  // No-op.
}
rcontrol_state::rcontrol_state(autogen::topic::rcontrol_state::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::rcontrol_state(s) {
  // No-op.
}
rcontrol_state::~rcontrol_state() {
  // No-op.
}
rcontrol_state::topic_t rcontrol_state::topic_index() const {
  return mc_topic;
}
string rcontrol_state::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
rcontrol_state::ts_t& rcontrol_state::timestamp() {
  return m_timestamp;
}
const rcontrol_state::ts_t& rcontrol_state::timestamp() const {
  return m_timestamp;
}
void rcontrol_state::clear() {
  m_timestamp = 0;
  clear_content();
}
string rcontrol_state::print() const {
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
rcontrol_state& rcontrol_state::operator=(const autogen::state::rcontrol_state& rhs) {
  autogen::state::rcontrol_state::operator=(rhs);
  return *this;
}
rcontrol_state& rcontrol_state::operator=(const rcontrol_state& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::rcontrol_state::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
