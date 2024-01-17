////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/led_cmd_nav.cpp                                                        //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/led_cmd_nav.h"
using autogen::packet::led_cmd_nav;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

led_cmd_nav::led_cmd_nav() :
  network::packet(autogen::type::LED_CMD_NAV) {
  initialize();
}
led_cmd_nav::~led_cmd_nav() {
  // No-op.
}
led_cmd_nav::type_t led_cmd_nav::type_index() const {
  return mc_type;
}
string led_cmd_nav::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void led_cmd_nav::initialize() {
  clear();
}
void led_cmd_nav::clear() {
  clear_content();
}
string led_cmd_nav::print() const {
  return type_label()+","+print_content();
}
led_cmd_nav& led_cmd_nav::operator=(const led_cmd_nav& rhs) {
  freq = rhs.freq;
  global = rhs.global;
  strobe_intensity = rhs.strobe_intensity;
  return *this;
}

void led_cmd_nav::clear_content() {
  freq = 0.0f;
  global = 0;
  strobe_intensity = 0;
}
string led_cmd_nav::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << freq << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << global << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << strobe_intensity << ",";
  return ss.str();
}
uint8* led_cmd_nav::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,freq,1);
  buff = network::packet::serialize(buff,global,1);
  buff = network::packet::serialize(buff,strobe_intensity,1);
  return buff;
}
const uint8* led_cmd_nav::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,freq,1);
  buff = network::packet::deserialize(buff,global,1);
  buff = network::packet::deserialize(buff,strobe_intensity,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
