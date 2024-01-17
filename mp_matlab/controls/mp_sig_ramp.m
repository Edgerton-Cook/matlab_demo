function [s] = mp_sig_ramp(t1,t2,t)

s = (t >= t1).*(t-t1)-(t >= t2).*(t-t2);
s = s/(t2-t1);
