////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/cm_local_data.cpp                                                      //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/cm_local_data.h"
using autogen::packet::cm_local_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

cm_local_data::cm_local_data() :
  network::packet(autogen::type::CM_LOCAL_DATA) {
  initialize();
}
cm_local_data::~cm_local_data() {
  // No-op.
}
cm_local_data::type_t cm_local_data::type_index() const {
  return mc_type;
}
string cm_local_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void cm_local_data::initialize() {
  clear();
}
void cm_local_data::clear() {
  clear_content();
}
string cm_local_data::print() const {
  return type_label()+","+print_content();
}
cm_local_data& cm_local_data::operator=(const cm_local_data& rhs) {
  deactivate = rhs.deactivate;
  master_ipv4 = rhs.master_ipv4;
  current_owner_ipv4 = rhs.current_owner_ipv4;
  mocap_data_counter = rhs.mocap_data_counter;
  return *this;
}

void cm_local_data::clear_content() {
  deactivate = 0;
  master_ipv4 = 0;
  current_owner_ipv4 = 0;
  mocap_data_counter = 0;
}
string cm_local_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << deactivate << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << master_ipv4 << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << current_owner_ipv4 << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << mocap_data_counter << ",";
  return ss.str();
}
uint8* cm_local_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,deactivate,1);
  buff = network::packet::serialize(buff,master_ipv4,1);
  buff = network::packet::serialize(buff,current_owner_ipv4,1);
  buff = network::packet::serialize(buff,mocap_data_counter,1);
  return buff;
}
const uint8* cm_local_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,deactivate,1);
  buff = network::packet::deserialize(buff,master_ipv4,1);
  buff = network::packet::deserialize(buff,current_owner_ipv4,1);
  buff = network::packet::deserialize(buff,mocap_data_counter,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
