////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/cm_uplink_data.cpp                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/cm_uplink_data.h"
using autogen::timestamped::cm_uplink_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

cm_uplink_data::cm_uplink_data(autogen::topic::cm_uplink_data::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::cm_uplink_data() {
  // No-op.
}
cm_uplink_data::~cm_uplink_data() {
  // No-op.
}
cm_uplink_data::topic_t cm_uplink_data::topic_index() const {
  return mc_topic;
}
string cm_uplink_data::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
cm_uplink_data::ts_t& cm_uplink_data::timestamp() {
  return m_timestamp;
}
const cm_uplink_data::ts_t& cm_uplink_data::timestamp() const {
  return m_timestamp;
}
void cm_uplink_data::clear() {
  m_timestamp = 0;
  clear_content();
}
string cm_uplink_data::print() const {
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
cm_uplink_data& cm_uplink_data::operator=(const autogen::packet::cm_uplink_data& rhs) {
  autogen::packet::cm_uplink_data::operator=(rhs);
  return *this;
}
cm_uplink_data& cm_uplink_data::operator=(const cm_uplink_data& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::cm_uplink_data::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
