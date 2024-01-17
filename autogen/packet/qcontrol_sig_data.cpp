////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/qcontrol_sig_data.cpp                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/qcontrol_sig_data.h"
using autogen::packet::qcontrol_sig_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

qcontrol_sig_data::qcontrol_sig_data() :
  network::packet(autogen::type::QCONTROL_SIG_DATA) {
  initialize();
}
qcontrol_sig_data::~qcontrol_sig_data() {
  // No-op.
}
qcontrol_sig_data::type_t qcontrol_sig_data::type_index() const {
  return mc_type;
}
string qcontrol_sig_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void qcontrol_sig_data::initialize() {
  clear();
}
void qcontrol_sig_data::clear() {
  clear_content();
}
string qcontrol_sig_data::print() const {
  return type_label()+","+print_content();
}
qcontrol_sig_data& qcontrol_sig_data::operator=(const qcontrol_sig_data& rhs) {
  clock_ref = rhs.clock_ref;
  pos_ref_ned = rhs.pos_ref_ned;
  vel_ref_ned = rhs.vel_ref_ned;
  accl_ref_ned = rhs.accl_ref_ned;
  q_i2r = rhs.q_i2r;
  omega_r = rhs.omega_r;
  tau_r = rhs.tau_r;
  w_req = rhs.w_req;
  w_alloc = rhs.w_alloc;
  f_alloc = rhs.f_alloc;
  u = rhs.u;
  return *this;
}

void qcontrol_sig_data::clear_content() {
  clock_ref = 0.0f;
  pos_ref_ned = gnc::matrix<float,3,1>();
  vel_ref_ned = gnc::matrix<float,3,1>();
  accl_ref_ned = gnc::matrix<float,3,1>();
  q_i2r = gnc::quat();
  omega_r = gnc::matrix<float,3,1>();
  tau_r = gnc::matrix<float,3,1>();
  w_req = gnc::matrix<float,4,1>();
  w_alloc = gnc::matrix<float,4,1>();
  f_alloc = gnc::matrix<float,4,1>();
  u = gnc::matrix<float,4,1>();
}
string qcontrol_sig_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << clock_ref << ",";
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << pos_ref_ned.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << vel_ref_ned.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << accl_ref_ned.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<4; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << q_i2r.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << omega_r.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << tau_r.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<4; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << w_req.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<4; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << w_alloc.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<4; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << f_alloc.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<4; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << u.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* qcontrol_sig_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,clock_ref,1);
  buff = network::packet::serialize(buff,pos_ref_ned.buff()[0],3);
  buff = network::packet::serialize(buff,vel_ref_ned.buff()[0],3);
  buff = network::packet::serialize(buff,accl_ref_ned.buff()[0],3);
  buff = network::packet::serialize(buff,q_i2r.buff()[0],4);
  buff = network::packet::serialize(buff,omega_r.buff()[0],3);
  buff = network::packet::serialize(buff,tau_r.buff()[0],3);
  buff = network::packet::serialize(buff,w_req.buff()[0],4);
  buff = network::packet::serialize(buff,w_alloc.buff()[0],4);
  buff = network::packet::serialize(buff,f_alloc.buff()[0],4);
  buff = network::packet::serialize(buff,u.buff()[0],4);
  return buff;
}
const uint8* qcontrol_sig_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,clock_ref,1);
  buff = network::packet::deserialize(buff,pos_ref_ned.buff()[0],3);
  buff = network::packet::deserialize(buff,vel_ref_ned.buff()[0],3);
  buff = network::packet::deserialize(buff,accl_ref_ned.buff()[0],3);
  buff = network::packet::deserialize(buff,q_i2r.buff()[0],4);
  buff = network::packet::deserialize(buff,omega_r.buff()[0],3);
  buff = network::packet::deserialize(buff,tau_r.buff()[0],3);
  buff = network::packet::deserialize(buff,w_req.buff()[0],4);
  buff = network::packet::deserialize(buff,w_alloc.buff()[0],4);
  buff = network::packet::deserialize(buff,f_alloc.buff()[0],4);
  buff = network::packet::deserialize(buff,u.buff()[0],4);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
