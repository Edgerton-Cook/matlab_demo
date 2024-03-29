function [C] = mp_quat2dcm(q)

q0 = q(1);
q1 = q(2);
q2 = q(3);
q3 = q(4);

C = zeros(3);
C(1,1) = 1-2*(q2^2+q3^2);
C(1,2) = 2*(q1*q2+q0*q3);
C(1,3) = 2*(q1*q3-q0*q2);
C(2,1) = 2*(q1*q2-q0*q3);
C(2,2) = 1-2*(q1^2+q3^2);
C(2,3) = 2*(q2*q3+q0*q1);
C(3,1) = 2*(q1*q3+q0*q2);
C(3,2) = 2*(q2*q3-q0*q1);
C(3,3) = 1-2*(q1^2+q2^2);