////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/mocap_data.cpp                                                         //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/mocap_data.h"
using autogen::packet::mocap_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

mocap_data::mocap_data() :
  network::packet(autogen::type::MOCAP_DATA) {
  initialize();
}
mocap_data::~mocap_data() {
  // No-op.
}
mocap_data::type_t mocap_data::type_index() const {
  return mc_type;
}
string mocap_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void mocap_data::initialize() {
  clear();
}
void mocap_data::clear() {
  clear_content();
}
string mocap_data::print() const {
  return type_label()+","+print_content();
}
mocap_data& mocap_data::operator=(const mocap_data& rhs) {
  rigid_body_id = rhs.rigid_body_id;
  pos_ned = rhs.pos_ned;
  q_i2b = rhs.q_i2b;
  return *this;
}

void mocap_data::clear_content() {
  rigid_body_id = 0;
  pos_ned = gnc::matrix<float,3,1>();
  q_i2b = gnc::quat();
}
string mocap_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << rigid_body_id << ",";
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << pos_ned.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<4; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << q_i2b.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* mocap_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,rigid_body_id,1);
  buff = network::packet::serialize(buff,pos_ned.buff()[0],3);
  buff = network::packet::serialize(buff,q_i2b.buff()[0],4);
  return buff;
}
const uint8* mocap_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,rigid_body_id,1);
  buff = network::packet::deserialize(buff,pos_ned.buff()[0],3);
  buff = network::packet::deserialize(buff,q_i2b.buff()[0],4);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
