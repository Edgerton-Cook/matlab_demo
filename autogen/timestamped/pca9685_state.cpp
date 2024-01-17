////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/pca9685_state.cpp                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/pca9685_state.h"
using autogen::timestamped::pca9685_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

pca9685_state::pca9685_state(autogen::topic::pca9685_state::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::pca9685_state() {
  // No-op.
}
pca9685_state::pca9685_state(autogen::topic::pca9685_state::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::pca9685_state(s) {
  // No-op.
}
pca9685_state::~pca9685_state() {
  // No-op.
}
pca9685_state::topic_t pca9685_state::topic_index() const {
  return mc_topic;
}
string pca9685_state::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
pca9685_state::ts_t& pca9685_state::timestamp() {
  return m_timestamp;
}
const pca9685_state::ts_t& pca9685_state::timestamp() const {
  return m_timestamp;
}
void pca9685_state::clear() {
  m_timestamp = 0;
  clear_content();
}
string pca9685_state::print() const {
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
pca9685_state& pca9685_state::operator=(const autogen::state::pca9685_state& rhs) {
  autogen::state::pca9685_state::operator=(rhs);
  return *this;
}
pca9685_state& pca9685_state::operator=(const pca9685_state& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::pca9685_state::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
