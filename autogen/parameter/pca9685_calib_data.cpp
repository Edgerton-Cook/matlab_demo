////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/pca9685_calib_data.cpp                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/pca9685_calib_data.h"
using autogen::parameter::pca9685_calib_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

pca9685_calib_data::pca9685_calib_data() : network::parameter(autogen::type::PCA9685_CALIB_DATA) {
  initialize();
}
pca9685_calib_data::pca9685_calib_data(const string& filename) :
  network::parameter(autogen::type::PCA9685_CALIB_DATA) {
  load(filename);
}
pca9685_calib_data::~pca9685_calib_data() {
  // No-op.
}
pca9685_calib_data::type_t pca9685_calib_data::type_index() const {
  return mc_type;
}
string pca9685_calib_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void pca9685_calib_data::initialize() {
  clear();
}
void pca9685_calib_data::clear() {
  clear_content();
}
string pca9685_calib_data::print() const {
  return type_label()+","+print_content();
}
void pca9685_calib_data::convert() {
}
void pca9685_calib_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::pca9685_calib_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void pca9685_calib_data::save(const string& filename) const {
  utilities::message("autogen::parameter::pca9685_calib_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
pca9685_calib_data& pca9685_calib_data::operator=(const pca9685_calib_data& rhs) {
  clock_correction_factor = rhs.clock_correction_factor;
  return *this;
}

void pca9685_calib_data::clear_content() {
  clock_correction_factor = 0.0f;
}
string pca9685_calib_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << clock_correction_factor << ",";
  return ss.str();
}
uint8* pca9685_calib_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,clock_correction_factor,1);
  return buff;
}
const uint8* pca9685_calib_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,clock_correction_factor,1);
  return buff;
}
void pca9685_calib_data::load_content(utilities::ifile& file, const string& parent) {
  file.read_float(parent+"clock_correction_factor",clock_correction_factor);
}
void pca9685_calib_data::save_content(utilities::ofile& file, const string& parent) const {
  file.write_float(parent+"clock_correction_factor",clock_correction_factor);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
