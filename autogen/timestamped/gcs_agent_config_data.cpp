////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/gcs_agent_config_data.cpp                                         //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/gcs_agent_config_data.h"
using autogen::timestamped::gcs_agent_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

gcs_agent_config_data::gcs_agent_config_data(autogen::topic::gcs_agent_config_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::parameter::gcs_agent_config_data() {
  // No-op.
}
gcs_agent_config_data::gcs_agent_config_data(autogen::topic::gcs_agent_config_data::TOPIC_T topic, const string& filename) :
  network::timestamped(topic),
  autogen::parameter::gcs_agent_config_data(filename) {
  // No-op.
}
gcs_agent_config_data::~gcs_agent_config_data() {
  // No-op.
}
gcs_agent_config_data::topic_t gcs_agent_config_data::topic_index() const {
  return mc_topic;
}
string gcs_agent_config_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
gcs_agent_config_data::ts_t& gcs_agent_config_data::timestamp() {
  return m_timestamp;
}
const gcs_agent_config_data::ts_t& gcs_agent_config_data::timestamp() const {
  return m_timestamp;
}
void gcs_agent_config_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string gcs_agent_config_data::print() const {
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
gcs_agent_config_data& gcs_agent_config_data::operator=(const autogen::parameter::gcs_agent_config_data& rhs) {
  autogen::parameter::gcs_agent_config_data::operator=(rhs);
  return *this;
}
gcs_agent_config_data& gcs_agent_config_data::operator=(const gcs_agent_config_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::parameter::gcs_agent_config_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////