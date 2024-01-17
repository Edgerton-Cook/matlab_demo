classdef mp_ndc_t < handle
  properties (Access = public)
    P_fb(1,1);
    F_fb(1,1);
    P_ff(1,1);
    F_ff(1,1);
    C(1,1);
    W(1,1);
    
    n_P_fb(1,1) uint32 = 0;
    n_F_fb(1,1) uint32 = 0;
    n_P_ff(1,1) uint32 = 0;
    n_F_ff(1,1) uint32 = 0;
    n_C(1,1) uint32 = 0;
    n_W(1,1) uint32 = 0;
    len(1,1) uint32 = 0;
    
    i_P_fb(:,1) uint32 = zeros(0,1,'uint32');
    i_F_fb(:,1) uint32 = zeros(0,1,'uint32');
    i_P_ff(:,1) uint32 = zeros(0,1,'uint32');
    i_F_ff(:,1) uint32 = zeros(0,1,'uint32');
    i_C(:,1) uint32 = zeros(0,1,'uint32');
    i_W(:,1) uint32 = zeros(0,1,'uint32');
    idx(:,1) uint32 = zeros(0,1,'uint32');
    
    x_i(:,1) double = zeros(0,1);
  end
  methods
    function [obj] = mp_ndc_t(P_fb,F_fb,P_ff,F_ff,C,W)
      P_fb_cas = mp_tf_cascade(P_fb);
      F_fb_cas = mp_tf_cascade(F_fb);
      P_ff_cas = mp_tf_cascade(P_ff);
      F_ff_cas = mp_tf_cascade(F_ff);
      C_cas = mp_tf_cascade(C);
      W_cas = mp_tf_cascade(W);
      
      P_fb_ss = mp_cascade2ss(P_fb_cas);
      F_fb_ss = mp_cascade2ss(F_fb_cas);
      P_ff_ss = mp_cascade2ss(P_ff_cas);
      F_ff_ss = mp_cascade2ss(F_ff_cas);
      C_ss = mp_cascade2ss(C_cas);
      W_ss = mp_cascade2ss(W_cas);
      
      obj.P_fb = P_fb_ss;
      obj.F_fb = F_fb_ss;
      obj.P_ff = P_ff_ss;
      obj.F_ff = F_ff_ss;
      obj.C = C_ss;
      obj.W = W_ss;
      
      obj.n_P_fb = length(obj.P_fb.A);
      obj.n_F_fb = length(obj.F_fb.A);
      obj.n_P_ff = length(obj.P_ff.A);
      obj.n_F_ff = length(obj.F_ff.A);
      obj.n_C = length(obj.C.A);
      obj.n_W = length(obj.W.A);
      obj.len = obj.n_P_fb ...
               +obj.n_F_fb ...
               +obj.n_P_ff ...
               +obj.n_F_ff ...
               +obj.n_C ...
               +obj.n_W;
      
      obj.i_P_fb = (1:obj.n_P_fb);
      obj.i_F_fb = (1:obj.n_F_fb)+obj.n_P_fb;
      obj.i_P_ff = (1:obj.n_P_ff)+obj.n_P_fb+obj.n_F_fb;
      obj.i_F_ff = (1:obj.n_F_ff)+obj.n_P_fb+obj.n_F_fb+obj.n_P_ff;
      obj.i_C = (1:obj.n_C)+obj.n_P_fb+obj.n_F_fb+obj.n_P_ff+obj.n_F_ff;
      obj.i_W = (1:obj.n_W)+obj.n_P_fb+obj.n_F_fb ...
                           +obj.n_P_ff+obj.n_F_ff+obj.n_C;
      obj.idx = 1:obj.len;
      
      obj.x_i = zeros(obj.len,1);
      
      if (obj.C.D ~= 0)
        error('C.D ~= 0!')
      end
    end
    function [s] = sigs(obj,x,y_sen,r_fb,r_ff,u_ff,u_W)
      s = struct;
      
      s.y_sen = y_sen;
      s.u_P_fb = r_fb;
      s.u_F_fb = r_fb;
      s.u_P_ff = r_ff;
      s.u_F_ff = u_ff;
      s.u_W = u_W;
      
      x_P_fb = x(obj.i_P_fb,:);
      x_F_fb = x(obj.i_F_fb,:);
      x_P_ff = x(obj.i_P_ff,:);
      x_F_ff = x(obj.i_F_ff,:);
      x_C = x(obj.i_C,:);
      x_W = x(obj.i_W,:);
      
      s.y_P_fb = obj.P_fb.C*x_P_fb+obj.P_fb.D*s.u_P_fb;
      s.y_F_fb = obj.F_fb.C*x_F_fb+obj.F_fb.D*s.u_F_fb;
      s.y_P_ff = obj.P_ff.C*x_P_ff+obj.P_ff.D*s.u_P_ff;
      s.y_F_ff = obj.F_ff.C*x_F_ff+obj.F_ff.D*s.u_F_ff;
      s.y_C = obj.C.C*x_C; % assumes obj.C.D is zero.
      s.y_W = obj.W.C*x_W+obj.W.D*s.u_W;
      
      s.r = s.u_P_fb+s.u_P_ff;
      s.e = s.u_P_fb+r_ff-s.y_sen;
      s.u_C = s.y_P_fb+s.y_P_ff-s.y_sen-s.y_W;
      s.u = s.y_C+s.y_F_fb+s.y_F_ff;
    end
    function [x_dot] = derivs(obj,x,y_sen,r_fb,r_ff,u_ff,u_W)
      s = obj.sigs(x,y_sen,r_fb,r_ff,u_ff,u_W);
      
      x_P_fb = x(obj.i_P_fb);
      x_F_fb = x(obj.i_F_fb);
      x_P_ff = x(obj.i_P_ff);
      x_F_ff = x(obj.i_F_ff);
      x_C = x(obj.i_C);
      x_W = x(obj.i_W);
      
      x_P_fb_dot = obj.P_fb.A*x_P_fb+obj.P_fb.B*s.u_P_fb;
      x_F_fb_dot = obj.F_fb.A*x_F_fb+obj.F_fb.B*s.u_F_fb;
      x_P_ff_dot = obj.P_ff.A*x_P_ff+obj.P_ff.B*s.u_P_ff;
      x_F_ff_dot = obj.F_ff.A*x_F_ff+obj.F_ff.B*s.u_F_ff;
      x_C_dot = obj.C.A*x_C+obj.C.B*s.u_C;
      x_W_dot = obj.W.A*x_W+obj.W.B*s.u_W;
      
      x_dot = zeros(obj.len,1);
      x_dot(obj.i_P_fb) = x_P_fb_dot;
      x_dot(obj.i_F_fb) = x_F_fb_dot;
      x_dot(obj.i_P_ff) = x_P_ff_dot;
      x_dot(obj.i_F_ff) = x_F_ff_dot;
      x_dot(obj.i_C) = x_C_dot;
      x_dot(obj.i_W) = x_W_dot;
    end
    function [u] = output(obj,x,r_fb,u_ff)
      u_F_fb = r_fb;
      u_F_ff = u_ff;
      
      x_F_fb = x(obj.i_F_fb,:);
      x_F_ff = x(obj.i_F_ff,:);
      x_C = x(obj.i_C,:);
      
      y_F_fb = obj.F_fb.C*x_F_fb+obj.F_fb.D*u_F_fb;
      y_F_ff = obj.F_ff.C*x_F_ff+obj.F_ff.D*u_F_ff;
      y_C = obj.C.C*x_C;
      
      u = y_C+y_F_fb+y_F_ff;
    end
  end
end
