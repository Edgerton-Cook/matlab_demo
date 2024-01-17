function [R] = mp_R2(x)

R = [cos(x) 0 -sin(x)
     0      1  0
     sin(x) 0  cos(x)];