////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/estimation_module_data.cpp                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/estimation_module_data.h"
using autogen::packet::estimation_module_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

estimation_module_data::estimation_module_data() :
  network::packet(autogen::type::ESTIMATION_MODULE_DATA) {
  initialize();
}
estimation_module_data::~estimation_module_data() {
  // No-op.
}
estimation_module_data::type_t estimation_module_data::type_index() const {
  return mc_type;
}
string estimation_module_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void estimation_module_data::initialize() {
  clear();
}
void estimation_module_data::clear() {
  clear_content();
}
string estimation_module_data::print() const {
  return type_label()+","+print_content();
}
estimation_module_data& estimation_module_data::operator=(const estimation_module_data& rhs) {
  state = rhs.state;
  sig = rhs.sig;
  local = rhs.local;
  config = rhs.config;
  return *this;
}

void estimation_module_data::clear_content() {
  state.clear();
  sig.clear();
  local.clear();
  config.clear();
}
string estimation_module_data::print_content() const {
  std::ostringstream ss;
  ss << state.print();
  ss << sig.print();
  ss << local.print();
  ss << config.print();
  return ss.str();
}
uint8* estimation_module_data::serialize_content(uint8* buff) const {
  buff = state.serialize_content(buff);
  buff = sig.serialize_content(buff);
  buff = local.serialize_content(buff);
  buff = config.serialize_content(buff);
  return buff;
}
const uint8* estimation_module_data::deserialize_content(const uint8* buff) {
  buff = state.deserialize_content(buff);
  buff = sig.deserialize_content(buff);
  buff = local.deserialize_content(buff);
  buff = config.deserialize_content(buff);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
