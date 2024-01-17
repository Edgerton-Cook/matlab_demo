////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/estimation_sig_data.cpp                                           //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/estimation_sig_data.h"
using autogen::timestamped::estimation_sig_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

estimation_sig_data::estimation_sig_data(autogen::topic::estimation_sig_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::estimation_sig_data() {
  // No-op.
}
estimation_sig_data::~estimation_sig_data() {
  // No-op.
}
estimation_sig_data::topic_t estimation_sig_data::topic_index() const {
  return mc_topic;
}
string estimation_sig_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
estimation_sig_data::ts_t& estimation_sig_data::timestamp() {
  return m_timestamp;
}
const estimation_sig_data::ts_t& estimation_sig_data::timestamp() const {
  return m_timestamp;
}
void estimation_sig_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string estimation_sig_data::print() const {
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
estimation_sig_data& estimation_sig_data::operator=(const autogen::packet::estimation_sig_data& rhs) {
  autogen::packet::estimation_sig_data::operator=(rhs);
  return *this;
}
estimation_sig_data& estimation_sig_data::operator=(const estimation_sig_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::estimation_sig_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
