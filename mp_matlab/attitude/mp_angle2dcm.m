function [C] = mp_angle2dcm(roll,pitch,yaw)

C = zeros(3,3);

sin_phi = sin(roll);
cos_phi = cos(roll);
sin_theta = sin(pitch);
cos_theta = cos(pitch);
sin_psi = sin(yaw);
cos_psi = cos(yaw);

C(1,1) = cos_theta*cos_psi;
C(1,2) = cos_theta*sin_psi;
C(1,3) = -sin_theta;
C(2,1) = sin_phi*sin_theta*cos_psi-cos_phi*sin_psi;
C(2,2) = sin_phi*sin_theta*sin_psi+cos_phi*cos_psi;
C(2,3) = sin_phi*cos_theta;
C(3,1) = cos_phi*sin_theta*cos_psi+sin_phi*sin_psi;
C(3,2) = cos_phi*sin_theta*sin_psi-sin_phi*cos_psi;
C(3,3) = cos_phi*cos_theta;