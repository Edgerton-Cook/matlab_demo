function [I] = inputs(r_h, ang1, ang2, t_f, r_drone, hoop_des)

% r_h - hoop position vector (3x1) [m]
% ang1 - hdg angle of hoop normal vec (positive cw from top view) [deg]
% ang2 - pitch angle of hoop normal vec (positive up) [deg]
% t_f - final time [s]

% all vector quantities are in Up-East-North coordinates. (why miki???)
I = struct;

%I.cvx_solver = 'ecos'; % solver
I.cvx_solver = 'SDPT3'; % solver
I.cvx_precision = 'low'; % precision
I.cvx_quiet = true; % cvx print option

I.n_scvx_max = 20; % max number of successive iterations
I.eps_tr = 3e-2; % trust region convergence tolerance
I.eps_vc = 1e-3; % virtual control convergence tolerance
I.lcvx_tol = 1e-2; % losslessness tolerance [N]

I.W_tr = 1e-1*blkdiag(eye(3),zeros(6)); % trust region weight matrix
I.W_vc = 1e5*eye(6); % virtual control weight matrix
I.W_udot = 1.0*eye(3); % control rate weight matrix

I.K = 30; % number of temporal nodes
I.t_f = t_f; % fixed final time [s]

I.g = [-9.81 0 0]'; % gravity vector (UEN) [m/s^2]
I.m = 0.35; % mass of quad-rotor [kg]
I.u_min = 1.00; % min thrust [N]
I.u_max = 7.00; % max thrust [N]
I.theta_max = 45; % max tilt angle [deg]

I.hoops = hoop_des;

for idx = 1:length(hoop_des)
    
    I.stc(idx).l_c = 0.2; % corridor half-length [m]
    I.stc(idx).rho_g = 100; % trigger corridor radius [m]
    I.stc(idx).rho_c = 0.0; %0.10; % constraint corridor radius [m]
    kk = rot(ang1(1,idx),ang2(1,idx))*[0 0 1]';
    I.stc(idx).n_h_hat = rot(ang1(idx),ang2(idx))*[0 0 1]'; % hoop orientation normal vector
    I.stc(idx).r_h = @(t) r_h(:,idx); % hoop position vector [m]
   
end

I.r_i = r_drone; % initial position [m]
I.r_f = [1; 0.0; 3.25];

end