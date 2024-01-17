////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/sc18is602b_state.cpp                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/sc18is602b_state.h"
using autogen::timestamped::sc18is602b_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

sc18is602b_state::sc18is602b_state(autogen::topic::sc18is602b_state::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::sc18is602b_state() {
  // No-op.
}
sc18is602b_state::sc18is602b_state(autogen::topic::sc18is602b_state::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::sc18is602b_state(s) {
  // No-op.
}
sc18is602b_state::~sc18is602b_state() {
  // No-op.
}
sc18is602b_state::topic_t sc18is602b_state::topic_index() const {
  return mc_topic;
}
string sc18is602b_state::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
sc18is602b_state::ts_t& sc18is602b_state::timestamp() {
  return m_timestamp;
}
const sc18is602b_state::ts_t& sc18is602b_state::timestamp() const {
  return m_timestamp;
}
void sc18is602b_state::clear() {
  m_timestamp = 0;
  clear_content();
}
string sc18is602b_state::print() const {
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
sc18is602b_state& sc18is602b_state::operator=(const autogen::state::sc18is602b_state& rhs) {
  autogen::state::sc18is602b_state::operator=(rhs);
  return *this;
}
sc18is602b_state& sc18is602b_state::operator=(const sc18is602b_state& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::sc18is602b_state::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
