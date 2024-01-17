////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/max11644eua_meas_data.cpp                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/max11644eua_meas_data.h"
using autogen::packet::max11644eua_meas_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

max11644eua_meas_data::max11644eua_meas_data() :
  network::packet(autogen::type::MAX11644EUA_MEAS_DATA) {
  initialize();
}
max11644eua_meas_data::~max11644eua_meas_data() {
  // No-op.
}
max11644eua_meas_data::type_t max11644eua_meas_data::type_index() const {
  return mc_type;
}
string max11644eua_meas_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void max11644eua_meas_data::initialize() {
  clear();
}
void max11644eua_meas_data::clear() {
  clear_content();
}
string max11644eua_meas_data::print() const {
  return type_label()+","+print_content();
}
max11644eua_meas_data& max11644eua_meas_data::operator=(const max11644eua_meas_data& rhs) {
  ain_0 = rhs.ain_0;
  ain_1 = rhs.ain_1;
  return *this;
}

void max11644eua_meas_data::clear_content() {
  ain_0 = 0.0f;
  ain_1 = 0.0f;
}
string max11644eua_meas_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << ain_0 << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << ain_1 << ",";
  return ss.str();
}
uint8* max11644eua_meas_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,ain_0,1);
  buff = network::packet::serialize(buff,ain_1,1);
  return buff;
}
const uint8* max11644eua_meas_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,ain_0,1);
  buff = network::packet::deserialize(buff,ain_1,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
