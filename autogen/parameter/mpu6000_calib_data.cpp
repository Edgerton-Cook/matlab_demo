////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/mpu6000_calib_data.cpp                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/mpu6000_calib_data.h"
using autogen::parameter::mpu6000_calib_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

mpu6000_calib_data::mpu6000_calib_data() : network::parameter(autogen::type::MPU6000_CALIB_DATA) {
  initialize();
}
mpu6000_calib_data::mpu6000_calib_data(const string& filename) :
  network::parameter(autogen::type::MPU6000_CALIB_DATA) {
  load(filename);
}
mpu6000_calib_data::~mpu6000_calib_data() {
  // No-op.
}
mpu6000_calib_data::type_t mpu6000_calib_data::type_index() const {
  return mc_type;
}
string mpu6000_calib_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void mpu6000_calib_data::initialize() {
  clear();
}
void mpu6000_calib_data::clear() {
  clear_content();
}
string mpu6000_calib_data::print() const {
  return type_label()+","+print_content();
}
void mpu6000_calib_data::convert() {
}
void mpu6000_calib_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::mpu6000_calib_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void mpu6000_calib_data::save(const string& filename) const {
  utilities::message("autogen::parameter::mpu6000_calib_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
mpu6000_calib_data& mpu6000_calib_data::operator=(const mpu6000_calib_data& rhs) {
  accl_bias = rhs.accl_bias;
  gyro_bias = rhs.gyro_bias;
  return *this;
}

void mpu6000_calib_data::clear_content() {
  accl_bias = gnc::matrix<float,3,1>();
  gyro_bias = gnc::matrix<float,3,1>();
}
string mpu6000_calib_data::print_content() const {
  std::ostringstream ss;
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << accl_bias.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << gyro_bias.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* mpu6000_calib_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,accl_bias.buff()[0],3);
  buff = network::packet::serialize(buff,gyro_bias.buff()[0],3);
  return buff;
}
const uint8* mpu6000_calib_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,accl_bias.buff()[0],3);
  buff = network::packet::deserialize(buff,gyro_bias.buff()[0],3);
  return buff;
}
void mpu6000_calib_data::load_content(utilities::ifile& file, const string& parent) {
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    std::ostringstream idx_str;
    idx_str << "(" << mpac_ijk1 << ")";
    file.read_float(parent+"accl_bias"+idx_str.str(),accl_bias(mpac_ijk1));
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    std::ostringstream idx_str;
    idx_str << "(" << mpac_ijk1 << ")";
    file.read_float(parent+"gyro_bias"+idx_str.str(),gyro_bias(mpac_ijk1));
  }
}
void mpu6000_calib_data::save_content(utilities::ofile& file, const string& parent) const {
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    std::ostringstream idx_str;
    idx_str << "(" << mpac_ijk1 << ")";
    file.write_float(parent+"accl_bias"+idx_str.str(),accl_bias(mpac_ijk1));
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    std::ostringstream idx_str;
    idx_str << "(" << mpac_ijk1 << ")";
    file.write_float(parent+"gyro_bias"+idx_str.str(),gyro_bias(mpac_ijk1));
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
