////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/rcontrol_local_data.cpp                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/rcontrol_local_data.h"
using autogen::packet::rcontrol_local_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

rcontrol_local_data::rcontrol_local_data() :
  network::packet(autogen::type::RCONTROL_LOCAL_DATA) {
  initialize();
}
rcontrol_local_data::~rcontrol_local_data() {
  // No-op.
}
rcontrol_local_data::type_t rcontrol_local_data::type_index() const {
  return mc_type;
}
string rcontrol_local_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void rcontrol_local_data::initialize() {
  clear();
}
void rcontrol_local_data::clear() {
  clear_content();
}
string rcontrol_local_data::print() const {
  return type_label()+","+print_content();
}
rcontrol_local_data& rcontrol_local_data::operator=(const rcontrol_local_data& rhs) {
  ref_i = rhs.ref_i;
  return *this;
}

void rcontrol_local_data::clear_content() {
  ref_i = gnc::matrix<float,3,1>();
}
string rcontrol_local_data::print_content() const {
  std::ostringstream ss;
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << ref_i.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* rcontrol_local_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,ref_i.buff()[0],3);
  return buff;
}
const uint8* rcontrol_local_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,ref_i.buff()[0],3);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
