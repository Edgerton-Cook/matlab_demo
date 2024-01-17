function [R] = rot(a1,a2)

R1 = [ 1         0         0
       0         cosd(a1)  sind(a1)
       0        -sind(a1)  cosd(a1)];
R2 = [ cosd(a2)  0        -sind(a2)
       0         1         0  
       sind(a2)  0         cosd(a2)];
R = R1*R2';
