function [q_normalized] = mp_quat_normalize(q)

q_normalized = q/norm(q);
