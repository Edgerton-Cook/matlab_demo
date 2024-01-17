////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/estimation_local_data.cpp                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/estimation_local_data.h"
using autogen::packet::estimation_local_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

estimation_local_data::estimation_local_data() :
  network::packet(autogen::type::ESTIMATION_LOCAL_DATA) {
  initialize();
}
estimation_local_data::~estimation_local_data() {
  // No-op.
}
estimation_local_data::type_t estimation_local_data::type_index() const {
  return mc_type;
}
string estimation_local_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void estimation_local_data::initialize() {
  clear();
}
void estimation_local_data::clear() {
  clear_content();
}
string estimation_local_data::print() const {
  return type_label()+","+print_content();
}
estimation_local_data& estimation_local_data::operator=(const estimation_local_data& rhs) {
  x = rhs.x;
  gyro_bias_integral = rhs.gyro_bias_integral;
  previous_mag_vec_meas = rhs.previous_mag_vec_meas;
  x_kf = rhs.x_kf;
  P_kf = rhs.P_kf;
  return *this;
}

void estimation_local_data::clear_content() {
  x = gnc::matrix<float,7,1>();
  gyro_bias_integral = gnc::matrix<float,3,1>();
  previous_mag_vec_meas = gnc::matrix<float,3,1>();
  x_kf = gnc::matrix<float,6,1>();
  P_kf = gnc::matrix<float,6,6>();
}
string estimation_local_data::print_content() const {
  std::ostringstream ss;
  for (uint32 mpac_ijk1=0; mpac_ijk1<7; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << x.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << gyro_bias_integral.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << previous_mag_vec_meas.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<6; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << x_kf.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<36; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << P_kf.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* estimation_local_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,x.buff()[0],7);
  buff = network::packet::serialize(buff,gyro_bias_integral.buff()[0],3);
  buff = network::packet::serialize(buff,previous_mag_vec_meas.buff()[0],3);
  buff = network::packet::serialize(buff,x_kf.buff()[0],6);
  buff = network::packet::serialize(buff,P_kf.buff()[0],36);
  return buff;
}
const uint8* estimation_local_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,x.buff()[0],7);
  buff = network::packet::deserialize(buff,gyro_bias_integral.buff()[0],3);
  buff = network::packet::deserialize(buff,previous_mag_vec_meas.buff()[0],3);
  buff = network::packet::deserialize(buff,x_kf.buff()[0],6);
  buff = network::packet::deserialize(buff,P_kf.buff()[0],36);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
