function [omega_sat] = mp_att_control(q_i2b,q_i2r, ...
                                      K_att,H_omega_fb_sat,mode)
  if isequal(mode,'naive')
    q_r2b = mp_quat_rectify(mp_quat_mult(mp_quat_conjugate(q_i2r),q_i2b));
    omega = -diag(K_att)*q_r2b(2:4);
  elseif isequal(mode,'prioritized')
    q_r2b = mp_quat_rectify(mp_quat_mult(mp_quat_conjugate(q_i2r),q_i2b));
    q_r2p = [q_r2b(1) 0 0 q_r2b(4)]'/norm([q_r2b(1) 0 0 q_r2b(4)]',2);
    q_p2b = mp_quat_rectify(mp_quat_mult(mp_quat_conjugate(q_r2p),q_r2b));
    omega = -diag(K_att)*(q_p2b(2:4)+q_r2p(2:4));
  end
  
  omega_xy = omega(1:2);
  omega_z = omega(3);
  
  omega_sat = zeros(3,1);
  omega_sat(1:2) = ...
    omega_xy/max(norm(H_omega_fb_sat(1:2,1:2)*omega_xy,2),1);
  omega_sat(3) = omega_z/max(abs(H_omega_fb_sat(3,3)*omega_z),1);
end
