////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/hmc5883l_config_data.cpp                                            //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/hmc5883l_config_data.h"
using autogen::parameter::hmc5883l_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

hmc5883l_config_data::hmc5883l_config_data() : network::parameter(autogen::type::HMC5883L_CONFIG_DATA) {
  initialize();
}
hmc5883l_config_data::hmc5883l_config_data(const string& filename) :
  network::parameter(autogen::type::HMC5883L_CONFIG_DATA) {
  load(filename);
}
hmc5883l_config_data::~hmc5883l_config_data() {
  // No-op.
}
hmc5883l_config_data::type_t hmc5883l_config_data::type_index() const {
  return mc_type;
}
string hmc5883l_config_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void hmc5883l_config_data::initialize() {
  clear();
}
void hmc5883l_config_data::clear() {
  clear_content();
}
string hmc5883l_config_data::print() const {
  return type_label()+","+print_content();
}
void hmc5883l_config_data::convert() {
  dev2body_angle_1 = (dev2body_angle_1_deg*0.017453292519943f);
  dev2body_angle_2 = (dev2body_angle_2_deg*0.017453292519943f);
  dev2body_angle_3 = (dev2body_angle_3_deg*0.017453292519943f);
}
void hmc5883l_config_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::hmc5883l_config_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void hmc5883l_config_data::save(const string& filename) const {
  utilities::message("autogen::parameter::hmc5883l_config_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
hmc5883l_config_data& hmc5883l_config_data::operator=(const hmc5883l_config_data& rhs) {
  op_mode = rhs.op_mode;
  avg_samp = rhs.avg_samp;
  rate = rhs.rate;
  meas_mode = rhs.meas_mode;
  fs_mag = rhs.fs_mag;
  n_calib_samples = rhs.n_calib_samples;
  dev2body_angle_1_deg = rhs.dev2body_angle_1_deg;
  dev2body_angle_2_deg = rhs.dev2body_angle_2_deg;
  dev2body_angle_3_deg = rhs.dev2body_angle_3_deg;
  return *this;
}

void hmc5883l_config_data::clear_content() {
  op_mode = 0;
  avg_samp = 0;
  rate = 0;
  meas_mode = 0;
  fs_mag = 0;
  n_calib_samples = 0;
  dev2body_angle_1_deg = 0.0f;
  dev2body_angle_1 = 0.0f;
  dev2body_angle_2_deg = 0.0f;
  dev2body_angle_2 = 0.0f;
  dev2body_angle_3_deg = 0.0f;
  dev2body_angle_3 = 0.0f;
}
string hmc5883l_config_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << op_mode << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << avg_samp << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << rate << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << meas_mode << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << fs_mag << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << n_calib_samples << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << dev2body_angle_1_deg << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << dev2body_angle_2_deg << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << dev2body_angle_3_deg << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << dev2body_angle_1 << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << dev2body_angle_2 << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << dev2body_angle_3 << ",";
  return ss.str();
}
uint8* hmc5883l_config_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,op_mode,1);
  buff = network::packet::serialize(buff,avg_samp,1);
  buff = network::packet::serialize(buff,rate,1);
  buff = network::packet::serialize(buff,meas_mode,1);
  buff = network::packet::serialize(buff,fs_mag,1);
  buff = network::packet::serialize(buff,n_calib_samples,1);
  buff = network::packet::serialize(buff,dev2body_angle_1_deg,1);
  buff = network::packet::serialize(buff,dev2body_angle_2_deg,1);
  buff = network::packet::serialize(buff,dev2body_angle_3_deg,1);
  return buff;
}
const uint8* hmc5883l_config_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,op_mode,1);
  buff = network::packet::deserialize(buff,avg_samp,1);
  buff = network::packet::deserialize(buff,rate,1);
  buff = network::packet::deserialize(buff,meas_mode,1);
  buff = network::packet::deserialize(buff,fs_mag,1);
  buff = network::packet::deserialize(buff,n_calib_samples,1);
  buff = network::packet::deserialize(buff,dev2body_angle_1_deg,1);
  buff = network::packet::deserialize(buff,dev2body_angle_2_deg,1);
  buff = network::packet::deserialize(buff,dev2body_angle_3_deg,1);
  return buff;
}
void hmc5883l_config_data::load_content(utilities::ifile& file, const string& parent) {
  file.read_uint8(parent+"op_mode",op_mode);
  file.read_uint8(parent+"avg_samp",avg_samp);
  file.read_uint8(parent+"rate",rate);
  file.read_uint8(parent+"meas_mode",meas_mode);
  file.read_uint8(parent+"fs_mag",fs_mag);
  file.read_uint32(parent+"n_calib_samples",n_calib_samples);
  file.read_float(parent+"dev2body_angle_1_deg",dev2body_angle_1_deg);
  file.read_float(parent+"dev2body_angle_2_deg",dev2body_angle_2_deg);
  file.read_float(parent+"dev2body_angle_3_deg",dev2body_angle_3_deg);
}
void hmc5883l_config_data::save_content(utilities::ofile& file, const string& parent) const {
  file.write_uint8(parent+"op_mode",op_mode);
  file.write_uint8(parent+"avg_samp",avg_samp);
  file.write_uint8(parent+"rate",rate);
  file.write_uint8(parent+"meas_mode",meas_mode);
  file.write_uint8(parent+"fs_mag",fs_mag);
  file.write_uint32(parent+"n_calib_samples",n_calib_samples);
  file.write_float(parent+"dev2body_angle_1_deg",dev2body_angle_1_deg);
  file.write_float(parent+"dev2body_angle_2_deg",dev2body_angle_2_deg);
  file.write_float(parent+"dev2body_angle_3_deg",dev2body_angle_3_deg);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
