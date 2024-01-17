////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/mpu6000_module_data.cpp                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/mpu6000_module_data.h"
using autogen::packet::mpu6000_module_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

mpu6000_module_data::mpu6000_module_data() :
  network::packet(autogen::type::MPU6000_MODULE_DATA) {
  initialize();
}
mpu6000_module_data::~mpu6000_module_data() {
  // No-op.
}
mpu6000_module_data::type_t mpu6000_module_data::type_index() const {
  return mc_type;
}
string mpu6000_module_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void mpu6000_module_data::initialize() {
  clear();
}
void mpu6000_module_data::clear() {
  clear_content();
}
string mpu6000_module_data::print() const {
  return type_label()+","+print_content();
}
mpu6000_module_data& mpu6000_module_data::operator=(const mpu6000_module_data& rhs) {
  state = rhs.state;
  meas = rhs.meas;
  local = rhs.local;
  config = rhs.config;
  calib = rhs.calib;
  return *this;
}

void mpu6000_module_data::clear_content() {
  state.clear();
  meas.clear();
  local.clear();
  config.clear();
  calib.clear();
}
string mpu6000_module_data::print_content() const {
  std::ostringstream ss;
  ss << state.print();
  ss << meas.print();
  ss << local.print();
  ss << config.print();
  ss << calib.print();
  return ss.str();
}
uint8* mpu6000_module_data::serialize_content(uint8* buff) const {
  buff = state.serialize_content(buff);
  buff = meas.serialize_content(buff);
  buff = local.serialize_content(buff);
  buff = config.serialize_content(buff);
  buff = calib.serialize_content(buff);
  return buff;
}
const uint8* mpu6000_module_data::deserialize_content(const uint8* buff) {
  buff = state.deserialize_content(buff);
  buff = meas.deserialize_content(buff);
  buff = local.deserialize_content(buff);
  buff = config.deserialize_content(buff);
  buff = calib.deserialize_content(buff);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
