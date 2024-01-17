function [L_imp] = mp_loopshape_s1_as_pm35s(f_co,varargin)

% Define ideal loop shape.
L_cas = cell(0,1);
L_cas{end+1,1} = zpk([],0,1);
L_cas{end+1,1} = mp_ctrl_lag(0.0625*f_co,1.15,2);
L_cas{end+1,1} = mp_ctrl_lag(0.1250*f_co,1.15,2);
L_cas{end+1,1} = mp_ctrl_lag(0.2500*f_co,1.15,2);
L_cas{end+1,1} = mp_ctrl_lag(0.5000*f_co,1.14,2);
L_cas{end+1,1} = mp_ctrl_lag(1.0000*f_co,1.13,2);
L_cas{end+1,1} = mp_ctrl_lead(2.50*f_co,1.30,2);
L_cas{end+1,1} = mp_ctrl_pole(7.20*f_co,4);

% Adjust gain at crossover frequency.
L_ideal = mp_tf_convolve(L_cas);
K_co_dB = mp_tf_eval(L_ideal,f_co);
L_ideal = 10^(-K_co_dB/20)*L_ideal;

% Compute TF of implemented portion of the loop.
if (nargin == 1)
  L_imp = L_ideal;
elseif (nargin == 2)
	L_comp = varargin{1};
  L_imp = minreal(L_ideal/L_comp);
end
