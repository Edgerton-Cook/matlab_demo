////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/mpu6000_config_data.cpp                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/mpu6000_config_data.h"
using autogen::parameter::mpu6000_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

mpu6000_config_data::mpu6000_config_data() : network::parameter(autogen::type::MPU6000_CONFIG_DATA) {
  initialize();
}
mpu6000_config_data::mpu6000_config_data(const string& filename) :
  network::parameter(autogen::type::MPU6000_CONFIG_DATA) {
  load(filename);
}
mpu6000_config_data::~mpu6000_config_data() {
  // No-op.
}
mpu6000_config_data::type_t mpu6000_config_data::type_index() const {
  return mc_type;
}
string mpu6000_config_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void mpu6000_config_data::initialize() {
  clear();
}
void mpu6000_config_data::clear() {
  clear_content();
}
string mpu6000_config_data::print() const {
  return type_label()+","+print_content();
}
void mpu6000_config_data::convert() {
  dev2body_angle_1 = (dev2body_angle_1_deg*0.017453292519943f);
  dev2body_angle_2 = (dev2body_angle_2_deg*0.017453292519943f);
  dev2body_angle_3 = (dev2body_angle_3_deg*0.017453292519943f);
}
void mpu6000_config_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::mpu6000_config_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void mpu6000_config_data::save(const string& filename) const {
  utilities::message("autogen::parameter::mpu6000_config_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
mpu6000_config_data& mpu6000_config_data::operator=(const mpu6000_config_data& rhs) {
  spi_bus_speed = rhs.spi_bus_speed;
  dlpf_cfg = rhs.dlpf_cfg;
  sample_rate_div = rhs.sample_rate_div;
  accl_fs = rhs.accl_fs;
  gyro_fs = rhs.gyro_fs;
  n_calib_samples = rhs.n_calib_samples;
  dev2body_angle_1_deg = rhs.dev2body_angle_1_deg;
  dev2body_angle_2_deg = rhs.dev2body_angle_2_deg;
  dev2body_angle_3_deg = rhs.dev2body_angle_3_deg;
  return *this;
}

void mpu6000_config_data::clear_content() {
  spi_bus_speed = 0;
  dlpf_cfg = 0;
  sample_rate_div = 0;
  accl_fs = 0;
  gyro_fs = 0;
  n_calib_samples = 0;
  dev2body_angle_1_deg = 0.0f;
  dev2body_angle_1 = 0.0f;
  dev2body_angle_2_deg = 0.0f;
  dev2body_angle_2 = 0.0f;
  dev2body_angle_3_deg = 0.0f;
  dev2body_angle_3 = 0.0f;
}
string mpu6000_config_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << spi_bus_speed << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << dlpf_cfg << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << sample_rate_div << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << accl_fs << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << gyro_fs << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << n_calib_samples << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << dev2body_angle_1_deg << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << dev2body_angle_2_deg << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << dev2body_angle_3_deg << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << dev2body_angle_1 << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << dev2body_angle_2 << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << dev2body_angle_3 << ",";
  return ss.str();
}
uint8* mpu6000_config_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,spi_bus_speed,1);
  buff = network::packet::serialize(buff,dlpf_cfg,1);
  buff = network::packet::serialize(buff,sample_rate_div,1);
  buff = network::packet::serialize(buff,accl_fs,1);
  buff = network::packet::serialize(buff,gyro_fs,1);
  buff = network::packet::serialize(buff,n_calib_samples,1);
  buff = network::packet::serialize(buff,dev2body_angle_1_deg,1);
  buff = network::packet::serialize(buff,dev2body_angle_2_deg,1);
  buff = network::packet::serialize(buff,dev2body_angle_3_deg,1);
  return buff;
}
const uint8* mpu6000_config_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,spi_bus_speed,1);
  buff = network::packet::deserialize(buff,dlpf_cfg,1);
  buff = network::packet::deserialize(buff,sample_rate_div,1);
  buff = network::packet::deserialize(buff,accl_fs,1);
  buff = network::packet::deserialize(buff,gyro_fs,1);
  buff = network::packet::deserialize(buff,n_calib_samples,1);
  buff = network::packet::deserialize(buff,dev2body_angle_1_deg,1);
  buff = network::packet::deserialize(buff,dev2body_angle_2_deg,1);
  buff = network::packet::deserialize(buff,dev2body_angle_3_deg,1);
  return buff;
}
void mpu6000_config_data::load_content(utilities::ifile& file, const string& parent) {
  file.read_uint32(parent+"spi_bus_speed",spi_bus_speed);
  file.read_uint8(parent+"dlpf_cfg",dlpf_cfg);
  file.read_uint8(parent+"sample_rate_div",sample_rate_div);
  file.read_uint8(parent+"accl_fs",accl_fs);
  file.read_uint8(parent+"gyro_fs",gyro_fs);
  file.read_uint32(parent+"n_calib_samples",n_calib_samples);
  file.read_float(parent+"dev2body_angle_1_deg",dev2body_angle_1_deg);
  file.read_float(parent+"dev2body_angle_2_deg",dev2body_angle_2_deg);
  file.read_float(parent+"dev2body_angle_3_deg",dev2body_angle_3_deg);
}
void mpu6000_config_data::save_content(utilities::ofile& file, const string& parent) const {
  file.write_uint32(parent+"spi_bus_speed",spi_bus_speed);
  file.write_uint8(parent+"dlpf_cfg",dlpf_cfg);
  file.write_uint8(parent+"sample_rate_div",sample_rate_div);
  file.write_uint8(parent+"accl_fs",accl_fs);
  file.write_uint8(parent+"gyro_fs",gyro_fs);
  file.write_uint32(parent+"n_calib_samples",n_calib_samples);
  file.write_float(parent+"dev2body_angle_1_deg",dev2body_angle_1_deg);
  file.write_float(parent+"dev2body_angle_2_deg",dev2body_angle_2_deg);
  file.write_float(parent+"dev2body_angle_3_deg",dev2body_angle_3_deg);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
