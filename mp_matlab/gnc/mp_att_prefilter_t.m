classdef mp_att_prefilter_t < handle
  properties (Access = public)
    n_q_i2r(1,1) uint32 = 0;
    n_omega_r(1,1) uint32 = 0;
    len(1,1) uint32 = 0;
    
    i_q_i2r(:,1) uint32 = zeros(0,1,'uint32');
    i_omega_r(:,1) uint32 = zeros(0,1,'uint32');
    idx(:,1) uint32 = zeros(0,1,'uint32');
    
    x_i(:,1) double = zeros(0,1);
    
    J(3,3) = eye(3);
    G_p(3,3) = zeros(3);
    G_d(3,3) = zeros(3);
    
    H_omega_sat(3,3) = zeros(3);
    H_tau_sat(3,3) = zeros(3);
    
    omega_sat_type(1,1) = inf;
    tau_sat_type(1,1) = inf;
  end
  methods
    function [obj] = mp_att_prefilter_t(J,G_p,G_d, ...
                                        omega_sat,omega_sat_type, ...
                                        tau_sat,tau_sat_type, ...
                                        q_i2r_i,omega_r_i)
      obj.n_q_i2r = 4;
      obj.n_omega_r = 3;
      obj.len = obj.n_q_i2r+obj.n_omega_r;
      
      obj.i_q_i2r = (1:obj.n_q_i2r);
      obj.i_omega_r = (1:obj.n_omega_r)+obj.n_q_i2r;
      obj.idx = 1:obj.len;
      
      obj.x_i = [q_i2r_i' omega_r_i']';
      
      obj.J = J;
      obj.G_p = G_p;
      obj.G_d = G_d;
      
      obj.H_omega_sat = G_p/G_d/diag(omega_sat);
      obj.H_tau_sat = inv(diag(tau_sat));
      
      obj.omega_sat_type = omega_sat_type;
      obj.tau_sat_type = tau_sat_type;
    end
    function [x_dot] = derivs(obj,x,q_i2d,omega_d,tau_d)
      q_i2r = x(obj.i_q_i2r);
      omega_r = x(obj.i_omega_r);
      tau_r = obj.output_tau_r(x,q_i2d,omega_d,tau_d);
      
      q_i2r_dot = 0.5*mp_skew4(omega_r)*q_i2r;
      omega_r_dot = obj.J\(tau_r-mp_skew3(omega_r)*obj.J*omega_r);
      
      x_dot = zeros(obj.len,1);
      x_dot(obj.i_q_i2r) = q_i2r_dot;
      x_dot(obj.i_omega_r) = omega_r_dot;
    end
    function [q_i2r] = output_q_i2r(obj,x)
      q_i2r = x(obj.i_q_i2r,:);
    end
    function [omega_r] = output_omega_r(obj,x)
      omega_r = x(obj.i_omega_r,:);
    end
    function [tau_r] = output_tau_r(obj,x,q_i2d,omega_d,tau_d)
      q_i2r = x(obj.i_q_i2r);
      omega_r = x(obj.i_omega_r);
      
      q_d2r = ...
        mp_quat_rectify(mp_quat_mult(mp_quat_conjugate(q_i2d),q_i2r));
      q_vec_sat = q_d2r(2:4)/max(norm(obj.H_omega_sat*q_d2r(2:4,:), ...
                                      obj.omega_sat_type),1);
      
      u_p = -obj.G_p*q_vec_sat;
      u_d = -obj.G_d*(omega_r-omega_d);
      
      tau_r_unsat = u_p+u_d+mp_skew3(omega_d)*obj.J*omega_d+tau_d;
      tau_r = tau_r_unsat/max(norm(obj.H_tau_sat*tau_r_unsat, ...
                                   obj.tau_sat_type),1);
    end
  end
end
