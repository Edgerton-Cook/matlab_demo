function [q_rectified] = mp_quat_rectify(q)

q_rectified = mp_sign(q(1,:)).*q;
