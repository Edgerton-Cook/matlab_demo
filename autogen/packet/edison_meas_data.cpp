////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/edison_meas_data.cpp                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/edison_meas_data.h"
using autogen::packet::edison_meas_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

edison_meas_data::edison_meas_data() :
  network::packet(autogen::type::EDISON_MEAS_DATA) {
  initialize();
}
edison_meas_data::~edison_meas_data() {
  // No-op.
}
edison_meas_data::type_t edison_meas_data::type_index() const {
  return mc_type;
}
string edison_meas_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void edison_meas_data::initialize() {
  clear();
}
void edison_meas_data::clear() {
  clear_content();
}
string edison_meas_data::print() const {
  return type_label()+","+print_content();
}
edison_meas_data& edison_meas_data::operator=(const edison_meas_data& rhs) {
  measured_pwm = rhs.measured_pwm;
  return *this;
}

void edison_meas_data::clear_content() {
  measured_pwm = 0.0f;
}
string edison_meas_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << measured_pwm << ",";
  return ss.str();
}
uint8* edison_meas_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,measured_pwm,1);
  return buff;
}
const uint8* edison_meas_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,measured_pwm,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
