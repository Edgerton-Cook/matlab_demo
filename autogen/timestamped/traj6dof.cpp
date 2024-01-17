////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/traj6dof.cpp                                                      //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/traj6dof.h"
using autogen::timestamped::traj6dof;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

traj6dof::traj6dof(autogen::topic::traj6dof::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::traj6dof() {
  // No-op.
}
traj6dof::~traj6dof() {
  // No-op.
}
traj6dof::topic_t traj6dof::topic_index() const {
  return mc_topic;
}
string traj6dof::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
traj6dof::ts_t& traj6dof::timestamp() {
  return m_timestamp;
}
const traj6dof::ts_t& traj6dof::timestamp() const {
  return m_timestamp;
}
void traj6dof::clear() {
  m_timestamp = 0;
  clear_content();
}
string traj6dof::print() const {
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
traj6dof& traj6dof::operator=(const autogen::packet::traj6dof& rhs) {
  autogen::packet::traj6dof::operator=(rhs);
  return *this;
}
traj6dof& traj6dof::operator=(const traj6dof& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::traj6dof::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
