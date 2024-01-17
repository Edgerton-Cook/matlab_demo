////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/qcontrol_sig_data.cpp                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/qcontrol_sig_data.h"
using autogen::timestamped::qcontrol_sig_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

qcontrol_sig_data::qcontrol_sig_data(autogen::topic::qcontrol_sig_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::qcontrol_sig_data() {
  // No-op.
}
qcontrol_sig_data::~qcontrol_sig_data() {
  // No-op.
}
qcontrol_sig_data::topic_t qcontrol_sig_data::topic_index() const {
  return mc_topic;
}
string qcontrol_sig_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
qcontrol_sig_data::ts_t& qcontrol_sig_data::timestamp() {
  return m_timestamp;
}
const qcontrol_sig_data::ts_t& qcontrol_sig_data::timestamp() const {
  return m_timestamp;
}
void qcontrol_sig_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string qcontrol_sig_data::print() const {
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
qcontrol_sig_data& qcontrol_sig_data::operator=(const autogen::packet::qcontrol_sig_data& rhs) {
  autogen::packet::qcontrol_sig_data::operator=(rhs);
  return *this;
}
qcontrol_sig_data& qcontrol_sig_data::operator=(const qcontrol_sig_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::qcontrol_sig_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
