////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/fm_cmd_data.cpp                                                        //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/fm_cmd_data.h"
using autogen::packet::fm_cmd_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

fm_cmd_data::fm_cmd_data() :
  network::packet(autogen::type::FM_CMD_DATA) {
  initialize();
}
fm_cmd_data::~fm_cmd_data() {
  // No-op.
}
fm_cmd_data::type_t fm_cmd_data::type_index() const {
  return mc_type;
}
string fm_cmd_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void fm_cmd_data::initialize() {
  clear();
}
void fm_cmd_data::clear() {
  clear_content();
}
string fm_cmd_data::print() const {
  return type_label()+","+print_content();
}
fm_cmd_data& fm_cmd_data::operator=(const fm_cmd_data& rhs) {
  exit_loop = rhs.exit_loop;
  states = rhs.states;
  led_solid = rhs.led_solid;
  led_blinking = rhs.led_blinking;
  led_spinning = rhs.led_spinning;
  led_progress = rhs.led_progress;
  led_nav = rhs.led_nav;
  return *this;
}

void fm_cmd_data::clear_content() {
  exit_loop = 0;
  states.clear();
  led_solid.clear();
  led_blinking.clear();
  led_spinning.clear();
  led_progress.clear();
  led_nav.clear();
}
string fm_cmd_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << exit_loop << ",";
  ss << states.print();
  ss << led_solid.print();
  ss << led_blinking.print();
  ss << led_spinning.print();
  ss << led_progress.print();
  ss << led_nav.print();
  return ss.str();
}
uint8* fm_cmd_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,exit_loop,1);
  buff = states.serialize_content(buff);
  buff = led_solid.serialize_content(buff);
  buff = led_blinking.serialize_content(buff);
  buff = led_spinning.serialize_content(buff);
  buff = led_progress.serialize_content(buff);
  buff = led_nav.serialize_content(buff);
  return buff;
}
const uint8* fm_cmd_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,exit_loop,1);
  buff = states.deserialize_content(buff);
  buff = led_solid.deserialize_content(buff);
  buff = led_blinking.deserialize_content(buff);
  buff = led_spinning.deserialize_content(buff);
  buff = led_progress.deserialize_content(buff);
  buff = led_nav.deserialize_content(buff);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
