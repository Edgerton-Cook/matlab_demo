////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/parameter/qcontrol_config_data.cpp                                            //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/qcontrol_config_data.h"
using autogen::parameter::qcontrol_config_data;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

qcontrol_config_data::qcontrol_config_data() : network::parameter(autogen::type::QCONTROL_CONFIG_DATA) {
  initialize();
}
qcontrol_config_data::qcontrol_config_data(const string& filename) :
  network::parameter(autogen::type::QCONTROL_CONFIG_DATA) {
  load(filename);
}
qcontrol_config_data::~qcontrol_config_data() {
  // No-op.
}
qcontrol_config_data::type_t qcontrol_config_data::type_index() const {
  return mc_type;
}
string qcontrol_config_data::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void qcontrol_config_data::initialize() {
  clear();
}
void qcontrol_config_data::clear() {
  clear_content();
}
string qcontrol_config_data::print() const {
  return type_label()+","+print_content();
}
void qcontrol_config_data::convert() {
  max_cmd_omega_xy = (max_cmd_omega_xy_dps*0.017453292519943f);
  max_cmd_omega_z = (max_cmd_omega_z_dps*0.017453292519943f);
  max_cmd_clock_rate = (max_cmd_clock_rate_dps*0.017453292519943f);
  max_cmd_tilt = (max_cmd_tilt_deg*0.017453292519943f);
  att_ctrl_fb_max_omega_xy = (att_ctrl_fb_max_omega_xy_dps*0.017453292519943f);
  att_ctrl_fb_max_omega_z = (att_ctrl_fb_max_omega_z_dps*0.017453292519943f);
  att_prefilt_omega_xy_sat = (att_prefilt_omega_xy_sat_dps*0.017453292519943f);
  att_prefilt_omega_z_sat = (att_prefilt_omega_z_sat_dps*0.017453292519943f);
  min_sensed_ver_accl = (min_sensed_ver_accl_g*9.80665f);
  max_sensed_ver_accl = (max_sensed_ver_accl_g*9.80665f);
  max_tilt = (max_tilt_deg*0.017453292519943f);
  tilt_comp_threshold = (tilt_comp_threshold_deg*0.017453292519943f);
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<10; ++mpac_ijk1) {
      F_tau[mpac_ijk0][mpac_ijk1].convert();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      F_xyz[mpac_ijk0][mpac_ijk1].convert();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      P_xyz[mpac_ijk0][mpac_ijk1].convert();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_xyz[mpac_ijk0][mpac_ijk1].convert();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<20; ++mpac_ijk1) {
      W_xyz[mpac_ijk0][mpac_ijk1].convert();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      F_c[mpac_ijk0][mpac_ijk1].convert();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      P_c[mpac_ijk0][mpac_ijk1].convert();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_c[mpac_ijk0][mpac_ijk1].convert();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<20; ++mpac_ijk1) {
      W_c[mpac_ijk0][mpac_ijk1].convert();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<10; ++mpac_ijk1) {
      C_att[mpac_ijk0][mpac_ijk1].convert();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_id_trans[mpac_ijk0][mpac_ijk1].convert();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_od_trans_pos[mpac_ijk0][mpac_ijk1].convert();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_od_trans_vel[mpac_ijk0][mpac_ijk1].convert();
    }
  }
}
void qcontrol_config_data::load(const string& filename) {
  clear();
  utilities::message("autogen::parameter::qcontrol_config_data::load","loading files from "+filename);
  utilities::ifile file(filename);
  load_content(file,"");
  convert();
}
void qcontrol_config_data::save(const string& filename) const {
  utilities::message("autogen::parameter::qcontrol_config_data::save","saving files to "+filename);
  utilities::ofile file(filename,utilities::ofile::OVERWRITE);
  save_content(file,"");
}
qcontrol_config_data& qcontrol_config_data::operator=(const qcontrol_config_data& rhs) {
  zero_thrust_pwm = rhs.zero_thrust_pwm;
  dpwm_min = rhs.dpwm_min;
  dpwm_max = rhs.dpwm_max;
  a_dpwm2force = rhs.a_dpwm2force;
  b_dpwm2force = rhs.b_dpwm2force;
  c_dpwm2force = rhs.c_dpwm2force;
  alloc_tol = rhs.alloc_tol;
  z_guar = rhs.z_guar;
  k_force2torque = rhs.k_force2torque;
  l_moment_arm = rhs.l_moment_arm;
  max_cmd_collective = rhs.max_cmd_collective;
  max_cmd_collective_rate = rhs.max_cmd_collective_rate;
  max_cmd_torque_xy = rhs.max_cmd_torque_xy;
  max_cmd_torque_z = rhs.max_cmd_torque_z;
  max_cmd_omega_xy_dps = rhs.max_cmd_omega_xy_dps;
  max_cmd_omega_z_dps = rhs.max_cmd_omega_z_dps;
  min_cmd_sensed_g = rhs.min_cmd_sensed_g;
  max_cmd_sensed_g = rhs.max_cmd_sensed_g;
  max_cmd_delta_sensed_g = rhs.max_cmd_delta_sensed_g;
  max_cmd_clock_rate_dps = rhs.max_cmd_clock_rate_dps;
  max_cmd_tilt_deg = rhs.max_cmd_tilt_deg;
  max_hvel = rhs.max_hvel;
  max_vvel = rhs.max_vvel;
  tau_hvel_ref = rhs.tau_hvel_ref;
  tau_vvel_ref = rhs.tau_vvel_ref;
  body_aligned_att_ctrl_cmd = rhs.body_aligned_att_ctrl_cmd;
  body_aligned_trans_ctrl_cmd = rhs.body_aligned_trans_ctrl_cmd;
  enable_att_ctrl_tilt_prioritization = rhs.enable_att_ctrl_tilt_prioritization;
  att_ctrl_fb_max_omega_xy_dps = rhs.att_ctrl_fb_max_omega_xy_dps;
  att_ctrl_fb_max_omega_z_dps = rhs.att_ctrl_fb_max_omega_z_dps;
  att_prefilt_J_xx = rhs.att_prefilt_J_xx;
  att_prefilt_J_yy = rhs.att_prefilt_J_yy;
  att_prefilt_J_zz = rhs.att_prefilt_J_zz;
  att_prefilt_omega_xy_sat_dps = rhs.att_prefilt_omega_xy_sat_dps;
  att_prefilt_omega_z_sat_dps = rhs.att_prefilt_omega_z_sat_dps;
  att_prefilt_tau_xy_sat = rhs.att_prefilt_tau_xy_sat;
  att_prefilt_tau_z_sat = rhs.att_prefilt_tau_z_sat;
  att_prefilt_k_p_xy = rhs.att_prefilt_k_p_xy;
  att_prefilt_k_p_z = rhs.att_prefilt_k_p_z;
  att_prefilt_k_d_xy = rhs.att_prefilt_k_d_xy;
  att_prefilt_k_d_z = rhs.att_prefilt_k_d_z;
  att_prefilt_n_steps = rhs.att_prefilt_n_steps;
  min_sensed_ver_accl_g = rhs.min_sensed_ver_accl_g;
  max_sensed_ver_accl_g = rhs.max_sensed_ver_accl_g;
  max_tilt_deg = rhs.max_tilt_deg;
  tilt_comp_threshold_deg = rhs.tilt_comp_threshold_deg;
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<10; ++mpac_ijk1) {
      F_tau[mpac_ijk0][mpac_ijk1] = rhs.F_tau[mpac_ijk0][mpac_ijk1];;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      F_xyz[mpac_ijk0][mpac_ijk1] = rhs.F_xyz[mpac_ijk0][mpac_ijk1];;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      P_xyz[mpac_ijk0][mpac_ijk1] = rhs.P_xyz[mpac_ijk0][mpac_ijk1];;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_xyz[mpac_ijk0][mpac_ijk1] = rhs.C_xyz[mpac_ijk0][mpac_ijk1];;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<20; ++mpac_ijk1) {
      W_xyz[mpac_ijk0][mpac_ijk1] = rhs.W_xyz[mpac_ijk0][mpac_ijk1];;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      F_c[mpac_ijk0][mpac_ijk1] = rhs.F_c[mpac_ijk0][mpac_ijk1];;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      P_c[mpac_ijk0][mpac_ijk1] = rhs.P_c[mpac_ijk0][mpac_ijk1];;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_c[mpac_ijk0][mpac_ijk1] = rhs.C_c[mpac_ijk0][mpac_ijk1];;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<20; ++mpac_ijk1) {
      W_c[mpac_ijk0][mpac_ijk1] = rhs.W_c[mpac_ijk0][mpac_ijk1];;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<10; ++mpac_ijk1) {
      C_att[mpac_ijk0][mpac_ijk1] = rhs.C_att[mpac_ijk0][mpac_ijk1];;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_id_trans[mpac_ijk0][mpac_ijk1] = rhs.C_id_trans[mpac_ijk0][mpac_ijk1];;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_od_trans_pos[mpac_ijk0][mpac_ijk1] = rhs.C_od_trans_pos[mpac_ijk0][mpac_ijk1];;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_od_trans_vel[mpac_ijk0][mpac_ijk1] = rhs.C_od_trans_vel[mpac_ijk0][mpac_ijk1];;
    }
  }
  return *this;
}

void qcontrol_config_data::clear_content() {
  zero_thrust_pwm = 0.0f;
  dpwm_min = 0.0f;
  dpwm_max = 0.0f;
  a_dpwm2force = 0.0f;
  b_dpwm2force = 0.0f;
  c_dpwm2force = 0.0f;
  alloc_tol = 0.0f;
  z_guar = 0.0f;
  k_force2torque = 0.0f;
  l_moment_arm = 0.0f;
  max_cmd_collective = 0.0f;
  max_cmd_collective_rate = 0.0f;
  max_cmd_torque_xy = 0.0f;
  max_cmd_torque_z = 0.0f;
  max_cmd_omega_xy_dps = 0.0f;
  max_cmd_omega_xy = 0.0f;
  max_cmd_omega_z_dps = 0.0f;
  max_cmd_omega_z = 0.0f;
  min_cmd_sensed_g = 0.0f;
  max_cmd_sensed_g = 0.0f;
  max_cmd_delta_sensed_g = 0.0f;
  max_cmd_clock_rate_dps = 0.0f;
  max_cmd_clock_rate = 0.0f;
  max_cmd_tilt_deg = 0.0f;
  max_cmd_tilt = 0.0f;
  max_hvel = 0.0f;
  max_vvel = 0.0f;
  tau_hvel_ref = 0.0f;
  tau_vvel_ref = 0.0f;
  body_aligned_att_ctrl_cmd = 0;
  body_aligned_trans_ctrl_cmd = 0;
  enable_att_ctrl_tilt_prioritization = 0;
  att_ctrl_fb_max_omega_xy_dps = 0.0f;
  att_ctrl_fb_max_omega_xy = 0.0f;
  att_ctrl_fb_max_omega_z_dps = 0.0f;
  att_ctrl_fb_max_omega_z = 0.0f;
  att_prefilt_J_xx = 0.0f;
  att_prefilt_J_yy = 0.0f;
  att_prefilt_J_zz = 0.0f;
  att_prefilt_omega_xy_sat_dps = 0.0f;
  att_prefilt_omega_xy_sat = 0.0f;
  att_prefilt_omega_z_sat_dps = 0.0f;
  att_prefilt_omega_z_sat = 0.0f;
  att_prefilt_tau_xy_sat = 0.0f;
  att_prefilt_tau_z_sat = 0.0f;
  att_prefilt_k_p_xy = 0.0f;
  att_prefilt_k_p_z = 0.0f;
  att_prefilt_k_d_xy = 0.0f;
  att_prefilt_k_d_z = 0.0f;
  att_prefilt_n_steps = 0;
  min_sensed_ver_accl_g = 0.0f;
  min_sensed_ver_accl = 0.0f;
  max_sensed_ver_accl_g = 0.0f;
  max_sensed_ver_accl = 0.0f;
  max_tilt_deg = 0.0f;
  max_tilt = 0.0f;
  tilt_comp_threshold_deg = 0.0f;
  tilt_comp_threshold = 0.0f;
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<10; ++mpac_ijk1) {
      F_tau[mpac_ijk0][mpac_ijk1].clear();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      F_xyz[mpac_ijk0][mpac_ijk1].clear();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      P_xyz[mpac_ijk0][mpac_ijk1].clear();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_xyz[mpac_ijk0][mpac_ijk1].clear();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<20; ++mpac_ijk1) {
      W_xyz[mpac_ijk0][mpac_ijk1].clear();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      F_c[mpac_ijk0][mpac_ijk1].clear();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      P_c[mpac_ijk0][mpac_ijk1].clear();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_c[mpac_ijk0][mpac_ijk1].clear();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<20; ++mpac_ijk1) {
      W_c[mpac_ijk0][mpac_ijk1].clear();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<10; ++mpac_ijk1) {
      C_att[mpac_ijk0][mpac_ijk1].clear();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_id_trans[mpac_ijk0][mpac_ijk1].clear();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_od_trans_pos[mpac_ijk0][mpac_ijk1].clear();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_od_trans_vel[mpac_ijk0][mpac_ijk1].clear();
    }
  }
}
string qcontrol_config_data::print_content() const {
  std::ostringstream ss;
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << zero_thrust_pwm << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << dpwm_min << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << dpwm_max << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << a_dpwm2force << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << b_dpwm2force << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << c_dpwm2force << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << alloc_tol << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << z_guar << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << k_force2torque << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << l_moment_arm << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_cmd_collective << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_cmd_collective_rate << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_cmd_torque_xy << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_cmd_torque_z << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_cmd_omega_xy_dps << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_cmd_omega_z_dps << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << min_cmd_sensed_g << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_cmd_sensed_g << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_cmd_delta_sensed_g << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_cmd_clock_rate_dps << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_cmd_tilt_deg << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_hvel << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_vvel << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << tau_hvel_ref << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << tau_vvel_ref << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << body_aligned_att_ctrl_cmd << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << body_aligned_trans_ctrl_cmd << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << enable_att_ctrl_tilt_prioritization << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_ctrl_fb_max_omega_xy_dps << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_ctrl_fb_max_omega_z_dps << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_prefilt_J_xx << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_prefilt_J_yy << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_prefilt_J_zz << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_prefilt_omega_xy_sat_dps << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_prefilt_omega_z_sat_dps << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_prefilt_tau_xy_sat << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_prefilt_tau_z_sat << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_prefilt_k_p_xy << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_prefilt_k_p_z << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_prefilt_k_d_xy << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_prefilt_k_d_z << ",";
  ss << std::setbase(10) << std::fixed << std::noshowpos << std::setprecision(0) << std::setfill('0') << std::setw(4) << att_prefilt_n_steps << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << min_sensed_ver_accl_g << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_sensed_ver_accl_g << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_tilt_deg << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << tilt_comp_threshold_deg << ",";
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<10; ++mpac_ijk1) {
      F_tau[mpac_ijk0][mpac_ijk1].print();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      F_xyz[mpac_ijk0][mpac_ijk1].print();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      P_xyz[mpac_ijk0][mpac_ijk1].print();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_xyz[mpac_ijk0][mpac_ijk1].print();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<20; ++mpac_ijk1) {
      W_xyz[mpac_ijk0][mpac_ijk1].print();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      F_c[mpac_ijk0][mpac_ijk1].print();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      P_c[mpac_ijk0][mpac_ijk1].print();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_c[mpac_ijk0][mpac_ijk1].print();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<20; ++mpac_ijk1) {
      W_c[mpac_ijk0][mpac_ijk1].print();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<10; ++mpac_ijk1) {
      C_att[mpac_ijk0][mpac_ijk1].print();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_id_trans[mpac_ijk0][mpac_ijk1].print();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_od_trans_pos[mpac_ijk0][mpac_ijk1].print();
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      C_od_trans_vel[mpac_ijk0][mpac_ijk1].print();
    }
  }
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_cmd_omega_xy << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_cmd_omega_z << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_cmd_clock_rate << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_cmd_tilt << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_ctrl_fb_max_omega_xy << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_ctrl_fb_max_omega_z << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_prefilt_omega_xy_sat << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << att_prefilt_omega_z_sat << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << min_sensed_ver_accl << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_sensed_ver_accl << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << max_tilt << ",";
  ss << std::setbase(10) << std::scientific << std::showpos << std::setprecision(8) << std::setfill('0') << std::setw(10) << tilt_comp_threshold << ",";
  return ss.str();
}
uint8* qcontrol_config_data::serialize_content(uint8* buff) const {
  buff = network::packet::serialize(buff,zero_thrust_pwm,1);
  buff = network::packet::serialize(buff,dpwm_min,1);
  buff = network::packet::serialize(buff,dpwm_max,1);
  buff = network::packet::serialize(buff,a_dpwm2force,1);
  buff = network::packet::serialize(buff,b_dpwm2force,1);
  buff = network::packet::serialize(buff,c_dpwm2force,1);
  buff = network::packet::serialize(buff,alloc_tol,1);
  buff = network::packet::serialize(buff,z_guar,1);
  buff = network::packet::serialize(buff,k_force2torque,1);
  buff = network::packet::serialize(buff,l_moment_arm,1);
  buff = network::packet::serialize(buff,max_cmd_collective,1);
  buff = network::packet::serialize(buff,max_cmd_collective_rate,1);
  buff = network::packet::serialize(buff,max_cmd_torque_xy,1);
  buff = network::packet::serialize(buff,max_cmd_torque_z,1);
  buff = network::packet::serialize(buff,max_cmd_omega_xy_dps,1);
  buff = network::packet::serialize(buff,max_cmd_omega_z_dps,1);
  buff = network::packet::serialize(buff,min_cmd_sensed_g,1);
  buff = network::packet::serialize(buff,max_cmd_sensed_g,1);
  buff = network::packet::serialize(buff,max_cmd_delta_sensed_g,1);
  buff = network::packet::serialize(buff,max_cmd_clock_rate_dps,1);
  buff = network::packet::serialize(buff,max_cmd_tilt_deg,1);
  buff = network::packet::serialize(buff,max_hvel,1);
  buff = network::packet::serialize(buff,max_vvel,1);
  buff = network::packet::serialize(buff,tau_hvel_ref,1);
  buff = network::packet::serialize(buff,tau_vvel_ref,1);
  buff = network::packet::serialize(buff,body_aligned_att_ctrl_cmd,1);
  buff = network::packet::serialize(buff,body_aligned_trans_ctrl_cmd,1);
  buff = network::packet::serialize(buff,enable_att_ctrl_tilt_prioritization,1);
  buff = network::packet::serialize(buff,att_ctrl_fb_max_omega_xy_dps,1);
  buff = network::packet::serialize(buff,att_ctrl_fb_max_omega_z_dps,1);
  buff = network::packet::serialize(buff,att_prefilt_J_xx,1);
  buff = network::packet::serialize(buff,att_prefilt_J_yy,1);
  buff = network::packet::serialize(buff,att_prefilt_J_zz,1);
  buff = network::packet::serialize(buff,att_prefilt_omega_xy_sat_dps,1);
  buff = network::packet::serialize(buff,att_prefilt_omega_z_sat_dps,1);
  buff = network::packet::serialize(buff,att_prefilt_tau_xy_sat,1);
  buff = network::packet::serialize(buff,att_prefilt_tau_z_sat,1);
  buff = network::packet::serialize(buff,att_prefilt_k_p_xy,1);
  buff = network::packet::serialize(buff,att_prefilt_k_p_z,1);
  buff = network::packet::serialize(buff,att_prefilt_k_d_xy,1);
  buff = network::packet::serialize(buff,att_prefilt_k_d_z,1);
  buff = network::packet::serialize(buff,att_prefilt_n_steps,1);
  buff = network::packet::serialize(buff,min_sensed_ver_accl_g,1);
  buff = network::packet::serialize(buff,max_sensed_ver_accl_g,1);
  buff = network::packet::serialize(buff,max_tilt_deg,1);
  buff = network::packet::serialize(buff,tilt_comp_threshold_deg,1);
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<10; ++mpac_ijk1) {
      buff = F_tau[mpac_ijk0][mpac_ijk1].serialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = F_xyz[mpac_ijk0][mpac_ijk1].serialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = P_xyz[mpac_ijk0][mpac_ijk1].serialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = C_xyz[mpac_ijk0][mpac_ijk1].serialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<20; ++mpac_ijk1) {
      buff = W_xyz[mpac_ijk0][mpac_ijk1].serialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = F_c[mpac_ijk0][mpac_ijk1].serialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = P_c[mpac_ijk0][mpac_ijk1].serialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = C_c[mpac_ijk0][mpac_ijk1].serialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<20; ++mpac_ijk1) {
      buff = W_c[mpac_ijk0][mpac_ijk1].serialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<10; ++mpac_ijk1) {
      buff = C_att[mpac_ijk0][mpac_ijk1].serialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = C_id_trans[mpac_ijk0][mpac_ijk1].serialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = C_od_trans_pos[mpac_ijk0][mpac_ijk1].serialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = C_od_trans_vel[mpac_ijk0][mpac_ijk1].serialize_content(buff);;
    }
  }
  return buff;
}
const uint8* qcontrol_config_data::deserialize_content(const uint8* buff) {
  buff = network::packet::deserialize(buff,zero_thrust_pwm,1);
  buff = network::packet::deserialize(buff,dpwm_min,1);
  buff = network::packet::deserialize(buff,dpwm_max,1);
  buff = network::packet::deserialize(buff,a_dpwm2force,1);
  buff = network::packet::deserialize(buff,b_dpwm2force,1);
  buff = network::packet::deserialize(buff,c_dpwm2force,1);
  buff = network::packet::deserialize(buff,alloc_tol,1);
  buff = network::packet::deserialize(buff,z_guar,1);
  buff = network::packet::deserialize(buff,k_force2torque,1);
  buff = network::packet::deserialize(buff,l_moment_arm,1);
  buff = network::packet::deserialize(buff,max_cmd_collective,1);
  buff = network::packet::deserialize(buff,max_cmd_collective_rate,1);
  buff = network::packet::deserialize(buff,max_cmd_torque_xy,1);
  buff = network::packet::deserialize(buff,max_cmd_torque_z,1);
  buff = network::packet::deserialize(buff,max_cmd_omega_xy_dps,1);
  buff = network::packet::deserialize(buff,max_cmd_omega_z_dps,1);
  buff = network::packet::deserialize(buff,min_cmd_sensed_g,1);
  buff = network::packet::deserialize(buff,max_cmd_sensed_g,1);
  buff = network::packet::deserialize(buff,max_cmd_delta_sensed_g,1);
  buff = network::packet::deserialize(buff,max_cmd_clock_rate_dps,1);
  buff = network::packet::deserialize(buff,max_cmd_tilt_deg,1);
  buff = network::packet::deserialize(buff,max_hvel,1);
  buff = network::packet::deserialize(buff,max_vvel,1);
  buff = network::packet::deserialize(buff,tau_hvel_ref,1);
  buff = network::packet::deserialize(buff,tau_vvel_ref,1);
  buff = network::packet::deserialize(buff,body_aligned_att_ctrl_cmd,1);
  buff = network::packet::deserialize(buff,body_aligned_trans_ctrl_cmd,1);
  buff = network::packet::deserialize(buff,enable_att_ctrl_tilt_prioritization,1);
  buff = network::packet::deserialize(buff,att_ctrl_fb_max_omega_xy_dps,1);
  buff = network::packet::deserialize(buff,att_ctrl_fb_max_omega_z_dps,1);
  buff = network::packet::deserialize(buff,att_prefilt_J_xx,1);
  buff = network::packet::deserialize(buff,att_prefilt_J_yy,1);
  buff = network::packet::deserialize(buff,att_prefilt_J_zz,1);
  buff = network::packet::deserialize(buff,att_prefilt_omega_xy_sat_dps,1);
  buff = network::packet::deserialize(buff,att_prefilt_omega_z_sat_dps,1);
  buff = network::packet::deserialize(buff,att_prefilt_tau_xy_sat,1);
  buff = network::packet::deserialize(buff,att_prefilt_tau_z_sat,1);
  buff = network::packet::deserialize(buff,att_prefilt_k_p_xy,1);
  buff = network::packet::deserialize(buff,att_prefilt_k_p_z,1);
  buff = network::packet::deserialize(buff,att_prefilt_k_d_xy,1);
  buff = network::packet::deserialize(buff,att_prefilt_k_d_z,1);
  buff = network::packet::deserialize(buff,att_prefilt_n_steps,1);
  buff = network::packet::deserialize(buff,min_sensed_ver_accl_g,1);
  buff = network::packet::deserialize(buff,max_sensed_ver_accl_g,1);
  buff = network::packet::deserialize(buff,max_tilt_deg,1);
  buff = network::packet::deserialize(buff,tilt_comp_threshold_deg,1);
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<10; ++mpac_ijk1) {
      buff = F_tau[mpac_ijk0][mpac_ijk1].deserialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = F_xyz[mpac_ijk0][mpac_ijk1].deserialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = P_xyz[mpac_ijk0][mpac_ijk1].deserialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = C_xyz[mpac_ijk0][mpac_ijk1].deserialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<20; ++mpac_ijk1) {
      buff = W_xyz[mpac_ijk0][mpac_ijk1].deserialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = F_c[mpac_ijk0][mpac_ijk1].deserialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = P_c[mpac_ijk0][mpac_ijk1].deserialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = C_c[mpac_ijk0][mpac_ijk1].deserialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<20; ++mpac_ijk1) {
      buff = W_c[mpac_ijk0][mpac_ijk1].deserialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<10; ++mpac_ijk1) {
      buff = C_att[mpac_ijk0][mpac_ijk1].deserialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = C_id_trans[mpac_ijk0][mpac_ijk1].deserialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = C_od_trans_pos[mpac_ijk0][mpac_ijk1].deserialize_content(buff);;
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      buff = C_od_trans_vel[mpac_ijk0][mpac_ijk1].deserialize_content(buff);;
    }
  }
  return buff;
}
void qcontrol_config_data::load_content(utilities::ifile& file, const string& parent) {
  file.read_float(parent+"zero_thrust_pwm",zero_thrust_pwm);
  file.read_float(parent+"dpwm_min",dpwm_min);
  file.read_float(parent+"dpwm_max",dpwm_max);
  file.read_float(parent+"a_dpwm2force",a_dpwm2force);
  file.read_float(parent+"b_dpwm2force",b_dpwm2force);
  file.read_float(parent+"c_dpwm2force",c_dpwm2force);
  file.read_float(parent+"alloc_tol",alloc_tol);
  file.read_float(parent+"z_guar",z_guar);
  file.read_float(parent+"k_force2torque",k_force2torque);
  file.read_float(parent+"l_moment_arm",l_moment_arm);
  file.read_float(parent+"max_cmd_collective",max_cmd_collective);
  file.read_float(parent+"max_cmd_collective_rate",max_cmd_collective_rate);
  file.read_float(parent+"max_cmd_torque_xy",max_cmd_torque_xy);
  file.read_float(parent+"max_cmd_torque_z",max_cmd_torque_z);
  file.read_float(parent+"max_cmd_omega_xy_dps",max_cmd_omega_xy_dps);
  file.read_float(parent+"max_cmd_omega_z_dps",max_cmd_omega_z_dps);
  file.read_float(parent+"min_cmd_sensed_g",min_cmd_sensed_g);
  file.read_float(parent+"max_cmd_sensed_g",max_cmd_sensed_g);
  file.read_float(parent+"max_cmd_delta_sensed_g",max_cmd_delta_sensed_g);
  file.read_float(parent+"max_cmd_clock_rate_dps",max_cmd_clock_rate_dps);
  file.read_float(parent+"max_cmd_tilt_deg",max_cmd_tilt_deg);
  file.read_float(parent+"max_hvel",max_hvel);
  file.read_float(parent+"max_vvel",max_vvel);
  file.read_float(parent+"tau_hvel_ref",tau_hvel_ref);
  file.read_float(parent+"tau_vvel_ref",tau_vvel_ref);
  file.read_bool(parent+"body_aligned_att_ctrl_cmd",body_aligned_att_ctrl_cmd);
  file.read_bool(parent+"body_aligned_trans_ctrl_cmd",body_aligned_trans_ctrl_cmd);
  file.read_bool(parent+"enable_att_ctrl_tilt_prioritization",enable_att_ctrl_tilt_prioritization);
  file.read_float(parent+"att_ctrl_fb_max_omega_xy_dps",att_ctrl_fb_max_omega_xy_dps);
  file.read_float(parent+"att_ctrl_fb_max_omega_z_dps",att_ctrl_fb_max_omega_z_dps);
  file.read_float(parent+"att_prefilt_J_xx",att_prefilt_J_xx);
  file.read_float(parent+"att_prefilt_J_yy",att_prefilt_J_yy);
  file.read_float(parent+"att_prefilt_J_zz",att_prefilt_J_zz);
  file.read_float(parent+"att_prefilt_omega_xy_sat_dps",att_prefilt_omega_xy_sat_dps);
  file.read_float(parent+"att_prefilt_omega_z_sat_dps",att_prefilt_omega_z_sat_dps);
  file.read_float(parent+"att_prefilt_tau_xy_sat",att_prefilt_tau_xy_sat);
  file.read_float(parent+"att_prefilt_tau_z_sat",att_prefilt_tau_z_sat);
  file.read_float(parent+"att_prefilt_k_p_xy",att_prefilt_k_p_xy);
  file.read_float(parent+"att_prefilt_k_p_z",att_prefilt_k_p_z);
  file.read_float(parent+"att_prefilt_k_d_xy",att_prefilt_k_d_xy);
  file.read_float(parent+"att_prefilt_k_d_z",att_prefilt_k_d_z);
  file.read_uint32(parent+"att_prefilt_n_steps",att_prefilt_n_steps);
  file.read_float(parent+"min_sensed_ver_accl_g",min_sensed_ver_accl_g);
  file.read_float(parent+"max_sensed_ver_accl_g",max_sensed_ver_accl_g);
  file.read_float(parent+"max_tilt_deg",max_tilt_deg);
  file.read_float(parent+"tilt_comp_threshold_deg",tilt_comp_threshold_deg);
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<10; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      F_tau[mpac_ijk0][mpac_ijk1].load_content(file,parent+"F_tau"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      F_xyz[mpac_ijk0][mpac_ijk1].load_content(file,parent+"F_xyz"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      P_xyz[mpac_ijk0][mpac_ijk1].load_content(file,parent+"P_xyz"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      C_xyz[mpac_ijk0][mpac_ijk1].load_content(file,parent+"C_xyz"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<20; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      W_xyz[mpac_ijk0][mpac_ijk1].load_content(file,parent+"W_xyz"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      F_c[mpac_ijk0][mpac_ijk1].load_content(file,parent+"F_c"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      P_c[mpac_ijk0][mpac_ijk1].load_content(file,parent+"P_c"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      C_c[mpac_ijk0][mpac_ijk1].load_content(file,parent+"C_c"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<20; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      W_c[mpac_ijk0][mpac_ijk1].load_content(file,parent+"W_c"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<10; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      C_att[mpac_ijk0][mpac_ijk1].load_content(file,parent+"C_att"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      C_id_trans[mpac_ijk0][mpac_ijk1].load_content(file,parent+"C_id_trans"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      C_od_trans_pos[mpac_ijk0][mpac_ijk1].load_content(file,parent+"C_od_trans_pos"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      C_od_trans_vel[mpac_ijk0][mpac_ijk1].load_content(file,parent+"C_od_trans_vel"+idx_ss.str()+".");
    }
  }
}
void qcontrol_config_data::save_content(utilities::ofile& file, const string& parent) const {
  file.write_float(parent+"zero_thrust_pwm",zero_thrust_pwm);
  file.write_float(parent+"dpwm_min",dpwm_min);
  file.write_float(parent+"dpwm_max",dpwm_max);
  file.write_float(parent+"a_dpwm2force",a_dpwm2force);
  file.write_float(parent+"b_dpwm2force",b_dpwm2force);
  file.write_float(parent+"c_dpwm2force",c_dpwm2force);
  file.write_float(parent+"alloc_tol",alloc_tol);
  file.write_float(parent+"z_guar",z_guar);
  file.write_float(parent+"k_force2torque",k_force2torque);
  file.write_float(parent+"l_moment_arm",l_moment_arm);
  file.write_float(parent+"max_cmd_collective",max_cmd_collective);
  file.write_float(parent+"max_cmd_collective_rate",max_cmd_collective_rate);
  file.write_float(parent+"max_cmd_torque_xy",max_cmd_torque_xy);
  file.write_float(parent+"max_cmd_torque_z",max_cmd_torque_z);
  file.write_float(parent+"max_cmd_omega_xy_dps",max_cmd_omega_xy_dps);
  file.write_float(parent+"max_cmd_omega_z_dps",max_cmd_omega_z_dps);
  file.write_float(parent+"min_cmd_sensed_g",min_cmd_sensed_g);
  file.write_float(parent+"max_cmd_sensed_g",max_cmd_sensed_g);
  file.write_float(parent+"max_cmd_delta_sensed_g",max_cmd_delta_sensed_g);
  file.write_float(parent+"max_cmd_clock_rate_dps",max_cmd_clock_rate_dps);
  file.write_float(parent+"max_cmd_tilt_deg",max_cmd_tilt_deg);
  file.write_float(parent+"max_hvel",max_hvel);
  file.write_float(parent+"max_vvel",max_vvel);
  file.write_float(parent+"tau_hvel_ref",tau_hvel_ref);
  file.write_float(parent+"tau_vvel_ref",tau_vvel_ref);
  file.write_bool(parent+"body_aligned_att_ctrl_cmd",body_aligned_att_ctrl_cmd);
  file.write_bool(parent+"body_aligned_trans_ctrl_cmd",body_aligned_trans_ctrl_cmd);
  file.write_bool(parent+"enable_att_ctrl_tilt_prioritization",enable_att_ctrl_tilt_prioritization);
  file.write_float(parent+"att_ctrl_fb_max_omega_xy_dps",att_ctrl_fb_max_omega_xy_dps);
  file.write_float(parent+"att_ctrl_fb_max_omega_z_dps",att_ctrl_fb_max_omega_z_dps);
  file.write_float(parent+"att_prefilt_J_xx",att_prefilt_J_xx);
  file.write_float(parent+"att_prefilt_J_yy",att_prefilt_J_yy);
  file.write_float(parent+"att_prefilt_J_zz",att_prefilt_J_zz);
  file.write_float(parent+"att_prefilt_omega_xy_sat_dps",att_prefilt_omega_xy_sat_dps);
  file.write_float(parent+"att_prefilt_omega_z_sat_dps",att_prefilt_omega_z_sat_dps);
  file.write_float(parent+"att_prefilt_tau_xy_sat",att_prefilt_tau_xy_sat);
  file.write_float(parent+"att_prefilt_tau_z_sat",att_prefilt_tau_z_sat);
  file.write_float(parent+"att_prefilt_k_p_xy",att_prefilt_k_p_xy);
  file.write_float(parent+"att_prefilt_k_p_z",att_prefilt_k_p_z);
  file.write_float(parent+"att_prefilt_k_d_xy",att_prefilt_k_d_xy);
  file.write_float(parent+"att_prefilt_k_d_z",att_prefilt_k_d_z);
  file.write_uint32(parent+"att_prefilt_n_steps",att_prefilt_n_steps);
  file.write_float(parent+"min_sensed_ver_accl_g",min_sensed_ver_accl_g);
  file.write_float(parent+"max_sensed_ver_accl_g",max_sensed_ver_accl_g);
  file.write_float(parent+"max_tilt_deg",max_tilt_deg);
  file.write_float(parent+"tilt_comp_threshold_deg",tilt_comp_threshold_deg);
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<10; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      F_tau[mpac_ijk0][mpac_ijk1].save_content(file,parent+"F_tau"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      F_xyz[mpac_ijk0][mpac_ijk1].save_content(file,parent+"F_xyz"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      P_xyz[mpac_ijk0][mpac_ijk1].save_content(file,parent+"P_xyz"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      C_xyz[mpac_ijk0][mpac_ijk1].save_content(file,parent+"C_xyz"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<20; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      W_xyz[mpac_ijk0][mpac_ijk1].save_content(file,parent+"W_xyz"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      F_c[mpac_ijk0][mpac_ijk1].save_content(file,parent+"F_c"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      P_c[mpac_ijk0][mpac_ijk1].save_content(file,parent+"P_c"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      C_c[mpac_ijk0][mpac_ijk1].save_content(file,parent+"C_c"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<1; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<20; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      W_c[mpac_ijk0][mpac_ijk1].save_content(file,parent+"W_c"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<10; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      C_att[mpac_ijk0][mpac_ijk1].save_content(file,parent+"C_att"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      C_id_trans[mpac_ijk0][mpac_ijk1].save_content(file,parent+"C_id_trans"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      C_od_trans_pos[mpac_ijk0][mpac_ijk1].save_content(file,parent+"C_od_trans_pos"+idx_ss.str()+".");
    }
  }
  for (uint32 mpac_ijk0=0; mpac_ijk0<3; ++mpac_ijk0) {
    for (uint32 mpac_ijk1=0; mpac_ijk1<15; ++mpac_ijk1) {
      std::ostringstream idx_ss;
      idx_ss << "[" << mpac_ijk0 << "]" << "[" << mpac_ijk1 << "]";
      C_od_trans_vel[mpac_ijk0][mpac_ijk1].save_content(file,parent+"C_od_trans_vel"+idx_ss.str()+".");
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
