////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/sc18is602b_config_data.cpp                                          //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/sc18is602b_config_data.h"
using autogen::parameter::sc18is602b_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

sc18is602b_config_data::sc18is602b_config_data() : network::parameter(autogen::type::SC18IS602B_CONFIG_DATA) {
  initialize();
}
sc18is602b_config_data::sc18is602b_config_data(const string& filename) :
  network::parameter(autogen::type::SC18IS602B_CONFIG_DATA) {
  load(filename);
}
sc18is602b_config_data::~sc18is602b_config_data() {
  // No-op.
}
sc18is602b_config_data::type_t sc18is602b_config_data::type_index() const {
  return mc_type;
}
string sc18is602b_config_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void sc18is602b_config_data::initialize() {
  clear();
}
void sc18is602b_config_data::clear() {
  clear_content();
}
string sc18is602b_config_data::print() const {
  return type_label()+","+print_content();
}
void sc18is602b_config_data::convert() {
}
void sc18is602b_config_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::sc18is602b_config_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void sc18is602b_config_data::save(const string& filename) const {
  utilities::message("autogen::parameter::sc18is602b_config_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
sc18is602b_config_data& sc18is602b_config_data::operator=(const sc18is602b_config_data& rhs) {
  cs = rhs.cs;
  return *this;
}

void sc18is602b_config_data::clear_content() {
  cs = 0;
}
string sc18is602b_config_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << cs << ",";
  return ss.str();
}
uint8* sc18is602b_config_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,cs,1);
  return buff;
}
const uint8* sc18is602b_config_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,cs,1);
  return buff;
}
void sc18is602b_config_data::load_content(utilities::ifile& file, const string& parent) {
  file.read_uint8(parent+"cs",cs);
}
void sc18is602b_config_data::save_content(utilities::ofile& file, const string& parent) const {
  file.write_uint8(parent+"cs",cs);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
