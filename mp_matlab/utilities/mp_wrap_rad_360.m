function [ret] = mp_wrap_rad_360(angle_rad)

two_pi = 2.0*pi;
revs = floor(abs(angle_rad)/two_pi);
angle_sign = mp_sign(angle_rad);
ret = angle_rad-two_pi*angle_sign.*revs-pi*(angle_sign-1.0);
