function [C] = mp_ctrl_lead(f_c,width,order)

fz = f_c/width;
fp = f_c*width;
C = minreal(mp_ctrl_zero(fz,order)*mp_ctrl_pole(fp,order));