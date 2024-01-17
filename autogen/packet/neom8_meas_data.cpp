////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/neom8_meas_data.cpp                                                    //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/neom8_meas_data.h"
using autogen::packet::neom8_meas_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

neom8_meas_data::neom8_meas_data() :
  network::packet(autogen::type::NEOM8_MEAS_DATA) {
  initialize();
}
neom8_meas_data::~neom8_meas_data() {
  // No-op.
}
neom8_meas_data::type_t neom8_meas_data::type_index() const {
  return mc_type;
}
string neom8_meas_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void neom8_meas_data::initialize() {
  clear();
}
void neom8_meas_data::clear() {
  clear_content();
}
string neom8_meas_data::print() const {
  return type_label()+","+print_content();
}
neom8_meas_data& neom8_meas_data::operator=(const neom8_meas_data& rhs) {
  i_tow_msec = rhs.i_tow_msec;
  f_tow_nsec = rhs.f_tow_nsec;
  week = rhs.week;
  gps_fix = rhs.gps_fix;
  flags = rhs.flags;
  px_ecef_cm = rhs.px_ecef_cm;
  py_ecef_cm = rhs.py_ecef_cm;
  pz_ecef_cm = rhs.pz_ecef_cm;
  p_acc_cm = rhs.p_acc_cm;
  vx_ecef_cmps = rhs.vx_ecef_cmps;
  vy_ecef_cmps = rhs.vy_ecef_cmps;
  vz_ecef_cmps = rhs.vz_ecef_cmps;
  v_acc_cmps = rhs.v_acc_cmps;
  p_dop_cm = rhs.p_dop_cm;
  num_sv = rhs.num_sv;
  pos_ned = rhs.pos_ned;
  vel_ned = rhs.vel_ned;
  return *this;
}

void neom8_meas_data::clear_content() {
  i_tow_msec = 0;
  f_tow_nsec = 0;
  week = 0;
  gps_fix = 0;
  flags = 0;
  px_ecef_cm = 0;
  py_ecef_cm = 0;
  pz_ecef_cm = 0;
  p_acc_cm = 0;
  vx_ecef_cmps = 0;
  vy_ecef_cmps = 0;
  vz_ecef_cmps = 0;
  v_acc_cmps = 0;
  p_dop_cm = 0;
  num_sv = 0;
  pos_ned = gnc::matrix<float,3,1>();
  vel_ned = gnc::matrix<float,3,1>();
}
string neom8_meas_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << i_tow_msec << ",";
  ss << std::setbase(10) << std::fixed << std::showpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << f_tow_nsec << ",";
  ss << std::setbase(10) << std::fixed << std::showpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << week << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << gps_fix << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << flags << ",";
  ss << std::setbase(10) << std::fixed << std::showpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << px_ecef_cm << ",";
  ss << std::setbase(10) << std::fixed << std::showpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << py_ecef_cm << ",";
  ss << std::setbase(10) << std::fixed << std::showpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << pz_ecef_cm << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << p_acc_cm << ",";
  ss << std::setbase(10) << std::fixed << std::showpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << vx_ecef_cmps << ",";
  ss << std::setbase(10) << std::fixed << std::showpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << vy_ecef_cmps << ",";
  ss << std::setbase(10) << std::fixed << std::showpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << vz_ecef_cmps << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << v_acc_cmps << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << p_dop_cm << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << num_sv << ",";
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << pos_ned.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << vel_ned.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* neom8_meas_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,i_tow_msec,1);
  buff = network::packet::serialize(buff,f_tow_nsec,1);
  buff = network::packet::serialize(buff,week,1);
  buff = network::packet::serialize(buff,gps_fix,1);
  buff = network::packet::serialize(buff,flags,1);
  buff = network::packet::serialize(buff,px_ecef_cm,1);
  buff = network::packet::serialize(buff,py_ecef_cm,1);
  buff = network::packet::serialize(buff,pz_ecef_cm,1);
  buff = network::packet::serialize(buff,p_acc_cm,1);
  buff = network::packet::serialize(buff,vx_ecef_cmps,1);
  buff = network::packet::serialize(buff,vy_ecef_cmps,1);
  buff = network::packet::serialize(buff,vz_ecef_cmps,1);
  buff = network::packet::serialize(buff,v_acc_cmps,1);
  buff = network::packet::serialize(buff,p_dop_cm,1);
  buff = network::packet::serialize(buff,num_sv,1);
  buff = network::packet::serialize(buff,pos_ned.buff()[0],3);
  buff = network::packet::serialize(buff,vel_ned.buff()[0],3);
  return buff;
}
const uint8* neom8_meas_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,i_tow_msec,1);
  buff = network::packet::deserialize(buff,f_tow_nsec,1);
  buff = network::packet::deserialize(buff,week,1);
  buff = network::packet::deserialize(buff,gps_fix,1);
  buff = network::packet::deserialize(buff,flags,1);
  buff = network::packet::deserialize(buff,px_ecef_cm,1);
  buff = network::packet::deserialize(buff,py_ecef_cm,1);
  buff = network::packet::deserialize(buff,pz_ecef_cm,1);
  buff = network::packet::deserialize(buff,p_acc_cm,1);
  buff = network::packet::deserialize(buff,vx_ecef_cmps,1);
  buff = network::packet::deserialize(buff,vy_ecef_cmps,1);
  buff = network::packet::deserialize(buff,vz_ecef_cmps,1);
  buff = network::packet::deserialize(buff,v_acc_cmps,1);
  buff = network::packet::deserialize(buff,p_dop_cm,1);
  buff = network::packet::deserialize(buff,num_sv,1);
  buff = network::packet::deserialize(buff,pos_ned.buff()[0],3);
  buff = network::packet::deserialize(buff,vel_ned.buff()[0],3);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
