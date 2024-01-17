////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/edison_local_data.cpp                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/edison_local_data.h"
using autogen::packet::edison_local_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

edison_local_data::edison_local_data() :
  network::packet(autogen::type::EDISON_LOCAL_DATA) {
  initialize();
}
edison_local_data::~edison_local_data() {
  // No-op.
}
edison_local_data::type_t edison_local_data::type_index() const {
  return mc_type;
}
string edison_local_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void edison_local_data::initialize() {
  clear();
}
void edison_local_data::clear() {
  clear_content();
}
string edison_local_data::print() const {
  return type_label()+","+print_content();
}
edison_local_data& edison_local_data::operator=(const edison_local_data& rhs) {
  fd = rhs.fd;
  return *this;
}

void edison_local_data::clear_content() {
  fd = 0;
}
string edison_local_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::showpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << fd << ",";
  return ss.str();
}
uint8* edison_local_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,fd,1);
  return buff;
}
const uint8* edison_local_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,fd,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
