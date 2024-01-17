////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/cm_state.cpp                                                      //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/cm_state.h"
using autogen::timestamped::cm_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

cm_state::cm_state(autogen::topic::cm_state::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::cm_state() {
  // No-op.
}
cm_state::cm_state(autogen::topic::cm_state::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::cm_state(s) {
  // No-op.
}
cm_state::~cm_state() {
  // No-op.
}
cm_state::topic_t cm_state::topic_index() const {
  return mc_topic;
}
string cm_state::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
cm_state::ts_t& cm_state::timestamp() {
  return m_timestamp;
}
const cm_state::ts_t& cm_state::timestamp() const {
  return m_timestamp;
}
void cm_state::clear() {
  m_timestamp = 0;
  clear_content();
}
string cm_state::print() const {
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
cm_state& cm_state::operator=(const autogen::state::cm_state& rhs) {
  autogen::state::cm_state::operator=(rhs);
  return *this;
}
cm_state& cm_state::operator=(const cm_state& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::cm_state::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
