////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/estimation_sig_data.cpp                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/estimation_sig_data.h"
using autogen::packet::estimation_sig_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

estimation_sig_data::estimation_sig_data() :
  network::packet(autogen::type::ESTIMATION_SIG_DATA) {
  initialize();
}
estimation_sig_data::~estimation_sig_data() {
  // No-op.
}
estimation_sig_data::type_t estimation_sig_data::type_index() const {
  return mc_type;
}
string estimation_sig_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void estimation_sig_data::initialize() {
  clear();
}
void estimation_sig_data::clear() {
  clear_content();
}
string estimation_sig_data::print() const {
  return type_label()+","+print_content();
}
estimation_sig_data& estimation_sig_data::operator=(const estimation_sig_data& rhs) {
  pos_ned = rhs.pos_ned;
  vel_ned = rhs.vel_ned;
  q_i2b = rhs.q_i2b;
  b_accl = rhs.b_accl;
  b_gyro = rhs.b_gyro;
  accl_b = rhs.accl_b;
  omega_b = rhs.omega_b;
  return *this;
}

void estimation_sig_data::clear_content() {
  pos_ned = gnc::matrix<float,3,1>();
  vel_ned = gnc::matrix<float,3,1>();
  q_i2b = gnc::quat();
  b_accl = gnc::matrix<float,3,1>();
  b_gyro = gnc::matrix<float,3,1>();
  accl_b = gnc::matrix<float,3,1>();
  omega_b = gnc::matrix<float,3,1>();
}
string estimation_sig_data::print_content() const {
  std::ostringstream ss;
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << pos_ned.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << vel_ned.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<4; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << q_i2b.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << b_accl.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << b_gyro.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << accl_b.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << omega_b.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* estimation_sig_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,pos_ned.buff()[0],3);
  buff = network::packet::serialize(buff,vel_ned.buff()[0],3);
  buff = network::packet::serialize(buff,q_i2b.buff()[0],4);
  buff = network::packet::serialize(buff,b_accl.buff()[0],3);
  buff = network::packet::serialize(buff,b_gyro.buff()[0],3);
  buff = network::packet::serialize(buff,accl_b.buff()[0],3);
  buff = network::packet::serialize(buff,omega_b.buff()[0],3);
  return buff;
}
const uint8* estimation_sig_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,pos_ned.buff()[0],3);
  buff = network::packet::deserialize(buff,vel_ned.buff()[0],3);
  buff = network::packet::deserialize(buff,q_i2b.buff()[0],4);
  buff = network::packet::deserialize(buff,b_accl.buff()[0],3);
  buff = network::packet::deserialize(buff,b_gyro.buff()[0],3);
  buff = network::packet::deserialize(buff,accl_b.buff()[0],3);
  buff = network::packet::deserialize(buff,omega_b.buff()[0],3);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
