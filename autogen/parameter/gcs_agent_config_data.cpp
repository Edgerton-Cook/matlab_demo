////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/gcs_agent_config_data.cpp                                           //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/gcs_agent_config_data.h"
using autogen::parameter::gcs_agent_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

gcs_agent_config_data::gcs_agent_config_data() : network::parameter(autogen::type::GCS_AGENT_CONFIG_DATA) {
  initialize();
}
gcs_agent_config_data::gcs_agent_config_data(const string& filename) :
  network::parameter(autogen::type::GCS_AGENT_CONFIG_DATA) {
  load(filename);
}
gcs_agent_config_data::~gcs_agent_config_data() {
  // No-op.
}
gcs_agent_config_data::type_t gcs_agent_config_data::type_index() const {
  return mc_type;
}
string gcs_agent_config_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void gcs_agent_config_data::initialize() {
  clear();
}
void gcs_agent_config_data::clear() {
  clear_content();
}
string gcs_agent_config_data::print() const {
  return type_label()+","+print_content();
}
void gcs_agent_config_data::convert() {
}
void gcs_agent_config_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::gcs_agent_config_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void gcs_agent_config_data::save(const string& filename) const {
  utilities::message("autogen::parameter::gcs_agent_config_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
gcs_agent_config_data& gcs_agent_config_data::operator=(const gcs_agent_config_data& rhs) {
  rover_min_battery_voltage = rhs.rover_min_battery_voltage;
  rover_max_battery_voltage = rhs.rover_max_battery_voltage;
  quadrotor_min_battery_voltage = rhs.quadrotor_min_battery_voltage;
  quadrotor_max_battery_voltage = rhs.quadrotor_max_battery_voltage;
  pix_margin = rhs.pix_margin;
  southwest_pos_n = rhs.southwest_pos_n;
  southwest_pos_e = rhs.southwest_pos_e;
  northeast_pos_n = rhs.northeast_pos_n;
  northeast_pos_e = rhs.northeast_pos_e;
  display_text = rhs.display_text;
  return *this;
}

void gcs_agent_config_data::clear_content() {
  rover_min_battery_voltage = 0.0f;
  rover_max_battery_voltage = 0.0f;
  quadrotor_min_battery_voltage = 0.0f;
  quadrotor_max_battery_voltage = 0.0f;
  pix_margin = 0;
  southwest_pos_n = 0.0f;
  southwest_pos_e = 0.0f;
  northeast_pos_n = 0.0f;
  northeast_pos_e = 0.0f;
  display_text = 0;
}
string gcs_agent_config_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << rover_min_battery_voltage << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << rover_max_battery_voltage << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << quadrotor_min_battery_voltage << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << quadrotor_max_battery_voltage << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << pix_margin << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << southwest_pos_n << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << southwest_pos_e << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << northeast_pos_n << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << northeast_pos_e << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << display_text << ",";
  return ss.str();
}
uint8* gcs_agent_config_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,rover_min_battery_voltage,1);
  buff = network::packet::serialize(buff,rover_max_battery_voltage,1);
  buff = network::packet::serialize(buff,quadrotor_min_battery_voltage,1);
  buff = network::packet::serialize(buff,quadrotor_max_battery_voltage,1);
  buff = network::packet::serialize(buff,pix_margin,1);
  buff = network::packet::serialize(buff,southwest_pos_n,1);
  buff = network::packet::serialize(buff,southwest_pos_e,1);
  buff = network::packet::serialize(buff,northeast_pos_n,1);
  buff = network::packet::serialize(buff,northeast_pos_e,1);
  buff = network::packet::serialize(buff,display_text,1);
  return buff;
}
const uint8* gcs_agent_config_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,rover_min_battery_voltage,1);
  buff = network::packet::deserialize(buff,rover_max_battery_voltage,1);
  buff = network::packet::deserialize(buff,quadrotor_min_battery_voltage,1);
  buff = network::packet::deserialize(buff,quadrotor_max_battery_voltage,1);
  buff = network::packet::deserialize(buff,pix_margin,1);
  buff = network::packet::deserialize(buff,southwest_pos_n,1);
  buff = network::packet::deserialize(buff,southwest_pos_e,1);
  buff = network::packet::deserialize(buff,northeast_pos_n,1);
  buff = network::packet::deserialize(buff,northeast_pos_e,1);
  buff = network::packet::deserialize(buff,display_text,1);
  return buff;
}
void gcs_agent_config_data::load_content(utilities::ifile& file, const string& parent) {
  file.read_float(parent+"rover_min_battery_voltage",rover_min_battery_voltage);
  file.read_float(parent+"rover_max_battery_voltage",rover_max_battery_voltage);
  file.read_float(parent+"quadrotor_min_battery_voltage",quadrotor_min_battery_voltage);
  file.read_float(parent+"quadrotor_max_battery_voltage",quadrotor_max_battery_voltage);
  file.read_uint32(parent+"pix_margin",pix_margin);
  file.read_float(parent+"southwest_pos_n",southwest_pos_n);
  file.read_float(parent+"southwest_pos_e",southwest_pos_e);
  file.read_float(parent+"northeast_pos_n",northeast_pos_n);
  file.read_float(parent+"northeast_pos_e",northeast_pos_e);
  file.read_bool(parent+"display_text",display_text);
}
void gcs_agent_config_data::save_content(utilities::ofile& file, const string& parent) const {
  file.write_float(parent+"rover_min_battery_voltage",rover_min_battery_voltage);
  file.write_float(parent+"rover_max_battery_voltage",rover_max_battery_voltage);
  file.write_float(parent+"quadrotor_min_battery_voltage",quadrotor_min_battery_voltage);
  file.write_float(parent+"quadrotor_max_battery_voltage",quadrotor_max_battery_voltage);
  file.write_uint32(parent+"pix_margin",pix_margin);
  file.write_float(parent+"southwest_pos_n",southwest_pos_n);
  file.write_float(parent+"southwest_pos_e",southwest_pos_e);
  file.write_float(parent+"northeast_pos_n",northeast_pos_n);
  file.write_float(parent+"northeast_pos_e",northeast_pos_e);
  file.write_bool(parent+"display_text",display_text);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
