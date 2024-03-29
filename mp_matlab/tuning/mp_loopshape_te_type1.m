function [L_imp] = mp_loopshape_te_type1(f_co,varargin)

% Define ideal loop shape.
L_cas = cell(0,1);
L_cas{end+1,1} = zpk([],0,1);
L_cas{end+1,1} = mp_ctrl_lag(0.25*f_co,1.16,1);
L_cas{end+1,1} = mp_ctrl_lag(0.30*f_co,1.16,1);
L_cas{end+1,1} = mp_ctrl_lag(0.35*f_co,1.16,1);
L_cas{end+1,1} = mp_ctrl_lag(0.40*f_co,1.16,1);
L_cas{end+1,1} = mp_ctrl_pole(2.15*f_co,1);

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
