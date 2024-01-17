////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/estimation_config_data.cpp                                          //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/estimation_config_data.h"
using autogen::parameter::estimation_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

estimation_config_data::estimation_config_data() : network::parameter(autogen::type::ESTIMATION_CONFIG_DATA) {
  initialize();
}
estimation_config_data::estimation_config_data(const string& filename) :
  network::parameter(autogen::type::ESTIMATION_CONFIG_DATA) {
  load(filename);
}
estimation_config_data::~estimation_config_data() {
  // No-op.
}
estimation_config_data::type_t estimation_config_data::type_index() const {
  return mc_type;
}
string estimation_config_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void estimation_config_data::initialize() {
  clear();
}
void estimation_config_data::clear() {
  clear_content();
}
string estimation_config_data::print() const {
  return type_label()+","+print_content();
}
void estimation_config_data::convert() {
  mag_dec = (mag_dec_deg*0.017453292519943f);
}
void estimation_config_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::estimation_config_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void estimation_config_data::save(const string& filename) const {
  utilities::message("autogen::parameter::estimation_config_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
estimation_config_data& estimation_config_data::operator=(const estimation_config_data& rhs) {
  beta_grav = rhs.beta_grav;
  beta_mag = rhs.beta_mag;
  zeta_gyro_bias = rhs.zeta_gyro_bias;
  grav_update_threshold_gs = rhs.grav_update_threshold_gs;
  mag_dec_deg = rhs.mag_dec_deg;
  return *this;
}

void estimation_config_data::clear_content() {
  beta_grav = 0.0f;
  beta_mag = 0.0f;
  zeta_gyro_bias = 0.0f;
  grav_update_threshold_gs = 0.0f;
  mag_dec_deg = 0.0f;
  mag_dec = 0.0f;
}
string estimation_config_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << beta_grav << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << beta_mag << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << zeta_gyro_bias << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << grav_update_threshold_gs << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << mag_dec_deg << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << mag_dec << ",";
  return ss.str();
}
uint8* estimation_config_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,beta_grav,1);
  buff = network::packet::serialize(buff,beta_mag,1);
  buff = network::packet::serialize(buff,zeta_gyro_bias,1);
  buff = network::packet::serialize(buff,grav_update_threshold_gs,1);
  buff = network::packet::serialize(buff,mag_dec_deg,1);
  return buff;
}
const uint8* estimation_config_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,beta_grav,1);
  buff = network::packet::deserialize(buff,beta_mag,1);
  buff = network::packet::deserialize(buff,zeta_gyro_bias,1);
  buff = network::packet::deserialize(buff,grav_update_threshold_gs,1);
  buff = network::packet::deserialize(buff,mag_dec_deg,1);
  return buff;
}
void estimation_config_data::load_content(utilities::ifile& file, const string& parent) {
  file.read_float(parent+"beta_grav",beta_grav);
  file.read_float(parent+"beta_mag",beta_mag);
  file.read_float(parent+"zeta_gyro_bias",zeta_gyro_bias);
  file.read_float(parent+"grav_update_threshold_gs",grav_update_threshold_gs);
  file.read_float(parent+"mag_dec_deg",mag_dec_deg);
}
void estimation_config_data::save_content(utilities::ofile& file, const string& parent) const {
  file.write_float(parent+"beta_grav",beta_grav);
  file.write_float(parent+"beta_mag",beta_mag);
  file.write_float(parent+"zeta_gyro_bias",zeta_gyro_bias);
  file.write_float(parent+"grav_update_threshold_gs",grav_update_threshold_gs);
  file.write_float(parent+"mag_dec_deg",mag_dec_deg);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
