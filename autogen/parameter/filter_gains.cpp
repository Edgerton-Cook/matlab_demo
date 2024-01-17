////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/filter_gains.cpp                                                    //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/filter_gains.h"
using autogen::parameter::filter_gains;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

filter_gains::filter_gains() : network::parameter(autogen::type::FILTER_GAINS) {
  initialize();
}
filter_gains::filter_gains(const string& filename) :
  network::parameter(autogen::type::FILTER_GAINS) {
  load(filename);
}
filter_gains::~filter_gains() {
  // No-op.
}
filter_gains::type_t filter_gains::type_index() const {
  return mc_type;
}
string filter_gains::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void filter_gains::initialize() {
  clear();
}
void filter_gains::clear() {
  clear_content();
}
string filter_gains::print() const {
  return type_label()+","+print_content();
}
void filter_gains::convert() {
}
void filter_gains::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::filter_gains::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void filter_gains::save(const string& filename) const {
  utilities::message("autogen::parameter::filter_gains::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
filter_gains& filter_gains::operator=(const filter_gains& rhs) {
  num = rhs.num;
  den = rhs.den;
  return *this;
}

void filter_gains::clear_content() {
  num = gnc::matrix<float,3,1>();
  den = gnc::matrix<float,3,1>();
}
string filter_gains::print_content() const {
  std::ostringstream ss;
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << num.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << den.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* filter_gains::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,num.buff()[0],3);
  buff = network::packet::serialize(buff,den.buff()[0],3);
  return buff;
}
const uint8* filter_gains::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,num.buff()[0],3);
  buff = network::packet::deserialize(buff,den.buff()[0],3);
  return buff;
}
void filter_gains::load_content(utilities::ifile& file, const string& parent) {
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    std::ostringstream idx_str;
    idx_str << "(" << mpac_ijk1 << ")";
    file.read_float(parent+"num"+idx_str.str(),num(mpac_ijk1));
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    std::ostringstream idx_str;
    idx_str << "(" << mpac_ijk1 << ")";
    file.read_float(parent+"den"+idx_str.str(),den(mpac_ijk1));
  }
}
void filter_gains::save_content(utilities::ofile& file, const string& parent) const {
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    std::ostringstream idx_str;
    idx_str << "(" << mpac_ijk1 << ")";
    file.write_float(parent+"num"+idx_str.str(),num(mpac_ijk1));
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    std::ostringstream idx_str;
    idx_str << "(" << mpac_ijk1 << ")";
    file.write_float(parent+"den"+idx_str.str(),den(mpac_ijk1));
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
