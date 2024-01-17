function [S] = mp_skew4(x)

x0 = x(1);
x1 = x(2);
x2 = x(3);

S = [ 0 -x0 -x1 -x2
     x0   0  x2 -x1
     x1 -x2   0  x0
     x2  x1 -x0   0];