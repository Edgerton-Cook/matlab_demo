////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/neom8_module_data.cpp                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/neom8_module_data.h"
using autogen::packet::neom8_module_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

neom8_module_data::neom8_module_data() :
  network::packet(autogen::type::NEOM8_MODULE_DATA) {
  initialize();
}
neom8_module_data::~neom8_module_data() {
  // No-op.
}
neom8_module_data::type_t neom8_module_data::type_index() const {
  return mc_type;
}
string neom8_module_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void neom8_module_data::initialize() {
  clear();
}
void neom8_module_data::clear() {
  clear_content();
}
string neom8_module_data::print() const {
  return type_label()+","+print_content();
}
neom8_module_data& neom8_module_data::operator=(const neom8_module_data& rhs) {
  state = rhs.state;
  meas = rhs.meas;
  local = rhs.local;
  config = rhs.config;
  return *this;
}

void neom8_module_data::clear_content() {
  state.clear();
  meas.clear();
  local.clear();
  config.clear();
}
string neom8_module_data::print_content() const {
  std::ostringstream ss;
  ss << state.print();
  ss << meas.print();
  ss << local.print();
  ss << config.print();
  return ss.str();
}
uint8* neom8_module_data::serialize_content(uint8* buff) const {
  buff = state.serialize_content(buff);
  buff = meas.serialize_content(buff);
  buff = local.serialize_content(buff);
  buff = config.serialize_content(buff);
  return buff;
}
const uint8* neom8_module_data::deserialize_content(const uint8* buff) {
  buff = state.deserialize_content(buff);
  buff = meas.deserialize_content(buff);
  buff = local.deserialize_content(buff);
  buff = config.deserialize_content(buff);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
