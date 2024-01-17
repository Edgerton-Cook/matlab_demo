function [yaw_deg] = mp_quat2yaw_deg(q)

yaw_deg = (180/pi)*mp_quat2yaw(q);