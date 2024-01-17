%% Clears
clear
clc
%% Inputs
animate = false;
t_f = 1.0;
theta_i = -45*(pi/180);
n_hat_i = [1 0 0]';
q_i2r_i = [cos(0.5*theta_i) n_hat_i'*sin(0.5*theta_i)]';
omega_r_i = [0 0 0]';

J = mp_model_vehicle('inertia');
G_p = 1.00*diag([2500 2500 1800]);
G_d = 1.25*diag([15 20 75]);

omega_sat = [600 600 600]'*(pi/180);
tau_sat = [0.25 0.25 0.05]';

omega_sat_type = 2;
tau_sat_type = 1;

p_att = mp_att_prefilter_t(J,G_p,G_d, ...
                           omega_sat,omega_sat_type, ...
                           tau_sat,tau_sat_type, ...
                           q_i2r_i,omega_r_i);
%% Run Simulation
t = linspace(0,t_f,1500);
x_i = p_att.x_i;
odeopt = odeset('abstol',1e-6,'reltol',1e-6);
[~,x] = ...
  ode45(@(t,x)p_att.derivs(x,Q_I2D(t),OMEGA_D(t),TAU_D(t)),t,x_i,odeopt);

q_i2r = p_att.output_q_i2r(x');
omega_r = p_att.output_omega_r(x');
tau_r = zeros(3,length(t));
for k=1:length(t)
  tau_r(:,k) = p_att.output_tau_r(x(k,:)', ...
                              Q_I2D(t(k)), ...
                              OMEGA_D(t(k)), ...
                              TAU_D(t(k)));
end
%% Plotting Setup
set(0,'defaulttextinterpreter','latex')
%% Figure 1 - Quaternion
figure(1),clf(1),set(1,'name','Quaternion')
labels = {'$q_0(t)$','$q_1(t)$','$q_2(t)$','$q_3(t)$'};
for i=1:4
  e_i = zeros(4,1);
  e_i(i) = 1;
  
  subplot(4,1,i),hold on,grid on
  plot(t,e_i'*mp_quat_rectify(Q_I2D(t)),'b')
  plot(t,e_i'*mp_quat_rectify(q_i2r),'r')
  
  xlabel('Time [s]')
  ylabel(labels{i})
end
%% Figure 2 - Angular Velocities
figure(2),clf(2),set(2,'name','Angular Velocities')
labels = {'$\omega_x(t)$','$\omega_y(t)$','$\omega_z(t)$'};
for i=1:3
  e_i = zeros(3,1);
  e_i(i) = 1;
  
  subplot(3,1,i),hold on,grid on
  plot(t,-omega_sat(i)*ones(size(t))*(180/pi),'color','k','linestyle','--')
  plot(t, omega_sat(i)*ones(size(t))*(180/pi),'color','k','linestyle','--')
  plot(t,e_i'*OMEGA_D(t)*(180/pi),'b')
  plot(t,omega_r(i,:)*(180/pi),'r')
  xlabel('Time [s]')
  ylabel([labels{i} ' [deg/s]'])
end
%% Figure 3 - Torques
figure(3),clf(3),set(3,'name','Torques')
labels = {'$\tau_x(t)$','$\tau_y(t)$','$\tau_z(t)$'};
for i=1:3
  e_i = zeros(3,1);
  e_i(i) = 1;
  
  subplot(3,1,i),hold on,grid on
  plot(t,-tau_sat(i)*ones(size(t)),'color','k','linestyle','--')
  plot(t, tau_sat(i)*ones(size(t)),'color','k','linestyle','--')
  plot(t,e_i'*TAU_D(t),'b')
  plot(t,tau_r(i,:),'r')
  xlabel('Time [s]')
  ylabel([labels{i} ' [N-m]'])
end
%% Figure 4 - Angular Error
q_error = mp_quat_rectify(mp_quat_mult(Q_I2D(t),mp_quat_conjugate(q_i2r)));
ang_error = 2*acosd(mp_saturation(-1,q_error(1,:),1));
tilt_error = zeros(size(t));
for k=1:length(t)
  C_i2r_k = mp_quat2dcm(q_i2r(:,k));
  C_i2d_k = mp_quat2dcm(Q_I2D(t(k)));
  
  zr_i = C_i2r_k'*[0 0 1]';
  zd_i = C_i2d_k'*[0 0 1]';
  
  tilt_error(k) = acosd(mp_saturation(-1,dot(zr_i,zd_i),1));
end

figure(4),clf(4),set(4,'name','Angular Error')

subplot(2,1,1),hold on,grid on
plot(t,ang_error,'r')
xlabel('Time [s]')
ylabel('Angular Error [deg]')

subplot(2,1,2),hold on,grid on
plot(t,tilt_error,'r')
xlabel('Time [s]')
ylabel('Tilt Error [deg]')
%% Figure 5 - Animate
if (animate)
  figure(5),clf(5),set(5,'name','Animation'),hold on,grid on
  for i=0:5:360
    plot(cosd(i)*[0.25 0.75],sind(i)*[0.25 0.75],'color',0.7*[1 1 1])
  end
  
  lh_d = line([0 0],[0 0],'color','b','linestyle','-');
  lh_r = line([0 0],[0 0],'color','r','linestyle','-');
  xlabel('$q_0(t)$')
  ylabel('$q_1(t)$')
  axis equal
  
  for k=1:length(t)
    e_1 = [1 0 0 0]';
    e_2 = [0 1 0 0]';

    set(lh_d,'xdata',[0 e_1'*Q_I2D(t(k))],'ydata',[0 e_2'*Q_I2D(t(k))])
    set(lh_r,'xdata',[0 q_i2r(1,k)],'ydata',[0 q_i2r(2,k)])
    set(gca,'xlim',1.5*[-1 1],'ylim',1.5*[-1 1])
    drawnow
  end
end
%% Functions
function [q_i2d] = Q_I2D(t)
%   theta = 90*(pi/180)*sin(2*pi*1*t);
%   theta = 90*mp_sig_step(0.20,t);
%   n_hat = [1 0 0]';
  
  theta = -60 ...
          +60*mp_sig_ramp(0.10,0.30,t) ...
          +60*mp_sig_ramp(0.30,0.50,t);
  n_hat = [1 0 0]'*mp_sig_spulse(0.0,0.3,t) ...
         +[0 1 0]'*mp_sig_spulse(0.3,1.1,t);
  
  q_i2d = [cosd(0.5*theta)
           sind(0.5*theta).*(n_hat./sum(n_hat.^2,1).^0.5)];
end
function [omega_d] = OMEGA_D(t)
  n_hat = [1 0 0]'*mp_sig_spulse(0.00,0.30,t) ...
         +[0 1 0]'*mp_sig_spulse(0.30,1.10,t);
  n_hat = n_hat./sum(n_hat.^2,1).^0.5;
  theta = -60 ...
          +60*mp_sig_ramp(0.10,0.30,t) ...
          +60*mp_sig_ramp(0.30,0.50,t);
  q = [cosd(0.5*theta)
       sind(0.5*theta).*n_hat];
  
  theta_dot = 60*mp_sig_spulse(0.10,0.30,t)/(0.30-0.10) ...
             +60*mp_sig_spulse(0.30,0.50,t)/(0.50-0.30);
  theta_dot = theta_dot*(pi/180);
  q_dot = [-0.5*sind(0.5*theta).*theta_dot
            0.5*cosd(0.5*theta).*theta_dot.*n_hat];
  
  omega_d = zeros(3,length(t));
  for k=1:length(t)
    Q_k = mp_skewQ(q(:,k));
    omega_d(:,k) = 0.5*Q_k(2:4,:)\q_dot(2:4,k);
  end
  
%   w = [zeros(1,length(t))
%        zeros(1,length(t))
%        zeros(1,length(t))];
end
function [tau_d] = TAU_D(t)
  tau_d = [zeros(1,length(t))
           zeros(1,length(t))
           zeros(1,length(t))];
end
