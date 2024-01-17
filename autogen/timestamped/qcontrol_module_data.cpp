////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/qcontrol_module_data.cpp                                          //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/qcontrol_module_data.h"
using autogen::timestamped::qcontrol_module_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

qcontrol_module_data::qcontrol_module_data(autogen::topic::qcontrol_module_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::qcontrol_module_data() {
  // No-op.
}
qcontrol_module_data::~qcontrol_module_data() {
  // No-op.
}
qcontrol_module_data::topic_t qcontrol_module_data::topic_index() const {
  return mc_topic;
}
string qcontrol_module_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
qcontrol_module_data::ts_t& qcontrol_module_data::timestamp() {
  return m_timestamp;
}
const qcontrol_module_data::ts_t& qcontrol_module_data::timestamp() const {
  return m_timestamp;
}
void qcontrol_module_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string qcontrol_module_data::print() const {
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
qcontrol_module_data& qcontrol_module_data::operator=(const autogen::packet::qcontrol_module_data& rhs) {
  autogen::packet::qcontrol_module_data::operator=(rhs);
  return *this;
}
qcontrol_module_data& qcontrol_module_data::operator=(const qcontrol_module_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::qcontrol_module_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
