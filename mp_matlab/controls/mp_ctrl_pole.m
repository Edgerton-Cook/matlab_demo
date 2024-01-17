function [C] = mp_ctrl_pole(f_co,order)

w_co = 2*pi*f_co;
C = zpk([],-w_co,w_co)^order;
