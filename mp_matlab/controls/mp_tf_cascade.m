function [T_zpk_cascade] = mp_tf_cascade(T_zpk)
% This function attempts to group the poles and zeros of 'C_zpk' into a 
% cascaded string of links given by the elements of the cell array 
% 'C_zpk_cas'. Each link in 'C_zpk_cas' has a numerator and denominator 
% that is either 1st or 2nd order. The function attempts to make each 
% link in 'C_zpk_cas' a proper transfer function when possible. The 
% function also attempts to group like frequencies of poles and zeros 
% together in each link. This function was designed to work with 
% continuous-time models, and is not intended to work with discrete-time 
% models. This function assumes there is at least one pole.

%% Triviality Check
if (length(T_zpk.Z{1}) <= 2)&&(length(T_zpk.P{1}) <= 2)
  T_zpk_cascade{1} = T_zpk;
  return
end
%% Initial Error Checking
% Print error when discrete-time model is provided.
if isequal(T_zpk.variable,'s')
  T_zpk = minreal(T_zpk);
else
  error('mp_cascade is designed to work with continuous-time models.')
end
%% Parse Zeros
n_z = length(T_zpk.Z{1});
z_num = [];
z_omega = [];
z_damping = [];
z_skip_list = [];
z_handled = 0;
for i=1:n_z
  if all(i ~= z_skip_list)
    if isreal(T_zpk.Z{1}(i))
      % Enter this branch if ith zero of 'C_zpk' is real.
      z_num(end+1) = 1; %#ok<AGROW>
      z_omega(end+1) = abs(T_zpk.Z{1}(i)); %#ok<AGROW>
      if (T_zpk.Z{1}(i) <= 0)
        z_damping(end+1) = 1; %#ok<AGROW>
      else
        z_damping(end+1) = -1; %#ok<AGROW>
      end
      z_handled = z_handled+1;
    else
      % Enter this branch if ith zero of 'C_zpk' is imaginary.
      for j=i+1:n_z
        % Search for complex conjugate. When found, add index to skip list
        % so that the pair is not revisited. This search can always begin
        % starting from the next element (i+1). Due to the skip list, the 
        % second element of the pair is never visited. Therefore, it is 
        % guaranteed that (i+1) <= nz.
        
        if (conj(T_zpk.Z{1}(i)) == T_zpk.Z{1}(j))
          z_R = real(T_zpk.Z{1}(i));
          z_I = imag(T_zpk.Z{1}(i));

          z_num(end+1) = 2; %#ok<AGROW>
          z_omega(end+1) = sqrt(z_R^2+z_I^2); %#ok<AGROW>
          z_damping(end+1) = -z_R/sqrt(z_R^2+z_I^2); %#ok<AGROW>
          z_skip_list(end+1) = j; %#ok<AGROW>
          z_handled = z_handled+2;
          break
        end
      end
    end
  end
end

if (z_handled ~= n_z)
  error('Failed to parse zeros.')
end
%% Parse Poles
n_p = length(T_zpk.P{1});
p_num = [];
p_omega = [];
p_damping = [];
p_skip_list = [];
p_handled = 0;
for i=1:n_p
  if all(i ~= p_skip_list)
    if isreal(T_zpk.P{1}(i))
      % Enter this branch if ith pole of 'C_zpk' is real.
      p_num(end+1) = 1; %#ok<AGROW>
      p_omega(end+1) = abs(T_zpk.P{1}(i)); %#ok<AGROW>
      if (T_zpk.P{1}(i) <= 0)
        p_damping(end+1) = 1; %#ok<AGROW>
      else
        p_damping(end+1) = -1; %#ok<AGROW>
      end
      p_handled = p_handled+1;
    else
      % Enter this branch if ith pole of 'C_zpk' is imaginary.
      for j=i+1:n_p
        % Search for complex conjugate. When found, add index to skip list
        % so that the pair is not revisited. This search can always begin
        % starting from the next element (i+1). Due to the skip list, the 
        % second element of the pair is never visited. Therefore, it is 
        % guaranteed that (i+1) <= np.
        
        if (conj(T_zpk.P{1}(i)) == T_zpk.P{1}(j))
          p_R = real(T_zpk.P{1}(i));
          p_I = imag(T_zpk.P{1}(i));
          
          p_num(end+1) = 2; %#ok<AGROW>
          p_omega(end+1) = sqrt(p_R^2+p_I^2); %#ok<AGROW>
          p_damping(end+1) = -p_R/sqrt(p_R^2+p_I^2); %#ok<AGROW>
          p_skip_list(end+1) = j; %#ok<AGROW>
          p_handled = p_handled+2;
          break
        end
      end
    end
  end
end

if (p_handled ~= n_p)
  error('Failed to parse poles.')
end
%% Make Zero-Pole Assignments
[Z_OMEGA,P_OMEGA] = meshgrid(log10(z_omega),log10(p_omega));
Z_OMEGA(isinf(Z_OMEGA)) = min(min(Z_OMEGA(~isinf(Z_OMEGA))));
P_OMEGA(isinf(P_OMEGA)) = min(min(P_OMEGA(~isinf(P_OMEGA))));

DOMEGA = abs(Z_OMEGA-P_OMEGA);
ASSIGNMENTS = false(length(p_num),length(z_num));
[Z_NUM,~] = meshgrid(z_num,p_num);
n_unassigned_zeros_s = 0;
n_unassigned_zeros_c = 0;

i_rows_ps = 1:length(p_num);
i_rows_ps(p_num ~= 1) = [];

i_rows_pc = 1:length(p_num);
i_rows_pc(p_num ~= 2) = [];

% First, assign poles to complex zeros.
for i=1:length(z_num)
  % Check if ith zero is complex.
  if (z_num(i) == 2)
    % Attempt to pair zero with either two simple poles, or one complex
    % pole. If complex pole is available, choose it only if its natural
    % frequency is closer to the zero's natural frequency than are the
    % the corner frequencies of the two simple poles.
    
    % Compute number of simple and complex poles available for assignment.
    i_ps_avail = all(ASSIGNMENTS(i_rows_ps,:) == false,2);
    i_pc_avail = all(ASSIGNMENTS(i_rows_pc,:) == false,2);
    n_ps_avail = sum(i_ps_avail);
    n_pc_avail = sum(i_pc_avail);
    
    i_rows_ps_avail = i_rows_ps(i_ps_avail);
    i_rows_pc_avail = i_rows_pc(i_pc_avail);
    
    domega_ps = DOMEGA(i_rows_ps_avail,i);
    domega_pc = DOMEGA(i_rows_pc_avail,i);
    
    if (n_ps_avail >= 2)&&(n_pc_avail >= 1)
      % There are at least two available simple poles, and at least one 
      % available complex pole.
      
      % Find candidate complex pole.
      [v_c,j_c] = min(domega_pc);
      
      % Find first candidate simple pole.
      [v_s1,j_s1] = min(domega_ps);
      
      % Find second candidate simple pole.
      i_select = ((1:length(domega_ps)) ~= j_s1);
      domega_ps_prime = domega_ps(i_select);
      i_rows_ps_avail_prime = i_rows_ps_avail(i_select);
      [v_s2,j_s2] = min(domega_ps_prime);
      
      if (v_s1 < v_c)&&(v_s2 < v_c)
        % Assign candidate simple poles.
        ASSIGNMENTS(i_rows_ps_avail(j_s1),i) = true;
        ASSIGNMENTS(i_rows_ps_avail_prime(j_s2),i) = true;
      else
        % Assign candidate complex pole.
        ASSIGNMENTS(i_rows_pc_avail(j_c),i) = true;
      end
    elseif (n_ps_avail < 2)&&(n_pc_avail >=1)
      % There is at least one available complex pole, but
      % less than two available simple poles (i.e. consider only 
      % complex poles for assignment).
      
      % Find candidate complex pole.
      [~,j] = min(domega_pc);
      
      % Assign candidate complex pole.
      ASSIGNMENTS(i_rows_pc_avail(j),i) = true;
    elseif (n_ps_avail >= 2)&&(n_pc_avail == 0)
      % There are at least two available simple poles, and no available
      % complex poles.
      
      % Find first candidate simple pole.
      [~,j_s1] = min(domega_ps);
      
      % Find second candidate simple pole.
      i_select = ((1:length(domega_ps)) ~= j_s1);
      domega_ps_prime = domega_ps(i_select);
      i_rows_ps_avail_prime = i_rows_ps_avail(i_select);
      [~,j_s2] = min(domega_ps_prime);
      
      % Assign candidate simple poles.
      ASSIGNMENTS(i_rows_ps_avail(j_s1),i) = true;
      ASSIGNMENTS(i_rows_ps_avail_prime(j_s2),i) = true;
    elseif (n_ps_avail == 1)&&(n_pc_avail == 0)
      % There is only one available simple pole, and no available 
      % complex poles.
      
      % Assign candidate simple pole.
      ASSIGNMENTS(i_rows_ps_avail,i) = true;
    elseif (n_ps_avail == 0)&&(n_pc_avail == 0)
      % There are no available poles.
      n_unassigned_zeros_c = n_unassigned_zeros_c+1;
      if (n_z > n_p)
        warning(['resulted in total of $d unassigned ' ...
                 'complex zeros (n_z=%d,n_p=%d)'], ...
                 n_unassigned_zeros_c,n_z,n_p);
      else
        error(['resulted in total of $d unassigned ' ...
               'complex zeros (n_z=%d,n_p=%d)'], ...
               n_unassigned_zeros_c,n_z,n_p);
      end
    end
  end
end

% Assign poles to remaining (simple) zeros.
for i=1:length(z_num)
  % Check if ith zero is simple.
  if (z_num(i) == 1)
    % Attempt to pair simple zero with either a simple or complex
    % pole. Two simple zeros can be assigned to one complex pole. Thus,
    % a simple zero can be assigned to simple poles that are not assigned,
    % or to complex poles that have no more than one assignment.
    
    % Compute number of simple and complex poles available for assignment.
    assignments_ps = ASSIGNMENTS(i_rows_ps,:).*Z_NUM(i_rows_ps,:);
    assignments_pc = ASSIGNMENTS(i_rows_pc,:).*Z_NUM(i_rows_pc,:);
    i_ps_avail = (sum(assignments_ps,2) == 0);
    i_pc_avail = (sum(assignments_pc,2) <= 1);
    n_ps_avail = sum(i_ps_avail);
    n_pc_avail = sum(i_pc_avail);
    
    i_rows_ps_avail = i_rows_ps(i_ps_avail);
    i_rows_pc_avail = i_rows_pc(i_pc_avail);
    
    domega_ps = DOMEGA(i_rows_ps_avail,i);
    domega_pc = DOMEGA(i_rows_pc_avail,i);
    
    if (n_ps_avail > 0)&&(n_pc_avail > 0)
      % There is at least one simple pole, and one complex pole available.
      
      % Find candidate complex pole.
      [v_c,j_c] = min(domega_pc);
      
      % Find candidate simple pole.
      [v_s,j_s] = min(domega_ps);
      
      if (v_c < v_s)
        % Assign this simple zero to the candidate complex pole.
        ASSIGNMENTS(i_rows_pc_avail(j_c),i) = true;
      else
        % Assign this simple zero to the candidate simple pole.
        ASSIGNMENTS(i_rows_ps_avail(j_s),i) = true;
      end
    elseif (n_ps_avail > 0)&&(n_pc_avail == 0)
      % There is at least one simple pole, but no complex pole available.
      
      % Find candidate simple pole.
      [~,j_s] = min(domega_ps);
      
      % Assign this simple zero to the candidate simple pole.
      ASSIGNMENTS(i_rows_ps_avail(j_s),i) = true;
    elseif (n_ps_avail == 0)&&(n_pc_avail > 0)
      % There is at least one complex pole, but no simple pole available. 
      
      % Find candidate complex pole.
      [~,j_c] = min(domega_pc);
      
      % Assign this simple zero to the candidate complex pole.
      ASSIGNMENTS(i_rows_pc_avail(j_c),i) = true;
    else
      % There are no available poles.
      n_unassigned_zeros_s = n_unassigned_zeros_s+1;
      if (n_z > n_p)
        warning(['resulted in total of %d unassigned ' ...
                 'simple zeros (n_z=%d,n_p=%d)'], ...
                 n_unassigned_zeros_s,n_z,n_p);
      else
        error(['resulted in total of %d unassigned ' ...
               'simple zeros (n_z=%d,n_p=%d)'], ...
               n_unassigned_zeros_s,n_z,n_p);
      end
    end
  end
end
%% Assemble Cascade Links
% Initialize cascade list.
T_zpk_cascade = {};

if (n_z > 0)
  % Generate list of indices for 'ASSIGNMENTS' matrix.
  i_z = 1:length(ASSIGNMENTS(1,:));
  i_p = 1:length(ASSIGNMENTS(:,1));

  % Compute number of assignments for each zero and pole.
  n_assign_z = sum(ASSIGNMENTS,1);
  n_assign_p = sum(ASSIGNMENTS,2);

  % Check that no zero or pole is assigned more than twice.
  if any(n_assign_z > 2)
    error('at least one zero has more than two pole assignments.')
  elseif (any(n_assign_p > 2))
    error('at least one pole has more than two zero assignments.')
  end

  % Make list of indeces for zeros and poles that have no assignments.
  i_z_none = i_z(n_assign_z == 0);
  i_p_none = i_p(n_assign_p == 0);

  % Make list of indeces for zeros and poles that have two assignments.
  i_z_double = i_z(n_assign_z == 2);
  i_p_double = i_p(n_assign_p == 2);

  % Check that for each zero (pole) with two assignments, the two
  % associated poles (zeros) do not have more than one assignment.
  if any(sum(ASSIGNMENTS(:,i_z_double),2) > 1)
    error(['pole associated with twice assigned ' ...
           'zero has a second assignment.'])
  elseif any(sum(ASSIGNMENTS(i_p_double,:),1) > 1)
    error(['zero associated with twice assigned ' ...
           'pole has a second assignment.'])
  end

  % Add the poles and zeros associated with double assignment to 
  % 'i_z_double' and 'i_p_double'.
  i_z_skip = i_z((n_assign_z == 0)| ...
                 (n_assign_z == 2)| ...
                 any(ASSIGNMENTS(i_p_double,:),1));
  i_p_skip = i_p((n_assign_p == 0)| ...
                 (n_assign_p == 2)| ...
                 any(ASSIGNMENTS(:,i_z_double),2));
  
  % Single assignment case 
  for i=1:length(ASSIGNMENTS(:,1))
    for j=1:length(ASSIGNMENTS(1,:))
      if (all(i~=i_p_skip))&&(all(j~=i_z_skip))&&(ASSIGNMENTS(i,j) == true)
        % Generate 'zpk' object for zero.
        if (abs(z_damping(j)) == 1)
          % Simple zero.
          L_z = zpk(-z_damping(j)*z_omega(j),[],1);
        else
          % Complex zero.
          L_z = zpk(z_omega(j)* ...
            [-z_damping(j)+sqrt(z_damping(j)^2-1)
             -z_damping(j)-sqrt(z_damping(j)^2-1)],[],1);
        end

        % Generate 'zpk' object for pole.
        if (abs(p_damping(i)) == 1)
          % Simple pole.
          L_p = zpk([],-p_damping(i)*p_omega(i),1);
        else
          % Complex zero.
          L_p = zpk([],p_omega(i)* ...
            [-p_damping(i)+sqrt(p_damping(i)^2-1)
             -p_damping(i)-sqrt(p_damping(i)^2-1)],1);
        end

        % Add link to cascade.
        T_zpk_cascade{end+1,1} = minreal(L_z*L_p); %#ok<AGROW>
      end
    end
  end

  % Double assigned zero case.
  for j=i_z_double
    % Generate 'zpk' object for complex zero.
    L_z = zpk(z_omega(j)*[-z_damping(j)+sqrt(z_damping(j)^2-1)
                          -z_damping(j)-sqrt(z_damping(j)^2-1)],[],1);

    % Generate 'zpk' objects for simple poles.
    L_p = zpk([],[],1);
    for i=i_p(ASSIGNMENTS(:,j))
      L_p = L_p*zpk([],-p_damping(i)*p_omega(i),1);
    end

    % Add link to cascade.
    T_zpk_cascade{end+1,1} = minreal(L_z*L_p); %#ok<AGROW>
  end

  % Double assigned pole case.
  for i=i_p_double
    % Generate 'zpk' object for complex pole.
    L_p = zpk([],p_omega(i)*[-p_damping(i)+sqrt(p_damping(i)^2-1)
                             -p_damping(i)-sqrt(p_damping(i)^2-1)],1);

    % Generate 'zpk' objects for simple zeros.
    L_z = zpk([],[],1);
    for j=i_z(ASSIGNMENTS(i,:))
      L_z = L_z*zpk(-z_damping(j)*z_omega(j),[],1);
    end

    % Add link to cascade.
    T_zpk_cascade{end+1,1} = minreal(L_z*L_p); %#ok<AGROW>
  end
  
  % Non-assigned pole case.
  for i=i_p_none
    % Generate 'zpk' object for pole.
    if (abs(p_damping(i)) == 1)
      % Simple pole.
      L_p = zpk([],-p_damping(i)*p_omega(i),1);
    else
      % Complex zero.
      L_p = zpk([],p_omega(i)*[-p_damping(i)+sqrt(p_damping(i)^2-1)
                               -p_damping(i)-sqrt(p_damping(i)^2-1)],1);
    end

    % Add link to cascade.
    T_zpk_cascade{end+1,1} = minreal(L_p); %#ok<AGROW>
  end
  
  % Non-assigned zero case.
  for j=i_z_none
    % Generate 'zpk' object for zero.
    if (abs(z_damping(j)) == 1)
      % Simple zero.
      L_z = zpk(-z_damping(j)*z_omega(j),[],1);
    else
      % Complex zero.
      L_z = zpk(z_omega(j)*[-z_damping(j)+sqrt(z_damping(j)^2-1)
                            -z_damping(j)-sqrt(z_damping(j)^2-1)],[],1);
    end

    % Add link to cascade.
    T_zpk_cascade{end+1,1} = minreal(L_z); %#ok<AGROW>
  end
else
  % Non-assigned pole case.
  for i=1:length(p_damping)
    % Generate 'zpk' object for pole.
    if (abs(p_damping(i)) == 1)
      % Simple pole.
      L_p = zpk([],-p_damping(i)*p_omega(i),1);
    else
      % Complex zero.
      L_p = zpk([],p_omega(i)*[-p_damping(i)+sqrt(p_damping(i)^2-1)
                               -p_damping(i)-sqrt(p_damping(i)^2-1)],1);
    end

    % Add link to cascade.
    T_zpk_cascade{end+1,1} = minreal(L_p); %#ok<AGROW>
  end
end
%% Normalize Cascade Links
K_tot = 1;
for i=1:length(T_zpk_cascade)
  if (any(T_zpk_cascade{i}.Z{1} == 0))||(any(T_zpk_cascade{i}.P{1} == 0))
    % If link contains zeros or poles located at the origin, normalize link
    % to 0 dB at f = 1 Hz.
    K_i_dB = mp_tf_eval(T_zpk_cascade{i},1);
  else
    % If link does not contain any zeros or poles at the origin, normalize 
    % linke to 0 dB at f = 0 Hz.
    K_i_dB = mp_tf_eval(T_zpk_cascade{i},0);
  end
  
  % Apply normalization to cascade link.
  T_zpk_cascade{i}.K = T_zpk_cascade{i}.K*10^(-K_i_dB/20); %#ok<AGROW>
  K_tot = K_tot*10^(-K_i_dB/20);
end

% Add original gain to cascaade.
T_zpk_cascade(2:end+1) = T_zpk_cascade(1:end);
T_zpk_cascade{1} = zpk([],[],T_zpk.K/K_tot);
%% Check Cascade vs. Input
% Concatenate cascade to produce a 'zpk' object that can be checked against
% the original 'T_zpk' 'zpk' object.
T_zpk_check = mp_tf_convolve(T_zpk_cascade);

% Sort check 'zpk' object.
Z_check = sortrows([real(T_zpk_check.Z{1}) imag(T_zpk_check.Z{1})],[1 2]);
P_check = sortrows([real(T_zpk_check.P{1}) imag(T_zpk_check.P{1})],[1 2]);

% Sort check 'zpk' object.
Z_orig = sortrows([real(T_zpk.Z{1}) imag(T_zpk.Z{1})],[1 2]);
P_orig = sortrows([real(T_zpk.P{1}) imag(T_zpk.P{1})],[1 2]);

if any(max(abs(Z_check-Z_orig)) > 1e-10)
  error('zeros of output do not match zeros of input.')
elseif any(max(abs(P_check-P_orig)) > 1e-10)
  error('poles of output do not match poles of input.')
elseif (abs(T_zpk_check.K/T_zpk.K-1) > 1e-10)
  error('gain of output does not match gain of input.')
end
