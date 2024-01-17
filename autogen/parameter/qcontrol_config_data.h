////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/qcontrol_config_data.h                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_PARAMETER_QCONTROL_CONFIG_DATA_H
#define AUTOGEN_PARAMETER_QCONTROL_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "utilities/ifile.h"
#include "utilities/ofile.h"
#include "autogen/globals/globals.h"
#include "autogen/parameter/filter_gains.h"
#include "autogen/parameter/filter_gains.h"
#include "autogen/parameter/filter_gains.h"
#include "autogen/parameter/filter_gains.h"
#include "autogen/parameter/filter_gains.h"
#include "autogen/parameter/filter_gains.h"
#include "autogen/parameter/filter_gains.h"
#include "autogen/parameter/filter_gains.h"
#include "autogen/parameter/filter_gains.h"
#include "autogen/parameter/filter_gains.h"
#include "autogen/parameter/filter_gains.h"
#include "autogen/parameter/filter_gains.h"
#include "autogen/parameter/filter_gains.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace parameter {
    class qcontrol_config_data : public network::parameter {
      public:
        float zero_thrust_pwm;
        float dpwm_min;
        float dpwm_max;
        float a_dpwm2force;
        float b_dpwm2force;
        float c_dpwm2force;
        float alloc_tol;
        float z_guar;
        float k_force2torque;
        float l_moment_arm;
        float max_cmd_collective;
        float max_cmd_collective_rate;
        float max_cmd_torque_xy;
        float max_cmd_torque_z;
        float max_cmd_omega_xy_dps;
        float max_cmd_omega_z_dps;
        float min_cmd_sensed_g;
        float max_cmd_sensed_g;
        float max_cmd_delta_sensed_g;
        float max_cmd_clock_rate_dps;
        float max_cmd_tilt_deg;
        float max_hvel;
        float max_vvel;
        float tau_hvel_ref;
        float tau_vvel_ref;
        bool body_aligned_att_ctrl_cmd;
        bool body_aligned_trans_ctrl_cmd;
        bool enable_att_ctrl_tilt_prioritization;
        float att_ctrl_fb_max_omega_xy_dps;
        float att_ctrl_fb_max_omega_z_dps;
        float att_prefilt_J_xx;
        float att_prefilt_J_yy;
        float att_prefilt_J_zz;
        float att_prefilt_omega_xy_sat_dps;
        float att_prefilt_omega_z_sat_dps;
        float att_prefilt_tau_xy_sat;
        float att_prefilt_tau_z_sat;
        float att_prefilt_k_p_xy;
        float att_prefilt_k_p_z;
        float att_prefilt_k_d_xy;
        float att_prefilt_k_d_z;
        uint32 att_prefilt_n_steps;
        float min_sensed_ver_accl_g;
        float max_sensed_ver_accl_g;
        float max_tilt_deg;
        float tilt_comp_threshold_deg;
        autogen::parameter::filter_gains F_tau[3][10];
        autogen::parameter::filter_gains F_xyz[3][15];
        autogen::parameter::filter_gains P_xyz[3][15];
        autogen::parameter::filter_gains C_xyz[3][15];
        autogen::parameter::filter_gains W_xyz[3][20];
        autogen::parameter::filter_gains F_c[1][15];
        autogen::parameter::filter_gains P_c[1][15];
        autogen::parameter::filter_gains C_c[1][15];
        autogen::parameter::filter_gains W_c[1][20];
        autogen::parameter::filter_gains C_att[3][10];
        autogen::parameter::filter_gains C_id_trans[3][15];
        autogen::parameter::filter_gains C_od_trans_pos[3][15];
        autogen::parameter::filter_gains C_od_trans_vel[3][15];
      public:
        float max_cmd_omega_xy;
        float max_cmd_omega_z;
        float max_cmd_clock_rate;
        float max_cmd_tilt;
        float att_ctrl_fb_max_omega_xy;
        float att_ctrl_fb_max_omega_z;
        float att_prefilt_omega_xy_sat;
        float att_prefilt_omega_z_sat;
        float min_sensed_ver_accl;
        float max_sensed_ver_accl;
        float max_tilt;
        float tilt_comp_threshold;

      public:
        qcontrol_config_data();
        qcontrol_config_data(const std::string& filename);
        virtual ~qcontrol_config_data();
        type_t type_index() const;
        std::string type_label() const;
        virtual void initialize();
        virtual void clear();
        virtual std::string print() const;
        void convert();
        void load(const std::string& filename);
        void save(const std::string& filename) const;
        qcontrol_config_data& operator=(const qcontrol_config_data& rhs);
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
      friend class autogen::parameter::rcontrol_config_data;
      friend class autogen::parameter::sc18is602b_config_data;
      friend class autogen::parameter::veh_config_data;
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
