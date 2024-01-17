////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/rcontrol_module_data.cpp                                               //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/rcontrol_module_data.h"
using autogen::packet::rcontrol_module_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

rcontrol_module_data::rcontrol_module_data() :
  network::packet(autogen::type::RCONTROL_MODULE_DATA) {
  initialize();
}
rcontrol_module_data::~rcontrol_module_data() {
  // No-op.
}
rcontrol_module_data::type_t rcontrol_module_data::type_index() const {
  return mc_type;
}
string rcontrol_module_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void rcontrol_module_data::initialize() {
  clear();
}
void rcontrol_module_data::clear() {
  clear_content();
}
string rcontrol_module_data::print() const {
  return type_label()+","+print_content();
}
rcontrol_module_data& rcontrol_module_data::operator=(const rcontrol_module_data& rhs) {
  state = rhs.state;
  mode = rhs.mode;
  sig = rhs.sig;
  local = rhs.local;
  config = rhs.config;
  return *this;
}

void rcontrol_module_data::clear_content() {
  state.clear();
  mode.clear();
  sig.clear();
  local.clear();
  config.clear();
}
string rcontrol_module_data::print_content() const {
  std::ostringstream ss;
  ss << state.print();
  ss << mode.print();
  ss << sig.print();
  ss << local.print();
  ss << config.print();
  return ss.str();
}
uint8* rcontrol_module_data::serialize_content(uint8* buff) const {
  buff = state.serialize_content(buff);
  buff = mode.serialize_content(buff);
  buff = sig.serialize_content(buff);
  buff = local.serialize_content(buff);
  buff = config.serialize_content(buff);
  return buff;
}
const uint8* rcontrol_module_data::deserialize_content(const uint8* buff) {
  buff = state.deserialize_content(buff);
  buff = mode.deserialize_content(buff);
  buff = sig.deserialize_content(buff);
  buff = local.deserialize_content(buff);
  buff = config.deserialize_content(buff);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
