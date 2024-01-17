////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/mpu6000_local_data.cpp                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/mpu6000_local_data.h"
using autogen::packet::mpu6000_local_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

mpu6000_local_data::mpu6000_local_data() :
  network::packet(autogen::type::MPU6000_LOCAL_DATA) {
  initialize();
}
mpu6000_local_data::~mpu6000_local_data() {
  // No-op.
}
mpu6000_local_data::type_t mpu6000_local_data::type_index() const {
  return mc_type;
}
string mpu6000_local_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void mpu6000_local_data::initialize() {
  clear();
}
void mpu6000_local_data::clear() {
  clear_content();
}
string mpu6000_local_data::print() const {
  return type_label()+","+print_content();
}
mpu6000_local_data& mpu6000_local_data::operator=(const mpu6000_local_data& rhs) {
  inv_accl_scale = rhs.inv_accl_scale;
  inv_gyro_scale = rhs.inv_gyro_scale;
  calibration_complete = rhs.calibration_complete;
  i_calib_sample = rhs.i_calib_sample;
  accl_bias_sum = rhs.accl_bias_sum;
  gyro_bias_sum = rhs.gyro_bias_sum;
  C_dev2body = rhs.C_dev2body;
  return *this;
}

void mpu6000_local_data::clear_content() {
  inv_accl_scale = 0.0f;
  inv_gyro_scale = 0.0f;
  calibration_complete = 0;
  i_calib_sample = 0;
  accl_bias_sum = gnc::matrix<float,3,1>();
  gyro_bias_sum = gnc::matrix<float,3,1>();
  C_dev2body = gnc::dcm();
}
string mpu6000_local_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << inv_accl_scale << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << inv_gyro_scale << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << calibration_complete << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << i_calib_sample << ",";
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << accl_bias_sum.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << gyro_bias_sum.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<9; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << C_dev2body.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* mpu6000_local_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,inv_accl_scale,1);
  buff = network::packet::serialize(buff,inv_gyro_scale,1);
  buff = network::packet::serialize(buff,calibration_complete,1);
  buff = network::packet::serialize(buff,i_calib_sample,1);
  buff = network::packet::serialize(buff,accl_bias_sum.buff()[0],3);
  buff = network::packet::serialize(buff,gyro_bias_sum.buff()[0],3);
  buff = network::packet::serialize(buff,C_dev2body.buff()[0],9);
  return buff;
}
const uint8* mpu6000_local_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,inv_accl_scale,1);
  buff = network::packet::deserialize(buff,inv_gyro_scale,1);
  buff = network::packet::deserialize(buff,calibration_complete,1);
  buff = network::packet::deserialize(buff,i_calib_sample,1);
  buff = network::packet::deserialize(buff,accl_bias_sum.buff()[0],3);
  buff = network::packet::deserialize(buff,gyro_bias_sum.buff()[0],3);
  buff = network::packet::deserialize(buff,C_dev2body.buff()[0],9);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
