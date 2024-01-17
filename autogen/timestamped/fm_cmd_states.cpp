////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/fm_cmd_states.cpp                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/fm_cmd_states.h"
using autogen::timestamped::fm_cmd_states;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

fm_cmd_states::fm_cmd_states(autogen::topic::fm_cmd_states::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::fm_cmd_states() {
  // No-op.
}
fm_cmd_states::~fm_cmd_states() {
  // No-op.
}
fm_cmd_states::topic_t fm_cmd_states::topic_index() const {
  return mc_topic;
}
string fm_cmd_states::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
fm_cmd_states::ts_t& fm_cmd_states::timestamp() {
  return m_timestamp;
}
const fm_cmd_states::ts_t& fm_cmd_states::timestamp() const {
  return m_timestamp;
}
void fm_cmd_states::clear() {
  m_timestamp = 0;
  clear_content();
}
string fm_cmd_states::print() const {
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
fm_cmd_states& fm_cmd_states::operator=(const autogen::packet::fm_cmd_states& rhs) {
  autogen::packet::fm_cmd_states::operator=(rhs);
  return *this;
}
fm_cmd_states& fm_cmd_states::operator=(const fm_cmd_states& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::fm_cmd_states::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
