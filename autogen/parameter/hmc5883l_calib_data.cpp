////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/hmc5883l_calib_data.cpp                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/hmc5883l_calib_data.h"
using autogen::parameter::hmc5883l_calib_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

hmc5883l_calib_data::hmc5883l_calib_data() : network::parameter(autogen::type::HMC5883L_CALIB_DATA) {
  initialize();
}
hmc5883l_calib_data::hmc5883l_calib_data(const string& filename) :
  network::parameter(autogen::type::HMC5883L_CALIB_DATA) {
  load(filename);
}
hmc5883l_calib_data::~hmc5883l_calib_data() {
  // No-op.
}
hmc5883l_calib_data::type_t hmc5883l_calib_data::type_index() const {
  return mc_type;
}
string hmc5883l_calib_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void hmc5883l_calib_data::initialize() {
  clear();
}
void hmc5883l_calib_data::clear() {
  clear_content();
}
string hmc5883l_calib_data::print() const {
  return type_label()+","+print_content();
}
void hmc5883l_calib_data::convert() {
}
void hmc5883l_calib_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::hmc5883l_calib_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void hmc5883l_calib_data::save(const string& filename) const {
  utilities::message("autogen::parameter::hmc5883l_calib_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
hmc5883l_calib_data& hmc5883l_calib_data::operator=(const hmc5883l_calib_data& rhs) {
  bias = rhs.bias;
  return *this;
}

void hmc5883l_calib_data::clear_content() {
  bias = gnc::matrix<float,3,1>();
}
string hmc5883l_calib_data::print_content() const {
  std::ostringstream ss;
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << bias.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* hmc5883l_calib_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,bias.buff()[0],3);
  return buff;
}
const uint8* hmc5883l_calib_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,bias.buff()[0],3);
  return buff;
}
void hmc5883l_calib_data::load_content(utilities::ifile& file, const string& parent) {
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    std::ostringstream idx_str;
    idx_str << "(" << mpac_ijk1 << ")";
    file.read_float(parent+"bias"+idx_str.str(),bias(mpac_ijk1));
  }
}
void hmc5883l_calib_data::save_content(utilities::ofile& file, const string& parent) const {
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    std::ostringstream idx_str;
    idx_str << "(" << mpac_ijk1 << ")";
    file.write_float(parent+"bias"+idx_str.str(),bias(mpac_ijk1));
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
