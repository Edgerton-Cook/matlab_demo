function [L_imp] = mp_loopshape_bessel(f_Hz,order,varargin)

% Define ideal loop shape.
[N_bessel,D_bessel] = besself(order,2*pi*f_Hz);
L_ideal = zpk(tf(N_bessel,D_bessel));

% Compute TF of implemented portion of the loop.
if (nargin == 2)
  L_imp = L_ideal;
elseif (nargin == 3)
	L_comp = varargin{1};
  L_imp = minreal(L_ideal/L_comp);
end
