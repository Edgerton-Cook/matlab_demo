////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/sc18is602b_local_data.cpp                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/sc18is602b_local_data.h"
using autogen::packet::sc18is602b_local_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

sc18is602b_local_data::sc18is602b_local_data() :
  network::packet(autogen::type::SC18IS602B_LOCAL_DATA) {
  initialize();
}
sc18is602b_local_data::~sc18is602b_local_data() {
  // No-op.
}
sc18is602b_local_data::type_t sc18is602b_local_data::type_index() const {
  return mc_type;
}
string sc18is602b_local_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void sc18is602b_local_data::initialize() {
  clear();
}
void sc18is602b_local_data::clear() {
  clear_content();
}
string sc18is602b_local_data::print() const {
  return type_label()+","+print_content();
}
sc18is602b_local_data& sc18is602b_local_data::operator=(const sc18is602b_local_data& rhs) {
  active_cs = rhs.active_cs;
  return *this;
}

void sc18is602b_local_data::clear_content() {
  active_cs = 0;
}
string sc18is602b_local_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << active_cs << ",";
  return ss.str();
}
uint8* sc18is602b_local_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,active_cs,1);
  return buff;
}
const uint8* sc18is602b_local_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,active_cs,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
