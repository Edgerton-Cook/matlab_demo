////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/hmc5883l_meas_data.cpp                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/hmc5883l_meas_data.h"
using autogen::packet::hmc5883l_meas_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

hmc5883l_meas_data::hmc5883l_meas_data() :
  network::packet(autogen::type::HMC5883L_MEAS_DATA) {
  initialize();
}
hmc5883l_meas_data::~hmc5883l_meas_data() {
  // No-op.
}
hmc5883l_meas_data::type_t hmc5883l_meas_data::type_index() const {
  return mc_type;
}
string hmc5883l_meas_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void hmc5883l_meas_data::initialize() {
  clear();
}
void hmc5883l_meas_data::clear() {
  clear_content();
}
string hmc5883l_meas_data::print() const {
  return type_label()+","+print_content();
}
hmc5883l_meas_data& hmc5883l_meas_data::operator=(const hmc5883l_meas_data& rhs) {
  mag_vec = rhs.mag_vec;
  return *this;
}

void hmc5883l_meas_data::clear_content() {
  mag_vec = gnc::matrix<float,3,1>();
}
string hmc5883l_meas_data::print_content() const {
  std::ostringstream ss;
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << mag_vec.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* hmc5883l_meas_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,mag_vec.buff()[0],3);
  return buff;
}
const uint8* hmc5883l_meas_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,mag_vec.buff()[0],3);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
