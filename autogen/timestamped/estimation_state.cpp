////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/estimation_state.cpp                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/estimation_state.h"
using autogen::timestamped::estimation_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

estimation_state::estimation_state(autogen::topic::estimation_state::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::estimation_state() {
  // No-op.
}
estimation_state::estimation_state(autogen::topic::estimation_state::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::estimation_state(s) {
  // No-op.
}
estimation_state::~estimation_state() {
  // No-op.
}
estimation_state::topic_t estimation_state::topic_index() const {
  return mc_topic;
}
string estimation_state::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
estimation_state::ts_t& estimation_state::timestamp() {
  return m_timestamp;
}
const estimation_state::ts_t& estimation_state::timestamp() const {
  return m_timestamp;
}
void estimation_state::clear() {
  m_timestamp = 0;
  clear_content();
}
string estimation_state::print() const {
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
estimation_state& estimation_state::operator=(const autogen::state::estimation_state& rhs) {
  autogen::state::estimation_state::operator=(rhs);
  return *this;
}
estimation_state& estimation_state::operator=(const estimation_state& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::estimation_state::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
