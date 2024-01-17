function [O] = socp(I,i_sc)
%#ok<*EQEFF>
%#ok<*VUNUS>
%#ok<*CHAIN>
%#ok<*NODEF>
%#ok<*IDISVAR>

% inputs
W_tr = I.W_tr;
W_vc = I.W_vc;
W_udot = I.W_udot;

K = I.K;
t_f = I.t_f;

g = I.g;
m = I.m;
u_min = I.u_min;
u_max = I.u_max;
theta_max = I.theta_max;

r_i = I.r_i;
r_f = I.r_f;

r0 = I.r0;
v0 = I.v0;
u0 = I.u0;

% derived inputs
dt = t_f/(K-1); % [s]

% cvx begin
cvx_tic
cvx_begin
cvx_solver(I.cvx_solver)
cvx_precision(I.cvx_precision)
cvx_quiet(I.cvx_quiet)

% solution variables
variable r(3,K)
variable v(3,K)
variable u(3,K)
variable s(1,K) nonnegative
variable J_tr(1,K) nonnegative
variable J_vc(1,K-1) nonnegative
variable J_udot(1,K-1) nonnegative
variable nu(6,K-1)

% cost function
minimize(sum(s)+sum(J_udot)+sum(J_tr)+sum(J_vc))

% initial conditions
r(:,1) == r_i;
v(:,1) == zeros(3,1);
u(:,1) == -m*g;

% Final Conditions
r(:,K) == r_f;
v(:,K) == zeros(3,1);
u(:,K) == -m*g;

% dyamics & virtual control
for k=1:K-1
  a_k = u(:,k)/m+g;
  a_kp1 = u(:,k+1)/m+g;
  
  % dynamics
  r(:,k+1) == r(:,k)+v(:,k)*dt+(1/3)*a_k*dt^2+(1/6)*a_kp1*dt^2+nu(1:3,k);
  v(:,k+1) == v(:,k)+(1/2)*(a_k+a_kp1)*dt+nu(4:6,k);
  
  % virtual control
  norm(W_vc*nu(:,k),1) <= J_vc(k);  
end

% control constraints
for k=1:K
  norm(u(:,k),2) <= s(k);   % lossless relaxation
  u_min <= s(k) <= u_max;   % magnitude constraint
  [1 0 0]*u(:,k) >= cosd(theta_max)*s(k);   % tilt constraint
  if all(~isnan(W_udot(:)))&&(k<K)
    norm(W_udot*(u(:,k+1)-u(:,k)),2) <= J_udot(k);  % ctrl rate constraint
  end
end

% compound stc & trust region
for k=1:K
  zk = [r(:,k)' v(:,k)' u(:,k)']';
  zk0 = [r0(:,k)' v0(:,k)' u0(:,k)']';
  dzk = zk-zk0;
  
  for idx = 1:length(I.hoops)
      % compound stc
      [h_k,dhdz_k] = expr_cstc(I,zk0,k,idx);
      if (I.stc(idx).rho_c > 0)
        h_k+dhdz_k*dzk <= 0;
      else
        h_k+dhdz_k*dzk == 0;
      end 
      
      clear h_k dhdz_k
  end


  % quadratic trust region
  dzk'*W_tr*dzk <= J_tr(k);
end

% cvx end
cvx_end

% outputs
O = struct;
O.t = linspace(0,t_f,K);
O.r = r;
O.v = v;
O.u = u;
O.s = s;
O.accl = O.u./I.m;
O.m = I.m;
O.J_tr = sum(J_tr);
O.J_vc = sum(J_vc);
O.J_udot = sum(J_udot);
O.converged = (O.J_tr < I.eps_tr)&&(O.J_vc < I.eps_vc);
O.lossless = (max(abs(sum(O.u.^2,1).^0.5-O.s)) < I.lcvx_tol);
O.timing = cvx_toc;

fprintf('iter = %02d, ',i_sc)
fprintf('conv = %01d, ',O.converged)
fprintf('lcvx = %01d, ',O.lossless)
fprintf('tsol = %04d, ',ceil(1000*O.timing(5)))
fprintf('J_tr = %+04.2e, ',sum(J_tr))
fprintf('J_vc = %+04.2e, ',sum(J_vc))
fprintf('J_udot = %+04.2e, ',sum(J_udot))
fprintf('status = %s',cvx_status)
fprintf('\n')