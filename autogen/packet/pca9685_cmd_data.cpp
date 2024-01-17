////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/pca9685_cmd_data.cpp                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/pca9685_cmd_data.h"
using autogen::packet::pca9685_cmd_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

pca9685_cmd_data::pca9685_cmd_data() :
  network::packet(autogen::type::PCA9685_CMD_DATA) {
  initialize();
}
pca9685_cmd_data::~pca9685_cmd_data() {
  // No-op.
}
pca9685_cmd_data::type_t pca9685_cmd_data::type_index() const {
  return mc_type;
}
string pca9685_cmd_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void pca9685_cmd_data::initialize() {
  clear();
}
void pca9685_cmd_data::clear() {
  clear_content();
}
string pca9685_cmd_data::print() const {
  return type_label()+","+print_content();
}
pca9685_cmd_data& pca9685_cmd_data::operator=(const pca9685_cmd_data& rhs) {
  pwm = rhs.pwm;
  return *this;
}

void pca9685_cmd_data::clear_content() {
  pwm = gnc::matrix<float,16,1>();
}
string pca9685_cmd_data::print_content() const {
  std::ostringstream ss;
  for (uint32 mpac_ijk1=0; mpac_ijk1<16; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << pwm.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* pca9685_cmd_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,pwm.buff()[0],16);
  return buff;
}
const uint8* pca9685_cmd_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,pwm.buff()[0],16);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
