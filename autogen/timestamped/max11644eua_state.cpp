////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/max11644eua_state.cpp                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/max11644eua_state.h"
using autogen::timestamped::max11644eua_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

max11644eua_state::max11644eua_state(autogen::topic::max11644eua_state::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::max11644eua_state() {
  // No-op.
}
max11644eua_state::max11644eua_state(autogen::topic::max11644eua_state::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::max11644eua_state(s) {
  // No-op.
}
max11644eua_state::~max11644eua_state() {
  // No-op.
}
max11644eua_state::topic_t max11644eua_state::topic_index() const {
  return mc_topic;
}
string max11644eua_state::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
max11644eua_state::ts_t& max11644eua_state::timestamp() {
  return m_timestamp;
}
const max11644eua_state::ts_t& max11644eua_state::timestamp() const {
  return m_timestamp;
}
void max11644eua_state::clear() {
  m_timestamp = 0;
  clear_content();
}
string max11644eua_state::print() const {
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
max11644eua_state& max11644eua_state::operator=(const autogen::state::max11644eua_state& rhs) {
  autogen::state::max11644eua_state::operator=(rhs);
  return *this;
}
max11644eua_state& max11644eua_state::operator=(const max11644eua_state& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::max11644eua_state::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
