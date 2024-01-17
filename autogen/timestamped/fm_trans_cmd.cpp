////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/fm_trans_cmd.cpp                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/fm_trans_cmd.h"
using autogen::timestamped::fm_trans_cmd;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

fm_trans_cmd::fm_trans_cmd(autogen::topic::fm_trans_cmd::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::fm_trans_cmd() {
  // No-op.
}
fm_trans_cmd::fm_trans_cmd(autogen::topic::fm_trans_cmd::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::fm_trans_cmd(s) {
  // No-op.
}
fm_trans_cmd::~fm_trans_cmd() {
  // No-op.
}
fm_trans_cmd::topic_t fm_trans_cmd::topic_index() const {
  return mc_topic;
}
string fm_trans_cmd::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
fm_trans_cmd::ts_t& fm_trans_cmd::timestamp() {
  return m_timestamp;
}
const fm_trans_cmd::ts_t& fm_trans_cmd::timestamp() const {
  return m_timestamp;
}
void fm_trans_cmd::clear() {
  m_timestamp = 0;
  clear_content();
}
string fm_trans_cmd::print() const {
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
fm_trans_cmd& fm_trans_cmd::operator=(const autogen::state::fm_trans_cmd& rhs) {
  autogen::state::fm_trans_cmd::operator=(rhs);
  return *this;
}
fm_trans_cmd& fm_trans_cmd::operator=(const fm_trans_cmd& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::fm_trans_cmd::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
