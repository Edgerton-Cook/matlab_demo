////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/heartbeat.cpp                                                          //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/heartbeat.h"
using autogen::packet::heartbeat;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

heartbeat::heartbeat() :
  network::packet(autogen::type::HEARTBEAT) {
  initialize();
}
heartbeat::~heartbeat() {
  // No-op.
}
heartbeat::type_t heartbeat::type_index() const {
  return mc_type;
}
string heartbeat::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void heartbeat::initialize() {
  clear();
}
void heartbeat::clear() {
  clear_content();
}
string heartbeat::print() const {
  return type_label()+","+print_content();
}
heartbeat& heartbeat::operator=(const heartbeat& rhs) {
  request_ownership = rhs.request_ownership;
  emergency_shutdown = rhs.emergency_shutdown;
  return *this;
}

void heartbeat::clear_content() {
  request_ownership = 0;
  emergency_shutdown = 0;
}
string heartbeat::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << request_ownership << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << emergency_shutdown << ",";
  return ss.str();
}
uint8* heartbeat::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,request_ownership,1);
  buff = network::packet::serialize(buff,emergency_shutdown,1);
  return buff;
}
const uint8* heartbeat::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,request_ownership,1);
  buff = network::packet::deserialize(buff,emergency_shutdown,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
