////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/rcontrol_cmd.cpp                                                       //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/rcontrol_cmd.h"
using autogen::packet::rcontrol_cmd;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

rcontrol_cmd::rcontrol_cmd() :
  network::packet(autogen::type::RCONTROL_CMD) {
  initialize();
}
rcontrol_cmd::~rcontrol_cmd() {
  // No-op.
}
rcontrol_cmd::type_t rcontrol_cmd::type_index() const {
  return mc_type;
}
string rcontrol_cmd::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void rcontrol_cmd::initialize() {
  clear();
}
void rcontrol_cmd::clear() {
  clear_content();
}
string rcontrol_cmd::print() const {
  return type_label()+","+print_content();
}
rcontrol_cmd& rcontrol_cmd::operator=(const rcontrol_cmd& rhs) {
  fm_trans_cmd = rhs.fm_trans_cmd;
  mode = rhs.mode;
  ch = rhs.ch;
  return *this;
}

void rcontrol_cmd::clear_content() {
  fm_trans_cmd.clear();
  mode.clear();
  ch = gnc::matrix<float,3,1>();
}
string rcontrol_cmd::print_content() const {
  std::ostringstream ss;
  ss << fm_trans_cmd.print();
  ss << mode.print();
  for (uint32 mpac_ijk1=0; mpac_ijk1<3; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << ch.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* rcontrol_cmd::serialize_content(uint8* buff) const {
  buff = fm_trans_cmd.serialize_content(buff);
  buff = mode.serialize_content(buff);
  buff = network::packet::serialize(buff,ch.buff()[0],3);
  return buff;
}
const uint8* rcontrol_cmd::deserialize_content(const uint8* buff) {
  buff = fm_trans_cmd.deserialize_content(buff);
  buff = mode.deserialize_content(buff);
  buff = network::packet::deserialize(buff,ch.buff()[0],3);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
