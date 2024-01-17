%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_qcontrol_config_data_t.m        %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_qcontrol_config_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.QCONTROL_CONFIG_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_qcontrol_config_data_t = autogen_topic_qcontrol_config_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    zero_thrust_pwm(1,1) single;
    dpwm_min(1,1) single;
    dpwm_max(1,1) single;
    a_dpwm2force(1,1) single;
    b_dpwm2force(1,1) single;
    c_dpwm2force(1,1) single;
    alloc_tol(1,1) single;
    z_guar(1,1) single;
    k_force2torque(1,1) single;
    l_moment_arm(1,1) single;
    max_cmd_collective(1,1) single;
    max_cmd_collective_rate(1,1) single;
    max_cmd_torque_xy(1,1) single;
    max_cmd_torque_z(1,1) single;
    max_cmd_omega_xy_dps(1,1) single;
    max_cmd_omega_z_dps(1,1) single;
    min_cmd_sensed_g(1,1) single;
    max_cmd_sensed_g(1,1) single;
    max_cmd_delta_sensed_g(1,1) single;
    max_cmd_clock_rate_dps(1,1) single;
    max_cmd_tilt_deg(1,1) single;
    max_hvel(1,1) single;
    max_vvel(1,1) single;
    tau_hvel_ref(1,1) single;
    tau_vvel_ref(1,1) single;
    body_aligned_att_ctrl_cmd(1,1) logical;
    body_aligned_trans_ctrl_cmd(1,1) logical;
    enable_att_ctrl_tilt_prioritization(1,1) logical;
    att_ctrl_fb_max_omega_xy_dps(1,1) single;
    att_ctrl_fb_max_omega_z_dps(1,1) single;
    att_prefilt_J_xx(1,1) single;
    att_prefilt_J_yy(1,1) single;
    att_prefilt_J_zz(1,1) single;
    att_prefilt_omega_xy_sat_dps(1,1) single;
    att_prefilt_omega_z_sat_dps(1,1) single;
    att_prefilt_tau_xy_sat(1,1) single;
    att_prefilt_tau_z_sat(1,1) single;
    att_prefilt_k_p_xy(1,1) single;
    att_prefilt_k_p_z(1,1) single;
    att_prefilt_k_d_xy(1,1) single;
    att_prefilt_k_d_z(1,1) single;
    att_prefilt_n_steps(1,1) uint32;
    min_sensed_ver_accl_g(1,1) single;
    max_sensed_ver_accl_g(1,1) single;
    max_tilt_deg(1,1) single;
    tilt_comp_threshold_deg(1,1) single;
    F_tau(3,10) autogen_filter_gains_t;
    F_xyz(3,15) autogen_filter_gains_t;
    P_xyz(3,15) autogen_filter_gains_t;
    C_xyz(3,15) autogen_filter_gains_t;
    W_xyz(3,20) autogen_filter_gains_t;
    F_c(1,15) autogen_filter_gains_t;
    P_c(1,15) autogen_filter_gains_t;
    C_c(1,15) autogen_filter_gains_t;
    W_c(1,20) autogen_filter_gains_t;
    C_att(3,10) autogen_filter_gains_t;
    C_id_trans(3,15) autogen_filter_gains_t;
    C_od_trans_pos(3,15) autogen_filter_gains_t;
    C_od_trans_vel(3,15) autogen_filter_gains_t;
  end
  methods (Static)
    function [n] = size()
      n = 11+11095;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 11095;
    end
  end
  methods (Sealed = true)
    function [buffer,i2] = serialize(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        buffer(i1+0) = uint8(obj.type);
        buffer(i1+1) = uint8(obj.topic);
        buffer(i1+2) = uint8(obj.node);
        buffer((i1+3):(i1+10)) = typecast(obj.ts,'uint8');
        [buffer,i2] = serialize_content(obj,buffer,i1+11);
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [success,i2] = deserialize(obj,buffer,i1)
      success = false;
      i2 = i1;
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        if ((length(buffer)-(i1-1)) >= obj.size())&& ...
           (obj.type == buffer(i1))&& ...
           (obj.topic == buffer(i1+1))
          obj.node = buffer(i1+2);
          obj.ts = typecast(buffer((i1+3):(i1+10)),'uint64');
          i2 = deserialize_content(obj,buffer,i1+11);
          success = (i2 > i1);
        end
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [buffer,i2] = serialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        buffer(i1+(0:(0+3))) = typecast(obj.zero_thrust_pwm,'uint8');
        buffer(i1+(4:(4+3))) = typecast(obj.dpwm_min,'uint8');
        buffer(i1+(8:(8+3))) = typecast(obj.dpwm_max,'uint8');
        buffer(i1+(12:(12+3))) = typecast(obj.a_dpwm2force,'uint8');
        buffer(i1+(16:(16+3))) = typecast(obj.b_dpwm2force,'uint8');
        buffer(i1+(20:(20+3))) = typecast(obj.c_dpwm2force,'uint8');
        buffer(i1+(24:(24+3))) = typecast(obj.alloc_tol,'uint8');
        buffer(i1+(28:(28+3))) = typecast(obj.z_guar,'uint8');
        buffer(i1+(32:(32+3))) = typecast(obj.k_force2torque,'uint8');
        buffer(i1+(36:(36+3))) = typecast(obj.l_moment_arm,'uint8');
        buffer(i1+(40:(40+3))) = typecast(obj.max_cmd_collective,'uint8');
        buffer(i1+(44:(44+3))) = typecast(obj.max_cmd_collective_rate,'uint8');
        buffer(i1+(48:(48+3))) = typecast(obj.max_cmd_torque_xy,'uint8');
        buffer(i1+(52:(52+3))) = typecast(obj.max_cmd_torque_z,'uint8');
        buffer(i1+(56:(56+3))) = typecast(obj.max_cmd_omega_xy_dps,'uint8');
        buffer(i1+(60:(60+3))) = typecast(obj.max_cmd_omega_z_dps,'uint8');
        buffer(i1+(64:(64+3))) = typecast(obj.min_cmd_sensed_g,'uint8');
        buffer(i1+(68:(68+3))) = typecast(obj.max_cmd_sensed_g,'uint8');
        buffer(i1+(72:(72+3))) = typecast(obj.max_cmd_delta_sensed_g,'uint8');
        buffer(i1+(76:(76+3))) = typecast(obj.max_cmd_clock_rate_dps,'uint8');
        buffer(i1+(80:(80+3))) = typecast(obj.max_cmd_tilt_deg,'uint8');
        buffer(i1+(84:(84+3))) = typecast(obj.max_hvel,'uint8');
        buffer(i1+(88:(88+3))) = typecast(obj.max_vvel,'uint8');
        buffer(i1+(92:(92+3))) = typecast(obj.tau_hvel_ref,'uint8');
        buffer(i1+(96:(96+3))) = typecast(obj.tau_vvel_ref,'uint8');
        buffer(i1+100) = typecast(uint8(obj.body_aligned_att_ctrl_cmd),'uint8');
        buffer(i1+101) = typecast(uint8(obj.body_aligned_trans_ctrl_cmd),'uint8');
        buffer(i1+102) = typecast(uint8(obj.enable_att_ctrl_tilt_prioritization),'uint8');
        buffer(i1+(103:(103+3))) = typecast(obj.att_ctrl_fb_max_omega_xy_dps,'uint8');
        buffer(i1+(107:(107+3))) = typecast(obj.att_ctrl_fb_max_omega_z_dps,'uint8');
        buffer(i1+(111:(111+3))) = typecast(obj.att_prefilt_J_xx,'uint8');
        buffer(i1+(115:(115+3))) = typecast(obj.att_prefilt_J_yy,'uint8');
        buffer(i1+(119:(119+3))) = typecast(obj.att_prefilt_J_zz,'uint8');
        buffer(i1+(123:(123+3))) = typecast(obj.att_prefilt_omega_xy_sat_dps,'uint8');
        buffer(i1+(127:(127+3))) = typecast(obj.att_prefilt_omega_z_sat_dps,'uint8');
        buffer(i1+(131:(131+3))) = typecast(obj.att_prefilt_tau_xy_sat,'uint8');
        buffer(i1+(135:(135+3))) = typecast(obj.att_prefilt_tau_z_sat,'uint8');
        buffer(i1+(139:(139+3))) = typecast(obj.att_prefilt_k_p_xy,'uint8');
        buffer(i1+(143:(143+3))) = typecast(obj.att_prefilt_k_p_z,'uint8');
        buffer(i1+(147:(147+3))) = typecast(obj.att_prefilt_k_d_xy,'uint8');
        buffer(i1+(151:(151+3))) = typecast(obj.att_prefilt_k_d_z,'uint8');
        buffer(i1+(155:(155+3))) = typecast(obj.att_prefilt_n_steps,'uint8');
        buffer(i1+(159:(159+3))) = typecast(obj.min_sensed_ver_accl_g,'uint8');
        buffer(i1+(163:(163+3))) = typecast(obj.max_sensed_ver_accl_g,'uint8');
        buffer(i1+(167:(167+3))) = typecast(obj.max_tilt_deg,'uint8');
        buffer(i1+(171:(171+3))) = typecast(obj.tilt_comp_threshold_deg,'uint8');
        for mpac_ijk0=1:3
          for mpac_ijk1=1:10
            buffer = obj.F_tau(mpac_ijk0,mpac_ijk1).serialize_content(buffer,i1+175+24*((mpac_ijk0-1)*10+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:3
          for mpac_ijk1=1:15
            buffer = obj.F_xyz(mpac_ijk0,mpac_ijk1).serialize_content(buffer,i1+895+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:3
          for mpac_ijk1=1:15
            buffer = obj.P_xyz(mpac_ijk0,mpac_ijk1).serialize_content(buffer,i1+1975+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:3
          for mpac_ijk1=1:15
            buffer = obj.C_xyz(mpac_ijk0,mpac_ijk1).serialize_content(buffer,i1+3055+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:3
          for mpac_ijk1=1:20
            buffer = obj.W_xyz(mpac_ijk0,mpac_ijk1).serialize_content(buffer,i1+4135+24*((mpac_ijk0-1)*20+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:1
          for mpac_ijk1=1:15
            buffer = obj.F_c(mpac_ijk0,mpac_ijk1).serialize_content(buffer,i1+5575+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:1
          for mpac_ijk1=1:15
            buffer = obj.P_c(mpac_ijk0,mpac_ijk1).serialize_content(buffer,i1+5935+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:1
          for mpac_ijk1=1:15
            buffer = obj.C_c(mpac_ijk0,mpac_ijk1).serialize_content(buffer,i1+6295+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:1
          for mpac_ijk1=1:20
            buffer = obj.W_c(mpac_ijk0,mpac_ijk1).serialize_content(buffer,i1+6655+24*((mpac_ijk0-1)*20+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:3
          for mpac_ijk1=1:10
            buffer = obj.C_att(mpac_ijk0,mpac_ijk1).serialize_content(buffer,i1+7135+24*((mpac_ijk0-1)*10+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:3
          for mpac_ijk1=1:15
            buffer = obj.C_id_trans(mpac_ijk0,mpac_ijk1).serialize_content(buffer,i1+7855+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:3
          for mpac_ijk1=1:15
            buffer = obj.C_od_trans_pos(mpac_ijk0,mpac_ijk1).serialize_content(buffer,i1+8935+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:3
          for mpac_ijk1=1:15
            buffer = obj.C_od_trans_vel(mpac_ijk0,mpac_ijk1).serialize_content(buffer,i1+10015+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        i2 = i1+11095;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.zero_thrust_pwm = typecast(buffer(i1+(0:(0+3))),'single');
        obj.dpwm_min = typecast(buffer(i1+(4:(4+3))),'single');
        obj.dpwm_max = typecast(buffer(i1+(8:(8+3))),'single');
        obj.a_dpwm2force = typecast(buffer(i1+(12:(12+3))),'single');
        obj.b_dpwm2force = typecast(buffer(i1+(16:(16+3))),'single');
        obj.c_dpwm2force = typecast(buffer(i1+(20:(20+3))),'single');
        obj.alloc_tol = typecast(buffer(i1+(24:(24+3))),'single');
        obj.z_guar = typecast(buffer(i1+(28:(28+3))),'single');
        obj.k_force2torque = typecast(buffer(i1+(32:(32+3))),'single');
        obj.l_moment_arm = typecast(buffer(i1+(36:(36+3))),'single');
        obj.max_cmd_collective = typecast(buffer(i1+(40:(40+3))),'single');
        obj.max_cmd_collective_rate = typecast(buffer(i1+(44:(44+3))),'single');
        obj.max_cmd_torque_xy = typecast(buffer(i1+(48:(48+3))),'single');
        obj.max_cmd_torque_z = typecast(buffer(i1+(52:(52+3))),'single');
        obj.max_cmd_omega_xy_dps = typecast(buffer(i1+(56:(56+3))),'single');
        obj.max_cmd_omega_z_dps = typecast(buffer(i1+(60:(60+3))),'single');
        obj.min_cmd_sensed_g = typecast(buffer(i1+(64:(64+3))),'single');
        obj.max_cmd_sensed_g = typecast(buffer(i1+(68:(68+3))),'single');
        obj.max_cmd_delta_sensed_g = typecast(buffer(i1+(72:(72+3))),'single');
        obj.max_cmd_clock_rate_dps = typecast(buffer(i1+(76:(76+3))),'single');
        obj.max_cmd_tilt_deg = typecast(buffer(i1+(80:(80+3))),'single');
        obj.max_hvel = typecast(buffer(i1+(84:(84+3))),'single');
        obj.max_vvel = typecast(buffer(i1+(88:(88+3))),'single');
        obj.tau_hvel_ref = typecast(buffer(i1+(92:(92+3))),'single');
        obj.tau_vvel_ref = typecast(buffer(i1+(96:(96+3))),'single');
        obj.body_aligned_att_ctrl_cmd = typecast(buffer(i1+100),'uint8');
        obj.body_aligned_trans_ctrl_cmd = typecast(buffer(i1+101),'uint8');
        obj.enable_att_ctrl_tilt_prioritization = typecast(buffer(i1+102),'uint8');
        obj.att_ctrl_fb_max_omega_xy_dps = typecast(buffer(i1+(103:(103+3))),'single');
        obj.att_ctrl_fb_max_omega_z_dps = typecast(buffer(i1+(107:(107+3))),'single');
        obj.att_prefilt_J_xx = typecast(buffer(i1+(111:(111+3))),'single');
        obj.att_prefilt_J_yy = typecast(buffer(i1+(115:(115+3))),'single');
        obj.att_prefilt_J_zz = typecast(buffer(i1+(119:(119+3))),'single');
        obj.att_prefilt_omega_xy_sat_dps = typecast(buffer(i1+(123:(123+3))),'single');
        obj.att_prefilt_omega_z_sat_dps = typecast(buffer(i1+(127:(127+3))),'single');
        obj.att_prefilt_tau_xy_sat = typecast(buffer(i1+(131:(131+3))),'single');
        obj.att_prefilt_tau_z_sat = typecast(buffer(i1+(135:(135+3))),'single');
        obj.att_prefilt_k_p_xy = typecast(buffer(i1+(139:(139+3))),'single');
        obj.att_prefilt_k_p_z = typecast(buffer(i1+(143:(143+3))),'single');
        obj.att_prefilt_k_d_xy = typecast(buffer(i1+(147:(147+3))),'single');
        obj.att_prefilt_k_d_z = typecast(buffer(i1+(151:(151+3))),'single');
        obj.att_prefilt_n_steps = typecast(buffer(i1+(155:(155+3))),'uint32');
        obj.min_sensed_ver_accl_g = typecast(buffer(i1+(159:(159+3))),'single');
        obj.max_sensed_ver_accl_g = typecast(buffer(i1+(163:(163+3))),'single');
        obj.max_tilt_deg = typecast(buffer(i1+(167:(167+3))),'single');
        obj.tilt_comp_threshold_deg = typecast(buffer(i1+(171:(171+3))),'single');
        for mpac_ijk0=1:3
          for mpac_ijk1=1:10
            obj.F_tau(mpac_ijk0,mpac_ijk1).deserialize_content(buffer,i1+175+24*((mpac_ijk0-1)*10+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:3
          for mpac_ijk1=1:15
            obj.F_xyz(mpac_ijk0,mpac_ijk1).deserialize_content(buffer,i1+895+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:3
          for mpac_ijk1=1:15
            obj.P_xyz(mpac_ijk0,mpac_ijk1).deserialize_content(buffer,i1+1975+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:3
          for mpac_ijk1=1:15
            obj.C_xyz(mpac_ijk0,mpac_ijk1).deserialize_content(buffer,i1+3055+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:3
          for mpac_ijk1=1:20
            obj.W_xyz(mpac_ijk0,mpac_ijk1).deserialize_content(buffer,i1+4135+24*((mpac_ijk0-1)*20+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:1
          for mpac_ijk1=1:15
            obj.F_c(mpac_ijk0,mpac_ijk1).deserialize_content(buffer,i1+5575+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:1
          for mpac_ijk1=1:15
            obj.P_c(mpac_ijk0,mpac_ijk1).deserialize_content(buffer,i1+5935+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:1
          for mpac_ijk1=1:15
            obj.C_c(mpac_ijk0,mpac_ijk1).deserialize_content(buffer,i1+6295+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:1
          for mpac_ijk1=1:20
            obj.W_c(mpac_ijk0,mpac_ijk1).deserialize_content(buffer,i1+6655+24*((mpac_ijk0-1)*20+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:3
          for mpac_ijk1=1:10
            obj.C_att(mpac_ijk0,mpac_ijk1).deserialize_content(buffer,i1+7135+24*((mpac_ijk0-1)*10+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:3
          for mpac_ijk1=1:15
            obj.C_id_trans(mpac_ijk0,mpac_ijk1).deserialize_content(buffer,i1+7855+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:3
          for mpac_ijk1=1:15
            obj.C_od_trans_pos(mpac_ijk0,mpac_ijk1).deserialize_content(buffer,i1+8935+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        for mpac_ijk0=1:3
          for mpac_ijk1=1:15
            obj.C_od_trans_vel(mpac_ijk0,mpac_ijk1).deserialize_content(buffer,i1+10015+24*((mpac_ijk0-1)*15+(mpac_ijk1-1)));
          end
        end
        i2 = i1+11095;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
