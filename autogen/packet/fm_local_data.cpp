////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/fm_local_data.cpp                                                      //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/fm_local_data.h"
using autogen::packet::fm_local_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

fm_local_data::fm_local_data() :
  network::packet(autogen::type::FM_LOCAL_DATA) {
  initialize();
}
fm_local_data::~fm_local_data() {
  // No-op.
}
fm_local_data::type_t fm_local_data::type_index() const {
  return mc_type;
}
string fm_local_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void fm_local_data::initialize() {
  clear();
}
void fm_local_data::clear() {
  clear_content();
}
string fm_local_data::print() const {
  return type_label()+","+print_content();
}
fm_local_data& fm_local_data::operator=(const fm_local_data& rhs) {
  boot_stage = rhs.boot_stage;
  initialize_stage = rhs.initialize_stage;
  calibrate_imu_stage = rhs.calibrate_imu_stage;
  calibrate_mag_stage = rhs.calibrate_mag_stage;
  calibrate_pwm_stage = rhs.calibrate_pwm_stage;
  calibrate_esc_stage = rhs.calibrate_esc_stage;
  deactivate_stage = rhs.deactivate_stage;
  shutdown_stage = rhs.shutdown_stage;
  return *this;
}

void fm_local_data::clear_content() {
  boot_stage = 0;
  initialize_stage = 0;
  calibrate_imu_stage = 0;
  calibrate_mag_stage = 0;
  calibrate_pwm_stage = 0;
  calibrate_esc_stage = 0;
  deactivate_stage = 0;
  shutdown_stage = 0;
}
string fm_local_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << boot_stage << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << initialize_stage << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << calibrate_imu_stage << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << calibrate_mag_stage << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << calibrate_pwm_stage << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << calibrate_esc_stage << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << deactivate_stage << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << shutdown_stage << ",";
  return ss.str();
}
uint8* fm_local_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,boot_stage,1);
  buff = network::packet::serialize(buff,initialize_stage,1);
  buff = network::packet::serialize(buff,calibrate_imu_stage,1);
  buff = network::packet::serialize(buff,calibrate_mag_stage,1);
  buff = network::packet::serialize(buff,calibrate_pwm_stage,1);
  buff = network::packet::serialize(buff,calibrate_esc_stage,1);
  buff = network::packet::serialize(buff,deactivate_stage,1);
  buff = network::packet::serialize(buff,shutdown_stage,1);
  return buff;
}
const uint8* fm_local_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,boot_stage,1);
  buff = network::packet::deserialize(buff,initialize_stage,1);
  buff = network::packet::deserialize(buff,calibrate_imu_stage,1);
  buff = network::packet::deserialize(buff,calibrate_mag_stage,1);
  buff = network::packet::deserialize(buff,calibrate_pwm_stage,1);
  buff = network::packet::deserialize(buff,calibrate_esc_stage,1);
  buff = network::packet::deserialize(buff,deactivate_stage,1);
  buff = network::packet::deserialize(buff,shutdown_stage,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
