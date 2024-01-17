////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/bus/data_bus.h                                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_BUS_DATA_BUS_H
#define AUTOGEN_BUS_DATA_BUS_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/veh_config_data.h"
#include "autogen/state/veh_config_state.h"
#include "autogen/packet/fm_module_data.h"
#include "autogen/packet/edison_module_data.h"
#include "autogen/packet/mpu6000_module_data.h"
#include "autogen/packet/hmc5883l_module_data.h"
#include "autogen/packet/neom8_module_data.h"
#include "autogen/packet/max11644eua_module_data.h"
#include "autogen/packet/power_module_data.h"
#include "autogen/packet/led_module_data.h"
#include "autogen/packet/estimation_module_data.h"
#include "autogen/packet/qcontrol_module_data.h"
#include "autogen/packet/rcontrol_module_data.h"
#include "autogen/packet/sc18is602b_module_data.h"
#include "autogen/packet/pca9685_module_data.h"
#include "autogen/packet/cm_module_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace bus {
    struct data_bus {
      network::timestamped::ts_t ts;
      parameter::veh_config_data veh_config_data;
      state::veh_config_state veh_config_state;
      packet::fm_module_data fm;
      packet::edison_module_data edison;
      packet::mpu6000_module_data mpu6000;
      packet::hmc5883l_module_data hmc5883l;
      packet::neom8_module_data neom8;
      packet::max11644eua_module_data max11644eua;
      packet::power_module_data power;
      packet::led_module_data led;
      packet::estimation_module_data estimation;
      packet::qcontrol_module_data qcontrol;
      packet::rcontrol_module_data rcontrol;
      packet::sc18is602b_module_data sc18is602b;
      packet::pca9685_module_data pca9685;
      packet::cm_module_data cm;

      void clear();
      void initialize();
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
