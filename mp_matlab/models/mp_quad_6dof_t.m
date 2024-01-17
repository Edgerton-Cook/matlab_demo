classdef mp_quad_6dof_t < handle
  properties (Access = public, Constant = true)
    m(1,1) = mp_model_vehicle('mass');
    g_i(3,1) = [0 0 9.8071]';
    J_b(3,3) = mp_model_vehicle('inertia');
    pwm_min(1,1) = 1150;
    pwm_max(1,1) = 1800;
    k_f2t(1,1) = 0.012;
    l_x(1,1) = 0.085;
    l_y(1,1) = 0.085;
  end
  properties (Access = public)
    d(1,1) function_handle = @(t)ones(4,1)*t;
    n(1,1) function_handle = @(t)ones(4,1)*t;
    f2p(1,1) function_handle = @(f)zeros(size(f));
    p2f(1,1) function_handle = @(p)zeros(size(p));
    
    f_min(1,1);
    f_max(1,1);
    
    A_thrust(1,1);
    A_torque(1,1);
    H_accl(1,1);
    H_gyro(1,1);
    
    H_f2w(4,4) = zeros(4,4);
    
    n_A_thrust(1,1) uint32 = 0;
    n_A_torque(1,1) uint32 = 0;
    n_H_accl(1,1) uint32 = 0;
    n_H_gyro(1,1) uint32 = 0;
    len(1,1) uint32 = 0;
    
    i_A1_thrust(:,1) uint32 = zeros(0,1,'uint32');
    i_A2_thrust(:,1) uint32 = zeros(0,1,'uint32');
    i_A3_thrust(:,1) uint32 = zeros(0,1,'uint32');
    i_A4_thrust(:,1) uint32 = zeros(0,1,'uint32');
    
    i_A1_torque(:,1) uint32 = zeros(0,1,'uint32');
    i_A2_torque(:,1) uint32 = zeros(0,1,'uint32');
    i_A3_torque(:,1) uint32 = zeros(0,1,'uint32');
    i_A4_torque(:,1) uint32 = zeros(0,1,'uint32');
    
    i_p_i(:,1) uint32 = zeros(0,1,'uint32');
    i_v_i(:,1) uint32 = zeros(0,1,'uint32');
    i_q_i2b(:,1) uint32 = zeros(0,1,'uint32');
    i_omega_b(:,1) uint32 = zeros(0,1,'uint32');
    
    i_H1(:,1) uint32 = zeros(0,1,'uint32');
    i_H2(:,1) uint32 = zeros(0,1,'uint32');
    i_H3(:,1) uint32 = zeros(0,1,'uint32');
    i_H4(:,1) uint32 = zeros(0,1,'uint32');
    
    idx(:,1) uint32 = zeros(0,1,'uint32');
    
    x_i(:,1) double = zeros(0,1);
  end
  methods
    function [obj] = ...
        mp_quad_6dof_t(A,H,d,n,p_i,v_i,q_i2b_i,omega_b_i,f_i)
      A_thrust_cas = mp_tf_cascade(A(1));
      A_torque_cas = mp_tf_cascade(A(4));
      H_accl_cas = mp_tf_cascade(H(1));
      H_gyro_cas = mp_tf_cascade(H(4));
      
      A_thrust_ss = mp_cascade2ss(A_thrust_cas);
      A_torque_ss = mp_cascade2ss(A_torque_cas);
      H_accl_ss = mp_cascade2ss(H_accl_cas);
      H_gyro_ss = mp_cascade2ss(H_gyro_cas);
      
      obj.d = d;
      obj.n = n;
      obj.f2p = @(f)(f/5.1282e-06).^0.5+obj.pwm_min;
      obj.p2f = @(p)5.1282e-06*(p-obj.pwm_min).^2;
      
      obj.f_min = obj.p2f(obj.pwm_min);
      obj.f_max = obj.p2f(obj.pwm_max);
      
      obj.A_thrust = A_thrust_ss;
      obj.A_torque = A_torque_ss;
      obj.H_accl = H_accl_ss;
      obj.H_gyro = H_gyro_ss;
      
      obj.H_f2w = [[ 1  1  1  1]
                   [-1 -1  1  1]*obj.l_y
                   [ 1 -1 -1  1]*obj.l_x
                   [ 1 -1  1 -1]*obj.k_f2t];
      
      obj.n_A_thrust = length(obj.A_thrust.A);
      obj.n_A_torque = length(obj.A_torque.A);
      obj.n_H_accl = length(obj.H_accl.A);
      obj.n_H_gyro = length(obj.H_gyro.A);
      obj.len = 3+3+4+3 ...
               +4*obj.n_A_thrust ...
               +4*obj.n_A_torque ...
               +obj.n_H_accl ...
               +3*obj.n_H_gyro;
      
      % Indicies of vehicle plant states.
      obj.i_p_i = uint32(1:3);
      obj.i_v_i = uint32(1:3)+obj.i_p_i(end);
      obj.i_q_i2b = uint32(1:4)+obj.i_v_i(end);
      obj.i_omega_b = uint32(1:3)+obj.i_q_i2b(end);
      
      % Indices of thrust actuator states.
      obj.i_A1_thrust = (1:obj.n_A_thrust)+obj.i_omega_b(end);
      obj.i_A2_thrust = (1:obj.n_A_thrust)+obj.i_A1_thrust(end);
      obj.i_A3_thrust = (1:obj.n_A_thrust)+obj.i_A2_thrust(end);
      obj.i_A4_thrust = (1:obj.n_A_thrust)+obj.i_A3_thrust(end);
      
      % Indices of torque actuator states.
      obj.i_A1_torque = (1:obj.n_A_torque)+obj.i_A4_thrust(end);
      obj.i_A2_torque = (1:obj.n_A_torque)+obj.i_A1_torque(end);
      obj.i_A3_torque = (1:obj.n_A_torque)+obj.i_A2_torque(end);
      obj.i_A4_torque = (1:obj.n_A_torque)+obj.i_A3_torque(end);
      
      % Indicies of sensor states.
      obj.i_H1 = (1:obj.n_H_accl)+obj.i_A4_torque(end);
      obj.i_H2 = (1:obj.n_H_gyro)+obj.i_H1(end);
      obj.i_H3 = (1:obj.n_H_gyro)+obj.i_H2(end);
      obj.i_H4 = (1:obj.n_H_gyro)+obj.i_H3(end);
      
      obj.idx = 1:obj.len;
      
      H_A_thrust = (obj.A_thrust.A+obj.A_thrust.B*obj.A_thrust.C);
      if (rank(H_A_thrust) < obj.n_A_thrust)
        v_H_A_thrust = null(H_A_thrust);
        x_A_thrust_i = ...
          (1/(obj.A_thrust.C*v_H_A_thrust(:,1)))*v_H_A_thrust(:,1)*f_i';
      elseif (obj.n_A_thrust == 1)
        x_A_thrust_i = (1/obj.A_thrust.C)*f_i';
      else
        error(['Encountered unexpected condition while ' ...
               'computing initial state of A_thrust.'])
      end
      
      H_A_torque = (obj.A_torque.A+obj.A_torque.B*obj.A_torque.C);
      if (rank(H_A_torque) < obj.n_A_torque)
        v_H_A_torque = null(H_A_torque);
        x_A_torque_i = ...
          (1/(obj.A_torque.C*v_H_A_torque(:,1)))*v_H_A_torque(:,1)*f_i';
      elseif (obj.n_A_torque == 1)
        x_A_torque_i = (1/obj.A_torque.C)*f_i';
      else
        error(['Encountered unexpected condition while ' ...
               'computing initial state of A_torque.'])
      end
      
      H_H_accl = (obj.H_accl.A+obj.H_accl.B*obj.H_accl.C);
      if (rank(H_H_accl) < obj.n_H_accl)
        v_H_H_accl = null(H_H_accl);
        x_H1_i = (1/(obj.H_accl.C*v_H_H_accl(:,1)))* ...
          v_H_H_accl(:,1)*(sum(f_i)/obj.m);
      else
        error(['Encountered unexpected condition while ' ...
               'computing initial state of H1.'])
      end
      
      H_H_gyro = (obj.H_gyro.A+obj.H_gyro.B*obj.H_gyro.C);
      if (rank(H_H_gyro) < obj.n_H_gyro)
        v_H_H_gyro = null(H_H_gyro);
        x_H2_i = (1/(obj.H_gyro.C*v_H_H_gyro(:,1)))* ...
          v_H_H_gyro(:,1)*(omega_b_i(1));
        x_H3_i = (1/(obj.H_gyro.C*v_H_H_gyro(:,1)))* ...
          v_H_H_gyro(:,1)*(omega_b_i(2));
        x_H4_i = (1/(obj.H_gyro.C*v_H_H_gyro(:,1)))* ...
          v_H_H_gyro(:,1)*(omega_b_i(3));
      else
        error(['Encountered unexpected condition while ' ...
               'computing initial state of H2, H3, H4.'])
      end
      
      obj.x_i = zeros(obj.len,1);
      
      % Initial plant states.
      obj.x_i(obj.i_p_i) = p_i;
      obj.x_i(obj.i_v_i) = v_i;
      obj.x_i(obj.i_q_i2b) = q_i2b_i;
      obj.x_i(obj.i_omega_b) = omega_b_i;
      
      % Initial thrust actuator states.
      obj.x_i(obj.i_A1_thrust) = x_A_thrust_i(:,1);
      obj.x_i(obj.i_A2_thrust) = x_A_thrust_i(:,2);
      obj.x_i(obj.i_A3_thrust) = x_A_thrust_i(:,3);
      obj.x_i(obj.i_A4_thrust) = x_A_thrust_i(:,4);
      
      % Initial torque actuator states.
      obj.x_i(obj.i_A1_torque) = x_A_torque_i(:,1);
      obj.x_i(obj.i_A2_torque) = x_A_torque_i(:,2);
      obj.x_i(obj.i_A3_torque) = x_A_torque_i(:,3);
      obj.x_i(obj.i_A4_torque) = x_A_torque_i(:,4);
      
      % Initial sensor states.
      obj.x_i(obj.i_H1) = x_H1_i;
      obj.x_i(obj.i_H2) = x_H2_i;
      obj.x_i(obj.i_H3) = x_H3_i;
      obj.x_i(obj.i_H4) = x_H4_i;
      
      if (obj.A_thrust.D ~= 0)
        error('A_thrust.D ~= 0!')
      elseif (obj.A_torque.D ~= 0)
        error('A_torque.D ~= 0!')
      elseif (obj.H_accl.D ~= 0)
        error('H_accl.D ~= 0!')
      elseif (obj.H_gyro.D ~= 0)
        error('H_gyro.D ~= 0!')
      end
    end
    function [s] = sigs(obj,t,x,u_pwm)
      s = struct;
      
      s.d = feval(obj.d,t);
      s.n = feval(obj.n,t);
      
      p_i = x(obj.i_p_i,:);
      v_i = x(obj.i_v_i,:);
      q_i2b = x(obj.i_q_i2b,:);
      q_i2b_norm = sum(q_i2b.^2,1).^0.5;
      q_i2b = q_i2b./q_i2b_norm;
      omega_b = x(obj.i_omega_b,:);
      
      x_A1_thrust = x(obj.i_A1_thrust,:);
      x_A2_thrust = x(obj.i_A2_thrust,:);
      x_A3_thrust = x(obj.i_A3_thrust,:);
      x_A4_thrust = x(obj.i_A4_thrust,:);
      
      x_A1_torque = x(obj.i_A1_torque,:);
      x_A2_torque = x(obj.i_A2_torque,:);
      x_A3_torque = x(obj.i_A3_torque,:);
      x_A4_torque = x(obj.i_A4_torque,:);
      
      x_H1 = x(obj.i_H1,:);
      x_H2 = x(obj.i_H2,:);
      x_H3 = x(obj.i_H3,:);
      x_H4 = x(obj.i_H4,:);
      
      s.u_pwm = u_pwm;
      s.u_pwm_sat = mp_saturation(obj.pwm_min,s.u_pwm,obj.pwm_max);
      
      s.u_A1 = obj.p2f(s.u_pwm_sat(1,:));
      s.u_A2 = obj.p2f(s.u_pwm_sat(2,:));
      s.u_A3 = obj.p2f(s.u_pwm_sat(3,:));
      s.u_A4 = obj.p2f(s.u_pwm_sat(4,:));
      
      % Assumes obj.A_thrust.D = 0.
      s.y_A1_thrust = obj.A_thrust.C*x_A1_thrust;
      s.y_A2_thrust = obj.A_thrust.C*x_A2_thrust;
      s.y_A3_thrust = obj.A_thrust.C*x_A3_thrust;
      s.y_A4_thrust = obj.A_thrust.C*x_A4_thrust;
      
      % Assumes obj.A_torque.D = 0.
      s.y_A1_torque = obj.A_torque.C*x_A1_torque;
      s.y_A2_torque = obj.A_torque.C*x_A2_torque;
      s.y_A3_torque = obj.A_torque.C*x_A3_torque;
      s.y_A4_torque = obj.A_torque.C*x_A4_torque;
      
      s.f = zeros(4,length(t));
      s.f(1,:) = s.y_A1_thrust;
      s.f(2,:) = s.y_A2_thrust;
      s.f(3,:) = s.y_A3_thrust;
      s.f(4,:) = s.y_A4_thrust;
      s.f_s_mot = (1/obj.m)*sum(s.f,1); % specific force due to motors.
      s.z_accl = -s.f_s_mot+(1/obj.m)*s.d(1,:);
      
      s.tau = zeros(4,length(t));
      s.tau(1,:) = s.y_A1_torque;
      s.tau(2,:) = s.y_A2_torque;
      s.tau(3,:) = s.y_A3_torque;
      s.tau(4,:) = s.y_A4_torque;
      s.u_torque_b = [obj.H_f2w(2:3,:)*s.f; obj.H_f2w(4,:)*s.tau];
      s.torque_b = s.u_torque_b+s.d(2:4,:);
      
      s.p_i = p_i;
      s.v_i = v_i;
      s.q_i2b = q_i2b;
      s.omega_b = omega_b;
      
      s.u_H1 = s.z_accl+s.n(1,:);
      s.u_H2 = s.omega_b(1,:)+s.n(2,:);
      s.u_H3 = s.omega_b(2,:)+s.n(3,:);
      s.u_H4 = s.omega_b(3,:)+s.n(4,:);
      
      s.y_H1 = obj.H_accl.C*x_H1; % assumes obj.H_accl.D = 0.
      s.y_H2 = obj.H_gyro.C*x_H2; % assumes obj.H_gyro.D = 0.
      s.y_H3 = obj.H_gyro.C*x_H3; % assumes obj.H_gyro.D = 0.
      s.y_H4 = obj.H_gyro.C*x_H4; % assumes obj.H_gyro.D = 0.
    end
    function [x_dot] = derivs(obj,t,x,u_pwm)
      s = obj.sigs(t,x,u_pwm);
      
      x_A1_thrust = x(obj.i_A1_thrust,:);
      x_A2_thrust = x(obj.i_A2_thrust,:);
      x_A3_thrust = x(obj.i_A3_thrust,:);
      x_A4_thrust = x(obj.i_A4_thrust,:);
      
      x_A1_torque = x(obj.i_A1_torque,:);
      x_A2_torque = x(obj.i_A2_torque,:);
      x_A3_torque = x(obj.i_A3_torque,:);
      x_A4_torque = x(obj.i_A4_torque,:);
      
      x_H1 = x(obj.i_H1);
      x_H2 = x(obj.i_H2);
      x_H3 = x(obj.i_H3);
      x_H4 = x(obj.i_H4);
      
      % Vehicle plant dynamics.
      p_i_dot = s.v_i;
      v_i_dot = mp_quat2dcm(s.q_i2b)'*[0 0 s.z_accl]'+obj.g_i;
      q_i2b_dot = 0.5*mp_skew4(s.omega_b)*s.q_i2b;
      omega_b_dot = ...
        obj.J_b\(s.torque_b-mp_skew3(s.omega_b)*obj.J_b*s.omega_b);
      
      % Thrust actuator dynamics.
      x_A1_thrust_dot = obj.A_thrust.A*x_A1_thrust+obj.A_thrust.B*s.u_A1;
      x_A2_thrust_dot = obj.A_thrust.A*x_A2_thrust+obj.A_thrust.B*s.u_A2;
      x_A3_thrust_dot = obj.A_thrust.A*x_A3_thrust+obj.A_thrust.B*s.u_A3;
      x_A4_thrust_dot = obj.A_thrust.A*x_A4_thrust+obj.A_thrust.B*s.u_A4;
      
      % Torque actuator dynamics.
      x_A1_torque_dot = obj.A_torque.A*x_A1_torque+obj.A_torque.B*s.u_A1;
      x_A2_torque_dot = obj.A_torque.A*x_A2_torque+obj.A_torque.B*s.u_A2;
      x_A3_torque_dot = obj.A_torque.A*x_A3_torque+obj.A_torque.B*s.u_A3;
      x_A4_torque_dot = obj.A_torque.A*x_A4_torque+obj.A_torque.B*s.u_A4;
      
      % Sensor dynamics.
      x_H1_dot = obj.H_accl.A*x_H1+obj.H_accl.B*s.u_H1;
      x_H2_dot = obj.H_gyro.A*x_H2+obj.H_gyro.B*s.u_H2;
      x_H3_dot = obj.H_gyro.A*x_H3+obj.H_gyro.B*s.u_H3;
      x_H4_dot = obj.H_gyro.A*x_H4+obj.H_gyro.B*s.u_H4;
      
      x_dot = zeros(obj.len,1);
      x_dot(obj.i_p_i) = p_i_dot;
      x_dot(obj.i_v_i) = v_i_dot;
      x_dot(obj.i_q_i2b) = q_i2b_dot;
      x_dot(obj.i_omega_b) = omega_b_dot;
      x_dot(obj.i_A1_thrust) = x_A1_thrust_dot;
      x_dot(obj.i_A2_thrust) = x_A2_thrust_dot;
      x_dot(obj.i_A3_thrust) = x_A3_thrust_dot;
      x_dot(obj.i_A4_thrust) = x_A4_thrust_dot;
      x_dot(obj.i_A1_torque) = x_A1_torque_dot;
      x_dot(obj.i_A2_torque) = x_A2_torque_dot;
      x_dot(obj.i_A3_torque) = x_A3_torque_dot;
      x_dot(obj.i_A4_torque) = x_A4_torque_dot;
      x_dot(obj.i_H1) = x_H1_dot;
      x_dot(obj.i_H2) = x_H2_dot;
      x_dot(obj.i_H3) = x_H3_dot;
      x_dot(obj.i_H4) = x_H4_dot;
    end
    function [y] = output_inertial(obj,x)
      y = [obj.H_accl.C*x(obj.i_H1,:)
           obj.H_gyro.C*x(obj.i_H2,:)
           obj.H_gyro.C*x(obj.i_H3,:)
           obj.H_gyro.C*x(obj.i_H4,:)];
    end
    function [y] = output_p_i(obj,x)
      y = x(obj.i_p_i,:);
    end
    function [y] = output_v_i(obj,x)
      y = x(obj.i_v_i,:);
    end
    function [y] = output_q_i2b(obj,x)
      y = x(obj.i_q_i2b,:);
    end
    function [y] = output_omega_b(obj,x)
      y = x(obj.i_omega_b,:);
    end
  end
end
