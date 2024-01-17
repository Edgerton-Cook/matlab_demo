////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/led_module_data.cpp                                                    //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/led_module_data.h"
using autogen::packet::led_module_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

led_module_data::led_module_data() :
  network::packet(autogen::type::LED_MODULE_DATA) {
  initialize();
}
led_module_data::~led_module_data() {
  // No-op.
}
led_module_data::type_t led_module_data::type_index() const {
  return mc_type;
}
string led_module_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void led_module_data::initialize() {
  clear();
}
void led_module_data::clear() {
  clear_content();
}
string led_module_data::print() const {
  return type_label()+","+print_content();
}
led_module_data& led_module_data::operator=(const led_module_data& rhs) {
  state = rhs.state;
  cmd = rhs.cmd;
  config = rhs.config;
  return *this;
}

void led_module_data::clear_content() {
  state.clear();
  cmd.clear();
  config.clear();
}
string led_module_data::print_content() const {
  std::ostringstream ss;
  ss << state.print();
  ss << cmd.print();
  ss << config.print();
  return ss.str();
}
uint8* led_module_data::serialize_content(uint8* buff) const {
  buff = state.serialize_content(buff);
  buff = cmd.serialize_content(buff);
  buff = config.serialize_content(buff);
  return buff;
}
const uint8* led_module_data::deserialize_content(const uint8* buff) {
  buff = state.deserialize_content(buff);
  buff = cmd.deserialize_content(buff);
  buff = config.deserialize_content(buff);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
