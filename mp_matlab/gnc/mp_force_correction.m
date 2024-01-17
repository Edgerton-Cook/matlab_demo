function [f_adjusted] = mp_force_correction(f_nominal, ...
                                            q_i2b,q_i2d,cone_angle)

q_d2b = mp_quat_rectify(mp_quat_mult(mp_quat_conjugate(q_i2d),q_i2b));
C_d2b = mp_quat2dcm(q_d2b);

zd_d = [0 0 1]';
zb_d = C_d2b'*[0 0 1]';
tilt_error = acos(dot(zb_d,zd_d));

theta_arg = min(tilt_error,cone_angle);
theta_arg = max(theta_arg,-cone_angle);
f_a = f_nominal*cos(tilt_error)/cos(theta_arg)^2;
f_adjusted = max(0,f_a);
