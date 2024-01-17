////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/led_config_data.cpp                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/led_config_data.h"
using autogen::parameter::led_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

led_config_data::led_config_data() : network::parameter(autogen::type::LED_CONFIG_DATA) {
  initialize();
}
led_config_data::led_config_data(const string& filename) :
  network::parameter(autogen::type::LED_CONFIG_DATA) {
  load(filename);
}
led_config_data::~led_config_data() {
  // No-op.
}
led_config_data::type_t led_config_data::type_index() const {
  return mc_type;
}
string led_config_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void led_config_data::initialize() {
  clear();
}
void led_config_data::clear() {
  clear_content();
}
string led_config_data::print() const {
  return type_label()+","+print_content();
}
void led_config_data::convert() {
}
void led_config_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::led_config_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void led_config_data::save(const string& filename) const {
  utilities::message("autogen::parameter::led_config_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
led_config_data& led_config_data::operator=(const led_config_data& rhs) {
  ir_led_intensity = rhs.ir_led_intensity;
  memcpy(ir_led_status,rhs.ir_led_status,12);
  return *this;
}

void led_config_data::clear_content() {
  ir_led_intensity = 0;
  memset(ir_led_status,0,12);
}
string led_config_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << ir_led_intensity << ",";
  for (uint32 mpac_ijk0=0; mpac_ijk0<12; ++mpac_ijk0) {
    ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << ir_led_status[mpac_ijk0] << ",";;
  }
  return ss.str();
}
uint8* led_config_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,ir_led_intensity,1);
  for (uint32 mpac_ijk0=0; mpac_ijk0<12; ++mpac_ijk0) {
    buff = network::packet::serialize(buff,ir_led_status[mpac_ijk0],12);;
  }
  return buff;
}
const uint8* led_config_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,ir_led_intensity,1);
  for (uint32 mpac_ijk0=0; mpac_ijk0<12; ++mpac_ijk0) {
    buff = network::packet::deserialize(buff,ir_led_status[mpac_ijk0],12);;
  }
  return buff;
}
void led_config_data::load_content(utilities::ifile& file, const string& parent) {
  file.read_uint8(parent+"ir_led_intensity",ir_led_intensity);
  for (uint32 mpac_ijk0=0; mpac_ijk0<12; ++mpac_ijk0) {
    std::ostringstream idx_ss;
    idx_ss << "[" << mpac_ijk0 << "]";
    file.read_bool(parent+"ir_led_status"+idx_ss.str(),ir_led_status[mpac_ijk0]);
  }
}
void led_config_data::save_content(utilities::ofile& file, const string& parent) const {
  file.write_uint8(parent+"ir_led_intensity",ir_led_intensity);
  for (uint32 mpac_ijk0=0; mpac_ijk0<12; ++mpac_ijk0) {
    std::ostringstream idx_ss;
    idx_ss << "[" << mpac_ijk0 << "]";
    file.write_bool(parent+"ir_led_status"+idx_ss.str(),ir_led_status[mpac_ijk0]);
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
