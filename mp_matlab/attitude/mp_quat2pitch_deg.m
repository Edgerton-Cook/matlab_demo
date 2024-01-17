function [pitch_deg] = mp_quat2pitch_deg(q)

pitch_deg = (180/pi)*mp_quat2pitch(q);