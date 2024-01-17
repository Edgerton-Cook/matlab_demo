function [omega_ff_b,tau_ff_b] = mp_att_correction(J_b, ...
                                                   q_i2r,omega_r,tau_r, ...
                                                   q_i2b,omega_b)

q_r2b = mp_quat_rectify(mp_quat_mult(mp_quat_conjugate(q_i2r),q_i2b));
C_r2b = mp_quat2dcm(q_r2b);

alpha_r = J_b\(tau_r-mp_skew3(omega_r)*J_b*omega_r);
alpha_b = C_r2b*alpha_r;

omega_ff_b = C_r2b*omega_r;
tau_ff_b = J_b*alpha_b+mp_skew3(omega_b)*J_b*omega_b;
