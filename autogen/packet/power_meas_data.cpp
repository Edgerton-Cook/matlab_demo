////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/power_meas_data.cpp                                                    //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/power_meas_data.h"
using autogen::packet::power_meas_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

power_meas_data::power_meas_data() :
  network::packet(autogen::type::POWER_MEAS_DATA) {
  initialize();
}
power_meas_data::~power_meas_data() {
  // No-op.
}
power_meas_data::type_t power_meas_data::type_index() const {
  return mc_type;
}
string power_meas_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void power_meas_data::initialize() {
  clear();
}
void power_meas_data::clear() {
  clear_content();
}
string power_meas_data::print() const {
  return type_label()+","+print_content();
}
power_meas_data& power_meas_data::operator=(const power_meas_data& rhs) {
  input_voltage = rhs.input_voltage;
  input_current = rhs.input_current;
  return *this;
}

void power_meas_data::clear_content() {
  input_voltage = 0.0f;
  input_current = 0.0f;
}
string power_meas_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << input_voltage << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << input_current << ",";
  return ss.str();
}
uint8* power_meas_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,input_voltage,1);
  buff = network::packet::serialize(buff,input_current,1);
  return buff;
}
const uint8* power_meas_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,input_voltage,1);
  buff = network::packet::deserialize(buff,input_current,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
