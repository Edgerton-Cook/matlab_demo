////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/qcontrol_local_data.cpp                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/qcontrol_local_data.h"
using autogen::packet::qcontrol_local_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

qcontrol_local_data::qcontrol_local_data() :
  network::packet(autogen::type::QCONTROL_LOCAL_DATA) {
  initialize();
}
qcontrol_local_data::~qcontrol_local_data() {
  // No-op.
}
qcontrol_local_data::type_t qcontrol_local_data::type_index() const {
  return mc_type;
}
string qcontrol_local_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void qcontrol_local_data::initialize() {
  clear();
}
void qcontrol_local_data::clear() {
  clear_content();
}
string qcontrol_local_data::print() const {
  return type_label()+","+print_content();
}
qcontrol_local_data& qcontrol_local_data::operator=(const qcontrol_local_data& rhs) {
  H_f2w = rhs.H_f2w;
  return *this;
}

void qcontrol_local_data::clear_content() {
  H_f2w = gnc::matrix<float,4,4>();
}
string qcontrol_local_data::print_content() const {
  std::ostringstream ss;
  for (uint32 mpac_ijk1=0; mpac_ijk1<16; ++mpac_ijk1) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << H_f2w.buff()[mpac_ijk1] << ",";
  }
  return ss.str();
}
uint8* qcontrol_local_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,H_f2w.buff()[0],16);
  return buff;
}
const uint8* qcontrol_local_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,H_f2w.buff()[0],16);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
