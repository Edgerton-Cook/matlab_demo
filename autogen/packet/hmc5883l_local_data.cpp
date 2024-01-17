////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/hmc5883l_local_data.cpp                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/hmc5883l_local_data.h"
using autogen::packet::hmc5883l_local_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

hmc5883l_local_data::hmc5883l_local_data() :
  network::packet(autogen::type::HMC5883L_LOCAL_DATA) {
  initialize();
}
hmc5883l_local_data::~hmc5883l_local_data() {
  // No-op.
}
hmc5883l_local_data::type_t hmc5883l_local_data::type_index() const {
  return mc_type;
}
string hmc5883l_local_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void hmc5883l_local_data::initialize() {
  clear();
}
void hmc5883l_local_data::clear() {
  clear_content();
}
string hmc5883l_local_data::print() const {
  return type_label()+","+print_content();
}
hmc5883l_local_data& hmc5883l_local_data::operator=(const hmc5883l_local_data& rhs) {
  inv_scale = rhs.inv_scale;
  C_dev2body = rhs.C_dev2body;
  calibration_complete = rhs.calibration_complete;
  i_calib_sample = rhs.i_calib_sample;
  return *this;
}

void hmc5883l_local_data::clear_content() {
  inv_scale = 0.0f;
  C_dev2body = gnc::dcm();
  calibration_complete = 0;
  i_calib_sample = 0;
}
string hmc5883l_local_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << inv_scale << ",";
  for (uint32 mpac_ijk1=0; mpac_ijk1<9; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << C_dev2body.buff()[mpac_ijk1] << ",";
  }
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << calibration_complete << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << i_calib_sample << ",";
  return ss.str();
}
uint8* hmc5883l_local_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,inv_scale,1);
  buff = network::packet::serialize(buff,C_dev2body.buff()[0],9);
  buff = network::packet::serialize(buff,calibration_complete,1);
  buff = network::packet::serialize(buff,i_calib_sample,1);
  return buff;
}
const uint8* hmc5883l_local_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,inv_scale,1);
  buff = network::packet::deserialize(buff,C_dev2body.buff()[0],9);
  buff = network::packet::deserialize(buff,calibration_complete,1);
  buff = network::packet::deserialize(buff,i_calib_sample,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
