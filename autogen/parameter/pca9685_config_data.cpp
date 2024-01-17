////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/pca9685_config_data.cpp                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/pca9685_config_data.h"
using autogen::parameter::pca9685_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

pca9685_config_data::pca9685_config_data() : network::parameter(autogen::type::PCA9685_CONFIG_DATA) {
  initialize();
}
pca9685_config_data::pca9685_config_data(const string& filename) :
  network::parameter(autogen::type::PCA9685_CONFIG_DATA) {
  load(filename);
}
pca9685_config_data::~pca9685_config_data() {
  // No-op.
}
pca9685_config_data::type_t pca9685_config_data::type_index() const {
  return mc_type;
}
string pca9685_config_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void pca9685_config_data::initialize() {
  clear();
}
void pca9685_config_data::clear() {
  clear_content();
}
string pca9685_config_data::print() const {
  return type_label()+","+print_content();
}
void pca9685_config_data::convert() {
}
void pca9685_config_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::pca9685_config_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void pca9685_config_data::save(const string& filename) const {
  utilities::message("autogen::parameter::pca9685_config_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
pca9685_config_data& pca9685_config_data::operator=(const pca9685_config_data& rhs) {
  memcpy(min_pwm,rhs.min_pwm,64);
  memcpy(max_pwm,rhs.max_pwm,64);
  update_rate = rhs.update_rate;
  calib_update_rate = rhs.calib_update_rate;
  calib_ch = rhs.calib_ch;
  n_calib_samples = rhs.n_calib_samples;
  nominal_calib_pwm = rhs.nominal_calib_pwm;
  pwm_dlpf_factor = rhs.pwm_dlpf_factor;
  pwm_meas_outlier_margin = rhs.pwm_meas_outlier_margin;
  return *this;
}

void pca9685_config_data::clear_content() {
  memset(min_pwm,0,64);
  memset(max_pwm,0,64);
  update_rate = 0.0f;
  calib_update_rate = 0.0f;
  calib_ch = 0;
  n_calib_samples = 0;
  nominal_calib_pwm = 0.0f;
  pwm_dlpf_factor = 0.0f;
  pwm_meas_outlier_margin = 0.0f;
}
string pca9685_config_data::print_content() const {
  std::ostringstream ss;
  for (uint32 mpac_ijk0=0; mpac_ijk0<16; ++mpac_ijk0) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << min_pwm[mpac_ijk0] << ",";;
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<16; ++mpac_ijk0) {
    ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_pwm[mpac_ijk0] << ",";;
  }
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << update_rate << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << calib_update_rate << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << calib_ch << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << n_calib_samples << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << nominal_calib_pwm << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << pwm_dlpf_factor << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << pwm_meas_outlier_margin << ",";
  return ss.str();
}
uint8* pca9685_config_data::serialize_content(uint8* buff) const {
  for (uint32 mpac_ijk0=0; mpac_ijk0<16; ++mpac_ijk0) {
    buff = network::packet::serialize(buff,min_pwm[mpac_ijk0],16);;
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<16; ++mpac_ijk0) {
    buff = network::packet::serialize(buff,max_pwm[mpac_ijk0],16);;
  }
  buff = network::packet::serialize(buff,update_rate,1);
  buff = network::packet::serialize(buff,calib_update_rate,1);
  buff = network::packet::serialize(buff,calib_ch,1);
  buff = network::packet::serialize(buff,n_calib_samples,1);
  buff = network::packet::serialize(buff,nominal_calib_pwm,1);
  buff = network::packet::serialize(buff,pwm_dlpf_factor,1);
  buff = network::packet::serialize(buff,pwm_meas_outlier_margin,1);
  return buff;
}
const uint8* pca9685_config_data::deserialize_content(const uint8* buff) {
  for (uint32 mpac_ijk0=0; mpac_ijk0<16; ++mpac_ijk0) {
    buff = network::packet::deserialize(buff,min_pwm[mpac_ijk0],16);;
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<16; ++mpac_ijk0) {
    buff = network::packet::deserialize(buff,max_pwm[mpac_ijk0],16);;
  }
  buff = network::packet::deserialize(buff,update_rate,1);
  buff = network::packet::deserialize(buff,calib_update_rate,1);
  buff = network::packet::deserialize(buff,calib_ch,1);
  buff = network::packet::deserialize(buff,n_calib_samples,1);
  buff = network::packet::deserialize(buff,nominal_calib_pwm,1);
  buff = network::packet::deserialize(buff,pwm_dlpf_factor,1);
  buff = network::packet::deserialize(buff,pwm_meas_outlier_margin,1);
  return buff;
}
void pca9685_config_data::load_content(utilities::ifile& file, const string& parent) {
  for (uint32 mpac_ijk0=0; mpac_ijk0<16; ++mpac_ijk0) {
    std::ostringstream idx_ss;
    idx_ss << "[" << mpac_ijk0 << "]";
    file.read_float(parent+"min_pwm"+idx_ss.str(),min_pwm[mpac_ijk0]);
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<16; ++mpac_ijk0) {
    std::ostringstream idx_ss;
    idx_ss << "[" << mpac_ijk0 << "]";
    file.read_float(parent+"max_pwm"+idx_ss.str(),max_pwm[mpac_ijk0]);
  }
  file.read_float(parent+"update_rate",update_rate);
  file.read_float(parent+"calib_update_rate",calib_update_rate);
  file.read_uint8(parent+"calib_ch",calib_ch);
  file.read_uint32(parent+"n_calib_samples",n_calib_samples);
  file.read_float(parent+"nominal_calib_pwm",nominal_calib_pwm);
  file.read_float(parent+"pwm_dlpf_factor",pwm_dlpf_factor);
  file.read_float(parent+"pwm_meas_outlier_margin",pwm_meas_outlier_margin);
}
void pca9685_config_data::save_content(utilities::ofile& file, const string& parent) const {
  for (uint32 mpac_ijk0=0; mpac_ijk0<16; ++mpac_ijk0) {
    std::ostringstream idx_ss;
    idx_ss << "[" << mpac_ijk0 << "]";
    file.write_float(parent+"min_pwm"+idx_ss.str(),min_pwm[mpac_ijk0]);
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<16; ++mpac_ijk0) {
    std::ostringstream idx_ss;
    idx_ss << "[" << mpac_ijk0 << "]";
    file.write_float(parent+"max_pwm"+idx_ss.str(),max_pwm[mpac_ijk0]);
  }
  file.write_float(parent+"update_rate",update_rate);
  file.write_float(parent+"calib_update_rate",calib_update_rate);
  file.write_uint8(parent+"calib_ch",calib_ch);
  file.write_uint32(parent+"n_calib_samples",n_calib_samples);
  file.write_float(parent+"nominal_calib_pwm",nominal_calib_pwm);
  file.write_float(parent+"pwm_dlpf_factor",pwm_dlpf_factor);
  file.write_float(parent+"pwm_meas_outlier_margin",pwm_meas_outlier_margin);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
