////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/bus/data_bus.cpp                                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/bus/data_bus.h"
using autogen::bus::data_bus;

////////////////////////////////////////////////////////////////////////////////////////////////////

void data_bus::clear() {
  ts = 0;
  veh_config_data.clear();
  veh_config_state.clear();
  fm.clear();
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
  cm.clear();
}
void data_bus::initialize() {
  ts = 0;
  veh_config_data.initialize();
  veh_config_state.initialize();
  fm.initialize();
  edison.initialize();
  mpu6000.initialize();
  hmc5883l.initialize();
  neom8.initialize();
  max11644eua.initialize();
  power.initialize();
  led.initialize();
  estimation.initialize();
  qcontrol.initialize();
  rcontrol.initialize();
  sc18is602b.initialize();
  pca9685.initialize();
  cm.initialize();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
