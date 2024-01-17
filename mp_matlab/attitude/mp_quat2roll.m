function [roll] = mp_quat2roll(q)

q0 = q(1,:);
q1 = q(2,:);
q2 = q(3,:);
q3 = q(4,:);

C_n2b_23 = 2*(q2.*q3+q0.*q1);
C_n2b_33 = 1-2*(q1.*q1+q2.*q2);

roll = atan2(C_n2b_23,C_n2b_33);