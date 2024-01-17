classdef mp_quad_1dof_t < handle
  properties (Access = public)
    d(1,1) function_handle = @(t)t;
    n(1,1) function_handle = @(t)t;
    
    A(1,1);
    G(1,1);
    H(1,1);
    
    n_A(1,1) uint32 = 0;
    n_G(1,1) uint32 = 0;
    n_H(1,1) uint32 = 0;
    len(1,1) uint32 = 0;
    
    i_A(:,1) uint32 = zeros(0,1,'uint32');
    i_G(:,1) uint32 = zeros(0,1,'uint32');
    i_H(:,1) uint32 = zeros(0,1,'uint32');
    idx(:,1) uint32 = zeros(0,1,'uint32');
    
    x_i(:,1) double = zeros(0,1);
  end
  methods
    function [obj] = mp_quad_1dof_t(A,G,H,d,n,y_A_i)
      A_cas = mp_tf_cascade(A);
      G_cas = mp_tf_cascade(G);
      H_cas = mp_tf_cascade(H);
      
      A_ss = mp_cascade2ss(A_cas);
      G_ss = mp_cascade2ss(G_cas);
      H_ss = mp_cascade2ss(H_cas);
      
      obj.d = d;
      obj.n = n;
      obj.A = A_ss;
      obj.G = G_ss;
      obj.H = H_ss;
      
      obj.n_A = length(obj.A.A);
      obj.n_G = length(obj.G.A);
      obj.n_H = length(obj.H.A);
      obj.len = obj.n_A+obj.n_G+obj.n_H;
      
      obj.i_A = (1:obj.n_A);
      obj.i_G = (1:obj.n_G)+obj.n_A;
      obj.i_H = (1:obj.n_H)+obj.n_A+obj.n_G;
      obj.idx = 1:obj.len;
      
      H_A = (obj.A.A+obj.A.B*obj.A.C);
      if (rank(H_A) < obj.n_A)
        v_H_A = null(H_A);
        x_A_i = (1/(obj.A.C*v_H_A(:,1)))*v_H_A(:,1)*y_A_i';
      elseif (obj.n_A == 1)
        x_A_i = (1/obj.A.C)*y_A_i';
      else
        error(['Encountered unexpected condition while ' ...
               'computing initial state of A.'])
      end
      
      obj.x_i = zeros(obj.len,1);
      obj.x_i(obj.i_A) = x_A_i;
      
      if (obj.A.D ~= 0)
        error('A.D ~= 0!')
      elseif (obj.H.D ~= 0)
        error('H.D ~= 0!')
      end
    end
    function [s] = sigs(obj,t,x,u_act,sat_lims)
      s = struct;
      
      s.d = feval(obj.d,t);
      s.n = feval(obj.n,t);
      
      x_A = x(obj.i_A,:);
      x_G = x(obj.i_G,:);
      x_H = x(obj.i_H,:);
      
      s.u_act = u_act;
      s.u_act_sat = mp_saturation(sat_lims(1,:),s.u_act,sat_lims(2,:));
      
      s.u_A = s.u_act_sat;
      s.y_A = obj.A.C*x_A; % assumes obj.A.D = 0.
      
      s.u_G = s.y_A+s.d;
      s.y_G = obj.G.C*x_G+obj.G.D*s.u_G;
      
      s.u_H = s.y_G+s.n;
      s.y_H = obj.H.C*x_H; % assumes obj.H.D = 0.
    end
    function [x_dot] = derivs(obj,t,x,u_act,sat_lims)
      s = obj.sigs(t,x,u_act,sat_lims);
      
      x_A = x(obj.i_A);
      x_G = x(obj.i_G);
      x_H = x(obj.i_H);
      
      x_A_dot = obj.A.A*x_A+obj.A.B*s.u_A;
      x_G_dot = obj.G.A*x_G+obj.G.B*s.u_G;
      x_H_dot = obj.H.A*x_H+obj.H.B*s.u_H;
      
      x_dot = zeros(obj.len,1);
      x_dot(obj.i_A) = x_A_dot;
      x_dot(obj.i_G) = x_G_dot;
      x_dot(obj.i_H) = x_H_dot;
    end
    function [y] = output(obj,x)
      y = obj.H.C*x(obj.i_H,:);
    end
  end
end
