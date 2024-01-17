////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/packet/fm_cmd_states.cpp                                                      //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/fm_cmd_states.h"
using autogen::packet::fm_cmd_states;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

fm_cmd_states::fm_cmd_states() :
  network::packet(autogen::type::FM_CMD_STATES) {
  initialize();
}
fm_cmd_states::~fm_cmd_states() {
  // No-op.
}
fm_cmd_states::type_t fm_cmd_states::type_index() const {
  return mc_type;
}
string fm_cmd_states::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void fm_cmd_states::initialize() {
  clear();
}
void fm_cmd_states::clear() {
  clear_content();
}
string fm_cmd_states::print() const {
  return type_label()+","+print_content();
}
fm_cmd_states& fm_cmd_states::operator=(const fm_cmd_states& rhs) {
  edison = rhs.edison;
  mpu6000 = rhs.mpu6000;
  hmc5883l = rhs.hmc5883l;
  neom8 = rhs.neom8;
  max11644eua = rhs.max11644eua;
  power = rhs.power;
  led = rhs.led;
  estimation = rhs.estimation;
  qcontrol = rhs.qcontrol;
  rcontrol = rhs.rcontrol;
  sc18is602b = rhs.sc18is602b;
  pca9685 = rhs.pca9685;
  return *this;
}

void fm_cmd_states::clear_content() {
  edison.clear();
  mpu6000.clear();
  hmc5883l.clear();
  neom8.clear();
  max11644eua.clear();
  power.clear();
  led.clear();
  estimation.clear();
  qcontrol.clear();
  rcontrol.clear();
  sc18is602b.clear();
  pca9685.clear();
}
string fm_cmd_states::print_content() const {
  std::ostringstream ss;
  ss << edison.print();
  ss << mpu6000.print();
  ss << hmc5883l.print();
  ss << neom8.print();
  ss << max11644eua.print();
  ss << power.print();
  ss << led.print();
  ss << estimation.print();
  ss << qcontrol.print();
  ss << rcontrol.print();
  ss << sc18is602b.print();
  ss << pca9685.print();
  return ss.str();
}
uint8* fm_cmd_states::serialize_content(uint8* buff) const {
  buff = edison.serialize_content(buff);
  buff = mpu6000.serialize_content(buff);
  buff = hmc5883l.serialize_content(buff);
  buff = neom8.serialize_content(buff);
  buff = max11644eua.serialize_content(buff);
  buff = power.serialize_content(buff);
  buff = led.serialize_content(buff);
  buff = estimation.serialize_content(buff);
  buff = qcontrol.serialize_content(buff);
  buff = rcontrol.serialize_content(buff);
  buff = sc18is602b.serialize_content(buff);
  buff = pca9685.serialize_content(buff);
  return buff;
}
const uint8* fm_cmd_states::deserialize_content(const uint8* buff) {
  buff = edison.deserialize_content(buff);
  buff = mpu6000.deserialize_content(buff);
  buff = hmc5883l.deserialize_content(buff);
  buff = neom8.deserialize_content(buff);
  buff = max11644eua.deserialize_content(buff);
  buff = power.deserialize_content(buff);
  buff = led.deserialize_content(buff);
  buff = estimation.deserialize_content(buff);
  buff = qcontrol.deserialize_content(buff);
  buff = rcontrol.deserialize_content(buff);
  buff = sc18is602b.deserialize_content(buff);
  buff = pca9685.deserialize_content(buff);
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
