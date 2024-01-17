////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/edison_module_data.cpp                                            //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/edison_module_data.h"
using autogen::timestamped::edison_module_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

edison_module_data::edison_module_data(autogen::topic::edison_module_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::edison_module_data() {
  // No-op.
}
edison_module_data::~edison_module_data() {
  // No-op.
}
edison_module_data::topic_t edison_module_data::topic_index() const {
  return mc_topic;
}
string edison_module_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
edison_module_data::ts_t& edison_module_data::timestamp() {
  return m_timestamp;
}
const edison_module_data::ts_t& edison_module_data::timestamp() const {
  return m_timestamp;
}
void edison_module_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string edison_module_data::print() const {
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
edison_module_data& edison_module_data::operator=(const autogen::packet::edison_module_data& rhs) {
  autogen::packet::edison_module_data::operator=(rhs);
  return *this;
}
edison_module_data& edison_module_data::operator=(const edison_module_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::edison_module_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
