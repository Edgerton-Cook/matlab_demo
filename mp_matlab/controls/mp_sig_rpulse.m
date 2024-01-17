function [s] = mp_sig_rpulse(t1,t2,t3,t4,t)

s = mp_sig_ramp(t1,t2,t)-mp_sig_ramp(t3,t4,t);
