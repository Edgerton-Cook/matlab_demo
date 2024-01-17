////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/pca9685_config_data.cpp                                           //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/pca9685_config_data.h"
using autogen::timestamped::pca9685_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

pca9685_config_data::pca9685_config_data(autogen::topic::pca9685_config_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::parameter::pca9685_config_data() {
  // No-op.
}
pca9685_config_data::pca9685_config_data(autogen::topic::pca9685_config_data::TOPIC_T topic, const string& filename) :
  network::timestamped(topic),
  autogen::parameter::pca9685_config_data(filename) {
  // No-op.
}
pca9685_config_data::~pca9685_config_data() {
  // No-op.
}
pca9685_config_data::topic_t pca9685_config_data::topic_index() const {
  return mc_topic;
}
string pca9685_config_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
pca9685_config_data::ts_t& pca9685_config_data::timestamp() {
  return m_timestamp;
}
const pca9685_config_data::ts_t& pca9685_config_data::timestamp() const {
  return m_timestamp;
}
void pca9685_config_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string pca9685_config_data::print() const {
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
pca9685_config_data& pca9685_config_data::operator=(const autogen::parameter::pca9685_config_data& rhs) {
  autogen::parameter::pca9685_config_data::operator=(rhs);
  return *this;
}
pca9685_config_data& pca9685_config_data::operator=(const pca9685_config_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::parameter::pca9685_config_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
