%% Clear
%#ok<*UNRCH>
clear
clc
%% Define System
run_sim = false;
mode = 'accl';
save_figures = false;
filename = mode;

if isequal(mode,'rate')
  f_co = 10;
  f_te = 2.0*f_co;
  f_ff = 2.0*f_co;%8.0*f_co;
  
  % Rate Setup
  A = mp_model_actuator('thrust','1st');
  G = mp_model_vehicle('x-rate');
  H = mp_model_mpu6000('gyro',3);
elseif isequal(mode,'accl')
  f_co = 10;
  f_te = 1.0*f_co;
  f_ff = 2.0*f_co;%8.0*f_co;
  
  % Z-Accl Setup
  A = mp_model_actuator('thrust','1st');
  G = mp_model_vehicle('z-accl');
  H = mp_model_mpu6000('accl',3);
end

% Controller Design
% C = mp_loopshape_s1_as_pm35(f_co,A*G*H);
% C = mp_loopshape_s1_as_pm65s(f_co,A*G*H);
% C = mp_loopshape_s2_as_pm35(f_co,A*G*H);
C = mp_loopshape_s2_as_pm35s(f_co,A*G*H);
% C = mp_loopshape_s2_as_pm35d(f_co,A*G*H);
% C = mp_loopshape_s3_ns_pm35(f_co,A*G*H);
% C = mp_loopshape_s3_ns_pm35m(f_co,A*G*H);
% C = mp_loopshape_s3_ns_pm35p(f_co,A*G*H);
% C = mp_loopshape_s3_ns_pm35s(f_co,A*G*H);

% NDC Element Design
if isequal(mode,'rate')
  T_E_desired = mp_loopshape_te_type1(f_te);
%   T_E_desired = mp_loopshape_te_type1d(f_te);
elseif isequal(mode,'accl')
  T_E_desired = mp_loopshape_te_type0(f_te);
%   T_E_desired = mp_loopshape_te_type0d(f_te);
end
W = mp_ndc_element(C,A*G*H,T_E_desired);
% W = zpk([],[],0);

% Feedback Prefilter Design
if isequal(mode,'rate')
  R_fb = mp_ctrl_complex_pole(f_ff,0.6,1)*mp_ctrl_pole(f_ff,1);
elseif isequal(mode,'accl')
  R_fb = mp_ctrl_complex_pole(f_ff,0.6,1);
end
P_fb = H*R_fb;
F_fb = R_fb/(A*G);

% Feed-Forward Prefilter Design
R_ff = mp_ctrl_complex_pole(f_ff,0.6,1);
P_ff = H*R_ff;
F_ff = R_ff/A;

G = 1.00*G;
%% Pre-Calculations
T_L = minreal(C*A*G*H);
T_G = minreal(C*W);
T_E = minreal((T_L-T_G)/(1+T_G));
%% Run Simulation
if (run_sim)
  plant = mp_quad_1dof_t(A,G,H,@D,@N,0);
  ndc = mp_ndc_t(P_fb,F_fb,P_ff,F_ff,C,W);
  
  t = 0:0.001:1.0;
  X_i = [plant.x_i' ndc.x_i']';
  odeopt = odeset('abstol',1e-6,'reltol',1e-6);
  [~,X] = ode45(@(t,X)derivs(t,X,plant,ndc),t,X_i,odeopt);
  
  x_plant = X(:,plant.idx)';
  x_ndc = X(:,ndc.idx+plant.len)';
  
  u_fb = r_fb(t);
  u_P_ff = r_ff(t);
  u_F_ff = u_ff(t);
  y_sen = plant.output(x_plant);
  u_req = ndc.output(x_ndc,u_fb,u_F_ff);
  u_sat = mp_saturation([1 0]*sat_lims(t),u_req,[0 1]*sat_lims(t));
  u_W = u_req-u_sat;
  
  s_plant = plant.sigs(t,x_plant,u_req,sat_lims(t));
  s_ndc = ndc.sigs(x_ndc,y_sen,u_fb,u_P_ff,u_F_ff,u_W);
end

if (~isempty(P_fb.Z{1}))||(~isempty(P_fb.P{1}))
  fprintf('P_fb_max = %+05.2f [Hz]\n', ...
    max(abs(real([P_fb.Z{1}' P_fb.P{1}'])))/2/pi)
end

if (~isempty(F_fb.Z{1}))||(~isempty(F_fb.P{1}))
  fprintf('F_fb_max = %+05.2f [Hz]\n', ...
    max(abs(real([F_fb.Z{1}' F_fb.P{1}'])))/2/pi)
end

if (~isempty(P_ff.Z{1}))||(~isempty(P_ff.P{1}))
  fprintf('P_ff_max = %+05.2f [Hz]\n', ...
    max(abs(real([P_ff.Z{1}' P_ff.P{1}'])))/2/pi)
end

if (~isempty(F_ff.Z{1}))||(~isempty(F_ff.P{1}))
  fprintf('F_ff_max = %+05.2f [Hz]\n', ...
    max(abs(real([F_ff.Z{1}' F_ff.P{1}'])))/2/pi)
end

fprintf('C_f_max = %+05.2f [Hz]\n',max(abs(real([C.Z{1}' C.P{1}'])))/2/pi)
fprintf('W_f_max = %+05.2f [Hz]\n',max(abs(real([W.Z{1}' W.P{1}'])))/2/pi)
%% Plotting Setup
set(0,'defaulttextinterpreter','latex')
fs = 12;
%% Figure 1 - Bode Plot (Loop)
settings_bode = mp_set_bode;
settings_bode.f_norm_Hz = f_co;

figure(1),clf(1),set(1,'name','Bode (Loop)'),grid on
mp_bode(T_L,'r',settings_bode)
mp_bode(G*A*C*P_fb/(1+T_L),'b')
%% Figure 2 - Bode Plot (Pre-Filters)
figure(2),clf(2),set(2,'name','Bode (Pre-Filters)'),grid on
mp_bode(P_fb,'r')
mp_bode(P_ff,'b')
mp_bode(F_ff,'color',[0 0.7 0])
%% Figure 3 - Bode Plot (NDC)
figure(3),clf(3),set(3,'name','Bode (NDC)'),grid on
mp_bode(C,'r')
mp_bode(W,'b')
%% Figure 4 - Bode Plot (FB)
figure(4),clf(4),set(4,'name','Bode (FB)'),grid on
mp_bode(1+T_G,'color',[0 0.7 0])
mp_bode(1+T_E,'b')
mp_bode(1+T_L,'r')
%% Figure 5 - Nichols Plot
settings_nichols = mp_set_nichols;
settings_nichols.f_norm_Hz = f_co;
settings_nichols.phase_lb = -270;
settings_nichols.phase_ub = -90;
settings_nichols.phase_delta = 45;

figure(5),clf(5),set(5,'name','Nichols')
mp_nichols(T_L,'r',settings_nichols)
mp_nichols(T_E,'b')
%% Figure 6 - Feed-Fwd Sim Results
if (run_sim)
  figure(6),clf(6),set(6,'name','Feed-Fwd')
  
  subplot(4,1,1),hold on,grid on
  plot(t,r_fb(t),'b')
  plot(t,s_ndc.y_P_fb,'r')
  xlabel('Time [s]')
  ylabel('$P_{fb}$')
  
  subplot(4,1,2),hold on,grid on
  plot(t,r_fb(t),'b')
  plot(t,s_ndc.y_F_fb,'r')
  xlabel('Time [s]')
  ylabel('$F_{fb}$')
  
  subplot(4,1,3),hold on,grid on
  plot(t,r_ff(t),'b')
  plot(t,s_ndc.y_P_ff,'r')
  xlabel('Time [s]')
  ylabel('$P_{ff}$')
  
  subplot(4,1,4),hold on,grid on
  plot(t,u_ff(t),'b')
  plot(t,s_ndc.y_F_ff,'r')
  xlabel('Time [s]')
  ylabel('$F_{ff}$')
end
%% Figure 7 - Feedback Sim Results
if (run_sim)  
  figure(7),clf(7),set(7,'name','Feedback')
  
  subplot(2,1,1),hold on,grid on
  plot(t,s_ndc.u_C,'r')
  plot(t,s_ndc.y_C,'b')
  xlabel('Time [s]')
  ylabel('$C$')
  
  subplot(2,1,2),hold on,grid on
  plot(t,s_ndc.u_W,'r')
  plot(t,s_ndc.y_W,'b')
  xlabel('Time [s]')
  ylabel('$W$')
end
%% Figure 8 - Tracking Sim Results
if (run_sim)
  figure(8),clf(8),set(8,'name','Tracking')
  
  subplot(4,1,1),hold on,grid on
  if isequal(mode,'rate')
    plot(t,s_ndc.r*(180/pi),'r')
    plot(t,s_plant.y_G*(180/pi),'b')
    ylabel('Ref/Output [deg/s]')
  elseif isequal(mode,'accl')
    plot(t,s_ndc.r*(1/9.807),'r')
    plot(t,s_plant.y_G*(1/9.807),'b')
    ylabel('Ref/Output [g''s]')
  end
  xlabel('Time [s]')
  
  subplot(4,1,2),hold on,grid on
  plot(t,[1 0]*sat_lims(t),'color','k','linestyle','--')
  plot(t,[0 1]*sat_lims(t),'color','k','linestyle','--')
  plot(t,s_plant.u_act,'color',0.7*[1 1 1],'linestyle','-')
  plot(t,s_plant.u_act_sat,'r')
  plot(t,s_plant.y_A,'b')
  xlabel('Time [s]')
  ylabel('$A$')
  if isequal(mode,'rate')
    set(gca,'ylim',0.50*[-1 1])
  elseif isequal(mode,'accl')
    set(gca,'ylim',[-1 10])
  end
  
  subplot(4,1,3),hold on,grid on
  if isequal(mode,'rate')
    plot(t,s_plant.d,'r')
    ylabel('Disturbance [N-m]')
  elseif isequal(mode,'accl')
    plot(t,s_plant.d,'r')
    ylabel('Disturbance [N]')
  end
  xlabel('Time [s]')
  
  subplot(4,1,4),hold on,grid on
  if isequal(mode,'rate')
    plot(t,s_plant.n*(180/pi),'r')
    ylabel('Noise [deg/s]')
  elseif isequal(mode,'accl')
    plot(t,s_plant.n*(1/9.807),'r')
    ylabel('Noise [g''s]')
  end
  xlabel('Time [s]')
end
%% Save Figures
figure(5)
if (save_figures)
  saveas(1,[filename '_bode_loop.png'      ],'png')
  saveas(2,[filename '_bode_prefilters.png'],'png')
  saveas(3,[filename '_bode_ndc.png'       ],'png')
  saveas(4,[filename '_bode_fb.png'        ],'png')
  saveas(5,[filename '_nichols.png'        ],'png')
  saveas(6,[filename '_sim_feedfwd.png'    ],'png')
  saveas(7,[filename '_sim_feedback.png'   ],'png')
  saveas(8,[filename '_sim_tracking.png'   ],'png')
end
%% Functions
function [s] = sat_lims(t)
%   lims = 2.0*((2/4)*(0.35*9.81)*0.081)*[-1 1]'*ones(1,length(t));
  lims = [1 8]'*ones(1,length(t));
  
  mod = ones(2,1)*ones(1,length(t));
%   mod = ones(2,1)*(1+0.1*sin(2*pi*4*t));
%   mod = ones(2,1)*(1-0.50*((0.265<=t)&(t<=0.30)));
%   mod = ones(2,1)*(1-0.75*sin(2*pi*15*(t-0.265)+pi).*(0.265<=t));
  
  s = mod.*lims;
%   s = 2.0*((2/4)*(0.35*9.81)*0.081)* ...
%     [-ones(1,length(t)); 0.5+0.6*cos(2*pi*6*(t-0.265))];
end
function [r] = r_fb(t)
%   A = 720*(pi/180);
  A = 1.0*(9.807);
  
%   r = zeros(size(t));
  r = mp_sig_step(0.1,t)*A;
%   r = mp_sig_ramp(0.1,0.3,t)*A;
%   r = mp_sig_parabola(0.1,0.3,t)*A;
%   r = mp_sig_spulse(0.1,0.3,t)*A;
%   r = mp_sig_rpulse(0.1,0.3,0.4,0.6,t)*A;
%   r = mp_sig_ppulse(0.1,0.3,0.4,0.6,0.05,t)*A;
end
function [r] = r_ff(t)
%   A = -0.005*1279.2;
%   A = 0.5*9.807;
  
  r = zeros(size(t));
%   r = mp_sig_ramp(0.5,0.8,t)*A;
end
function [u] = u_ff(t)
%   A = -0.005;
%   A = 0.5*9.807*mp_model_vehicle('mass');
  
  u = zeros(size(t));
%   u = mp_sig_spulse(0.5,0.8,t)*A;
%   u = mp_sig_ramp(0.5,0.8,t)*A;
end
function [d] = D(t)
%   A = (2/4)*(0.35*9.81)*0.085;
%   A = -0.5*0.35*9.81;
  
  d = zeros(size(t));
%   d = mp_sig_step(0.4,t)*A;
%   d = mp_sig_ppulse(0.4,0.5,0.6,0.7,0.05,t)*A;
%   d = mp_sig_ppulse(0.4,0.6,0.7,0.9,0.05,t)*A;
end
function [n] = N(t)
	n = zeros(size(t));
end
function [X_dot] = derivs(t,X,plant,ndc)
	fprintf('%05.2f\n',t)
  
  x_plant = X(plant.idx);
  x_ndc = X(ndc.idx+plant.len);
  
  u_fb = r_fb(t);
  u_P_ff = r_ff(t);
  u_F_ff = u_ff(t);
  y_sen = plant.output(x_plant);
  u_req = ndc.output(x_ndc,u_fb,u_F_ff);
  u_sat = mp_saturation([1 0]*sat_lims(t),u_req,[0 1]*sat_lims(t));
  u_W = u_req-u_sat;
  
  X_dot = zeros(plant.len+ndc.len,1);
  X_dot(plant.idx) = plant.derivs(t,x_plant,u_req,sat_lims(t));
  X_dot(ndc.idx+plant.len) = ...
    ndc.derivs(x_ndc,y_sen,u_fb,u_P_ff,u_F_ff,u_W);
end
