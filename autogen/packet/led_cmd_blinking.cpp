////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/led_cmd_blinking.cpp                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/led_cmd_blinking.h"
using autogen::packet::led_cmd_blinking;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

led_cmd_blinking::led_cmd_blinking() :
  network::packet(autogen::type::LED_CMD_BLINKING) {
  initialize();
}
led_cmd_blinking::~led_cmd_blinking() {
  // No-op.
}
led_cmd_blinking::type_t led_cmd_blinking::type_index() const {
  return mc_type;
}
string led_cmd_blinking::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void led_cmd_blinking::initialize() {
  clear();
}
void led_cmd_blinking::clear() {
  clear_content();
}
string led_cmd_blinking::print() const {
  return type_label()+","+print_content();
}
led_cmd_blinking& led_cmd_blinking::operator=(const led_cmd_blinking& rhs) {
  t = rhs.t;
  freq = rhs.freq;
  global = rhs.global;
  red = rhs.red;
  green = rhs.green;
  blue = rhs.blue;
  return *this;
}

void led_cmd_blinking::clear_content() {
  t = 0.0f;
  freq = 0.0f;
  global = 0;
  red = 0;
  green = 0;
  blue = 0;
}
string led_cmd_blinking::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << t << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << freq << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << global << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << red << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << green << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << blue << ",";
  return ss.str();
}
uint8* led_cmd_blinking::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,t,1);
  buff = network::packet::serialize(buff,freq,1);
  buff = network::packet::serialize(buff,global,1);
  buff = network::packet::serialize(buff,red,1);
  buff = network::packet::serialize(buff,green,1);
  buff = network::packet::serialize(buff,blue,1);
  return buff;
}
const uint8* led_cmd_blinking::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,t,1);
  buff = network::packet::deserialize(buff,freq,1);
  buff = network::packet::deserialize(buff,global,1);
  buff = network::packet::deserialize(buff,red,1);
  buff = network::packet::deserialize(buff,green,1);
  buff = network::packet::deserialize(buff,blue,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
