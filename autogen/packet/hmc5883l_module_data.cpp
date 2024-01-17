////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/hmc5883l_module_data.cpp                                               //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/hmc5883l_module_data.h"
using autogen::packet::hmc5883l_module_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

hmc5883l_module_data::hmc5883l_module_data() :
  network::packet(autogen::type::HMC5883L_MODULE_DATA) {
  initialize();
}
hmc5883l_module_data::~hmc5883l_module_data() {
  // No-op.
}
hmc5883l_module_data::type_t hmc5883l_module_data::type_index() const {
  return mc_type;
}
string hmc5883l_module_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void hmc5883l_module_data::initialize() {
  clear();
}
void hmc5883l_module_data::clear() {
  clear_content();
}
string hmc5883l_module_data::print() const {
  return type_label()+","+print_content();
}
hmc5883l_module_data& hmc5883l_module_data::operator=(const hmc5883l_module_data& rhs) {
  state = rhs.state;
  meas = rhs.meas;
  local = rhs.local;
  config = rhs.config;
  calib = rhs.calib;
  return *this;
}

void hmc5883l_module_data::clear_content() {
  state.clear();
  meas.clear();
  local.clear();
  config.clear();
  calib.clear();
}
string hmc5883l_module_data::print_content() const {
  std::ostringstream ss;
  ss << state.print();
  ss << meas.print();
  ss << local.print();
  ss << config.print();
  ss << calib.print();
  return ss.str();
}
uint8* hmc5883l_module_data::serialize_content(uint8* buff) const {
  buff = state.serialize_content(buff);
  buff = meas.serialize_content(buff);
  buff = local.serialize_content(buff);
  buff = config.serialize_content(buff);
  buff = calib.serialize_content(buff);
  return buff;
}
const uint8* hmc5883l_module_data::deserialize_content(const uint8* buff) {
  buff = state.deserialize_content(buff);
  buff = meas.deserialize_content(buff);
  buff = local.deserialize_content(buff);
  buff = config.deserialize_content(buff);
  buff = calib.deserialize_content(buff);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
