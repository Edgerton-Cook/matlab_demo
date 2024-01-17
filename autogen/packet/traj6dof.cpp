////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/traj6dof.cpp                                                           //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/traj6dof.h"
using autogen::packet::traj6dof;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

traj6dof::traj6dof() :
  network::packet(autogen::type::TRAJ6DOF) {
  initialize();
}
traj6dof::~traj6dof() {
  // No-op.
}
traj6dof::type_t traj6dof::type_index() const {
  return mc_type;
}
string traj6dof::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void traj6dof::initialize() {
  clear();
}
void traj6dof::clear() {
  clear_content();
}
string traj6dof::print() const {
  return type_label()+","+print_content();
}
traj6dof& traj6dof::operator=(const traj6dof& rhs) {
  epoch = rhs.epoch;
  is_new = rhs.is_new;
  loop = rhs.loop;
  K = rhs.K;
  time = rhs.time;
  pos_ned = rhs.pos_ned;
  vel_ned = rhs.vel_ned;
  accl_ned = rhs.accl_ned;
  omega_body = rhs.omega_body;
  torque_body = rhs.torque_body;
  clock_angle = rhs.clock_angle;
  return *this;
}

void traj6dof::clear_content() {
  epoch = 0;
  is_new = 0;
  loop = 0;
  K = 0;
  time = gnc::matrix<float,1,50>();
  pos_ned = gnc::matrix<float,3,50>();
  vel_ned = gnc::matrix<float,3,50>();
  accl_ned = gnc::matrix<float,3,50>();
  omega_body = gnc::matrix<float,3,50>();
  torque_body = gnc::matrix<float,3,50>();
  clock_angle = gnc::matrix<float,1,50>();
}
string traj6dof::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << epoch << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << is_new << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << loop << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << K << ",";
  for (uint32 mpac_ijk1=0; mpac_ijk1<50; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << time.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<150; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << pos_ned.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<150; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << vel_ned.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<150; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << accl_ned.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<150; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << omega_body.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<150; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << torque_body.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<50; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << clock_angle.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* traj6dof::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,epoch,1);
  buff = network::packet::serialize(buff,is_new,1);
  buff = network::packet::serialize(buff,loop,1);
  buff = network::packet::serialize(buff,K,1);
  buff = network::packet::serialize(buff,time.buff()[0],50);
  buff = network::packet::serialize(buff,pos_ned.buff()[0],150);
  buff = network::packet::serialize(buff,vel_ned.buff()[0],150);
  buff = network::packet::serialize(buff,accl_ned.buff()[0],150);
  buff = network::packet::serialize(buff,omega_body.buff()[0],150);
  buff = network::packet::serialize(buff,torque_body.buff()[0],150);
  buff = network::packet::serialize(buff,clock_angle.buff()[0],50);
  return buff;
}
const uint8* traj6dof::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,epoch,1);
  buff = network::packet::deserialize(buff,is_new,1);
  buff = network::packet::deserialize(buff,loop,1);
  buff = network::packet::deserialize(buff,K,1);
  buff = network::packet::deserialize(buff,time.buff()[0],50);
  buff = network::packet::deserialize(buff,pos_ned.buff()[0],150);
  buff = network::packet::deserialize(buff,vel_ned.buff()[0],150);
  buff = network::packet::deserialize(buff,accl_ned.buff()[0],150);
  buff = network::packet::deserialize(buff,omega_body.buff()[0],150);
  buff = network::packet::deserialize(buff,torque_body.buff()[0],150);
  buff = network::packet::deserialize(buff,clock_angle.buff()[0],50);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
