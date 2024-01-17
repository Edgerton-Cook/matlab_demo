function [yaw] = mp_quat2yaw(q)

q0 = q(1,:);
q1 = q(2,:);
q2 = q(3,:);
q3 = q(4,:);

C_n2b_11 = 1-2*(q2.*q2+q3.*q3);
C_n2b_12 = 2*(q1.*q2+q0.*q3);

yaw = atan2(C_n2b_12,C_n2b_11);