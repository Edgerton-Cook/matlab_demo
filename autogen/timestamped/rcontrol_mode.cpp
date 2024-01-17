////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/rcontrol_mode.cpp                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/rcontrol_mode.h"
using autogen::timestamped::rcontrol_mode;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

rcontrol_mode::rcontrol_mode(autogen::topic::rcontrol_mode::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::rcontrol_mode() {
  // No-op.
}
rcontrol_mode::rcontrol_mode(autogen::topic::rcontrol_mode::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::rcontrol_mode(s) {
  // No-op.
}
rcontrol_mode::~rcontrol_mode() {
  // No-op.
}
rcontrol_mode::topic_t rcontrol_mode::topic_index() const {
  return mc_topic;
}
string rcontrol_mode::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
rcontrol_mode::ts_t& rcontrol_mode::timestamp() {
  return m_timestamp;
}
const rcontrol_mode::ts_t& rcontrol_mode::timestamp() const {
  return m_timestamp;
}
void rcontrol_mode::clear() {
  m_timestamp = 0;
  clear_content();
}
string rcontrol_mode::print() const {
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
rcontrol_mode& rcontrol_mode::operator=(const autogen::state::rcontrol_mode& rhs) {
  autogen::state::rcontrol_mode::operator=(rhs);
  return *this;
}
rcontrol_mode& rcontrol_mode::operator=(const rcontrol_mode& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::rcontrol_mode::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
