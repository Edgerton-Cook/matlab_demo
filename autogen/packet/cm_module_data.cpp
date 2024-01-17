////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/cm_module_data.cpp                                                     //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/cm_module_data.h"
using autogen::packet::cm_module_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

cm_module_data::cm_module_data() :
  network::packet(autogen::type::CM_MODULE_DATA) {
  initialize();
}
cm_module_data::~cm_module_data() {
  // No-op.
}
cm_module_data::type_t cm_module_data::type_index() const {
  return mc_type;
}
string cm_module_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void cm_module_data::initialize() {
  clear();
}
void cm_module_data::clear() {
  clear_content();
}
string cm_module_data::print() const {
  return type_label()+","+print_content();
}
cm_module_data& cm_module_data::operator=(const cm_module_data& rhs) {
  state = rhs.state;
  uplink = rhs.uplink;
  local = rhs.local;
  config = rhs.config;
  return *this;
}

void cm_module_data::clear_content() {
  state.clear();
  uplink.clear();
  local.clear();
  config.clear();
}
string cm_module_data::print_content() const {
  std::ostringstream ss;
  ss << state.print();
  ss << uplink.print();
  ss << local.print();
  ss << config.print();
  return ss.str();
}
uint8* cm_module_data::serialize_content(uint8* buff) const {
  buff = state.serialize_content(buff);
  buff = uplink.serialize_content(buff);
  buff = local.serialize_content(buff);
  buff = config.serialize_content(buff);
  return buff;
}
const uint8* cm_module_data::deserialize_content(const uint8* buff) {
  buff = state.deserialize_content(buff);
  buff = uplink.deserialize_content(buff);
  buff = local.deserialize_content(buff);
  buff = config.deserialize_content(buff);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
