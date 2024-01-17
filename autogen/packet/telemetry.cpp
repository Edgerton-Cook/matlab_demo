////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/telemetry.cpp                                                          //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/telemetry.h"
using autogen::packet::telemetry;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

telemetry::telemetry() :
  network::packet(autogen::type::TELEMETRY) {
  initialize();
}
telemetry::~telemetry() {
  // No-op.
}
telemetry::type_t telemetry::type_index() const {
  return mc_type;
}
string telemetry::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void telemetry::initialize() {
  clear();
}
void telemetry::clear() {
  clear_content();
}
string telemetry::print() const {
  return type_label()+","+print_content();
}
telemetry& telemetry::operator=(const telemetry& rhs) {
  veh_config = rhs.veh_config;
  ownership = rhs.ownership;
  fm_state = rhs.fm_state;
  qcontrol_mode = rhs.qcontrol_mode;
  rcontrol_mode = rhs.rcontrol_mode;
  battery_voltage = rhs.battery_voltage;
  q_i2b = rhs.q_i2b;
  q_i2r = rhs.q_i2r;
  pos_ned = rhs.pos_ned;
  pos_ref_ned = rhs.pos_ref_ned;
  vel_ned = rhs.vel_ned;
  accl_b = rhs.accl_b;
  gps_nsv = rhs.gps_nsv;
  gps_fix = rhs.gps_fix;
  return *this;
}

void telemetry::clear_content() {
  veh_config.clear();
  ownership.clear();
  fm_state.clear();
  qcontrol_mode.clear();
  rcontrol_mode.clear();
  battery_voltage = 0.0f;
  q_i2b = gnc::quat();
  q_i2r = gnc::quat();
  pos_ned = gnc::matrix<float,3,1>();
  pos_ref_ned = gnc::matrix<float,3,1>();
  vel_ned = gnc::matrix<float,3,1>();
  accl_b = gnc::matrix<float,3,1>();
  gps_nsv = 0;
  gps_fix = 0;
}
string telemetry::print_content() const {
  std::ostringstream ss;
  ss << veh_config.print();
  ss << ownership.print();
  ss << fm_state.print();
  ss << qcontrol_mode.print();
  ss << rcontrol_mode.print();
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << battery_voltage << ",";
  for (uint32 mpac_ijk1=0; mpac_ijk1<4; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << q_i2b.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<4; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << q_i2r.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << pos_ned.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << pos_ref_ned.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << vel_ned.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << accl_b.buff()[mpac_ijk1] << ",";
  }
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << gps_nsv << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << gps_fix << ",";
  return ss.str();
}
uint8* telemetry::serialize_content(uint8* buff) const {
  buff = veh_config.serialize_content(buff);
  buff = ownership.serialize_content(buff);
  buff = fm_state.serialize_content(buff);
  buff = qcontrol_mode.serialize_content(buff);
  buff = rcontrol_mode.serialize_content(buff);
  buff = network::packet::serialize(buff,battery_voltage,1);
  buff = network::packet::serialize(buff,q_i2b.buff()[0],4);
  buff = network::packet::serialize(buff,q_i2r.buff()[0],4);
  buff = network::packet::serialize(buff,pos_ned.buff()[0],3);
  buff = network::packet::serialize(buff,pos_ref_ned.buff()[0],3);
  buff = network::packet::serialize(buff,vel_ned.buff()[0],3);
  buff = network::packet::serialize(buff,accl_b.buff()[0],3);
  buff = network::packet::serialize(buff,gps_nsv,1);
  buff = network::packet::serialize(buff,gps_fix,1);
  return buff;
}
const uint8* telemetry::deserialize_content(const uint8* buff) {
  buff = veh_config.deserialize_content(buff);
  buff = ownership.deserialize_content(buff);
  buff = fm_state.deserialize_content(buff);
  buff = qcontrol_mode.deserialize_content(buff);
  buff = rcontrol_mode.deserialize_content(buff);
  buff = network::packet::deserialize(buff,battery_voltage,1);
  buff = network::packet::deserialize(buff,q_i2b.buff()[0],4);
  buff = network::packet::deserialize(buff,q_i2r.buff()[0],4);
  buff = network::packet::deserialize(buff,pos_ned.buff()[0],3);
  buff = network::packet::deserialize(buff,pos_ref_ned.buff()[0],3);
  buff = network::packet::deserialize(buff,vel_ned.buff()[0],3);
  buff = network::packet::deserialize(buff,accl_b.buff()[0],3);
  buff = network::packet::deserialize(buff,gps_nsv,1);
  buff = network::packet::deserialize(buff,gps_fix,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
