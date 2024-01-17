function [L_imp] = mp_loopshape_te_type0(f_co,varargin)

% Define ideal loop shape.
L_cas = cell(0,1);
L_cas{end+1,1} = mp_ctrl_lag(1.00*f_co,1.30,2);
L_cas{end+1,1} = mp_ctrl_complex_pole(1.0*f_co,2.50,1);
L_cas{end+1,1} = mp_ctrl_complex_zero(3.10*f_co,0.7,1);
L_cas{end+1,1} = mp_ctrl_complex_pole(4.90*f_co,0.6,1);
L_cas{end+1,1} = mp_ctrl_complex_pole(7*f_co,0.8,1);

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
