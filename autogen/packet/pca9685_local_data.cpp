////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/pca9685_local_data.cpp                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/pca9685_local_data.h"
using autogen::packet::pca9685_local_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

pca9685_local_data::pca9685_local_data() :
  network::packet(autogen::type::PCA9685_LOCAL_DATA) {
  initialize();
}
pca9685_local_data::~pca9685_local_data() {
  // No-op.
}
pca9685_local_data::type_t pca9685_local_data::type_index() const {
  return mc_type;
}
string pca9685_local_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void pca9685_local_data::initialize() {
  clear();
}
void pca9685_local_data::clear() {
  clear_content();
}
string pca9685_local_data::print() const {
  return type_label()+","+print_content();
}
pca9685_local_data& pca9685_local_data::operator=(const pca9685_local_data& rhs) {
  mode1_byte = rhs.mode1_byte;
  mode2_byte = rhs.mode2_byte;
  usec2counts = rhs.usec2counts;
  memcpy(time_table_usec[0],rhs.time_table_usec[0],64);
  calibration_complete = rhs.calibration_complete;
  i_calib_sample = rhs.i_calib_sample;
  return *this;
}

void pca9685_local_data::clear_content() {
  mode1_byte = 0;
  mode2_byte = 0;
  usec2counts = 0.0f;
  memset(time_table_usec[0],0,64);
  calibration_complete = 0;
  i_calib_sample = 0;
}
string pca9685_local_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << mode1_byte << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << mode2_byte << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << usec2counts << ",";
  for (uint32 mpac_ijk0=0; mpac_ijk0<16; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<2; ++mpac_ijk1) {
      ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << time_table_usec[mpac_ijk0][mpac_ijk1] << ",";;
    }
  }
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << calibration_complete << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << i_calib_sample << ",";
  return ss.str();
}
uint8* pca9685_local_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,mode1_byte,1);
  buff = network::packet::serialize(buff,mode2_byte,1);
  buff = network::packet::serialize(buff,usec2counts,1);
  for (uint32 mpac_ijk0=0; mpac_ijk0<16; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<2; ++mpac_ijk1) {
      buff = network::packet::serialize(buff,time_table_usec[mpac_ijk0][mpac_ijk1],32);;
    }
  }
  buff = network::packet::serialize(buff,calibration_complete,1);
  buff = network::packet::serialize(buff,i_calib_sample,1);
  return buff;
}
const uint8* pca9685_local_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,mode1_byte,1);
  buff = network::packet::deserialize(buff,mode2_byte,1);
  buff = network::packet::deserialize(buff,usec2counts,1);
  for (uint32 mpac_ijk0=0; mpac_ijk0<16; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<2; ++mpac_ijk1) {
      buff = network::packet::deserialize(buff,time_table_usec[mpac_ijk0][mpac_ijk1],32);;
    }
  }
  buff = network::packet::deserialize(buff,calibration_complete,1);
  buff = network::packet::deserialize(buff,i_calib_sample,1);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////