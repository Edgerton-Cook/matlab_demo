////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/rcontrol_sig_data.cpp                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/rcontrol_sig_data.h"
using autogen::packet::rcontrol_sig_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

rcontrol_sig_data::rcontrol_sig_data() :
  network::packet(autogen::type::RCONTROL_SIG_DATA) {
  initialize();
}
rcontrol_sig_data::~rcontrol_sig_data() {
  // No-op.
}
rcontrol_sig_data::type_t rcontrol_sig_data::type_index() const {
  return mc_type;
}
string rcontrol_sig_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void rcontrol_sig_data::initialize() {
  clear();
}
void rcontrol_sig_data::clear() {
  clear_content();
}
string rcontrol_sig_data::print() const {
  return type_label()+","+print_content();
}
rcontrol_sig_data& rcontrol_sig_data::operator=(const rcontrol_sig_data& rhs) {
  u = rhs.u;
  q_i2r = rhs.q_i2r;
  return *this;
}

void rcontrol_sig_data::clear_content() {
  u = gnc::matrix<float,3,1>();
  q_i2r = gnc::quat();
}
string rcontrol_sig_data::print_content() const {
  std::ostringstream ss;
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << u.buff()[mpac_ijk1] << ",";
  }
  for (uint32 mpac_ijk1=0; mpac_ijk1<4; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << q_i2r.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* rcontrol_sig_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,u.buff()[0],3);
  buff = network::packet::serialize(buff,q_i2r.buff()[0],4);
  return buff;
}
const uint8* rcontrol_sig_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,u.buff()[0],3);
  buff = network::packet::deserialize(buff,q_i2r.buff()[0],4);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
