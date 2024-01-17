////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/neom8_config_data.cpp                                               //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/neom8_config_data.h"
using autogen::parameter::neom8_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

neom8_config_data::neom8_config_data() : network::parameter(autogen::type::NEOM8_CONFIG_DATA) {
  initialize();
}
neom8_config_data::neom8_config_data(const string& filename) :
  network::parameter(autogen::type::NEOM8_CONFIG_DATA) {
  load(filename);
}
neom8_config_data::~neom8_config_data() {
  // No-op.
}
neom8_config_data::type_t neom8_config_data::type_index() const {
  return mc_type;
}
string neom8_config_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void neom8_config_data::initialize() {
  clear();
}
void neom8_config_data::clear() {
  clear_content();
}
string neom8_config_data::print() const {
  return type_label()+","+print_content();
}
void neom8_config_data::convert() {
  ned_origin_lat = (ned_origin_lat_deg*0.017453292519943f);
  ned_origin_lon = (ned_origin_lon_deg*0.017453292519943f);
}
void neom8_config_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::neom8_config_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void neom8_config_data::save(const string& filename) const {
  utilities::message("autogen::parameter::neom8_config_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
neom8_config_data& neom8_config_data::operator=(const neom8_config_data& rhs) {
  ned_origin_lat_deg = rhs.ned_origin_lat_deg;
  ned_origin_lon_deg = rhs.ned_origin_lon_deg;
  ned_origin_alt = rhs.ned_origin_alt;
  return *this;
}

void neom8_config_data::clear_content() {
  ned_origin_lat_deg = 0.0d;
  ned_origin_lat = 0.0d;
  ned_origin_lon_deg = 0.0d;
  ned_origin_lon = 0.0d;
  ned_origin_alt = 0.0d;
}
string neom8_config_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << ned_origin_lat_deg << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << ned_origin_lon_deg << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << ned_origin_alt << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << ned_origin_lat << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << ned_origin_lon << ",";
  return ss.str();
}
uint8* neom8_config_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,ned_origin_lat_deg,1);
  buff = network::packet::serialize(buff,ned_origin_lon_deg,1);
  buff = network::packet::serialize(buff,ned_origin_alt,1);
  return buff;
}
const uint8* neom8_config_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,ned_origin_lat_deg,1);
  buff = network::packet::deserialize(buff,ned_origin_lon_deg,1);
  buff = network::packet::deserialize(buff,ned_origin_alt,1);
  return buff;
}
void neom8_config_data::load_content(utilities::ifile& file, const string& parent) {
  file.read_double(parent+"ned_origin_lat_deg",ned_origin_lat_deg);
  file.read_double(parent+"ned_origin_lon_deg",ned_origin_lon_deg);
  file.read_double(parent+"ned_origin_alt",ned_origin_alt);
}
void neom8_config_data::save_content(utilities::ofile& file, const string& parent) const {
  file.write_double(parent+"ned_origin_lat_deg",ned_origin_lat_deg);
  file.write_double(parent+"ned_origin_lon_deg",ned_origin_lon_deg);
  file.write_double(parent+"ned_origin_alt",ned_origin_alt);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
