function [T_zpk] = mp_tf2zpk(T)

T_zpk = tf2zpk(T.num{1},T.den{1});
