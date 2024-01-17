////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/power_module_data.cpp                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/power_module_data.h"
using autogen::packet::power_module_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

power_module_data::power_module_data() :
  network::packet(autogen::type::POWER_MODULE_DATA) {
  initialize();
}
power_module_data::~power_module_data() {
  // No-op.
}
power_module_data::type_t power_module_data::type_index() const {
  return mc_type;
}
string power_module_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void power_module_data::initialize() {
  clear();
}
void power_module_data::clear() {
  clear_content();
}
string power_module_data::print() const {
  return type_label()+","+print_content();
}
power_module_data& power_module_data::operator=(const power_module_data& rhs) {
  state = rhs.state;
  meas = rhs.meas;
  calib = rhs.calib;
  return *this;
}

void power_module_data::clear_content() {
  state.clear();
  meas.clear();
  calib.clear();
}
string power_module_data::print_content() const {
  std::ostringstream ss;
  ss << state.print();
  ss << meas.print();
  ss << calib.print();
  return ss.str();
}
uint8* power_module_data::serialize_content(uint8* buff) const {
  buff = state.serialize_content(buff);
  buff = meas.serialize_content(buff);
  buff = calib.serialize_content(buff);
  return buff;
}
const uint8* power_module_data::deserialize_content(const uint8* buff) {
  buff = state.deserialize_content(buff);
  buff = meas.deserialize_content(buff);
  buff = calib.deserialize_content(buff);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
