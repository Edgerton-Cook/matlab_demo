function [ret] = mp_model_vehicle(model,varargin)

m = 0.354; % vehicle mass [kg]
J = diag([781716.914
          937378.697
          1581030.483])*1e-9; % vehicle inertia [kg-m^2]

if (nargin == 1)
  H_zoh = zpk([],[],1);
elseif (nargin == 3)
  f_samp = varargin{1}; % sampling frequency [Hz]
  order = varargin{2}; % Pade approximation order
  
  [N_esT,D_esT] = pade(1/f_samp,order);
  esT = zpk(tf(N_esT,D_esT));
  H_zoh = minreal((1-esT)*zpk([],0,f_samp));
end

if isequal(model,'x-rate')
  ret = zpk([],0,1/J(1,1))*H_zoh;
elseif isequal(model,'y-rate')
  ret = zpk([],0,1/J(2,2))*H_zoh;
elseif isequal(model,'z-rate')
  ret = zpk([],0,1/J(3,3))*H_zoh;
elseif isequal(model,'z-accl')
  ret = zpk([],[],1/m)*H_zoh;
elseif isequal(model,'vel')
  ret = zpk([],0,1/m)*H_zoh;
elseif isequal(model,'pos')
  ret = zpk([],[0 0],1/m)*H_zoh;
elseif isequal(model,'mass')
  ret = m;
elseif isequal(model,'inertia')
  ret = J;
end
