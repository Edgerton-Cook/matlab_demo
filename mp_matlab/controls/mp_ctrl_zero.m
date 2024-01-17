function [C] = mp_ctrl_zero(f_co,order)

w_co = 2*pi*f_co;
C = zpk(-w_co,[],1/w_co)^order;
