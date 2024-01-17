////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/edison_state.cpp                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/edison_state.h"
using autogen::timestamped::edison_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

edison_state::edison_state(autogen::topic::edison_state::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::edison_state() {
  // No-op.
}
edison_state::edison_state(autogen::topic::edison_state::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::edison_state(s) {
  // No-op.
}
edison_state::~edison_state() {
  // No-op.
}
edison_state::topic_t edison_state::topic_index() const {
  return mc_topic;
}
string edison_state::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
edison_state::ts_t& edison_state::timestamp() {
  return m_timestamp;
}
const edison_state::ts_t& edison_state::timestamp() const {
  return m_timestamp;
}
void edison_state::clear() {
  m_timestamp = 0;
  clear_content();
}
string edison_state::print() const {
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
edison_state& edison_state::operator=(const autogen::state::edison_state& rhs) {
  autogen::state::edison_state::operator=(rhs);
  return *this;
}
edison_state& edison_state::operator=(const edison_state& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::edison_state::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
