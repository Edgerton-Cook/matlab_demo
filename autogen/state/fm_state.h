////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/fm_state.h                                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_STATE_FM_STATE_H
#define AUTOGEN_STATE_FM_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/globals/globals.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace state {
    class fm_state : public network::state {
      public:
        enum STATE_T {
          BOOT,
          IDLE,
          INITIALIZE,
          ACTIVE,
          TEST_MODE,
          DEACTIVATE,
          CALIBRATE_IMU,
          CALIBRATE_MAG,
          CALIBRATE_PWM,
          CALIBRATE_ESC,
          SHUTDOWN,
          BEGIN = BOOT,
          END = SHUTDOWN
        };
        class state_machine {
          private:
            const std::string mc_name;
            state_t m_previous_accepted_state_index;
            state_t m_current_accepted_state_index;
            std::string m_previous_accepted_state_label;
            std::string m_current_accepted_state_label;

          public:
            state_machine(const std::string& name, STATE_T s);
            state_machine(const std::string& name, const fm_state& s);
            ~state_machine();
            STATE_T previous_state_index() const;
            STATE_T current_state_index() const;
            std::string previous_state_label() const;
            std::string current_state_label() const;
            void update(const fm_state& ref_state);
        };

      protected:
        static const bool s_transitions[11][11];

      public:
        fm_state();
        fm_state(STATE_T s);
        virtual ~fm_state();
        type_t type_index() const;
        std::string type_label() const;
        virtual void initialize();
        virtual void clear();
        virtual std::string print() const;
        STATE_T index() const;
        std::string label() const;
        fm_state& operator=(const fm_state& rhs);
        fm_state& operator=(STATE_T rhs);
        bool operator==(const fm_state& rhs) const;
        bool operator==(STATE_T rhs) const;
      protected:
        void clear_content();
        std::string print_content() const;
        uint8* serialize_content(uint8* buff) const;
        const uint8* deserialize_content(const uint8* buff);

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
      friend class autogen::parameter::cm_config_data;
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
