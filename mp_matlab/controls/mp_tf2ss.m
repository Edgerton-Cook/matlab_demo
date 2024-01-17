function [T_sys] = mp_tf2ss(T)

[A_T,B_T,C_T,D_T] = tf2ss(T.num{1},T.den{1});
T_sys = ss(A_T,B_T,C_T,D_T);
