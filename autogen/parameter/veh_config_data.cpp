////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/veh_config_data.cpp                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/veh_config_data.h"
using autogen::parameter::veh_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

veh_config_data::veh_config_data() : network::parameter(autogen::type::VEH_CONFIG_DATA) {
  initialize();
}
veh_config_data::veh_config_data(const string& filename) :
  network::parameter(autogen::type::VEH_CONFIG_DATA) {
  load(filename);
}
veh_config_data::~veh_config_data() {
  // No-op.
}
veh_config_data::type_t veh_config_data::type_index() const {
  return mc_type;
}
string veh_config_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void veh_config_data::initialize() {
  clear();
}
void veh_config_data::clear() {
  clear_content();
}
string veh_config_data::print() const {
  return type_label()+","+print_content();
}
void veh_config_data::convert() {
}
void veh_config_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::veh_config_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void veh_config_data::save(const string& filename) const {
  utilities::message("autogen::parameter::veh_config_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
veh_config_data& veh_config_data::operator=(const veh_config_data& rhs) {
  number = rhs.number;
  configuration = rhs.configuration;
  return *this;
}

void veh_config_data::clear_content() {
  number = 0;
  configuration = 0;
}
string veh_config_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << number << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << configuration << ",";
  return ss.str();
}
uint8* veh_config_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,number,1);
  buff = network::packet::serialize(buff,configuration,1);
  return buff;
}
const uint8* veh_config_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,number,1);
  buff = network::packet::deserialize(buff,configuration,1);
  return buff;
}
void veh_config_data::load_content(utilities::ifile& file, const string& parent) {
  file.read_uint8(parent+"number",number);
  file.read_uint8(parent+"configuration",configuration);
}
void veh_config_data::save_content(utilities::ofile& file, const string& parent) const {
  file.write_uint8(parent+"number",number);
  file.write_uint8(parent+"configuration",configuration);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
