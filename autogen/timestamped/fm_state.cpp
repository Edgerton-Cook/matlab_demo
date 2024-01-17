////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/fm_state.cpp                                                      //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/fm_state.h"
using autogen::timestamped::fm_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

fm_state::fm_state(autogen::topic::fm_state::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::fm_state() {
  // No-op.
}
fm_state::fm_state(autogen::topic::fm_state::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::fm_state(s) {
  // No-op.
}
fm_state::~fm_state() {
  // No-op.
}
fm_state::topic_t fm_state::topic_index() const {
  return mc_topic;
}
string fm_state::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
fm_state::ts_t& fm_state::timestamp() {
  return m_timestamp;
}
const fm_state::ts_t& fm_state::timestamp() const {
  return m_timestamp;
}
void fm_state::clear() {
  m_timestamp = 0;
  clear_content();
}
string fm_state::print() const {
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
fm_state& fm_state::operator=(const autogen::state::fm_state& rhs) {
  autogen::state::fm_state::operator=(rhs);
  return *this;
}
fm_state& fm_state::operator=(const fm_state& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::fm_state::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
