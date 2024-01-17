////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/led_cmd_data.cpp                                                       //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/led_cmd_data.h"
using autogen::packet::led_cmd_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

led_cmd_data::led_cmd_data() :
  network::packet(autogen::type::LED_CMD_DATA) {
  initialize();
}
led_cmd_data::~led_cmd_data() {
  // No-op.
}
led_cmd_data::type_t led_cmd_data::type_index() const {
  return mc_type;
}
string led_cmd_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void led_cmd_data::initialize() {
  clear();
}
void led_cmd_data::clear() {
  clear_content();
}
string led_cmd_data::print() const {
  return type_label()+","+print_content();
}
led_cmd_data& led_cmd_data::operator=(const led_cmd_data& rhs) {
  memcpy(apa102c_buffer,rhs.apa102c_buffer,72);
  apa102c_n_bytes = rhs.apa102c_n_bytes;
  ir_led_pwm = rhs.ir_led_pwm;
  return *this;
}

void led_cmd_data::clear_content() {
  memset(apa102c_buffer,0,72);
  apa102c_n_bytes = 0;
  ir_led_pwm = gnc::matrix<float,12,1>();
}
string led_cmd_data::print_content() const {
  std::ostringstream ss;
  for (uint32 mpac_ijk0=0; mpac_ijk0<72; ++mpac_ijk0) {
    ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << apa102c_buffer[mpac_ijk0] << ",";;
  }
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << apa102c_n_bytes << ",";
  for (uint32 mpac_ijk1=0; mpac_ijk1<12; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << ir_led_pwm.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* led_cmd_data::serialize_content(uint8* buff) const {
  for (uint32 mpac_ijk0=0; mpac_ijk0<72; ++mpac_ijk0) {
    buff = network::packet::serialize(buff,apa102c_buffer[mpac_ijk0],72);;
  }
  buff = network::packet::serialize(buff,apa102c_n_bytes,1);
  buff = network::packet::serialize(buff,ir_led_pwm.buff()[0],12);
  return buff;
}
const uint8* led_cmd_data::deserialize_content(const uint8* buff) {
  for (uint32 mpac_ijk0=0; mpac_ijk0<72; ++mpac_ijk0) {
    buff = network::packet::deserialize(buff,apa102c_buffer[mpac_ijk0],72);;
  }
  buff = network::packet::deserialize(buff,apa102c_n_bytes,1);
  buff = network::packet::deserialize(buff,ir_led_pwm.buff()[0],12);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
