////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/neom8_config_data.cpp                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/neom8_config_data.h"
using autogen::timestamped::neom8_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

neom8_config_data::neom8_config_data(autogen::topic::neom8_config_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::parameter::neom8_config_data() {
  // No-op.
}
neom8_config_data::neom8_config_data(autogen::topic::neom8_config_data::TOPIC_T topic, const string& filename) :
  network::timestamped(topic),
  autogen::parameter::neom8_config_data(filename) {
  // No-op.
}
neom8_config_data::~neom8_config_data() {
  // No-op.
}
neom8_config_data::topic_t neom8_config_data::topic_index() const {
  return mc_topic;
}
string neom8_config_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
neom8_config_data::ts_t& neom8_config_data::timestamp() {
  return m_timestamp;
}
const neom8_config_data::ts_t& neom8_config_data::timestamp() const {
  return m_timestamp;
}
void neom8_config_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string neom8_config_data::print() const {
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
neom8_config_data& neom8_config_data::operator=(const autogen::parameter::neom8_config_data& rhs) {
  autogen::parameter::neom8_config_data::operator=(rhs);
  return *this;
}
neom8_config_data& neom8_config_data::operator=(const neom8_config_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::parameter::neom8_config_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
