function [s] = mp_sig_spulse(t1,t2,t)

s = mp_sig_step(t1,t)-mp_sig_step(t2,t);
