////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/fm_config_data.cpp                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/fm_config_data.h"
using autogen::parameter::fm_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

fm_config_data::fm_config_data() : network::parameter(autogen::type::FM_CONFIG_DATA) {
  initialize();
}
fm_config_data::fm_config_data(const string& filename) :
  network::parameter(autogen::type::FM_CONFIG_DATA) {
  load(filename);
}
fm_config_data::~fm_config_data() {
  // No-op.
}
fm_config_data::type_t fm_config_data::type_index() const {
  return mc_type;
}
string fm_config_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void fm_config_data::initialize() {
  clear();
}
void fm_config_data::clear() {
  clear_content();
}
string fm_config_data::print() const {
  return type_label()+","+print_content();
}
void fm_config_data::convert() {
}
void fm_config_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::fm_config_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void fm_config_data::save(const string& filename) const {
  utilities::message("autogen::parameter::fm_config_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
fm_config_data& fm_config_data::operator=(const fm_config_data& rhs) {
  calib_blinking_freq = rhs.calib_blinking_freq;
  calib_color_intensity = rhs.calib_color_intensity;
  calib_complete_steps = rhs.calib_complete_steps;
  esc_green_countdown_steps = rhs.esc_green_countdown_steps;
  esc_red_countdown_steps = rhs.esc_red_countdown_steps;
  return *this;
}

void fm_config_data::clear_content() {
  calib_blinking_freq = 0.0f;
  calib_color_intensity = 0;
  calib_complete_steps = 0;
  esc_green_countdown_steps = 0;
  esc_red_countdown_steps = 0;
}
string fm_config_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << calib_blinking_freq << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << calib_color_intensity << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << calib_complete_steps << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << esc_green_countdown_steps << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << esc_red_countdown_steps << ",";
  return ss.str();
}
uint8* fm_config_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,calib_blinking_freq,1);
  buff = network::packet::serialize(buff,calib_color_intensity,1);
  buff = network::packet::serialize(buff,calib_complete_steps,1);
  buff = network::packet::serialize(buff,esc_green_countdown_steps,1);
  buff = network::packet::serialize(buff,esc_red_countdown_steps,1);
  return buff;
}
const uint8* fm_config_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,calib_blinking_freq,1);
  buff = network::packet::deserialize(buff,calib_color_intensity,1);
  buff = network::packet::deserialize(buff,calib_complete_steps,1);
  buff = network::packet::deserialize(buff,esc_green_countdown_steps,1);
  buff = network::packet::deserialize(buff,esc_red_countdown_steps,1);
  return buff;
}
void fm_config_data::load_content(utilities::ifile& file, const string& parent) {
  file.read_float(parent+"calib_blinking_freq",calib_blinking_freq);
  file.read_uint8(parent+"calib_color_intensity",calib_color_intensity);
  file.read_uint32(parent+"calib_complete_steps",calib_complete_steps);
  file.read_uint32(parent+"esc_green_countdown_steps",esc_green_countdown_steps);
  file.read_uint32(parent+"esc_red_countdown_steps",esc_red_countdown_steps);
}
void fm_config_data::save_content(utilities::ofile& file, const string& parent) const {
  file.write_float(parent+"calib_blinking_freq",calib_blinking_freq);
  file.write_uint8(parent+"calib_color_intensity",calib_color_intensity);
  file.write_uint32(parent+"calib_complete_steps",calib_complete_steps);
  file.write_uint32(parent+"esc_green_countdown_steps",esc_green_countdown_steps);
  file.write_uint32(parent+"esc_red_countdown_steps",esc_red_countdown_steps);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
