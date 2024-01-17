%% Clear
%#ok<*SAGROW>
%#ok<*UNRCH>
clear
clc
global traj
%% Inputs
% Extract trajectory.
traj = trajectory_3dof(21,-0.1,1.65);

% Simulation parameters.
t_i = -0.10;
t_f = 1.65;
dt = 0.001;
integrator = 'ode45';

% Algorithm parameters.
tol = 1e-8;
z_guar = 0.00;

% Initial conditions.
p_i = [0 0 0]';
v_i = [0 0 0]';
q_i2b_i = Q_I2D(t_i);
omega_b_i = OMEGA_D(t_i);
f_i = 0*0.25*0.35*norm(mp_quad_6dof_t.g_i)*ones(4,1);

% Attitude prefilter parameters.
J_b = mp_model_vehicle('inertia');
G_p = 1.00*diag([2500 2500 1800]);
G_d = 1.25*diag([15 20 75]);
omega_sat = [600 600 600]'*(pi/180);
tau_sat = [0.40 0.40 0.10]';
% tau_sat = [0.25 0.25 0.05]';
omega_sat_type = inf;
tau_sat_type = 1;
q_i2r_i = Q_I2D(t_i);
omega_r_i = OMEGA_D(t_i);

% Attitude control parameters.
K_att = [35.0 35.0 10.0]';
omega_fb_sat = [1000 1000 50]'*(pi/180);
H_omega_fb_sat = inv(diag(omega_fb_sat));
fa_cone_angle = 45*(pi/180);

% Post-processing options.
save_figures = false;
filename = 'ex3';
%% System Definition
A(1) = mp_model_actuator('thrust','2nd');
A(2) = mp_model_actuator('thrust','2nd');
A(3) = mp_model_actuator('thrust','2nd');
A(4) = mp_model_actuator('thrust','2nd'); % ('torque','2nd')
G(1) = mp_model_vehicle('z-accl');
G(2) = mp_model_vehicle('x-rate');
G(3) = mp_model_vehicle('y-rate');
G(4) = mp_model_vehicle('z-rate');
H(1) = mp_model_mpu6000('accl',3);
H(2) = mp_model_mpu6000('gyro',3);
H(3) = mp_model_mpu6000('gyro',3);
H(4) = mp_model_mpu6000('gyro',3);
%% Control Design
f_co = 10;
f_te = 2.0*f_co;
f_ff = 8.0*f_co;

for i=1:4
  C(i) = mp_loopshape_s3_ns_pm35m(f_co,A(i)*G(i)*H(i));
  if (i == 1)
    T_E_desired = mp_loopshape_te_type0(f_te);
    R_fb = mp_ctrl_complex_pole(f_ff,0.6,1);
  else
    T_E_desired = mp_loopshape_te_type1(f_te);
    R_fb = mp_ctrl_complex_pole(f_ff,0.6,1)*mp_ctrl_pole(f_ff,1);
  end
  
  W(i) = mp_ndc_element(C(i),A(i)*G(i)*H(i),T_E_desired);
  
  P_fb(i) = H(i)*R_fb;
  F_fb(i)=  R_fb/(A(i)*G(i));
  
  R_ff = mp_ctrl_complex_pole(f_ff,0.6,1);
  P_ff(i) = H(i)*R_ff;
  F_ff(i) = R_ff/A(i);
  
  T_L(i) = minreal(C(i)*A(i)*G(i)*H(i));
  T_G(i) = minreal(C(i)*W(i));
  T_E(i) = minreal((T_L(i)-T_G(i))/(1+T_G(i)));
end
%% Run Simulation
plant = mp_quad_6dof_t(A,H,@D,@N,p_i,v_i,q_i2b_i,omega_b_i,f_i);
for i=1:4
  ndc_cxyz(i) = mp_ndc_t(P_fb(i),F_fb(i),P_ff(i),F_ff(i),C(i),W(i));
end
p_att = mp_att_prefilter_t(J_b,G_p,G_d, ...
                           omega_sat,omega_sat_type, ...
                           tau_sat,tau_sat_type, ...
                           q_i2r_i,omega_r_i);

t = t_i:dt:t_f;
X_i = [plant.x_i
       ndc_cxyz(1).x_i
       ndc_cxyz(2).x_i
       ndc_cxyz(3).x_i
       ndc_cxyz(4).x_i
       p_att.x_i];

if isequal(integrator,'ode45')
  odeopt = odeset('abstol',1e-6,'reltol',1e-6);
  [~,X] = ode45(...
    @(t,X)derivs(t,X, ...
                 plant, ...
                 ndc_cxyz,z_guar,tol, ...
                 p_att,K_att,H_omega_fb_sat,fa_cone_angle), ...
    t,X_i,odeopt);
elseif isequal(integrator,'rk4')
  [~,X] = mp_rk4(...
    @(t,X)derivs(t,X, ...
                 plant, ...
                 ndc_cxyz,z_guar,tol, ...
                 p_att,K_att,H_omega_fb_sat,fa_cone_angle), ...
    t,X_i);
end
%% Extract Sim Outputs
i_plant = plant.idx;
i_ndc_c = ndc_cxyz(1).idx+i_plant(end);
i_ndc_x = ndc_cxyz(2).idx+i_ndc_c(end);
i_ndc_y = ndc_cxyz(3).idx+i_ndc_x(end);
i_ndc_z = ndc_cxyz(4).idx+i_ndc_y(end);
i_p_att = p_att.idx+i_ndc_z(end);

x_plant = X(:,i_plant)';
x_ndc_c = X(:,i_ndc_c)';
x_ndc_x = X(:,i_ndc_x)';
x_ndc_y = X(:,i_ndc_y)';
x_ndc_z = X(:,i_ndc_z)';
x_p_att = X(:,i_p_att)';

w_r = zeros(4,length(t));
w_a = zeros(4,length(t));
f_a = zeros(4,length(t));
u_pwm = zeros(4,length(t));

q_i2d = zeros(4,length(t));
q_i2r = zeros(4,length(t));
q_i2b = zeros(4,length(t));

omega_d = zeros(3,length(t));
omega_r = zeros(3,length(t));
omega_gyro_b = zeros(3,length(t));
omega_ff_b = zeros(3,length(t));
omega_ff_fb_b = zeros(3,length(t));

tau_r = zeros(3,length(t));
tau_d = zeros(3,length(t));
tau_ff_b = zeros(3,length(t));

e_tilt_r = zeros(1,length(t));
e_tilt_b = zeros(1,length(t));
e_clock_r = zeros(1,length(t));
e_clock_b = zeros(1,length(t));

fs_d = zeros(1,length(t));
fs_b = zeros(1,length(t));

p_i = plant.output_p_i(x_plant);
v_i = plant.output_v_i(x_plant);

for k=1:length(t)
  % Desired attitude.
  q_i2d(:,k) = Q_I2D(t(k));
  omega_d(:,k) = OMEGA_D(t(k));
  tau_d(:,k) = TAU_D(t(k));
  
  % Extract desired, refernce, and body attitudes.
  q_i2r(:,k) = p_att.output_q_i2r(x_p_att(:,k));
  omega_r(:,k) = p_att.output_omega_r(x_p_att(:,k));
  tau_r(:,k) = p_att.output_tau_r(x_p_att(:,k), ...
                                  q_i2d(:,k),omega_d(:,k),tau_d(:,k));
  fs_d(1,k) = FS_D(t(k));
  
  % Perform attitude and force adjustments.
  q_i2b(:,k) = x_plant(plant.i_q_i2b,k);
  y_plant_inertial_k = plant.output_inertial(x_plant(:,k));
  omega_gyro_b(:,k) = y_plant_inertial_k(2:4);
  [omega_ff_b(:,k),tau_ff_b(:,k)] = ...
    mp_att_correction(plant.J_b, ...
                      q_i2r(:,k),omega_r(:,k),tau_r(:,k), ...
                      q_i2b(:,k),omega_gyro_b(:,k));
  fs_b(1,k) = ...
    mp_force_correction(fs_d(1,k),q_i2b(:,k),q_i2d(:,k),fa_cone_angle);
  
  % Force + angular velocity feedback signals.
  r_fb_k = zeros(4,1);
  r_fb_k(1) = fs_b(1,k);
  r_fb_k(2:4) = ...
    mp_att_control(q_i2b(:,k),q_i2r(:,k), ...
                   K_att,H_omega_fb_sat,'prioritized');
  
  omega_fb_b(:,k) = r_fb_k(2:4);
  omega_ff_fb_b(:,k) = omega_ff_b(:,k)+omega_fb_b(:,k);
  
  u_ff_k = zeros(4,1);
  u_ff_k(2:4) = tau_r(:,k);
  
  q_d2r_k = mp_quat_mult(mp_quat_conjugate(q_i2d(:,k)),q_i2r(:,k));
  q_d2b_k = mp_quat_mult(mp_quat_conjugate(q_i2d(:,k)),q_i2b(:,k));
  
  e_tilt_r(k) = acos(dot(mp_quat2dcm(q_d2r_k)'*[0 0 1]',[0 0 1]'));
  e_tilt_b(k) = acos(dot(mp_quat2dcm(q_d2b_k)'*[0 0 1]',[0 0 1]'));
  e_clock_r(k) = mp_quat2yaw(q_d2r_k);
  e_clock_b(k) = mp_quat2yaw(q_d2b_k);
  
  w_r(1,k) = ndc_cxyz(1).output(x_ndc_c(:,k),r_fb_k(1),u_ff_k(1));
  w_r(2,k) = ndc_cxyz(2).output(x_ndc_x(:,k),r_fb_k(2),u_ff_k(2));
  w_r(3,k) = ndc_cxyz(3).output(x_ndc_y(:,k),r_fb_k(3),u_ff_k(3));
  w_r(4,k) = ndc_cxyz(4).output(x_ndc_z(:,k),r_fb_k(4),u_ff_k(4));
  
  [w_a(:,k),f_a(:,k)] = mp_qallocator(w_r(:,k),z_guar,plant.H_f2w, ...
                                      plant.l_x,plant.l_y,plant.k_f2t, ...
                                      plant.f_min,plant.f_max,tol);
  u_pwm(:,k) = f2p_assumed(plant,f_a(:,k));
end

s_plant = plant.sigs(t,x_plant,u_pwm);
%% Plotting Setup
set(0,'defaulttextinterpreter','latex')
fs = 12;
%% Figure 1 - PWMs
figure(1),clf(1),set(1,'name','PWMs')
labels = {'$p_1$ [us]','$p_2$ [us]','$p_3$ [us]','$p_4$ [us]'};
for i=1:4
  subplot(4,1,i),hold on,grid on
  plot(t,plant.pwm_min*ones(size(t)),'color','k','linestyle','--')
  plot(t,plant.pwm_max*ones(size(t)),'color','k','linestyle','--')
  plot(t,s_plant.u_pwm(i,:),'b')
  plot(t,s_plant.u_pwm_sat(i,:),'r')
  xlabel('Time [s]','fontsize',fs)
  ylabel(labels{i},'fontsize',fs)
  set(gca,'fontsize',fs)
  set(gca,'ylim',[1000 2000])
  set(gca,'ytick',1000:250:2000)
end
%% Figure 2 - Motor Forces
figure(2),clf(2),set(2,'name','Motor Forces')
labels = {'$f_1$ [N]','$f_2$ [N]','$f_3$ [N]','$f_4$ [N]'};
for i=1:4
  subplot(4,1,i),hold on,grid on
  plot(t,plant.f_min*ones(size(t)),'color','k','linestyle','--')
  plot(t,plant.f_max*ones(size(t)),'color','k','linestyle','--')
  plot(t,f_a(i,:),'color',[0 0.7 0])
  plot(t,plant.p2f(s_plant.u_pwm_sat(i,:)),'color',[0 0.7 0])
  plot(t,p2f_assumed(plant,s_plant.u_pwm_sat(i,:)),'b')
  plot(t,s_plant.f(i,:),'r')
  xlabel('Time [s]','fontsize',fs)
  ylabel(labels{i},'fontsize',fs)
  set(gca,'fontsize',fs)
  set(gca,'ylim',[0 3.0],'ytick',0:1.0:3.0)
end
%% Figure 3 - Allocation
figure(3),clf(3),set(3,'name','Allocation')
labels = {'$u_c$ [N]','$u_x$ [N-m]','$u_y$ [N-m]','$u_z$ [N-m]'};
ylims = [0 10; -0.6 0.6; -0.6 0.6; -0.1 0.1];
yticks = [0 2.5 10; -0.6 0.3 0.6; -0.6 0.3 0.6; -0.1 0.05 0.1];
for i=1:4
  subplot(4,1,i),hold on,grid on
  plot(t,w_r(i,:),'b')
  plot(t,w_a(i,:),'r')
  xlabel('Time [s]','fontsize',fs)
  ylabel(labels{i},'fontsize',fs)
  set(gca,'fontsize',fs)
  set(gca,'ylim',ylims(i,:),'ytick',yticks(i,1):yticks(i,2):yticks(i,3))
end
%% Figure 4 - Inertial
figure(4),clf(4),set(4,'name','Inertial')

fact = [1/norm(mp_quad_6dof_t.g_i) 180/pi 180/pi 180/pi]';
labels = {'$f_s$ [g''s]', ...
          '$\omega_x$ [deg/s]', ...
          '$\omega_y$ [deg/s]', ...
          '$\omega_z$ [deg/s]'};
for i=1:4
  subplot(4,1,i),hold on,grid on
  xlabel('Time [s]','fontsize',fs)
  ylabel(labels{i},'fontsize',fs)
  set(gca,'fontsize',fs)
  if (i == 1)
    plot(t,fs_d*fact(i),'color',[0 0.7 0])
    plot(t,fs_b*fact(i),'b')
    plot(t,-s_plant.z_accl*fact(i),'r')
    set(gca,'ylim',[-1 3],'ytick',-10:1.0:10)
  else
    plot(t,omega_d(i-1,:)*fact(i),'color',[0 0.7 0])
    plot(t,omega_r(i-1,:)*fact(i),'b')
    plot(t,omega_ff_fb_b(i-1,:)*fact(i),'m')
    plot(t,s_plant.omega_b(i-1,:)*fact(i),'r')
    set(gca,'ylim',500*[-1 1],'ytick',-5000:250:5000)
  end
end
%% Figure 5 - Attitude
figure(5),clf(5),set(5,'name','Attitude')
labels = {'$\phi$ [deg]','$\theta$ [deg]','$\psi$ [deg]'};
rpy_d = [mp_quat2roll(q_i2d); mp_quat2pitch(q_i2d); mp_quat2yaw(q_i2d)];
rpy_r = [mp_quat2roll(q_i2r); mp_quat2pitch(q_i2r); mp_quat2yaw(q_i2r)];
rpy_b = [mp_quat2roll(q_i2b); mp_quat2pitch(q_i2b); mp_quat2yaw(q_i2b)];
for i=1:3
  subplot(3,1,i),hold on,grid on
  plot(t,rpy_d(i,:)*(180/pi),'color',[0 0.7 0])
  plot(t,rpy_r(i,:)*(180/pi),'r')
  plot(t,rpy_b(i,:)*(180/pi),'b')
  xlabel('Time [s]','fontsize',fs)
  ylabel(labels{i},'fontsize',fs)
  set(gca,'fontsize',fs)
  set(gca,'ylim',180*[-1 1],'ytick',-180:90:180)
end
%% Figure 6 - Attitude Error
figure(6),clf(6),set(6,'name','Attitude Error')

subplot(2,1,1),hold on,grid on
plot(t,e_tilt_r*(180/pi),'r')
plot(t,e_tilt_b*(180/pi),'b')
xlabel('Time [s]','fontsize',fs)
ylabel('Tilt Error [deg]','fontsize',fs)
set(gca,'fontsize',fs)
set(gca,'ylim',180*[-1 1],'ytick',-180:90:180)

subplot(2,1,2),hold on,grid on
plot(t,e_clock_r*(180/pi),'r')
plot(t,e_clock_b*(180/pi),'b')
xlabel('Time [s]','fontsize',fs)
ylabel('Clock Error [deg]','fontsize',fs)
set(gca,'fontsize',fs)
set(gca,'ylim',180*[-1 1],'ytick',-180:90:180)
%% Figure 7 - Velocities
figure(7),clf(7),set(7,'name','Velocities')
labels = {'$v_n$ [m/s]','$v_e$ [m/s]','$v_d$ [m/s]'};
for i=1:3
  subplot(3,1,i),hold on,grid on
  plot(t,interp1(traj.t,traj.v_i(i,:),t,'linear'),'b')
  plot(t,v_i(i,:),'r')
  xlabel('Time [s]','fontsize',fs)
  ylabel(labels{i},'fontsize',fs)
  set(gca,'fontsize',fs)
  if (i == 3)
    set(gca,'ydir','reverse')
  end
end
%% Figure 8 - Positions
figure(8),clf(8),set(8,'name','Positions')
labels = {'$p_n$ [m]','$p_e$ [m]','$p_d$ [m]'};
for i=1:3
  subplot(3,1,i),hold on,grid on
  plot(t,interp1(traj.t,traj.p_i(i,:),t,'linear'),'b')
  plot(t,p_i(i,:),'r')
  xlabel('Time [s]','fontsize',fs)
  ylabel(labels{i},'fontsize',fs)
  set(gca,'fontsize',fs)
  if (i == 3)
    set(gca,'ydir','reverse')
  end
end
%% Save Figures
if (save_figures)
  saveas(1,[filename '_pwms.png'],'png')
  saveas(2,[filename '_motor_forces.png'],'png')
  saveas(3,[filename '_allocation.png'],'png')
  saveas(4,[filename '_inertial.png'],'png')
  saveas(5,[filename '_attitude.png'],'png')
end
%% Functions
function [d] = D(t)
  d = zeros(4,length(t));
end
function [n] = N(t)
	n = zeros(4,length(t));
end
function [fs_d] = FS_D(t)
  global traj
  fs_d = interp1(traj.t,traj.fs_d,t,'linear');
  
%   fs_d = mp_sig_step(0.05,t)*(9.8071);
end
function [q_i2d] = Q_I2D(t)
  global traj
  pnt_vec_i = zeros(3,length(t));
  pnt_vec_i(1,:) = interp1(traj.t,traj.fs_hat_i(1,:),t,'linear');
  pnt_vec_i(2,:) = interp1(traj.t,traj.fs_hat_i(2,:),t,'linear');
  pnt_vec_i(3,:) = interp1(traj.t,traj.fs_hat_i(3,:),t,'linear');
  q_i2d = mp_vec2quat(pnt_vec_i,0*ones(size(t)));
  
% %   theta = 90*(pi/180)*sin(2*pi*1*t);
% %   theta = 90*mp_sig_step(0.20,t);
% %   n_hat = [1 0 0]';
%   
%   theta = -60 ...
%           +60*mp_sig_ramp(0.10,0.30,t) ...
%           +60*mp_sig_ramp(0.30,0.50,t);
%   n_hat = [1 0 0]'*mp_sig_spulse(0.0,0.3,t) ...
%          +[0 1 0]'*mp_sig_spulse(0.3,1.6,t);
%   
%   q_i2d = [cosd(0.5*theta)
%            sind(0.5*theta).*(n_hat./sum(n_hat.^2,1).^0.5)];
%   q_i2d = [ones(1,length(t))
%            zeros(3,length(t))];
end
function [omega_d] = OMEGA_D(t)
  global traj
  omega_d = zeros(3,length(t));
  omega_d(1,:) = interp1(traj.t,traj.omega_d(1,:),t,'linear');
  omega_d(2,:) = interp1(traj.t,traj.omega_d(2,:),t,'linear');
  omega_d(3,:) = interp1(traj.t,traj.omega_d(3,:),t,'linear');
  
%   n_hat = [1 0 0]'*mp_sig_spulse(0.00,0.30,t) ...
%          +[0 1 0]'*mp_sig_spulse(0.30,1.60,t);
%   n_hat = n_hat./sum(n_hat.^2,1).^0.5;
%   theta = -60 ...
%           +60*mp_sig_ramp(0.10,0.30,t) ...
%           +60*mp_sig_ramp(0.30,0.50,t);
%   q = [cosd(0.5*theta)
%        sind(0.5*theta).*n_hat];
%   
%   theta_dot = 60*mp_sig_spulse(0.10,0.30,t)/(0.30-0.10) ...
%              +60*mp_sig_spulse(0.30,0.50,t)/(0.50-0.30);
%   theta_dot = theta_dot*(pi/180);
%   q_dot = [-0.5*sind(0.5*theta).*theta_dot
%             0.5*cosd(0.5*theta).*theta_dot.*n_hat];
%   
%   omega_d = zeros(3,length(t));
%   for k=1:length(t)
%     Q_k = mp_skewQ(q(:,k));
%     omega_d(:,k) = 0.5*Q_k(2:4,:)\q_dot(2:4,k);
%   end
%   
%   omega_d = [zeros(1,length(t))
%              zeros(1,length(t))
%              zeros(1,length(t))];
end
function [tau_d] = TAU_D(t)
  global traj
  tau_d = zeros(3,length(t));
  tau_d(1,:) = interp1(traj.t,traj.tau_d(1,:),t,'linear');
  tau_d(2,:) = interp1(traj.t,traj.tau_d(2,:),t,'linear');
  tau_d(3,:) = interp1(traj.t,traj.tau_d(3,:),t,'linear');
  
%   tau_d = [zeros(1,length(t))
%            zeros(1,length(t))
%            zeros(1,length(t))];
end

function [p] = f2p_assumed(plant,f)
%   p = 300*f+plant.pwm_min;
  p = plant.f2p(f);
end
function [f] = p2f_assumed(plant,p)
%   f = (1/300)*(p-plant.pwm_min);
  f = plant.p2f(p);
end
function [X_dot] = derivs(t,X, ...
                          plant, ...
                          ndc_cxyz,z_guar,tol, ...
                          p_att,K_att,H_omega_fb_sat,fa_cone_angle)
	fprintf('%07.4f\n',t)
  
  i_plant = plant.idx;
  i_ndc{1} = ndc_cxyz(1).idx+i_plant(end);
  i_ndc{2} = ndc_cxyz(2).idx+i_ndc{1}(end);
  i_ndc{3} = ndc_cxyz(3).idx+i_ndc{2}(end);
  i_ndc{4} = ndc_cxyz(4).idx+i_ndc{3}(end);
  i_p_att = p_att.idx+i_ndc{4}(end);
  
  x_plant = X(i_plant);
  x_p_att = X(i_p_att);
  
  % Desired attitude.
  q_i2d = Q_I2D(t);
  omega_d = OMEGA_D(t);
  tau_d = TAU_D(t);
  
  % Extract reference attitude, angular velocity, torques, and 
  % specific force.
  q_i2r = p_att.output_q_i2r(x_p_att);
  omega_r = p_att.output_omega_r(x_p_att);
  tau_r = p_att.output_tau_r(x_p_att,q_i2d,omega_d,tau_d);
  fs_d = FS_D(t);
  
  % Perform attitude and force adjustments.
  q_i2b = x_plant(plant.i_q_i2b);
  y_plant_inertial = plant.output_inertial(x_plant);
  omega_gyro_b = y_plant_inertial(2:4);
  [omega_ff_b,tau_ff_b] = mp_att_correction(plant.J_b, ...
                                            q_i2r,omega_r,tau_r, ...
                                            q_i2b,omega_gyro_b);
  fs_b = mp_force_correction(fs_d,q_i2b,q_i2d,fa_cone_angle);
  
  % Extract inertial sensor outputs.
  y = zeros(4,1);
  y(1) = -y_plant_inertial(1);
  y(2:4) = omega_gyro_b;
  
  % Force + angular velocity feedback signals.
  r_fb = zeros(4,1);
  r_fb(1) = fs_b;
  r_fb(2:4) = ...
    mp_att_control(q_i2b,q_i2r,K_att,H_omega_fb_sat,'prioritized');
  
  % Angular velocity feed-forward.
  r_ff = zeros(4,1);
  r_ff(2:4) = omega_ff_b;
  
  % Torque feed-forward.
  u_ff = zeros(4,1);
  u_ff(2:4) = tau_ff_b;
  
  % Get low-level controller outputs.
  c_r = ndc_cxyz(1).output(X(i_ndc{1}),r_fb(1),u_ff(1));
  x_r = ndc_cxyz(2).output(X(i_ndc{2}),r_fb(2),u_ff(2));
  y_r = ndc_cxyz(3).output(X(i_ndc{3}),r_fb(3),u_ff(3));
  z_r = ndc_cxyz(4).output(X(i_ndc{4}),r_fb(4),u_ff(4));
  
  % Allocator.
  w_r = [c_r x_r y_r z_r]';
  [w_a,f_a] = mp_ allocator(w_r,z_guar,plant.H_f2w, ...
                            plant.l_x,plant.l_y,plant.k_f2t, ...
                            plant.f_min,plant.f_max,tol);
  
  % Force to PWM mapping.
  u_pwm = f2p_assumed(plant,f_a);
  
  % Compute inputs to NDC element.
  u_W = zeros(4,1);
  u_W(1) = w_r(1)-w_a(1);
  u_W(2) = w_r(2)-w_a(2);
  u_W(3) = w_r(3)-w_a(3);
  u_W(4) = w_r(4)-w_a(4);
  
  % Compute derivatives.
  X_dot = zeros(size(X));
  X_dot(i_plant) = plant.derivs(t,x_plant,u_pwm);
  for i=1:4
    X_dot(i_ndc{i}) = ...
      ndc_cxyz(i).derivs(X(i_ndc{i}),y(i),r_fb(i),r_ff(i),u_ff(i),u_W(i));
  end
  X_dot(i_p_att) = p_att.derivs(x_p_att,q_i2d,omega_d,tau_d);
end
