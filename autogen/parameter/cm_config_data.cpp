////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/cm_config_data.cpp                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/cm_config_data.h"
using autogen::parameter::cm_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

cm_config_data::cm_config_data() : network::parameter(autogen::type::CM_CONFIG_DATA) {
  initialize();
}
cm_config_data::cm_config_data(const string& filename) :
  network::parameter(autogen::type::CM_CONFIG_DATA) {
  load(filename);
}
cm_config_data::~cm_config_data() {
  // No-op.
}
cm_config_data::type_t cm_config_data::type_index() const {
  return mc_type;
}
string cm_config_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void cm_config_data::initialize() {
  clear();
}
void cm_config_data::clear() {
  clear_content();
}
string cm_config_data::print() const {
  return type_label()+","+print_content();
}
void cm_config_data::convert() {
  default_quad_subs.convert();
  default_rover_subs.convert();
}
void cm_config_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::cm_config_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void cm_config_data::save(const string& filename) const {
  utilities::message("autogen::parameter::cm_config_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
cm_config_data& cm_config_data::operator=(const cm_config_data& rhs) {
  master_ip1 = rhs.master_ip1;
  master_ip2 = rhs.master_ip2;
  master_ip3 = rhs.master_ip3;
  master_ip4 = rhs.master_ip4;
  master_port = rhs.master_port;
  max_mocap_data_counter = rhs.max_mocap_data_counter;
  max_heartbeat_counter = rhs.max_heartbeat_counter;
  guidance_computer_config = rhs.guidance_computer_config;
  default_quad_subs = rhs.default_quad_subs;
  default_rover_subs = rhs.default_rover_subs;
  tablet_ip1 = rhs.tablet_ip1;
  tablet_ip2 = rhs.tablet_ip2;
  tablet_ip3 = rhs.tablet_ip3;
  tablet_ip4 = rhs.tablet_ip4;
  tablet_port = rhs.tablet_port;
  return *this;
}

void cm_config_data::clear_content() {
  master_ip1 = 0;
  master_ip2 = 0;
  master_ip3 = 0;
  master_ip4 = 0;
  master_port = 0;
  max_mocap_data_counter = 0;
  max_heartbeat_counter = 0;
  guidance_computer_config = 0;
  default_quad_subs.clear();
  default_rover_subs.clear();
  tablet_ip1 = 0;
  tablet_ip2 = 0;
  tablet_ip3 = 0;
  tablet_ip4 = 0;
  tablet_port = 0;
}
string cm_config_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << master_ip1 << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << master_ip2 << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << master_ip3 << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << master_ip4 << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << master_port << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << max_mocap_data_counter << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << max_heartbeat_counter << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << guidance_computer_config << ",";
  ss << default_quad_subs.print();
  ss << default_rover_subs.print();
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << tablet_ip1 << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << tablet_ip2 << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << tablet_ip3 << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << tablet_ip4 << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << tablet_port << ",";
  return ss.str();
}
uint8* cm_config_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,master_ip1,1);
  buff = network::packet::serialize(buff,master_ip2,1);
  buff = network::packet::serialize(buff,master_ip3,1);
  buff = network::packet::serialize(buff,master_ip4,1);
  buff = network::packet::serialize(buff,master_port,1);
  buff = network::packet::serialize(buff,max_mocap_data_counter,1);
  buff = network::packet::serialize(buff,max_heartbeat_counter,1);
  buff = network::packet::serialize(buff,guidance_computer_config,1);
  buff = default_quad_subs.serialize_content(buff);
  buff = default_rover_subs.serialize_content(buff);
  buff = network::packet::serialize(buff,tablet_ip1,1);
  buff = network::packet::serialize(buff,tablet_ip2,1);
  buff = network::packet::serialize(buff,tablet_ip3,1);
  buff = network::packet::serialize(buff,tablet_ip4,1);
  buff = network::packet::serialize(buff,tablet_port,1);
  return buff;
}
const uint8* cm_config_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,master_ip1,1);
  buff = network::packet::deserialize(buff,master_ip2,1);
  buff = network::packet::deserialize(buff,master_ip3,1);
  buff = network::packet::deserialize(buff,master_ip4,1);
  buff = network::packet::deserialize(buff,master_port,1);
  buff = network::packet::deserialize(buff,max_mocap_data_counter,1);
  buff = network::packet::deserialize(buff,max_heartbeat_counter,1);
  buff = network::packet::deserialize(buff,guidance_computer_config,1);
  buff = default_quad_subs.deserialize_content(buff);
  buff = default_rover_subs.deserialize_content(buff);
  buff = network::packet::deserialize(buff,tablet_ip1,1);
  buff = network::packet::deserialize(buff,tablet_ip2,1);
  buff = network::packet::deserialize(buff,tablet_ip3,1);
  buff = network::packet::deserialize(buff,tablet_ip4,1);
  buff = network::packet::deserialize(buff,tablet_port,1);
  return buff;
}
void cm_config_data::load_content(utilities::ifile& file, const string& parent) {
  file.read_uint8(parent+"master_ip1",master_ip1);
  file.read_uint8(parent+"master_ip2",master_ip2);
  file.read_uint8(parent+"master_ip3",master_ip3);
  file.read_uint8(parent+"master_ip4",master_ip4);
  file.read_uint16(parent+"master_port",master_port);
  file.read_uint32(parent+"max_mocap_data_counter",max_mocap_data_counter);
  file.read_uint32(parent+"max_heartbeat_counter",max_heartbeat_counter);
  file.read_bool(parent+"guidance_computer_config",guidance_computer_config);
  default_quad_subs.load_content(file,parent+"default_quad_subs.");
  default_rover_subs.load_content(file,parent+"default_rover_subs.");
  file.read_uint8(parent+"tablet_ip1",tablet_ip1);
  file.read_uint8(parent+"tablet_ip2",tablet_ip2);
  file.read_uint8(parent+"tablet_ip3",tablet_ip3);
  file.read_uint8(parent+"tablet_ip4",tablet_ip4);
  file.read_uint16(parent+"tablet_port",tablet_port);
}
void cm_config_data::save_content(utilities::ofile& file, const string& parent) const {
  file.write_uint8(parent+"master_ip1",master_ip1);
  file.write_uint8(parent+"master_ip2",master_ip2);
  file.write_uint8(parent+"master_ip3",master_ip3);
  file.write_uint8(parent+"master_ip4",master_ip4);
  file.write_uint16(parent+"master_port",master_port);
  file.write_uint32(parent+"max_mocap_data_counter",max_mocap_data_counter);
  file.write_uint32(parent+"max_heartbeat_counter",max_heartbeat_counter);
  file.write_bool(parent+"guidance_computer_config",guidance_computer_config);
  default_quad_subs.save_content(file,parent+"default_quad_subs.");
  default_rover_subs.save_content(file,parent+"default_rover_subs.");
  file.write_uint8(parent+"tablet_ip1",tablet_ip1);
  file.write_uint8(parent+"tablet_ip2",tablet_ip2);
  file.write_uint8(parent+"tablet_ip3",tablet_ip3);
  file.write_uint8(parent+"tablet_ip4",tablet_ip4);
  file.write_uint16(parent+"tablet_port",tablet_port);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
