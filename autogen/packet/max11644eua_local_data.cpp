////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/max11644eua_local_data.cpp                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/max11644eua_local_data.h"
using autogen::packet::max11644eua_local_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

max11644eua_local_data::max11644eua_local_data() :
  network::packet(autogen::type::MAX11644EUA_LOCAL_DATA) {
  initialize();
}
max11644eua_local_data::~max11644eua_local_data() {
  // No-op.
}
max11644eua_local_data::type_t max11644eua_local_data::type_index() const {
  return mc_type;
}
string max11644eua_local_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void max11644eua_local_data::initialize() {
  clear();
}
void max11644eua_local_data::clear() {
  clear_content();
}
string max11644eua_local_data::print() const {
  return type_label()+","+print_content();
}
max11644eua_local_data& max11644eua_local_data::operator=(const max11644eua_local_data& rhs) {
  counts_to_volts = rhs.counts_to_volts;
  return *this;
}

void max11644eua_local_data::clear_content() {
  counts_to_volts = 0.0f;
}
string max11644eua_local_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << counts_to_volts << ",";
  return ss.str();
}
uint8* max11644eua_local_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,counts_to_volts,1);
  return buff;
}
const uint8* max11644eua_local_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,counts_to_volts,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
