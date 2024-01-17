////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/rcontrol_config_data.cpp                                            //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/rcontrol_config_data.h"
using autogen::parameter::rcontrol_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

rcontrol_config_data::rcontrol_config_data() : network::parameter(autogen::type::RCONTROL_CONFIG_DATA) {
  initialize();
}
rcontrol_config_data::rcontrol_config_data(const string& filename) :
  network::parameter(autogen::type::RCONTROL_CONFIG_DATA) {
  load(filename);
}
rcontrol_config_data::~rcontrol_config_data() {
  // No-op.
}
rcontrol_config_data::type_t rcontrol_config_data::type_index() const {
  return mc_type;
}
string rcontrol_config_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void rcontrol_config_data::initialize() {
  clear();
}
void rcontrol_config_data::clear() {
  clear_content();
}
string rcontrol_config_data::print() const {
  return type_label()+","+print_content();
}
void rcontrol_config_data::convert() {
  cl_max_ang_rate = (cl_max_ang_rate_dps*0.017453292519943f);
}
void rcontrol_config_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::rcontrol_config_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void rcontrol_config_data::save(const string& filename) const {
  utilities::message("autogen::parameter::rcontrol_config_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
rcontrol_config_data& rcontrol_config_data::operator=(const rcontrol_config_data& rhs) {
  test_mode_base_pwm = rhs.test_mode_base_pwm;
  test_mode_delta_pwm = rhs.test_mode_delta_pwm;
  ol_base_pwm = rhs.ol_base_pwm;
  ol_delta_pwm = rhs.ol_delta_pwm;
  cl_base_pwm = rhs.cl_base_pwm;
  cl_max_vel = rhs.cl_max_vel;
  cl_max_ang_rate_dps = rhs.cl_max_ang_rate_dps;
  cl_kp_pos = rhs.cl_kp_pos;
  cl_kp_hdg = rhs.cl_kp_hdg;
  cl_u_vf_sat = rhs.cl_u_vf_sat;
  cl_u_vs_sat = rhs.cl_u_vs_sat;
  cl_u_vh_sat = rhs.cl_u_vh_sat;
  return *this;
}

void rcontrol_config_data::clear_content() {
  test_mode_base_pwm = 0.0f;
  test_mode_delta_pwm = 0.0f;
  ol_base_pwm = 0.0f;
  ol_delta_pwm = 0.0f;
  cl_base_pwm = 0.0f;
  cl_max_vel = 0.0f;
  cl_max_ang_rate_dps = 0.0f;
  cl_max_ang_rate = 0.0f;
  cl_kp_pos = 0.0f;
  cl_kp_hdg = 0.0f;
  cl_u_vf_sat = 0.0f;
  cl_u_vs_sat = 0.0f;
  cl_u_vh_sat = 0.0f;
}
string rcontrol_config_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << test_mode_base_pwm << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << test_mode_delta_pwm << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << ol_base_pwm << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << ol_delta_pwm << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << cl_base_pwm << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << cl_max_vel << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << cl_max_ang_rate_dps << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << cl_kp_pos << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << cl_kp_hdg << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << cl_u_vf_sat << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << cl_u_vs_sat << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << cl_u_vh_sat << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << cl_max_ang_rate << ",";
  return ss.str();
}
uint8* rcontrol_config_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,test_mode_base_pwm,1);
  buff = network::packet::serialize(buff,test_mode_delta_pwm,1);
  buff = network::packet::serialize(buff,ol_base_pwm,1);
  buff = network::packet::serialize(buff,ol_delta_pwm,1);
  buff = network::packet::serialize(buff,cl_base_pwm,1);
  buff = network::packet::serialize(buff,cl_max_vel,1);
  buff = network::packet::serialize(buff,cl_max_ang_rate_dps,1);
  buff = network::packet::serialize(buff,cl_kp_pos,1);
  buff = network::packet::serialize(buff,cl_kp_hdg,1);
  buff = network::packet::serialize(buff,cl_u_vf_sat,1);
  buff = network::packet::serialize(buff,cl_u_vs_sat,1);
  buff = network::packet::serialize(buff,cl_u_vh_sat,1);
  return buff;
}
const uint8* rcontrol_config_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,test_mode_base_pwm,1);
  buff = network::packet::deserialize(buff,test_mode_delta_pwm,1);
  buff = network::packet::deserialize(buff,ol_base_pwm,1);
  buff = network::packet::deserialize(buff,ol_delta_pwm,1);
  buff = network::packet::deserialize(buff,cl_base_pwm,1);
  buff = network::packet::deserialize(buff,cl_max_vel,1);
  buff = network::packet::deserialize(buff,cl_max_ang_rate_dps,1);
  buff = network::packet::deserialize(buff,cl_kp_pos,1);
  buff = network::packet::deserialize(buff,cl_kp_hdg,1);
  buff = network::packet::deserialize(buff,cl_u_vf_sat,1);
  buff = network::packet::deserialize(buff,cl_u_vs_sat,1);
  buff = network::packet::deserialize(buff,cl_u_vh_sat,1);
  return buff;
}
void rcontrol_config_data::load_content(utilities::ifile& file, const string& parent) {
  file.read_float(parent+"test_mode_base_pwm",test_mode_base_pwm);
  file.read_float(parent+"test_mode_delta_pwm",test_mode_delta_pwm);
  file.read_float(parent+"ol_base_pwm",ol_base_pwm);
  file.read_float(parent+"ol_delta_pwm",ol_delta_pwm);
  file.read_float(parent+"cl_base_pwm",cl_base_pwm);
  file.read_float(parent+"cl_max_vel",cl_max_vel);
  file.read_float(parent+"cl_max_ang_rate_dps",cl_max_ang_rate_dps);
  file.read_float(parent+"cl_kp_pos",cl_kp_pos);
  file.read_float(parent+"cl_kp_hdg",cl_kp_hdg);
  file.read_float(parent+"cl_u_vf_sat",cl_u_vf_sat);
  file.read_float(parent+"cl_u_vs_sat",cl_u_vs_sat);
  file.read_float(parent+"cl_u_vh_sat",cl_u_vh_sat);
}
void rcontrol_config_data::save_content(utilities::ofile& file, const string& parent) const {
  file.write_float(parent+"test_mode_base_pwm",test_mode_base_pwm);
  file.write_float(parent+"test_mode_delta_pwm",test_mode_delta_pwm);
  file.write_float(parent+"ol_base_pwm",ol_base_pwm);
  file.write_float(parent+"ol_delta_pwm",ol_delta_pwm);
  file.write_float(parent+"cl_base_pwm",cl_base_pwm);
  file.write_float(parent+"cl_max_vel",cl_max_vel);
  file.write_float(parent+"cl_max_ang_rate_dps",cl_max_ang_rate_dps);
  file.write_float(parent+"cl_kp_pos",cl_kp_pos);
  file.write_float(parent+"cl_kp_hdg",cl_kp_hdg);
  file.write_float(parent+"cl_u_vf_sat",cl_u_vf_sat);
  file.write_float(parent+"cl_u_vs_sat",cl_u_vs_sat);
  file.write_float(parent+"cl_u_vh_sat",cl_u_vh_sat);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
