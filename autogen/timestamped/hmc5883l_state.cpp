////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/hmc5883l_state.cpp                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/hmc5883l_state.h"
using autogen::timestamped::hmc5883l_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

hmc5883l_state::hmc5883l_state(autogen::topic::hmc5883l_state::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::hmc5883l_state() {
  // No-op.
}
hmc5883l_state::hmc5883l_state(autogen::topic::hmc5883l_state::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::hmc5883l_state(s) {
  // No-op.
}
hmc5883l_state::~hmc5883l_state() {
  // No-op.
}
hmc5883l_state::topic_t hmc5883l_state::topic_index() const {
  return mc_topic;
}
string hmc5883l_state::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
hmc5883l_state::ts_t& hmc5883l_state::timestamp() {
  return m_timestamp;
}
const hmc5883l_state::ts_t& hmc5883l_state::timestamp() const {
  return m_timestamp;
}
void hmc5883l_state::clear() {
  m_timestamp = 0;
  clear_content();
}
string hmc5883l_state::print() const {
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
hmc5883l_state& hmc5883l_state::operator=(const autogen::state::hmc5883l_state& rhs) {
  autogen::state::hmc5883l_state::operator=(rhs);
  return *this;
}
hmc5883l_state& hmc5883l_state::operator=(const hmc5883l_state& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::hmc5883l_state::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
