function [L_imp] = mp_loopshape_s2_as_pm35d(f_co,varargin)

% Define ideal loop shape.
L_cas = cell(0,1);
L_cas{end+1,1} = zpk([],[0 0],1);
L_cas{end+1,1} = mp_ctrl_zero(0.42*f_co,1);
L_cas{end+1,1} = mp_ctrl_lead(0.40*f_co,1.10,1);
L_cas{end+1,1} = mp_ctrl_complex_pole(1.05*f_co,1.00,1);
L_cas{end+1,1} = mp_ctrl_complex_zero(1.35*f_co,1.00,1);
L_cas{end+1,1} = mp_ctrl_lag(2.00*f_co,1.18,1);
L_cas{end+1,1} = mp_ctrl_complex_zero(2.20*f_co,0.7,1);
L_cas{end+1,1} = mp_ctrl_complex_pole(3.20*f_co,0.6,1);
L_cas{end+1,1} = mp_ctrl_complex_pole(7.80*f_co,0.6,3);

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
