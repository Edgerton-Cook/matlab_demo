////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/edison_config_data.cpp                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/edison_config_data.h"
using autogen::parameter::edison_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

edison_config_data::edison_config_data() : network::parameter(autogen::type::EDISON_CONFIG_DATA) {
  initialize();
}
edison_config_data::edison_config_data(const string& filename) :
  network::parameter(autogen::type::EDISON_CONFIG_DATA) {
  load(filename);
}
edison_config_data::~edison_config_data() {
  // No-op.
}
edison_config_data::type_t edison_config_data::type_index() const {
  return mc_type;
}
string edison_config_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void edison_config_data::initialize() {
  clear();
}
void edison_config_data::clear() {
  clear_content();
}
string edison_config_data::print() const {
  return type_label()+","+print_content();
}
void edison_config_data::convert() {
}
void edison_config_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::edison_config_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void edison_config_data::save(const string& filename) const {
  utilities::message("autogen::parameter::edison_config_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
edison_config_data& edison_config_data::operator=(const edison_config_data& rhs) {
  altimeter_i2c_en = rhs.altimeter_i2c_en;
  i2c_1_en = rhs.i2c_1_en;
  i2c_2_en = rhs.i2c_2_en;
  spi_1_en = rhs.spi_1_en;
  spi_2_en = rhs.spi_2_en;
  uart_en = rhs.uart_en;
  pwm_gpio_ch = rhs.pwm_gpio_ch;
  timeout_msec = rhs.timeout_msec;
  return *this;
}

void edison_config_data::clear_content() {
  altimeter_i2c_en = 0;
  i2c_1_en = 0;
  i2c_2_en = 0;
  spi_1_en = 0;
  spi_2_en = 0;
  uart_en = 0;
  pwm_gpio_ch = 0;
  timeout_msec = 0;
}
string edison_config_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << altimeter_i2c_en << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << i2c_1_en << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << i2c_2_en << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << spi_1_en << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << spi_2_en << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << uart_en << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << pwm_gpio_ch << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << timeout_msec << ",";
  return ss.str();
}
uint8* edison_config_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,altimeter_i2c_en,1);
  buff = network::packet::serialize(buff,i2c_1_en,1);
  buff = network::packet::serialize(buff,i2c_2_en,1);
  buff = network::packet::serialize(buff,spi_1_en,1);
  buff = network::packet::serialize(buff,spi_2_en,1);
  buff = network::packet::serialize(buff,uart_en,1);
  buff = network::packet::serialize(buff,pwm_gpio_ch,1);
  buff = network::packet::serialize(buff,timeout_msec,1);
  return buff;
}
const uint8* edison_config_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,altimeter_i2c_en,1);
  buff = network::packet::deserialize(buff,i2c_1_en,1);
  buff = network::packet::deserialize(buff,i2c_2_en,1);
  buff = network::packet::deserialize(buff,spi_1_en,1);
  buff = network::packet::deserialize(buff,spi_2_en,1);
  buff = network::packet::deserialize(buff,uart_en,1);
  buff = network::packet::deserialize(buff,pwm_gpio_ch,1);
  buff = network::packet::deserialize(buff,timeout_msec,1);
  return buff;
}
void edison_config_data::load_content(utilities::ifile& file, const string& parent) {
  file.read_bool(parent+"altimeter_i2c_en",altimeter_i2c_en);
  file.read_bool(parent+"i2c_1_en",i2c_1_en);
  file.read_bool(parent+"i2c_2_en",i2c_2_en);
  file.read_bool(parent+"spi_1_en",spi_1_en);
  file.read_bool(parent+"spi_2_en",spi_2_en);
  file.read_bool(parent+"uart_en",uart_en);
  file.read_uint8(parent+"pwm_gpio_ch",pwm_gpio_ch);
  file.read_uint8(parent+"timeout_msec",timeout_msec);
}
void edison_config_data::save_content(utilities::ofile& file, const string& parent) const {
  file.write_bool(parent+"altimeter_i2c_en",altimeter_i2c_en);
  file.write_bool(parent+"i2c_1_en",i2c_1_en);
  file.write_bool(parent+"i2c_2_en",i2c_2_en);
  file.write_bool(parent+"spi_1_en",spi_1_en);
  file.write_bool(parent+"spi_2_en",spi_2_en);
  file.write_bool(parent+"uart_en",uart_en);
  file.write_uint8(parent+"pwm_gpio_ch",pwm_gpio_ch);
  file.write_uint8(parent+"timeout_msec",timeout_msec);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
