////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/filter_gains.cpp                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/filter_gains.h"
using autogen::timestamped::filter_gains;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

filter_gains::filter_gains(autogen::topic::filter_gains::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::parameter::filter_gains() {
  // No-op.
}
filter_gains::filter_gains(autogen::topic::filter_gains::TOPIC_T topic, const string& filename) :
  network::timestamped(topic),
  autogen::parameter::filter_gains(filename) {
  // No-op.
}
filter_gains::~filter_gains() {
  // No-op.
}
filter_gains::topic_t filter_gains::topic_index() const {
  return mc_topic;
}
string filter_gains::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
filter_gains::ts_t& filter_gains::timestamp() {
  return m_timestamp;
}
const filter_gains::ts_t& filter_gains::timestamp() const {
  return m_timestamp;
}
void filter_gains::clear() {
  m_timestamp = 0;
  clear_content();
}
string filter_gains::print() const {
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
filter_gains& filter_gains::operator=(const autogen::parameter::filter_gains& rhs) {
  autogen::parameter::filter_gains::operator=(rhs);
  return *this;
}
filter_gains& filter_gains::operator=(const filter_gains& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::parameter::filter_gains::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
