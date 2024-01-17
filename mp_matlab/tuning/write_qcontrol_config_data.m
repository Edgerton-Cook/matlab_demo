%% Clears
clear
clc
%% General Inputs
perform_plotting = false;
write_to_file = true;
f_samp = 400;
disc_method = 'tustin';
filt_num_max = 3;
filt_den_max = 3;
mpu6000_dlpf = 5;
n_Pade = 2;
%% Rate controller specifications
f_co_xy = 6.00; % [Hz]
f_te_xy = 2.00*f_co_xy; % [Hz]
f_ff_xy = 3.50*f_co_xy; % [Hz]

f_co_z = 6.00; % [Hz]
f_te_z = 2.00*f_co_z; % [Hz]
f_ff_z = 3.50*f_co_z; % [Hz]

names_xyz = {'F_tau','F_xyz','P_xyz','C_xyz','W_xyz'};
sizes_xyz = {     10,     15,     15,     15,     20};

A_xyz = cell(3,1);
A_xyz{1} = mp_model_actuator('thrust','1st');
A_xyz{2} = mp_model_actuator('thrust','1st');
A_xyz{3} = mp_model_actuator('torque','1st');

G_xyz = cell(3,1);
G_xyz{1} = mp_model_vehicle('x-rate',f_samp,n_Pade);
G_xyz{2} = mp_model_vehicle('y-rate',f_samp,n_Pade);
G_xyz{3} = mp_model_vehicle('z-rate');

H_xyz = mp_model_mpu6000('gyro',mpu6000_dlpf);

C_xyz = cell(3,1);
C_xyz{1} = mp_loopshape_s2_as_pm35(f_co_xy,A_xyz{1}*G_xyz{1}*H_xyz);
C_xyz{2} = mp_loopshape_s2_as_pm35(f_co_xy,A_xyz{2}*G_xyz{2}*H_xyz);
C_xyz{3} = zpk([],[],0);
% C_xyz{3} = mp_ctrl_pid(0.025,0.3,0.00,50);

T_xyz_des = cell(3,1);
T_xyz_des{1} = mp_loopshape_te_type1(f_te_xy);
T_xyz_des{2} = mp_loopshape_te_type1(f_te_xy);
T_xyz_des{3} = mp_loopshape_te_type1d(f_te_z);

W_xyz = cell(3,1);
W_xyz{1} = mp_ndc_element(C_xyz{1},A_xyz{1}*G_xyz{1}*H_xyz,T_xyz_des{1});
W_xyz{2} = mp_ndc_element(C_xyz{2},A_xyz{2}*G_xyz{2}*H_xyz,T_xyz_des{2});
W_xyz{3} = zpk([],[],0);

L_xyz = cell(3,1);
L_xyz{1} = minreal(C_xyz{1}*A_xyz{1}*G_xyz{1}*H_xyz);
L_xyz{2} = minreal(C_xyz{2}*A_xyz{2}*G_xyz{2}*H_xyz);
L_xyz{3} = minreal(C_xyz{3}*A_xyz{3}*G_xyz{3}*H_xyz);

T_cl_xyz = cell(3,1);
T_cl_xyz{1} = minreal(C_xyz{1}*A_xyz{1}*G_xyz{1}/(1+L_xyz{1}));
T_cl_xyz{2} = minreal(C_xyz{2}*A_xyz{2}*G_xyz{2}/(1+L_xyz{2}));
T_cl_xyz{3} = minreal(C_xyz{3}*A_xyz{3}*G_xyz{3}/(1+L_xyz{3}));

Q_xyz = cell(3,1);
Q_xyz{1} = mp_ctrl_pole(f_ff_xy,6);
Q_xyz{2} = mp_ctrl_pole(f_ff_xy,6);
Q_xyz{3} = mp_ctrl_pole(f_ff_z,6);

F_tau = cell(3,1);
F_tau{1} = zpk([],[],0);
F_tau{2} = zpk([],[],0);
F_tau{3} = zpk([],[],0);

F_xyz = cell(3,1);
F_xyz{1} = Q_xyz{1}/(A_xyz{1}*G_xyz{1});
F_xyz{2} = Q_xyz{2}/(A_xyz{2}*G_xyz{2});
F_xyz{3} = zpk([],[],0);

P_xyz = cell(3,1);
P_xyz{1} = H_xyz*Q_xyz{1};
P_xyz{2} = H_xyz*Q_xyz{2};
P_xyz{3} = zpk([],[],1);
%% Z-Accl controller specifications
f_co_c = 6.0; % [Hz]
f_te_c = 1.00*f_co_c; % [Hz]
f_ff_c = 5.00*f_co_c; % [Hz]

names_c = {'F_c','P_c','C_c','W_c'};
sizes_c = {   15,   15,   15,   20};

A_c = cell(1,1);
A_c{1} = mp_model_actuator('thrust','1st');

G_c = cell(1,1);
G_c{1} = mp_model_vehicle('z-accl',f_samp,n_Pade);

H_c = mp_model_mpu6000('accl',mpu6000_dlpf);

C_c{1} = mp_loopshape_s2_as_pm35(f_co_c,A_c{1}*G_c{1}*H_c);
T_c_des{1} = mp_loopshape_te_type0(f_te_c);
W_c{1} = mp_ndc_element(C_c{1},A_c{1}*G_c{1}*H_c,T_c_des{1});

L_c{1} = minreal(C_c{1}*A_c{1}*G_c{1}*H_c);
T_cl_c{1} = minreal(C_c{1}*A_c{1}*G_c{1}/(1+L_c{1}));

Q_c{1} = mp_ctrl_pole(f_ff_c,6);
F_c{1} = Q_c{1}/(A_c{1}*G_c{1});
P_c{1} = H_c*Q_c{1};
%% Preprocessing
if (write_to_file)
  fid = fopen('../../config/qcontrol_config_data.txt','w+');
end

if (perform_plotting)
  colors = {'r',[0 0.7 0],'b'};
  fs = 12;
  ms = 18;
  lw = 2;
  set(0,'defaulttextinterpreter','latex')
  
  settings_bode_xyz = mp_set_bode;
  settings_bode_xyz.f_norm_Hz = f_co_xy;
  settings_bode_xyz.fontsize = fs;
  settings_bode_xyz.exp_lb = -6;
  settings_bode_xyz.exp_ub = 6;
  
  settings_nichols_xyz = mp_set_nichols;
  settings_nichols_xyz.f_norm_Hz = f_co_xy;
  settings_nichols_xyz.phase_lb = -270;
  settings_nichols_xyz.phase_ub = -90;
  settings_nichols_xyz.phase_delta = 45;
  settings_nichols_xyz.fontsize = fs;
  settings_nichols_xyz.marker_size = ms;
  
  settings_bode_c = mp_set_bode;
  settings_bode_c.f_norm_Hz = f_co_c;
  settings_bode_c.fontsize = fs;
  settings_bode_c.exp_lb = -6;
  settings_bode_c.exp_ub = 6;
  
  settings_nichols_c = mp_set_nichols;
  settings_nichols_c.f_norm_Hz = f_co_c;
  settings_nichols_c.phase_lb = -270;
  settings_nichols_c.phase_ub = -90;
  settings_nichols_c.phase_delta = 45;
  settings_nichols_c.fontsize = fs;
  settings_nichols_c.marker_size = ms;
  
  figure( 1),clf( 1),set( 1,'name','Motor Calib.'),grid on
  figure( 2),clf( 2),set( 2,'name','XYZ-Nichols (L)'),grid on
  figure( 3),clf( 3),set( 3,'name','XYZ-Bode (L)'),grid on
  figure( 4),clf( 4),set( 4,'name','XYZ-Bode (F)'),grid on
  figure( 5),clf( 5),set( 5,'name','XYZ-Bode (P)'),grid on
  figure( 6),clf( 6),set( 6,'name','XYZ-Bode (C)'),grid on
  figure( 7),clf( 7),set( 7,'name','XYZ-Bode (W)'),grid on
  figure( 8),clf( 8),set( 8,'name','C-Nichols (L)'),grid on
  figure( 9),clf( 9),set( 9,'name','C-Bode (L)'),grid on
  figure(10),clf(10),set(10,'name','C-Bode (F)'),grid on
  figure(11),clf(11),set(11,'name','C-Bode (P)'),grid on
  figure(12),clf(12),set(12,'name','C-Bode (C)'),grid on
  figure(13),clf(13),set(13,'name','C-Bode (W)'),grid on
end
%% Motor Parameters
pwm_0 = 1100; % zero-thrust PWM [us]
V_calib = 10.0; % calibration voltage [V]

p_00 =  3.487;     % (3.264, 3.71)
p_10 = -0.2723;    % (-0.288, -0.2566)
p_01 = -0.004932;  % (-0.005157, -0.004708)
p_11 =  0.0002591; % (0.0002485, 0.0002698)
p_02 =  1.574e-06; % (1.511e-06, 1.638e-06)

a = p_02; % [N/us]
b = p_01+p_11*V_calib+2*p_02*pwm_0; % [N/us]
c = p_00+p_10*V_calib+p_01*pwm_0+p_11*V_calib*pwm_0+p_02*pwm_0^2; % [N/us]

if (write_to_file)
  fprintf(fid,'\n');
  fprintf(fid,'zero_thrust_pwm = %e\n',pwm_0); % [us]
  fprintf(fid,'dpwm_min = %e\n',20); % [us]
  fprintf(fid,'dpwm_max = %e\n',700); % [us]
  fprintf(fid,'a_dpwm2force = %e\n',a); % [N/us]
  fprintf(fid,'b_dpwm2force = %e\n',b); % [N/us]
  fprintf(fid,'c_dpwm2force = %e\n',c); % [N/us]
  fprintf(fid,'\n');
end

if (perform_plotting)
  figure(1),clf(1),hold on,grid on
  PWMs = linspace(1000,1800,1000);
  DPWMs = PWMs-pwm_0;
  plot(DPWMs,4*(a*DPWMs.^2+b*DPWMs+c)/(0.35*9.81),'color','r', ...
                                                  'linestyle','-', ...
                                                  'linewidth',lw)
  plot(DPWMs,4*(p_00 ...
               +p_10*V_calib ...
               +p_01*PWMs ...
               +p_11*V_calib*PWMs ...
               +p_02*PWMs.^2)/(0.35*9.81),'color','b', ...
                                          'linestyle','--', ...
                                          'linewidth',lw)
  xlabel('$\Delta$-PWM [us]')
  ylabel('Motor Force ($\times 4$) [g''s]')
  set(gca,'ylim',[0 3])
end
%% Allocator Parameters
if (write_to_file)
  fprintf(fid,'\n');
  fprintf(fid,'alloc_tol = %e\n',1e-6);
  fprintf(fid,'z_guar = %e\n',-0.05); % [N-m]
  fprintf(fid,'k_force2torque = %e\n',0.015); % [m]
  fprintf(fid,'l_moment_arm = %e\n',0.085); % [m]
  fprintf(fid,'\n');
end
%% Command Parameters
if (write_to_file)
  fprintf(fid,'\n');
  fprintf(fid,'max_cmd_collective = %e\n',12.0); % [N]
  fprintf(fid,'max_cmd_collective_rate = %e\n',7.5); % [N/s]
  fprintf(fid,'max_cmd_torque_xy = %e\n',0.25*9.81*0.35*0.085); % [N-m]
  fprintf(fid,'max_cmd_torque_z = %e\n',0.025*9.81*0.35*0.085); % [N-m]
  fprintf(fid,'max_cmd_omega_xy_dps = %e\n',180); % [deg/s]
  fprintf(fid,'max_cmd_omega_z_dps = %e\n',45); % [deg/s]
  fprintf(fid,'min_cmd_sensed_g = %e\n',0.50); % [g's]
  fprintf(fid,'max_cmd_sensed_g = %e\n',1.50); % [g's]
  fprintf(fid,'max_cmd_delta_sensed_g = %e\n',0.35); % [g's]
  fprintf(fid,'max_cmd_clock_rate_dps = %e\n',90); % [deg/s]
  fprintf(fid,'max_cmd_tilt_deg = %e\n',55); % [deg]
  fprintf(fid,'body_aligned_att_ctrl_cmd = %s\n','false'); % [true,false]
  fprintf(fid,'max_hvel = %e\n',2.00); % max hor vel [m/s]
  fprintf(fid,'max_vvel = %e\n',1.00); % max ver vel [m/s]
  fprintf(fid,'tau_hvel_ref = %e\n',0.35); % hor vel cmd time const [s]
  fprintf(fid,'tau_vvel_ref = %e\n',0.65); % vert vel cmd time const [s]
  fprintf(fid,'body_aligned_trans_ctrl_cmd = %s\n','false'); % [true,false]
  fprintf(fid,'\n');
end
%% Attitude Controller Parameters
if (write_to_file)
  fprintf(fid,'\n');
  fprintf(fid,'enable_att_ctrl_tilt_prioritization = %s\n','true');
  fprintf(fid,'att_ctrl_fb_max_omega_xy_dps = %e\n',360); % [deg/s]
  fprintf(fid,'att_ctrl_fb_max_omega_z_dps = %e\n',90); % [deg/s]
  fprintf(fid,'\n');
  
  % DEACTIVATED IN AUTOPILOT %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  J_b = mp_model_vehicle('inertia');
  
  fprintf(fid,'att_prefilt_J_xx = %e\n',J_b(1,1)); % [kg-m^2]
  fprintf(fid,'att_prefilt_J_yy = %e\n',J_b(2,2)); % [kg-m^2]
  fprintf(fid,'att_prefilt_J_zz = %e\n',J_b(3,3)); % [kg-m^2]
  fprintf(fid,'att_prefilt_omega_xy_sat_dps = %e\n',360); % [deg/s]
  fprintf(fid,'att_prefilt_omega_z_sat_dps = %e\n',180); % [deg/s]
  fprintf(fid,'att_prefilt_tau_xy_sat = %e\n',0.30); % [N-m]
  fprintf(fid,'att_prefilt_tau_z_sat = %e\n',0.10); % [N-m]
  fprintf(fid,'att_prefilt_k_p_xy = %e\n',120.0);
  fprintf(fid,'att_prefilt_k_p_z = %e\n',120.0);
  fprintf(fid,'att_prefilt_k_d_xy = %e\n',20.0);
  fprintf(fid,'att_prefilt_k_d_z = %e\n',20.0);
  fprintf(fid,'att_prefilt_n_steps = %d\n',15);
  fprintf(fid,'\n');
  % DEACTIVATED IN AUTOPILOT %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  N_C_ATT = 10;
  
  C_att = cell(3,1);
  C_att{1} = mp_ctrl_pid(17.5,0.0,0.0,50.0);
  C_att{2} = mp_ctrl_pid(17.5,0.0,0.0,50.0);
  C_att{3} = mp_ctrl_pid(5.0,0.0,0.0,50.0);
  
  for i=1:3
    T_i_cas = mp_tf_cascade(C_att{i});
    for j=1:N_C_ATT
      if (j <= length(T_i_cas))
        T_ij_d = mp_tf_discretize(T_i_cas{j},f_samp,disc_method);
      else
        T_ij_d = zpk([],[],1);
      end
      T_ij_filt = mp_filter('init',T_ij_d);
      filt_ij_name = sprintf('C_att[%d][%d]',i-1,j-1);
      mp_filter('write',T_ij_filt,filt_num_max, ...
                        filt_den_max,fid,filt_ij_name);
      fprintf(fid,'\n');
    end
  fprintf(fid,'\n');
  end
  fprintf(fid,'\n');
end
%% Translational Controller Parameters
if (write_to_file)
  fprintf(fid,'\n');
  fprintf(fid,'min_sensed_ver_accl_g = %e\n',0.15); % [g's]
  fprintf(fid,'max_sensed_ver_accl_g = %e\n',2.25); % [g's]
  fprintf(fid,'max_tilt_deg = %e\n',55); % [deg]
  fprintf(fid,'tilt_comp_threshold_deg = %e\n',70); % [deg]
  fprintf(fid,'\n');
  
  N_C_TRANS = 15;
  names_trans = {'C_id_trans','C_od_trans_pos','C_od_trans_vel'};
  
  C_id_trans = cell(3,1);
%   C_id_trans{1} = mp_ctrl_pid(6.0,0.0,6.0,1);%*mp_loopshape_bessel(32.0,4);
%   C_id_trans{2} = mp_ctrl_pid(6.0,0.0,6.0,1);%*mp_loopshape_bessel(32.0,4);
%   C_id_trans{3} = mp_ctrl_pid(10.0,0.0,10.0,1);
  C_id_trans{1} = 6.0+6.0*zpk(0,[],1)*mp_ctrl_pole(10.0,1);
  C_id_trans{2} = 6.0+6.0*zpk(0,[],1)*mp_ctrl_pole(10.0,1);
  C_id_trans{3} = 10.0+10.0*zpk(0,[],1)*mp_ctrl_pole(10.0,1);
  
  C_od_trans_pos = cell(3,1);
  C_od_trans_pos{1} = mp_ctrl_pid(8.0,0.0,0.0,50);
  C_od_trans_pos{2} = mp_ctrl_pid(8.0,0.0,0.0,50);
  C_od_trans_pos{3} = mp_ctrl_pid(10.0,0.0,0.0,50);
  
  C_od_trans_vel = cell(3,1);
  C_od_trans_vel{1} = mp_ctrl_pid(8.0,0.0,0.0,50);
  C_od_trans_vel{2} = mp_ctrl_pid(8.0,0.0,0.0,50);
  C_od_trans_vel{3} = mp_ctrl_pid(10.0,0.0,0.0,50);
  
  for k=1:length(names_trans)
    for i=1:3
      T_i_cas = eval(['mp_tf_cascade(' names_trans{k} '{i});']);
      for j=1:N_C_TRANS
        if (j <= length(T_i_cas))
          T_ij_d = mp_tf_discretize(T_i_cas{j},f_samp,'zoh');
        else
          T_ij_d = zpk([],[],1);
        end
        T_ij_filt = mp_filter('init',T_ij_d);
        filt_ij_name = sprintf([names_trans{k} '[%d][%d]'],i-1,j-1);
        mp_filter('write',T_ij_filt,filt_num_max, ...
                          filt_den_max,fid,filt_ij_name);
        fprintf(fid,'\n');
      end
    fprintf(fid,'\n');
    end
    fprintf(fid,'\n');
  end
end
%% Rate Controller
for k=1:length(names_xyz)
  for i=1:3
    T_i_cas = eval(['mp_tf_cascade(' names_xyz{k} '{i});']);
    if (length(T_i_cas) < sizes_xyz{k})
      for ii=1:length(T_i_cas)
        if (length(T_i_cas{ii}.Z{1}) > length(T_i_cas{ii}.P{1}))
          fprintf([names_xyz{k} '(%d) - FAIL!!!\n'],i);
          fclose(fid);
          return
        end
      end
      fprintf([names_xyz{k} '(%d) - pass\n'],i);
    else
      fprintf([names_xyz{k} '(%d) - FAIL!!!\n'],i);
      fclose(fid);
      return
    end
    
    if (write_to_file)
      fprintf('   writing...\n')
      for j=1:sizes_xyz{k}
        if (j <= length(T_i_cas))
          T_ij_d = mp_tf_discretize(T_i_cas{j},f_samp,disc_method);
        else
          T_ij_d = zpk([],[],1);
        end
        T_ij_filt = mp_filter('init',T_ij_d);
        filt_ij_name = sprintf([names_xyz{k} '[%d][%d]'],i-1,j-1);
        mp_filter('write',T_ij_filt,filt_num_max, ...
                          filt_den_max,fid,filt_ij_name);
        fprintf(fid,'\n');
      end
      fprintf(fid,'\n');
    end
  end
  
  if (write_to_file)
    fprintf(fid,'\n');
  end
end

if (perform_plotting)
  L_xyz = cell(3,1);
  T_xyz = cell(3,1);
  
  for i=1:3
    L_xyz{i,1} = minreal(C_xyz{i}*A_xyz{i}*G_xyz{i}*H_xyz);
    T_xyz{i,1} = minreal((L_xyz{i}-W_xyz{i}*C_xyz{i})/ ...
                         (1+W_xyz{i}*C_xyz{i}));
    
    figure(2)
    mp_nichols(L_xyz{i}, ...
      'color',colors{i}, ...
      'linestyle','-', ...
      'linewidth',lw, ...
      settings_nichols_xyz)
    mp_nichols(T_xyz{i}, ...
      'color',colors{i}, ...
      'linestyle','--', ...
      'linewidth',lw, ...
      settings_nichols_xyz)
    
    figure(3)
    mp_bode(C_xyz{i}*A_xyz{i}*G_xyz{i}*H_xyz, ...
      'color',colors{i}, ...
      'linestyle','-', ...
      'linewidth',lw, ...
      settings_bode_xyz)
    
    figure(4)
    mp_bode(F_tau{i}, ...
      'color',colors{i}, ...
      'linestyle','--', ...
      'linewidth',lw, ...
      settings_bode_xyz)
    mp_bode(F_xyz{i}, ...
      'color',colors{i}, ...
      'linestyle','-', ...
      'linewidth',lw, ...
      settings_bode_xyz)
    
    figure(5)
    mp_bode(P_xyz{i}, ...
      'color',colors{i}, ...
      'linestyle','-', ...
      'linewidth',lw, ...
      settings_bode_xyz)
    mp_bode(minreal(P_xyz{i}*T_cl_xyz{i}), ...
      'color',colors{i}, ...
      'linestyle','--', ...
      'linewidth',lw, ...
      settings_bode_xyz)
    
    figure(6)
    mp_bode(C_xyz{i}, ...
      'color',colors{i}, ...
      'linestyle','-', ...
      'linewidth',lw, ...
      settings_bode_xyz)
    
    figure(7)
    mp_bode(W_xyz{i}, ...
      'color',colors{i}, ...
      'linestyle','-', ...
      'linewidth',lw, ...
      settings_bode_xyz)
  end
end
%% Z-Accl Controller
for k=1:length(names_c)
  for i=1
    T_i_cas = eval(['mp_tf_cascade(' names_c{k} '{i});']);
    if (length(T_i_cas) < sizes_c{k})
      for ii=1:length(T_i_cas)
        if (length(T_i_cas{ii}.Z{1}) > length(T_i_cas{ii}.P{1}))
          fprintf([names_c{k} '(%d) - FAIL!!!\n'],i);
          fclose(fid);
          return
        end
      end
      fprintf([names_c{k} '(%d) - pass\n'],i);
    else
      fprintf([names_c{k} '(%d) - FAIL!!!\n'],i);
      fclose(fid);
      return
    end
    
    if (write_to_file)
      fprintf('   writing...\n')
      for j=1:sizes_c{k}
        if (j <= length(T_i_cas))
          T_ij_d = mp_tf_discretize(T_i_cas{j},f_samp,disc_method);
        else
          T_ij_d = zpk([],[],1);
        end
        T_ij_filt = mp_filter('init',T_ij_d);
        filt_ij_name = sprintf([names_c{k} '[%d][%d]'],i-1,j-1);
        mp_filter('write',T_ij_filt,filt_num_max, ...
                          filt_den_max,fid,filt_ij_name);
        fprintf(fid,'\n');
      end
      fprintf(fid,'\n');
    end
  end
  
  if (write_to_file)
    fprintf(fid,'\n');
  end
end

if (perform_plotting)
  L_c = cell(3,1);
  T_c = cell(3,1);
  
  for i=1
    L_c{i,1} = minreal(C_c{i}*A_c{i}*G_c{i}*H_c);
    T_c{i,1} = minreal((L_c{i}-W_c{i}*C_c{i})/ ...
                       (1+W_c{i}*C_c{i}));
    
    figure(8)
    mp_nichols(L_c{i}, ...
      'color',colors{i}, ...
      'linestyle','-', ...
      'linewidth',lw, ...
      settings_nichols_c)
    mp_nichols(T_c{i}, ...
      'color',colors{i}, ...
      'linestyle','--', ...
      'linewidth',lw, ...
      settings_nichols_c)
    
    figure(9)
    mp_bode(C_c{i}*A_c{i}*G_c{i}*H_c, ...
      'color',colors{i}, ...
      'linestyle','-', ...
      'linewidth',lw, ...
      settings_bode_c)
    
    figure(10)
    mp_bode(F_tau{i}, ...
      'color',colors{i}, ...
      'linestyle','--', ...
      'linewidth',lw, ...
      settings_bode_c)
    mp_bode(F_c{i}, ...
      'color',colors{i}, ...
      'linestyle','-', ...
      'linewidth',lw, ...
      settings_bode_c)
    
    figure(11)
    mp_bode(P_c{i}, ...
      'color',colors{i}, ...
      'linestyle','-', ...
      'linewidth',lw, ...
      settings_bode_c)
    mp_bode(minreal(P_c{i}*T_cl_c{i}), ...
      'color',colors{i}, ...
      'linestyle','--', ...
      'linewidth',lw, ...
      settings_bode_c)
    
    figure(12)
    mp_bode(C_c{i}, ...
      'color',colors{i}, ...
      'linestyle','-', ...
      'linewidth',lw, ...
      settings_bode_c)
    
    figure(13)
    mp_bode(W_c{i}, ...
      'color',colors{i}, ...
      'linestyle','-', ...
      'linewidth',lw, ...
      settings_bode_c)
  end
end
%% Postprocessing
if (write_to_file)
  fclose(fid);
end
