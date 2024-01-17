////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/sc18is602b_module_data.cpp                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/sc18is602b_module_data.h"
using autogen::packet::sc18is602b_module_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

sc18is602b_module_data::sc18is602b_module_data() :
  network::packet(autogen::type::SC18IS602B_MODULE_DATA) {
  initialize();
}
sc18is602b_module_data::~sc18is602b_module_data() {
  // No-op.
}
sc18is602b_module_data::type_t sc18is602b_module_data::type_index() const {
  return mc_type;
}
string sc18is602b_module_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void sc18is602b_module_data::initialize() {
  clear();
}
void sc18is602b_module_data::clear() {
  clear_content();
}
string sc18is602b_module_data::print() const {
  return type_label()+","+print_content();
}
sc18is602b_module_data& sc18is602b_module_data::operator=(const sc18is602b_module_data& rhs) {
  state = rhs.state;
  local = rhs.local;
  config = rhs.config;
  return *this;
}

void sc18is602b_module_data::clear_content() {
  state.clear();
  local.clear();
  config.clear();
}
string sc18is602b_module_data::print_content() const {
  std::ostringstream ss;
  ss << state.print();
  ss << local.print();
  ss << config.print();
  return ss.str();
}
uint8* sc18is602b_module_data::serialize_content(uint8* buff) const {
  buff = state.serialize_content(buff);
  buff = local.serialize_content(buff);
  buff = config.serialize_content(buff);
  return buff;
}
const uint8* sc18is602b_module_data::deserialize_content(const uint8* buff) {
  buff = state.deserialize_content(buff);
  buff = local.deserialize_content(buff);
  buff = config.deserialize_content(buff);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
