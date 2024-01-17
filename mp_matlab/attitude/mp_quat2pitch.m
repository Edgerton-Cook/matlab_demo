function [pitch] = mp_quat2pitch(q)

q0 = q(1,:);
q1 = q(2,:);
q2 = q(3,:);
q3 = q(4,:);

C_n2b_13 = 2*(q1.*q3-q0.*q2);
C_n2b_13_sat = mp_saturation(-1,C_n2b_13,1);

pitch = asin(-C_n2b_13_sat);
