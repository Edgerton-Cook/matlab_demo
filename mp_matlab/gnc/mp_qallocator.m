function [w_alloc,f_alloc] = mp_qallocator(w_req,z_guar,H_f2w, ...
                                           l_x,l_y,k_f2t,f_min,f_max,tol)

% Map inputs to local variables.
c_req = w_req(1);
x_req = w_req(2);
y_req = w_req(3);
z_req = w_req(4);
z_max = 2*k_f2t*(f_max-f_min);
if (rank(H_f2w) > 3)
  z_guar = mp_saturation(0,z_guar,z_max);
else
  z_guar = 0;
end

% Compute feasible xy-polytope.
z_thresh = min(abs(z_req),z_guar);
v_a = [2*l_y*(f_max-f_min) 0 0]';
v_b = [l_y*(f_max-f_min) l_x*(f_max-f_min) k_f2t*(f_max-f_min)]';
v_c = [0 2*l_x*(f_max-f_min) 0]';
v_d = [0 0 z_max]';
v_xy = zeros(2,8);
if (z_thresh < v_b(3))
  k_ab = (z_thresh-v_a(3))/(v_b(3)-v_a(3));
  k_cb = (z_thresh-v_c(3))/(v_b(3)-v_c(3));
  v_xy(1,1) = (1-k_ab)*v_a(1)+k_ab*v_b(1);
  v_xy(2,1) = (1-k_ab)*v_a(2)+k_ab*v_b(2);
  v_xy(1,2) = (1-k_cb)*v_c(1)+k_cb*v_b(1);
  v_xy(2,2) = (1-k_cb)*v_c(2)+k_cb*v_b(2);
  v_xy(1,3) = -v_xy(1,2);
  v_xy(2,3) =  v_xy(2,2);
  v_xy(1,4) = -v_xy(1,1);
  v_xy(2,4) =  v_xy(2,1);
  v_xy(1,5) = -v_xy(1,1);
  v_xy(2,5) = -v_xy(2,1);
  v_xy(1,6) = -v_xy(1,2);
  v_xy(2,6) = -v_xy(2,2);
  v_xy(1,7) =  v_xy(1,2);
  v_xy(2,7) = -v_xy(2,2);
  v_xy(1,8) =  v_xy(1,1);
  v_xy(2,8) = -v_xy(2,1);
else
  k_bd = (z_thresh-v_b(3))/(v_d(3)-v_b(3));
  v_xy(1,1) = (1-k_bd)*v_b(1)+k_bd*v_d(1);
  v_xy(2,1) = (1-k_bd)*v_b(2)+k_bd*v_d(2);
  v_xy(1,2) =  v_xy(1,1);
  v_xy(2,2) =  v_xy(2,1);
  v_xy(1,3) = -v_xy(1,1);
  v_xy(2,3) =  v_xy(2,1);
  v_xy(1,4) = -v_xy(1,1);
  v_xy(2,4) =  v_xy(2,1);
  v_xy(1,5) = -v_xy(1,1);
  v_xy(2,5) = -v_xy(2,1);
  v_xy(1,6) = -v_xy(1,1);
  v_xy(2,6) = -v_xy(2,1);
  v_xy(1,7) =  v_xy(1,1);
  v_xy(2,7) = -v_xy(2,1);
  v_xy(1,8) =  v_xy(1,1);
  v_xy(2,8) = -v_xy(2,1);
end

% Project xy-torque into feasible polytope.
norm_inf = max(l_x*abs(x_req),l_y*abs(y_req));
norm_inf_v = max(l_x*abs(v_xy(1,1)),l_y*abs(v_xy(2,1)));
if (norm_inf > norm_inf_v)
  x_req = x_req*norm_inf_v/norm_inf;
  y_req = y_req*norm_inf_v/norm_inf;
end
norm_one = l_x*abs(x_req)+l_y*abs(y_req);
norm_one_v = l_x*abs(v_xy(1,1))+l_y*abs(v_xy(2,1));
if (norm_one > norm_one_v)
  x_p = x_req*norm_one_v/norm_one;
  y_p = y_req*norm_one_v/norm_one;
else
  x_p = x_req;
  y_p = y_req;
end

% Allocate projected xy-torques.
x_alloc = x_p;
y_alloc = y_p;

% Solve for forces that satisfy allocated xy-torques.
H_xy = H_f2w(2:3,:);
w_xy = [x_alloc y_alloc]';
f_xy = H_xy'/(H_xy*H_xy')*w_xy;

if (rank(H_f2w) == 3)
  % Enter here if the force-to-wrench mapping is rank deficient.
  
  % Compute bounds on collective.
  b1 = 4*max(f_min-f_xy);
  b2 = 4*min(f_max-f_xy);
  
  % Determine best collective thrust allocation.
  c_alloc = mp_saturation(b1,c_req,b2);
  
  % Determine final motor force allocation.
  H_cxy = H_f2w(1:3,:);
  w_cxy = [c_alloc x_alloc y_alloc]';
  f_alloc = H_cxy'/(H_cxy*H_cxy')*w_cxy;
elseif (rank(H_f2w) == 4)
  % Enter here if the force-to-wrench mapping is surjective.
  
  % Solve for feasible c-z box given required projected xy-torques.
  b1 = 4*k_f2t*max(f_min-f_xy(sign(H_f2w(4,:)) > 0));
  b2 = 4*k_f2t*max(f_min-f_xy(sign(H_f2w(4,:)) < 0));
  b3 = 4*k_f2t*min(f_max-f_xy(sign(H_f2w(4,:)) > 0));
  b4 = 4*k_f2t*min(f_max-f_xy(sign(H_f2w(4,:)) < 0));
  A = [ k_f2t  k_f2t -k_f2t -k_f2t; 1 -1 -1  1]';
  b = [b1 b2 -b3 -b4]';
  
  % Add half-space inequality constraint when z-torque 
  % guarantee zone exists.
  if (0 < z_guar)&&(z_req > z_guar)
    A_hat = [A; 0 1; 0 -1];
    b_hat = [b; z_guar; -z_req];
  elseif (0 < z_guar)&&(z_req < -z_guar)
    A_hat = [A; 0 -1; 0 1];
    b_hat = [b; z_guar; z_req];
  else
    A_hat = [A; 0 0; 0 0];
    b_hat = [b; 0; 0];
  end
  
  % Solve for all possible vertices of new feasible cz-polytope. We know 
  % that there will be four intersection points for this feasible polytope 
  % in the absence of the above the half-space inequality constraint, and 
  % eight intersection points in the presence of the above half-space 
  % inequality constraint (at least two of which can be ignored).
  v_cz_all = zeros(2,12);
  v_cz_all(:,1) = A_hat([1 4],:)\b_hat([1 4]);
  v_cz_all(:,2) = A_hat([1 2],:)\b_hat([1 2]);
  v_cz_all(:,3) = A_hat([3 2],:)\b_hat([3 2]);
  v_cz_all(:,4) = A_hat([3 4],:)\b_hat([3 4]);
  if (0 < z_guar)&&((z_req > z_guar)||(z_req < -z_guar))
    % Enter this branch if requested z-torque is outside of guarantee band.
    % Otherwise leave the remaining four vertices as zeros.
    v_cz_all(:, 5) = A_hat([1 5],:)\b_hat([1 5]);
    v_cz_all(:, 6) = A_hat([2 5],:)\b_hat([2 5]);
    v_cz_all(:, 7) = A_hat([3 5],:)\b_hat([3 5]);
    v_cz_all(:, 8) = A_hat([4 5],:)\b_hat([4 5]);
    v_cz_all(:, 9) = A_hat([1 6],:)\b_hat([1 6]);
    v_cz_all(:,10) = A_hat([2 6],:)\b_hat([2 6]);
    v_cz_all(:,11) = A_hat([3 6],:)\b_hat([3 6]);
    v_cz_all(:,12) = A_hat([4 6],:)\b_hat([4 6]);
  else
    v_cz_all(1,5:12) = v_cz_all(1,4);
    v_cz_all(2,5:12) = v_cz_all(2,4);
  end

  % Remove verticies that are outside of new feasible cz-polytope.
  A_hat_v_cz_all = A_hat*v_cz_all;
  v_cz = zeros(2,12);
  j = 1;
  for i=1:12
    slack_cz_all = A_hat_v_cz_all(:,i)-b_hat;
    if all(slack_cz_all >= -tol)
      v_cz(:,j) = v_cz_all(:,i);
      j = j+1;
    end
  end
  for i=j:12
    v_cz(:,i) = v_cz(:,j-1);
  end
  
  if (z_guar > 0)&&(-z_guar <= z_req)&&(z_req <= z_guar)
    % Allocate z.
    z_alloc = z_req;

    % Determine best z-torque allocation.
    slack = A*[c_req z_alloc]'-b;
    if any(slack < -tol)
      % Enter here if requested z-torque cannot be achieved.
      [~,i_alloc] = min(slack);
      c_alloc = (b(i_alloc)-A(i_alloc,2)*z_alloc)/A(i_alloc,1);
    else
      % Enter here if requested z-torque can be achieved.
      c_alloc = c_req;
    end
  else
    % Determine best collective thrust allocation.
    if (all(v_cz(1,:) < c_req))
      % Enter here if requested thrust cannot be achieved (too large).
      [c_alloc,~] = max(v_cz(1,:));
    elseif (all(c_req < v_cz(1,:)))
      % Enter here if requested thrust cannot be achieved (too small).
      [c_alloc,~] = min(v_cz(1,:));
    else
      % Enter here if requested thrust can be achieved.
      c_alloc = c_req;
    end

    % Determine best z-torque allocation.
    slack = A*[c_alloc z_req]'-b;
    if any(slack < -tol)
      % Enter here if requested z-torque cannot be achieved.
      [~,i_alloc] = min(slack);
      z_alloc = (b(i_alloc)-A(i_alloc,1)*c_alloc)/A(i_alloc,2);
    else
      % Enter here if requested z-torque can be achieved.
      z_alloc = z_req;
    end
  end
  
  % Determine final motor force allocation.
  f_alloc = H_f2w\[c_alloc x_alloc y_alloc z_alloc]';
end

% Clean up noise from output.
for i=1:4
  if (f_alloc(i) < f_min-10*tol)
    warning('infeasible f found: %+06.4e violation.', ...
            f_alloc(i)-f_min+10*tol)
  elseif (f_alloc(i) > f_max+10*tol)
    warning('infeasible f found: %+06.4e violation.', ...
            f_alloc(i)-f_max-10*tol)
  end
  f_alloc(i) = mp_saturation(f_min,f_alloc(i),f_max);
end

% Determine final wrench allocation.
w_alloc = H_f2w*f_alloc;
