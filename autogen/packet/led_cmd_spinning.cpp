////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/led_cmd_spinning.cpp                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/led_cmd_spinning.h"
using autogen::packet::led_cmd_spinning;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

led_cmd_spinning::led_cmd_spinning() :
  network::packet(autogen::type::LED_CMD_SPINNING) {
  initialize();
}
led_cmd_spinning::~led_cmd_spinning() {
  // No-op.
}
led_cmd_spinning::type_t led_cmd_spinning::type_index() const {
  return mc_type;
}
string led_cmd_spinning::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void led_cmd_spinning::initialize() {
  clear();
}
void led_cmd_spinning::clear() {
  clear_content();
}
string led_cmd_spinning::print() const {
  return type_label()+","+print_content();
}
led_cmd_spinning& led_cmd_spinning::operator=(const led_cmd_spinning& rhs) {
  phi_r = rhs.phi_r;
  phi_g = rhs.phi_g;
  phi_b = rhs.phi_b;
  ft_r = rhs.ft_r;
  fs_r = rhs.fs_r;
  ft_g = rhs.ft_g;
  fs_g = rhs.fs_g;
  ft_b = rhs.ft_b;
  fs_b = rhs.fs_b;
  global = rhs.global;
  red = rhs.red;
  green = rhs.green;
  blue = rhs.blue;
  return *this;
}

void led_cmd_spinning::clear_content() {
  phi_r = 0.0f;
  phi_g = 0.0f;
  phi_b = 0.0f;
  ft_r = 0.0f;
  fs_r = 0.0f;
  ft_g = 0.0f;
  fs_g = 0.0f;
  ft_b = 0.0f;
  fs_b = 0.0f;
  global = 0;
  red = 0;
  green = 0;
  blue = 0;
}
string led_cmd_spinning::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << phi_r << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << phi_g << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << phi_b << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << ft_r << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << fs_r << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << ft_g << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << fs_g << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << ft_b << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << fs_b << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << global << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << red << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << green << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << blue << ",";
  return ss.str();
}
uint8* led_cmd_spinning::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,phi_r,1);
  buff = network::packet::serialize(buff,phi_g,1);
  buff = network::packet::serialize(buff,phi_b,1);
  buff = network::packet::serialize(buff,ft_r,1);
  buff = network::packet::serialize(buff,fs_r,1);
  buff = network::packet::serialize(buff,ft_g,1);
  buff = network::packet::serialize(buff,fs_g,1);
  buff = network::packet::serialize(buff,ft_b,1);
  buff = network::packet::serialize(buff,fs_b,1);
  buff = network::packet::serialize(buff,global,1);
  buff = network::packet::serialize(buff,red,1);
  buff = network::packet::serialize(buff,green,1);
  buff = network::packet::serialize(buff,blue,1);
  return buff;
}
const uint8* led_cmd_spinning::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,phi_r,1);
  buff = network::packet::deserialize(buff,phi_g,1);
  buff = network::packet::deserialize(buff,phi_b,1);
  buff = network::packet::deserialize(buff,ft_r,1);
  buff = network::packet::deserialize(buff,fs_r,1);
  buff = network::packet::deserialize(buff,ft_g,1);
  buff = network::packet::deserialize(buff,fs_g,1);
  buff = network::packet::deserialize(buff,ft_b,1);
  buff = network::packet::deserialize(buff,fs_b,1);
  buff = network::packet::deserialize(buff,global,1);
  buff = network::packet::deserialize(buff,red,1);
  buff = network::packet::deserialize(buff,green,1);
  buff = network::packet::deserialize(buff,blue,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
