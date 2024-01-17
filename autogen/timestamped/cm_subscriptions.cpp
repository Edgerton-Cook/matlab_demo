////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/cm_subscriptions.cpp                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/cm_subscriptions.h"
using autogen::timestamped::cm_subscriptions;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

cm_subscriptions::cm_subscriptions(autogen::topic::cm_subscriptions::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::parameter::cm_subscriptions() {
  // No-op.
}
cm_subscriptions::cm_subscriptions(autogen::topic::cm_subscriptions::TOPIC_T topic, const string& filename) :
  network::timestamped(topic),
  autogen::parameter::cm_subscriptions(filename) {
  // No-op.
}
cm_subscriptions::~cm_subscriptions() {
  // No-op.
}
cm_subscriptions::topic_t cm_subscriptions::topic_index() const {
  return mc_topic;
}
string cm_subscriptions::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
cm_subscriptions::ts_t& cm_subscriptions::timestamp() {
  return m_timestamp;
}
const cm_subscriptions::ts_t& cm_subscriptions::timestamp() const {
  return m_timestamp;
}
void cm_subscriptions::clear() {
  m_timestamp = 0;
  clear_content();
}
string cm_subscriptions::print() const {
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
cm_subscriptions& cm_subscriptions::operator=(const autogen::parameter::cm_subscriptions& rhs) {
  autogen::parameter::cm_subscriptions::operator=(rhs);
  return *this;
}
cm_subscriptions& cm_subscriptions::operator=(const cm_subscriptions& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::parameter::cm_subscriptions::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
