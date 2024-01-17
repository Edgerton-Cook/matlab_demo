function [C] = mp_ctrl_lag(f_c,width,order)

fp = f_c/width;
fz = f_c*width;
C = minreal(mp_ctrl_pole(fp,order)*mp_ctrl_zero(fz,order));