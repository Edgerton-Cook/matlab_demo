function [R] = mp_R1(x)

R = [1  0      0
     0  cos(x) sin(x)
     0 -sin(x) cos(x)];