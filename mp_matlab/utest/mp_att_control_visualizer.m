%% Clears
clear
clc
%% Inputs
global q_i2r_spec

% Sim parameters.
t_f = 2;
n = 500;
animate = false;

% Reference roll, pitch, yaw.
roll_r = 0*(pi/180);
pitch_r = 0*(pi/180);
yaw_r = 0*(pi/180);
q_i2r_spec = mp_angle2quat(roll_r,pitch_r,yaw_r);

% Initial roll, pitch, yaw.
roll_i = 0.0*(pi/180);
pitch_i = 0*(pi/180);
yaw_i = 180*(pi/180);
q1_i2b = mp_angle2quat(roll_i,pitch_i,yaw_i);
q2_i2b = mp_angle2quat(roll_i,pitch_i,yaw_i);
% q1_i2b = [1 1 0 1]'; q1_i2b = q1_i2b/norm(q1_i2b);
% q2_i2b = q1_i2b;

% Controller parameters.
K_att = [25.0 25.0 10.0]';
omega_fb_sat = [700 700 50]'*(pi/180);
%% Simulate
H_omega_fb_sat = inv(diag(omega_fb_sat));

t = linspace(0,t_f,n);
X_i = [q1_i2b' q2_i2b']';
odeopt = odeset('abstol',1e-9,'reltol',1e-9);
[~,X] = ode45(@(t,X)derivs(t,X,K_att,H_omega_fb_sat),t,X_i,odeopt);
q1_i2b = X(:,1:4)';
q2_i2b = X(:,5:8)';
%% Plotting Setup
set(0,'defaulttextinterpreter','latex')
%% Figure 1 - Tilt and Clock Error
tilt_error = zeros(2,length(t));
clock_error = zeros(2,length(t));
for k=1:length(t)
  q_i2r_k = Q_I2R(t(k));
  q1_i2b_k = q1_i2b(:,k);
  q2_i2b_k = q2_i2b(:,k);
  
  q1_r2b_k = mp_quat_mult(mp_quat_conjugate(q_i2r_k),q1_i2b_k);
  q2_r2b_k = mp_quat_mult(mp_quat_conjugate(q_i2r_k),q2_i2b_k);
  
%   C_i2r_k = mp_quat2dcm(q_i2r_k);
  C1_r2b_k = mp_quat2dcm(q1_r2b_k);
  C2_r2b_k = mp_quat2dcm(q2_r2b_k);
  
  xb1_r_k = C1_r2b_k'*[1 0 0]';
  zb1_r_k = C1_r2b_k'*[0 0 1]';
  
  xb2_r_k = C2_r2b_k'*[1 0 0]';
  zb2_r_k = C2_r2b_k'*[0 0 1]';
  
  tilt_error(1,k) = acosd(zb1_r_k(3));
  tilt_error(2,k) = acosd(zb2_r_k(3));
  clock_error(1,k) = atan2d(xb1_r_k(2),xb1_r_k(1));
  clock_error(2,k) = atan2d(xb2_r_k(2),xb2_r_k(1));
end

figure(1),clf(1),set(1,'name','Tilt & Clock Err')

subplot(2,1,1),hold on,grid on
plot(t,tilt_error(1,:),'r')
plot(t,tilt_error(2,:),'b')
xlabel('Time [s]')
ylabel('Tilt Error [deg]')

subplot(2,1,2),hold on,grid on
plot(t,clock_error(1,:),'r')
plot(t,clock_error(2,:),'b')
xlabel('Time [s]')
ylabel('Clock Error [deg]')
%% Figure 2 - Quaternion
figure(2),clf(2),set(2,'name','Quaternion')
labels = {'$q_0$','$q_1$','$q_2$','$q_3$'};
for i=1:4
  subplot(4,1,i),hold on,grid on
  plot(t,q1_i2b(i,:),'color','r')
  plot(t,q2_i2b(i,:),'color','b')
  xlabel('Time [s]')
  ylabel(labels{i})
  set(gca,'ylim',1.25*[-1 1])
end
%% Figure 3 - Angular Velocities
omegas1 = zeros(3,length(t));
omegas2 = zeros(3,length(t));
for k=1:length(t)
  q_i2r_k = Q_I2R(t(k));
  q1_i2b_k = q1_i2b(:,k);
  q2_i2b_k = q2_i2b(:,k);
  omegas1(:,k) = ...
    mp_att_control(q1_i2b_k,q_i2r_k,K_att,H_omega_fb_sat,'naive');
  omegas2(:,k) = ...
    mp_att_control(q2_i2b_k,q_i2r_k,K_att,H_omega_fb_sat,'prioritized');
end

figure(3),clf(3),set(3,'name','Ang. Vels.')
labels = {'$\omega_x$ [deg/s]', ...
          '$\omega_y$ [deg/s]', ...
          '$\omega_z$ [deg/s]'};
for i=1:3
  subplot(3,1,i),hold on,grid on
  plot(t,-omega_fb_sat(i)*ones(size(t))*(180/pi), ...
    'color','k','linestyle','--')
  plot(t, omega_fb_sat(i)*ones(size(t))*(180/pi), ...
    'color','k','linestyle','--')
  plot(t,omegas1(i,:)*(180/pi),'r')
  plot(t,omegas2(i,:)*(180/pi),'b')
  xlabel('Time [s]')
  ylabel(labels{i})
  set(gca,'xlim',[0 1])
  if (i == 3)
    set(gca,'ylim',300*[-1 1])
  else
    set(gca,'ylim',600*[-1 1])
  end
end
%% Figure 4 - Animation
if (animate)
  figure(4),clf(4),set(4,'name','Animation'),hold on,grid on
  hx_r = line([0 0],[0 0],[0 0],'linewidth',1,'color','r');
  hy_r = line([0 0],[0 0],[0 0],'linewidth',1,'color',[0 0.7 0]);
  hz_r = line([0 0],[0 0],[0 0],'linewidth',1,'color','b');
  hx_b = line([0 0],[0 0],[0 0],'linewidth',3,'color','r');
  hy_b = line([0 0],[0 0],[0 0],'linewidth',3,'color',[0 0.7 0]);
  hz_b = line([0 0],[0 0],[0 0],'linewidth',3,'color','b');
  axis equal
  xlabel('N')
  ylabel('E')
  zlabel('D')
  set(gca,'ydir','reverse')
  set(gca,'zdir','reverse')
  set(gca,'xlim',1.5*[-1 1],'ylim',1.5*[-1 1],'zlim',1.5*[-1 1])
  view(3)
  
  for k=1:length(t)
    q_i2r_k = Q_I2R(t(k));
    C_i2r_k = mp_quat2dcm(q_i2r_k);
    x_r_axis = C_i2r_k'*[1 0 0]';
    y_r_axis = C_i2r_k'*[0 1 0]';
    z_r_axis = C_i2r_k'*[0 0 1]';
    
    set(hx_r,'xdata',[0 x_r_axis(1)], ...
             'ydata',[0 x_r_axis(2)], ...
             'zdata',[0 x_r_axis(3)])
    set(hy_r,'xdata',[0 y_r_axis(1)], ...
             'ydata',[0 y_r_axis(2)], ...
             'zdata',[0 y_r_axis(3)])
    set(hz_r,'xdata',[0 z_r_axis(1)], ...
             'ydata',[0 z_r_axis(2)], ...
             'zdata',[0 z_r_axis(3)])
    
%     q_i2b_k = q1_i2b(:,k);
    q_i2b_k = q2_i2b(:,k);
    C_i2b_k = mp_quat2dcm(q_i2b_k);
    x_b_axis = C_i2b_k'*[1 0 0]';
    y_b_axis = C_i2b_k'*[0 1 0]';
    z_b_axis = C_i2b_k'*[0 0 1]';
    
    set(hx_b,'xdata',[0 x_b_axis(1)], ...
             'ydata',[0 x_b_axis(2)], ...
             'zdata',[0 x_b_axis(3)])
    set(hy_b,'xdata',[0 y_b_axis(1)], ...
             'ydata',[0 y_b_axis(2)], ...
             'zdata',[0 y_b_axis(3)])
    set(hz_b,'xdata',[0 z_b_axis(1)], ...
             'ydata',[0 z_b_axis(2)], ...
             'zdata',[0 z_b_axis(3)])
    
    drawnow
  end
end
%% Functions 
function [q_i2r] = Q_I2R(t)
  global q_i2r_spec
  q_i2r = q_i2r_spec;
end
function [X_dot] = derivs(t,X,K,H_omega_sat)
  q_i2r = Q_I2R(t);
  q1_i2b = X(1:4);
  q2_i2b = X(5:8);
  
  omega1 = mp_att_control(q1_i2b,q_i2r,K,H_omega_sat,'naive');
  omega2 = mp_att_control(q2_i2b,q_i2r,K,H_omega_sat,'prioritized');
  
  q1_i2b_dot = 0.5*mp_skew4(omega1)*q1_i2b;
  q2_i2b_dot = 0.5*mp_skew4(omega2)*q2_i2b;
  
  X_dot = zeros(size(X));
  X_dot(1:4) = q1_i2b_dot;
  X_dot(5:8) = q2_i2b_dot;
end
