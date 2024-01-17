////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/neom8_local_data.cpp                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/neom8_local_data.h"
using autogen::packet::neom8_local_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

neom8_local_data::neom8_local_data() :
  network::packet(autogen::type::NEOM8_LOCAL_DATA) {
  initialize();
}
neom8_local_data::~neom8_local_data() {
  // No-op.
}
neom8_local_data::type_t neom8_local_data::type_index() const {
  return mc_type;
}
string neom8_local_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void neom8_local_data::initialize() {
  clear();
}
void neom8_local_data::clear() {
  clear_content();
}
string neom8_local_data::print() const {
  return type_label()+","+print_content();
}
neom8_local_data& neom8_local_data::operator=(const neom8_local_data& rhs) {
  C_ecef2ned = rhs.C_ecef2ned;
  ned_origin_x_ecef_cm = rhs.ned_origin_x_ecef_cm;
  ned_origin_y_ecef_cm = rhs.ned_origin_y_ecef_cm;
  ned_origin_z_ecef_cm = rhs.ned_origin_z_ecef_cm;
  return *this;
}

void neom8_local_data::clear_content() {
  C_ecef2ned = gnc::dcm();
  ned_origin_x_ecef_cm = 0;
  ned_origin_y_ecef_cm = 0;
  ned_origin_z_ecef_cm = 0;
}
string neom8_local_data::print_content() const {
  std::ostringstream ss;
  for (uint32 mpac_ijk1=0; mpac_ijk1<9; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << C_ecef2ned.buff()[mpac_ijk1] << ",";
  }
  ss << std::setbase(10) << std::fixed << std::showpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << ned_origin_x_ecef_cm << ",";
  ss << std::setbase(10) << std::fixed << std::showpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << ned_origin_y_ecef_cm << ",";
  ss << std::setbase(10) << std::fixed << std::showpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << ned_origin_z_ecef_cm << ",";
  return ss.str();
}
uint8* neom8_local_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,C_ecef2ned.buff()[0],9);
  buff = network::packet::serialize(buff,ned_origin_x_ecef_cm,1);
  buff = network::packet::serialize(buff,ned_origin_y_ecef_cm,1);
  buff = network::packet::serialize(buff,ned_origin_z_ecef_cm,1);
  return buff;
}
const uint8* neom8_local_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,C_ecef2ned.buff()[0],9);
  buff = network::packet::deserialize(buff,ned_origin_x_ecef_cm,1);
  buff = network::packet::deserialize(buff,ned_origin_y_ecef_cm,1);
  buff = network::packet::deserialize(buff,ned_origin_z_ecef_cm,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
