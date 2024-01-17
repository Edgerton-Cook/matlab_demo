////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/cm_subscriptions.cpp                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/cm_subscriptions.h"
using autogen::parameter::cm_subscriptions;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

cm_subscriptions::cm_subscriptions() : network::parameter(autogen::type::CM_SUBSCRIPTIONS) {
  initialize();
}
cm_subscriptions::cm_subscriptions(const string& filename) :
  network::parameter(autogen::type::CM_SUBSCRIPTIONS) {
  load(filename);
}
cm_subscriptions::~cm_subscriptions() {
  // No-op.
}
cm_subscriptions::type_t cm_subscriptions::type_index() const {
  return mc_type;
}
string cm_subscriptions::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void cm_subscriptions::initialize() {
  clear();
}
void cm_subscriptions::clear() {
  clear_content();
}
string cm_subscriptions::print() const {
  return type_label()+","+print_content();
}
void cm_subscriptions::convert() {
}
void cm_subscriptions::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::cm_subscriptions::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void cm_subscriptions::save(const string& filename) const {
  utilities::message("autogen::parameter::cm_subscriptions::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
cm_subscriptions& cm_subscriptions::operator=(const cm_subscriptions& rhs) {
  telemetry_rate = rhs.telemetry_rate;
  mpu6000_meas_data_rate = rhs.mpu6000_meas_data_rate;
  pca9685_cmd_data_rate = rhs.pca9685_cmd_data_rate;
  return *this;
}

void cm_subscriptions::clear_content() {
  telemetry_rate = 0;
  mpu6000_meas_data_rate = 0;
  pca9685_cmd_data_rate = 0;
}
string cm_subscriptions::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << telemetry_rate << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << mpu6000_meas_data_rate << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << pca9685_cmd_data_rate << ",";
  return ss.str();
}
uint8* cm_subscriptions::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,telemetry_rate,1);
  buff = network::packet::serialize(buff,mpu6000_meas_data_rate,1);
  buff = network::packet::serialize(buff,pca9685_cmd_data_rate,1);
  return buff;
}
const uint8* cm_subscriptions::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,telemetry_rate,1);
  buff = network::packet::deserialize(buff,mpu6000_meas_data_rate,1);
  buff = network::packet::deserialize(buff,pca9685_cmd_data_rate,1);
  return buff;
}
void cm_subscriptions::load_content(utilities::ifile& file, const string& parent) {
  file.read_uint16(parent+"telemetry_rate",telemetry_rate);
  file.read_uint16(parent+"mpu6000_meas_data_rate",mpu6000_meas_data_rate);
  file.read_uint16(parent+"pca9685_cmd_data_rate",pca9685_cmd_data_rate);
}
void cm_subscriptions::save_content(utilities::ofile& file, const string& parent) const {
  file.write_uint16(parent+"telemetry_rate",telemetry_rate);
  file.write_uint16(parent+"mpu6000_meas_data_rate",mpu6000_meas_data_rate);
  file.write_uint16(parent+"pca9685_cmd_data_rate",pca9685_cmd_data_rate);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
