////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/veh_config_state.cpp                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/veh_config_state.h"
using autogen::timestamped::veh_config_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

veh_config_state::veh_config_state(autogen::topic::veh_config_state::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::state::veh_config_state() {
  // No-op.
}
veh_config_state::veh_config_state(autogen::topic::veh_config_state::TOPIC_T topic, STATE_T s) :
  network::timestamped(topic),
  autogen::state::veh_config_state(s) {
  // No-op.
}
veh_config_state::~veh_config_state() {
  // No-op.
}
veh_config_state::topic_t veh_config_state::topic_index() const {
  return mc_topic;
}
string veh_config_state::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
veh_config_state::ts_t& veh_config_state::timestamp() {
  return m_timestamp;
}
const veh_config_state::ts_t& veh_config_state::timestamp() const {
  return m_timestamp;
}
void veh_config_state::clear() {
  m_timestamp = 0;
  clear_content();
}
string veh_config_state::print() const {
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
veh_config_state& veh_config_state::operator=(const autogen::state::veh_config_state& rhs) {
  autogen::state::veh_config_state::operator=(rhs);
  return *this;
}
veh_config_state& veh_config_state::operator=(const veh_config_state& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::state::veh_config_state::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
