function [q_conj] = mp_quat_conjugate(q)

q_conj = [q(1,:)' -q(2:4,:)']';
