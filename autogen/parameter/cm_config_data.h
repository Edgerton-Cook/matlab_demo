////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/cm_config_data.h                                                    //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_PARAMETER_CM_CONFIG_DATA_H
#define AUTOGEN_PARAMETER_CM_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "utilities/ifile.h"
#include "utilities/ofile.h"
#include "autogen/globals/globals.h"
#include "autogen/parameter/cm_subscriptions.h"
#include "autogen/parameter/cm_subscriptions.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace parameter {
    class cm_config_data : public network::parameter {
      public:
        uint8 master_ip1;
        uint8 master_ip2;
        uint8 master_ip3;
        uint8 master_ip4;
        uint16 master_port;
        uint32 max_mocap_data_counter;
        uint32 max_heartbeat_counter;
        bool guidance_computer_config;
        autogen::parameter::cm_subscriptions default_quad_subs;
        autogen::parameter::cm_subscriptions default_rover_subs;
        uint8 tablet_ip1;
        uint8 tablet_ip2;
        uint8 tablet_ip3;
        uint8 tablet_ip4;
        uint16 tablet_port;

      public:
        cm_config_data();
        cm_config_data(const std::string& filename);
        virtual ~cm_config_data();
        type_t type_index() const;
        std::string type_label() const;
        virtual void initialize();
        virtual void clear();
        virtual std::string print() const;
        void convert();
        void load(const std::string& filename);
        void save(const std::string& filename) const;
        cm_config_data& operator=(const cm_config_data& rhs);
      protected:
        void clear_content();
        std::string print_content() const;
        uint8* serialize_content(uint8* buff) const;
        const uint8* deserialize_content(const uint8* buff);
        void load_content(utilities::ifile& file, const std::string& parent);
        void save_content(utilities::ofile& file, const std::string& parent) const;

      friend class autogen::packet::cm_local_data;
      friend class autogen::packet::cm_module_data;
      friend class autogen::packet::cm_uplink_data;
      friend class autogen::packet::edison_local_data;
      friend class autogen::packet::edison_meas_data;
      friend class autogen::packet::edison_module_data;
      friend class autogen::packet::estimation_local_data;
      friend class autogen::packet::estimation_module_data;
      friend class autogen::packet::estimation_sig_data;
      friend class autogen::packet::fm_cmd_data;
      friend class autogen::packet::fm_cmd_states;
      friend class autogen::packet::fm_local_data;
      friend class autogen::packet::fm_module_data;
      friend class autogen::packet::heartbeat;
      friend class autogen::packet::hmc5883l_local_data;
      friend class autogen::packet::hmc5883l_meas_data;
      friend class autogen::packet::hmc5883l_module_data;
      friend class autogen::packet::led_cmd_blinking;
      friend class autogen::packet::led_cmd_data;
      friend class autogen::packet::led_cmd_nav;
      friend class autogen::packet::led_cmd_progress;
      friend class autogen::packet::led_cmd_solid;
      friend class autogen::packet::led_cmd_spinning;
      friend class autogen::packet::led_module_data;
      friend class autogen::packet::max11644eua_local_data;
      friend class autogen::packet::max11644eua_meas_data;
      friend class autogen::packet::max11644eua_module_data;
      friend class autogen::packet::mocap_data;
      friend class autogen::packet::mpu6000_local_data;
      friend class autogen::packet::mpu6000_meas_data;
      friend class autogen::packet::mpu6000_module_data;
      friend class autogen::packet::neom8_local_data;
      friend class autogen::packet::neom8_meas_data;
      friend class autogen::packet::neom8_module_data;
      friend class autogen::packet::pca9685_cmd_data;
      friend class autogen::packet::pca9685_local_data;
      friend class autogen::packet::pca9685_module_data;
      friend class autogen::packet::power_meas_data;
      friend class autogen::packet::power_module_data;
      friend class autogen::packet::qcontrol_cmd;
      friend class autogen::packet::qcontrol_local_data;
      friend class autogen::packet::qcontrol_module_data;
      friend class autogen::packet::qcontrol_sig_data;
      friend class autogen::packet::rcontrol_cmd;
      friend class autogen::packet::rcontrol_local_data;
      friend class autogen::packet::rcontrol_module_data;
      friend class autogen::packet::rcontrol_sig_data;
      friend class autogen::packet::sc18is602b_local_data;
      friend class autogen::packet::sc18is602b_module_data;
      friend class autogen::packet::telemetry;
      friend class autogen::packet::traj3dof;
      friend class autogen::packet::traj6dof;
      friend class autogen::state::cm_state;
      friend class autogen::state::edison_state;
      friend class autogen::state::estimation_state;
      friend class autogen::state::fm_state;
      friend class autogen::state::fm_trans_cmd;
      friend class autogen::state::hmc5883l_state;
      friend class autogen::state::led_state;
      friend class autogen::state::max11644eua_state;
      friend class autogen::state::mpu6000_state;
      friend class autogen::state::neom8_state;
      friend class autogen::state::ownership_state;
      friend class autogen::state::pca9685_state;
      friend class autogen::state::power_state;
      friend class autogen::state::qcontrol_mode;
      friend class autogen::state::qcontrol_state;
      friend class autogen::state::rcontrol_mode;
      friend class autogen::state::rcontrol_state;
      friend class autogen::state::sc18is602b_state;
      friend class autogen::state::veh_config_state;
      friend class autogen::parameter::cm_subscriptions;
      friend class autogen::parameter::edison_config_data;
      friend class autogen::parameter::estimation_config_data;
      friend class autogen::parameter::filter_gains;
      friend class autogen::parameter::fm_config_data;
      friend class autogen::parameter::gcs_agent_config_data;
      friend class autogen::parameter::hmc5883l_calib_data;
      friend class autogen::parameter::hmc5883l_config_data;
      friend class autogen::parameter::led_config_data;
      friend class autogen::parameter::mpu6000_calib_data;
      friend class autogen::parameter::mpu6000_config_data;
      friend class autogen::parameter::neom8_config_data;
      friend class autogen::parameter::pca9685_calib_data;
      friend class autogen::parameter::pca9685_config_data;
      friend class autogen::parameter::power_calib_data;
      friend class autogen::parameter::qcontrol_config_data;
      friend class autogen::parameter::rcontrol_config_data;
      friend class autogen::parameter::sc18is602b_config_data;
      friend class autogen::parameter::veh_config_data;
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
