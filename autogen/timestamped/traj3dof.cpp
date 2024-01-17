////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/traj3dof.cpp                                                      //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/traj3dof.h"
using autogen::timestamped::traj3dof;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

traj3dof::traj3dof(autogen::topic::traj3dof::TOPIC_T topic) :
  network::timestamped(topic),
  autogen::packet::traj3dof() {
  // No-op.
}
traj3dof::~traj3dof() {
  // No-op.
}
traj3dof::topic_t traj3dof::topic_index() const {
  return mc_topic;
}
string traj3dof::topic_label() const {
  return autogen::labels::topic_labels[mc_topic];
}
traj3dof::ts_t& traj3dof::timestamp() {
  return m_timestamp;
}
const traj3dof::ts_t& traj3dof::timestamp() const {
  return m_timestamp;
}
void traj3dof::clear() {
  m_timestamp = 0;
  clear_content();
}
string traj3dof::print() const {
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
traj3dof& traj3dof::operator=(const autogen::packet::traj3dof& rhs) {
  autogen::packet::traj3dof::operator=(rhs);
  return *this;
}
traj3dof& traj3dof::operator=(const traj3dof& rhs) {
  m_timestamp = rhs.m_timestamp;
  autogen::packet::traj3dof::operator=(rhs);
  return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
