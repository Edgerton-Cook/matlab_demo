////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/mpu6000_meas_data.cpp                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/mpu6000_meas_data.h"
using autogen::packet::mpu6000_meas_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

mpu6000_meas_data::mpu6000_meas_data() :
  network::packet(autogen::type::MPU6000_MEAS_DATA) {
  initialize();
}
mpu6000_meas_data::~mpu6000_meas_data() {
  // No-op.
}
mpu6000_meas_data::type_t mpu6000_meas_data::type_index() const {
  return mc_type;
}
string mpu6000_meas_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void mpu6000_meas_data::initialize() {
  clear();
}
void mpu6000_meas_data::clear() {
  clear_content();
}
string mpu6000_meas_data::print() const {
  return type_label()+","+print_content();
}
mpu6000_meas_data& mpu6000_meas_data::operator=(const mpu6000_meas_data& rhs) {
  accl = rhs.accl;
  gyro = rhs.gyro;
  temp = rhs.temp;
  return *this;
}

void mpu6000_meas_data::clear_content() {
  accl = gnc::matrix<float,3,1>();
  gyro = gnc::matrix<float,3,1>();
  temp = 0.0f;
}
string mpu6000_meas_data::print_content() const {
  std::ostringstream ss;
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << accl.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << gyro.buff()[mpac_ijk1] << ",";
  }
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << temp << ",";
  return ss.str();
}
uint8* mpu6000_meas_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,accl.buff()[0],3);
  buff = network::packet::serialize(buff,gyro.buff()[0],3);
  buff = network::packet::serialize(buff,temp,1);
  return buff;
}
const uint8* mpu6000_meas_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,accl.buff()[0],3);
  buff = network::packet::deserialize(buff,gyro.buff()[0],3);
  buff = network::packet::deserialize(buff,temp,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
