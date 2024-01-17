////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/pca9685_module_data.cpp                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/pca9685_module_data.h"
using autogen::packet::pca9685_module_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

pca9685_module_data::pca9685_module_data() :
  network::packet(autogen::type::PCA9685_MODULE_DATA) {
  initialize();
}
pca9685_module_data::~pca9685_module_data() {
  // No-op.
}
pca9685_module_data::type_t pca9685_module_data::type_index() const {
  return mc_type;
}
string pca9685_module_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void pca9685_module_data::initialize() {
  clear();
}
void pca9685_module_data::clear() {
  clear_content();
}
string pca9685_module_data::print() const {
  return type_label()+","+print_content();
}
pca9685_module_data& pca9685_module_data::operator=(const pca9685_module_data& rhs) {
  state = rhs.state;
  cmd = rhs.cmd;
  local = rhs.local;
  config = rhs.config;
  calib = rhs.calib;
  return *this;
}

void pca9685_module_data::clear_content() {
  state.clear();
  cmd.clear();
  local.clear();
  config.clear();
  calib.clear();
}
string pca9685_module_data::print_content() const {
  std::ostringstream ss;
  ss << state.print();
  ss << cmd.print();
  ss << local.print();
  ss << config.print();
  ss << calib.print();
  return ss.str();
}
uint8* pca9685_module_data::serialize_content(uint8* buff) const {
  buff = state.serialize_content(buff);
  buff = cmd.serialize_content(buff);
  buff = local.serialize_content(buff);
  buff = config.serialize_content(buff);
  buff = calib.serialize_content(buff);
  return buff;
}
const uint8* pca9685_module_data::deserialize_content(const uint8* buff) {
  buff = state.deserialize_content(buff);
  buff = cmd.deserialize_content(buff);
  buff = local.deserialize_content(buff);
  buff = config.deserialize_content(buff);
  buff = calib.deserialize_content(buff);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
