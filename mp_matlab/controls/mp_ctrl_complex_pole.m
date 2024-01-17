function [C] = mp_ctrl_complex_pole(f_n,zeta,order)

wn = 2*pi*f_n;
C = zpk([],-zeta*wn+wn*[sqrt(zeta^2-1) -sqrt(zeta^2-1)],wn^2)^order;
