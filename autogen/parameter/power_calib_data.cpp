////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/power_calib_data.cpp                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/power_calib_data.h"
using autogen::parameter::power_calib_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

power_calib_data::power_calib_data() : network::parameter(autogen::type::POWER_CALIB_DATA) {
  initialize();
}
power_calib_data::power_calib_data(const string& filename) :
  network::parameter(autogen::type::POWER_CALIB_DATA) {
  load(filename);
}
power_calib_data::~power_calib_data() {
  // No-op.
}
power_calib_data::type_t power_calib_data::type_index() const {
  return mc_type;
}
string power_calib_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void power_calib_data::initialize() {
  clear();
}
void power_calib_data::clear() {
  clear_content();
}
string power_calib_data::print() const {
  return type_label()+","+print_content();
}
void power_calib_data::convert() {
}
void power_calib_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::power_calib_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void power_calib_data::save(const string& filename) const {
  utilities::message("autogen::parameter::power_calib_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
power_calib_data& power_calib_data::operator=(const power_calib_data& rhs) {
  voltage_coeff = rhs.voltage_coeff;
  current_coeff = rhs.current_coeff;
  return *this;
}

void power_calib_data::clear_content() {
  voltage_coeff = 0.0f;
  current_coeff = 0.0f;
}
string power_calib_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << voltage_coeff << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << current_coeff << ",";
  return ss.str();
}
uint8* power_calib_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,voltage_coeff,1);
  buff = network::packet::serialize(buff,current_coeff,1);
  return buff;
}
const uint8* power_calib_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,voltage_coeff,1);
  buff = network::packet::deserialize(buff,current_coeff,1);
  return buff;
}
void power_calib_data::load_content(utilities::ifile& file, const string& parent) {
  file.read_float(parent+"voltage_coeff",voltage_coeff);
  file.read_float(parent+"current_coeff",current_coeff);
}
void power_calib_data::save_content(utilities::ofile& file, const string& parent) const {
  file.write_float(parent+"voltage_coeff",voltage_coeff);
  file.write_float(parent+"current_coeff",current_coeff);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
