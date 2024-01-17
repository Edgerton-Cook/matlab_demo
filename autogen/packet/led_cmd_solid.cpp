////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/led_cmd_solid.cpp                                                      //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/led_cmd_solid.h"
using autogen::packet::led_cmd_solid;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

led_cmd_solid::led_cmd_solid() :
  network::packet(autogen::type::LED_CMD_SOLID) {
  initialize();
}
led_cmd_solid::~led_cmd_solid() {
  // No-op.
}
led_cmd_solid::type_t led_cmd_solid::type_index() const {
  return mc_type;
}
string led_cmd_solid::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void led_cmd_solid::initialize() {
  clear();
}
void led_cmd_solid::clear() {
  clear_content();
}
string led_cmd_solid::print() const {
  return type_label()+","+print_content();
}
led_cmd_solid& led_cmd_solid::operator=(const led_cmd_solid& rhs) {
  global = rhs.global;
  red = rhs.red;
  green = rhs.green;
  blue = rhs.blue;
  return *this;
}

void led_cmd_solid::clear_content() {
  global = 0;
  red = 0;
  green = 0;
  blue = 0;
}
string led_cmd_solid::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << global << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << red << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << green << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << blue << ",";
  return ss.str();
}
uint8* led_cmd_solid::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,global,1);
  buff = network::packet::serialize(buff,red,1);
  buff = network::packet::serialize(buff,green,1);
  buff = network::packet::serialize(buff,blue,1);
  return buff;
}
const uint8* led_cmd_solid::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,global,1);
  buff = network::packet::deserialize(buff,red,1);
  buff = network::packet::deserialize(buff,green,1);
  buff = network::packet::deserialize(buff,blue,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
