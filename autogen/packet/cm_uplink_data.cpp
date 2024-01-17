////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/cm_uplink_data.cpp                                                     //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/cm_uplink_data.h"
using autogen::packet::cm_uplink_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

cm_uplink_data::cm_uplink_data() :
  network::packet(autogen::type::CM_UPLINK_DATA) {
  initialize();
}
cm_uplink_data::~cm_uplink_data() {
  // No-op.
}
cm_uplink_data::type_t cm_uplink_data::type_index() const {
  return mc_type;
}
string cm_uplink_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void cm_uplink_data::initialize() {
  clear();
}
void cm_uplink_data::clear() {
  clear_content();
}
string cm_uplink_data::print() const {
  return type_label()+","+print_content();
}
cm_uplink_data& cm_uplink_data::operator=(const cm_uplink_data& rhs) {
  mocap = rhs.mocap;
  qcontrol_cmd = rhs.qcontrol_cmd;
  rcontrol_cmd = rhs.rcontrol_cmd;
  traj3dof = rhs.traj3dof;
  return *this;
}

void cm_uplink_data::clear_content() {
  mocap.clear();
  qcontrol_cmd.clear();
  rcontrol_cmd.clear();
  traj3dof.clear();
}
string cm_uplink_data::print_content() const {
  std::ostringstream ss;
  ss << mocap.print();
  ss << qcontrol_cmd.print();
  ss << rcontrol_cmd.print();
  ss << traj3dof.print();
  return ss.str();
}
uint8* cm_uplink_data::serialize_content(uint8* buff) const {
  buff = mocap.serialize_content(buff);
  buff = qcontrol_cmd.serialize_content(buff);
  buff = rcontrol_cmd.serialize_content(buff);
  buff = traj3dof.serialize_content(buff);
  return buff;
}
const uint8* cm_uplink_data::deserialize_content(const uint8* buff) {
  buff = mocap.deserialize_content(buff);
  buff = qcontrol_cmd.deserialize_content(buff);
  buff = rcontrol_cmd.deserialize_content(buff);
  buff = traj3dof.deserialize_content(buff);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
