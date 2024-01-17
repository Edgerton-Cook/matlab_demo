function [ret] = mp_wrap_rad_180(angle_rad)

ret = mp_wrap_rad_360(angle_rad);
ret = ret-2.0*pi*(ret > pi);