function [roll_deg] = mp_quat2roll_deg(q)

roll_deg = (180/pi)*mp_quat2roll(q);