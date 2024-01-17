////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/cm_local_data.cpp                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/cm_local_data.h"
using autogen::timestamped::cm_local_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

cm_local_data::cm_local_data(autogen::topic::cm_local_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::cm_local_data() {
  // No-op.
}
cm_local_data::~cm_local_data() {
  // No-op.
}
cm_local_data::topic_t cm_local_data::topic_index() const {
  return mc_topic;
}
string cm_local_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
cm_local_data::ts_t& cm_local_data::timestamp() {
  return m_timestamp;
}
const cm_local_data::ts_t& cm_local_data::timestamp() const {
  return m_timestamp;
}
void cm_local_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string cm_local_data::print() const {
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
cm_local_data& cm_local_data::operator=(const autogen::packet::cm_local_data& rhs) {
  autogen::packet::cm_local_data::operator=(rhs);
  return *this;
}
cm_local_data& cm_local_data::operator=(const cm_local_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::cm_local_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
