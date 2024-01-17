function [L_imp] = mp_loopshape_s3_ns_pm45(f_co,varargin)

% Define ideal loop shape.
L_cas = cell(0,1);
L_cas{end+1,1} = zpk([],[0 0 0],1);
L_cas{end+1,1} = mp_ctrl_complex_zero(0.20*f_co,0.22,1);
L_cas{end+1,1} = mp_ctrl_lag(0.50*f_co,1.25,1);
L_cas{end+1,1} = mp_ctrl_lag(     f_co,1.25,1);
L_cas{end+1,1} = mp_ctrl_lag(2.00*f_co,1.05,1);
L_cas{end+1,1} = mp_ctrl_complex_zero(2.5*f_co,0.70,1)*...
                 mp_ctrl_complex_pole(4.3*f_co,0.70,1);
L_cas{end+1,1} = mp_ctrl_complex_pole(4.5*f_co,0.50,1);
L_cas{end+1,1} = mp_ctrl_complex_pole(4.5*f_co,0.50,1);

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
