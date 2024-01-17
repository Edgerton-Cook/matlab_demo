%% CLears
clear
clc
%% Inputs
plot_bode_loop = false;
plot_bode_r2y = false;
plot_bode_d2y = false;
plot_bode_s = false;
plot_nichols = true;
plot_reference = true;
plot_disturbance = true;
plot_sensitivity_int = false;

colors = {'r',[0 0.7 0],'b',[0.50 0 0.75],[0 0.75 1.00],'k'};

f_co = 10;

t = linspace(0,2,5000);
% u = mp_sig_step(0.1,t); % step
u = mp_sig_ramp(0.1,0.2,t); % ramp
% u = mp_sig_parabola(0.1,0.3,t)-mp_sig_parabola(0.6,0.8,t); % parabola
% u = mp_sig_ppulse(0.1,0.5,0.7,1.1,0.10,t); % smooth pulse
% u = sin(2*pi*0.3*t); % sinusoidal

r = u;
d = u;
%% System Definition
A = mp_model_actuator('thrust','2nd');

% G = mp_model_vehicle('x-rate');
% H = mp_model_mpu6000('gyro',3);

G = mp_model_vehicle('z-accl');
H = mp_model_mpu6000('accl',3);
%% Controllers
C = cell(0,1);
C{end+1,1} = mp_loopshape_s1_as_pm65s(f_co,A*G*H);
C{end+1,1} = mp_loopshape_s1_as_pm35s(f_co,A*G*H);
C{end+1,1} = mp_loopshape_s2_as_pm35s(f_co,A*G*H);
% C{end+1,1} = mp_loopshape_s3_ns_pm35s(f_co,A*G*H);
% C{end+1,1} = mp_loopshape_s1_as_pm35(f_co,A*G*H);
% C{end+1,1} = mp_loopshape_s2_as_pm35(f_co,A*G*H);
% C{end+1,1} = mp_loopshape_s3_ns_pm35(f_co,A*G*H);
% C{end+1,1} = mp_loopshape_s3_ns_pm35m(f_co,A*G*H);
% C{end+1,1} = mp_loopshape_s3_ns_pm35p(f_co,A*G*H);

% G = 0.50*G;
% G = 0.75*G;
% G = 1.25*G;
% G = 1.50*G;
% G = 1.95*G;
%% Calculations
for i=1:length(C)
  fprintf('Pole-Zero Excess C{%d} = %d\n', ...
    i,length(C{i}.P{1})-length(C{i}.Z{1}))
end

L = cell(size(C));
T_r2y = cell(size(C));
T_d2y = cell(size(C));
S = cell(size(C));
for i=1:length(C)
  L{i} = minreal(C{i}*A*G*H);
  T_r2y{i} = minreal(G*A*C{i}/(1+L{i}));
  T_d2y{i} = minreal(G/(1+L{i}));
  S{i} = minreal(1/(1+L{i}));
end
%% Plotting Setup
set(0,'defaulttextinterpreter','latex')
fs = 12;
lw = 2;
ms = 15;
%% Bode Plot - Loop TF
settings_bode = mp_set_bode;
settings_bode.fontsize = fs;
settings_bode.f_norm_Hz = f_co;

if (plot_bode_loop)
  figure(1),clf(1),set(1,'name','Loop'),grid on
  for i=1:length(C)
    mp_bode(L{i},'color',colors{i}, ...
                 'linewidth',lw, ...
                 'markersize',ms, ...
                 settings_bode)
  end
  set(gca,'fontsize',fs)
end
%% Bode Plot - T_R2Y
if (plot_bode_r2y)
  figure(2),clf(2),set(2,'name','R2Y'),grid on
  for i=1:length(C)
    mp_bode(T_r2y{i},'color',colors{i}, ...
                     'linewidth',lw, ...
                     'markersize',ms)
  end
  set(gca,'fontsize',fs)
end
%% Bode Plot - T_D2Y
if (plot_bode_d2y)
  figure(3),clf(3),set(3,'name','D2Y'),grid on
  for i=1:length(C)
    mp_bode(T_d2y{i},'color',colors{i}, ...
                     'linewidth',lw, ...
                     'markersize',ms)
  end
  set(gca,'fontsize',fs)
end
%% Bode Plot - S
if (plot_bode_s)
  figure(4),clf(4),set(4,'name','S'),grid on
  for i=1:length(C)
    mp_bode(S{i},'color',colors{i}, ...
                 'linewidth',lw, ...
                 'markersize',ms)
  end
  set(gca,'fontsize',fs)
end
%% Nichols Plot
settings_nichols = mp_set_nichols;
settings_nichols.fontsize = fs;
settings_nichols.f_norm_Hz = f_co;
settings_nichols.phase_lb = -270;
settings_nichols.phase_ub = -90;
settings_nichols.phase_delta = 45;
settings_nichols.show_pos_fb_region = false;

if (plot_nichols)
  figure(5),clf(5),set(5,'name','Nichols')
  for i=1:length(C)
    mp_nichols(L{i},'color',colors{i}, ...
                    'linewidth',lw, ...
                    'markersize',ms, ...
                    settings_nichols)
  end
end
%% Response to Reference
if (plot_reference)
  y_r = cell(size(C));
  for i=1:length(C)
    y_r{i} = lsim(T_r2y{i},r,t);
  end
  
  figure(6),clf(6),set(6,'name','Reference'),hold on,grid on
  for i=1:length(C)
    plot(t,y_r{i},'color',colors{i}, ...
                  'linewidth',lw, ...
                  'markersize',ms)
  end
  plot(t,r,'color','k','linewidth',1,'linestyle','--')
  xlabel('Time [s]')
  ylabel('Response to Reference')
  set(gca,'fontsize',fs)
end
%% Response to Disturbance
if (plot_disturbance)
  y_d = cell(size(C));
  for i=1:length(C)
    y_d{i} = lsim(T_d2y{i},d,t);
  end
  
  figure(7),clf(7),set(7,'name','Disturbance'),hold on,grid on
  for i=1:length(C)
    plot(t,y_d{i},'color',colors{i}, ...
                  'linewidth',lw, ...
                  'markersize',ms)
  end
  plot(t,d,'color','k','linewidth',1,'linestyle','--')
  xlabel('Time [s]')
  ylabel('Response to Disturbance')
  set(gca,'fontsize',fs)
end
%% Sensitivity Calculation
if (plot_sensitivity_int)
  figure(8),clf(8),set(8,'name','Sens. Integ.')
  f_Hz = 10.^linspace(6,-9,1000);
  odeopt = odeset('abstol',1e-9,'reltol',1e-9);
  
  s = cell(size(C));
  for i=1:length(C)
    [~,s{i}] = ode45(@(w,x)log(10^(mp_tf_eval(S{i},w)/20)),f_Hz,0,odeopt);
  end
  
  ax1 = subplot(2,1,1); hold on,grid on
  for i=1:length(C)
    plot(f_Hz,s{i},'color',colors{i}, ...
                   'linewidth',lw, ...
                   'markersize',ms)
  end
  xlabel('Frequency [Hz]')
  ylabel('$\int_0^{\infty}{ln |S(j\omega)| d\omega}$')
  set(gca,'xscale','log')
  
  ax2 = subplot(2,1,2); hold on,grid on
  for i=1:length(C)
    plot(f_Hz,log(10.^(mp_tf_eval(S{i},f_Hz)/20)),'color',colors{i}, ...
                                                  'linewidth',lw, ...
                                                  'markersize',ms)
  end
  xlabel('Frequency [Hz]')
  ylabel('$ln |S(j\omega)|$')
  set(gca,'xscale','log')
  
  linkaxes([ax1 ax2],'x')
end
