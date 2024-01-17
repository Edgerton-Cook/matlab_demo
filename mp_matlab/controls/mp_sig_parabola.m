function [s] = mp_sig_parabola(t1,t2,t)

s = (t >= t1).*(t-t1).^2-(t >= t2).*(t-t2).^2;
s = s/(t2-t1)^2;
