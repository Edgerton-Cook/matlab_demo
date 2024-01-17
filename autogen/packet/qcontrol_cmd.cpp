////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/qcontrol_cmd.cpp                                                       //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/qcontrol_cmd.h"
using autogen::packet::qcontrol_cmd;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

qcontrol_cmd::qcontrol_cmd() :
  network::packet(autogen::type::QCONTROL_CMD) {
  initialize();
}
qcontrol_cmd::~qcontrol_cmd() {
  // No-op.
}
qcontrol_cmd::type_t qcontrol_cmd::type_index() const {
  return mc_type;
}
string qcontrol_cmd::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void qcontrol_cmd::initialize() {
  clear();
}
void qcontrol_cmd::clear() {
  clear_content();
}
string qcontrol_cmd::print() const {
  return type_label()+","+print_content();
}
qcontrol_cmd& qcontrol_cmd::operator=(const qcontrol_cmd& rhs) {
  fm_trans_cmd = rhs.fm_trans_cmd;
  mode = rhs.mode;
  ch = rhs.ch;
  return *this;
}

void qcontrol_cmd::clear_content() {
  fm_trans_cmd.clear();
  mode.clear();
  ch = gnc::matrix<float,4,1>();
}
string qcontrol_cmd::print_content() const {
  std::ostringstream ss;
  ss << fm_trans_cmd.print();
  ss << mode.print();
  for (uint32 mpac_ijk1=0; mpac_ijk1<4; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << ch.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* qcontrol_cmd::serialize_content(uint8* buff) const {
  buff = fm_trans_cmd.serialize_content(buff);
  buff = mode.serialize_content(buff);
  buff = network::packet::serialize(buff,ch.buff()[0],4);
  return buff;
}
const uint8* qcontrol_cmd::deserialize_content(const uint8* buff) {
  buff = fm_trans_cmd.deserialize_content(buff);
  buff = mode.deserialize_content(buff);
  buff = network::packet::deserialize(buff,ch.buff()[0],4);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
