////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/max11644eua_module_data.cpp                                            //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/max11644eua_module_data.h"
using autogen::packet::max11644eua_module_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

max11644eua_module_data::max11644eua_module_data() :
  network::packet(autogen::type::MAX11644EUA_MODULE_DATA) {
  initialize();
}
max11644eua_module_data::~max11644eua_module_data() {
  // No-op.
}
max11644eua_module_data::type_t max11644eua_module_data::type_index() const {
  return mc_type;
}
string max11644eua_module_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void max11644eua_module_data::initialize() {
  clear();
}
void max11644eua_module_data::clear() {
  clear_content();
}
string max11644eua_module_data::print() const {
  return type_label()+","+print_content();
}
max11644eua_module_data& max11644eua_module_data::operator=(const max11644eua_module_data& rhs) {
  state = rhs.state;
  meas = rhs.meas;
  local = rhs.local;
  return *this;
}

void max11644eua_module_data::clear_content() {
  state.clear();
  meas.clear();
  local.clear();
}
string max11644eua_module_data::print_content() const {
  std::ostringstream ss;
  ss << state.print();
  ss << meas.print();
  ss << local.print();
  return ss.str();
}
uint8* max11644eua_module_data::serialize_content(uint8* buff) const {
  buff = state.serialize_content(buff);
  buff = meas.serialize_content(buff);
  buff = local.serialize_content(buff);
  return buff;
}
const uint8* max11644eua_module_data::deserialize_content(const uint8* buff) {
  buff = state.deserialize_content(buff);
  buff = meas.deserialize_content(buff);
  buff = local.deserialize_content(buff);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
