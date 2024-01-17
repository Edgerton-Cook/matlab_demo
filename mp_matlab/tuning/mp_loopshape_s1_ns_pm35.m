function [L_imp] = mp_loopshape_s1_ns_pm35(f_co,varargin)

% Define ideal loop shape.
dsl = 0.55;
fsl = 0.10;
dsh = 0.24;
fsh = 0.205;
L_cas = cell(0,1);

% Integrators.
L_cas{end+1,1} = zpk([],0,1);

% Low-frequency Bode step.
L_cas{end+1,1} = tf([1 0],1)*mp_ctrl_zero(fsh*f_co,1) ...
            *mp_ctrl_complex_pole(fsl*f_co,dsl,1);
L_cas{end+1,1} = mp_ctrl_complex_zero(fsh*f_co,dsh,1) ...
            *mp_ctrl_complex_pole(fsl*f_co,dsl,1);
L_cas{end+1,1} = mp_ctrl_complex_zero(fsh*f_co,dsh,1) ...
            *mp_ctrl_complex_pole(fsl*f_co,dsl,1);

L_cas{end+1,1} = mp_ctrl_lag(0.50*f_co,1.40,1);
L_cas{end+1,1} = mp_ctrl_lag(     f_co,1.40,1);
L_cas{end+1,1} = mp_ctrl_lag(2.00*f_co,1.10,1);

% High-frequency Bode step.
L_cas{end+1,1} = mp_ctrl_complex_zero(2.50*f_co,0.65,1)*...
             mp_ctrl_complex_pole(4.3*f_co,0.65,1);
L_cas{end+1,1} = mp_ctrl_complex_pole(4.3*f_co,0.45,1);
L_cas{end+1,1} = mp_ctrl_complex_pole(4.3*f_co,0.45,1);

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
