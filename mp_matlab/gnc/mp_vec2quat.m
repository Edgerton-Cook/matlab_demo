function [q_i2r] = mp_vec2quat(pnt_vec_i,clock_angle)

pnt_vec_hat_i = pnt_vec_i./sum(pnt_vec_i.^2,1).^0.5;

z = [0 0 -1]';
cos_g2 = (0.5*(1+z'*pnt_vec_hat_i)).^0.5;
n_hat_sin_g2 = 0.5*mp_skew3(z)*pnt_vec_hat_i./cos_g2;
q_i2p = [cos_g2; n_hat_sin_g2];

q_p2r = [cos(0.5*clock_angle); [0 0 1]'*sin(0.5*clock_angle)];
q_i2r = mp_quat_rectify(mp_quat_mult(q_i2p,q_p2r));
