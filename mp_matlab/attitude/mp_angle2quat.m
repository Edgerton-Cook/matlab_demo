function [q] = mp_angle2quat(roll,pitch,yaw)

C = mp_angle2dcm(roll,pitch,yaw);

tr0 = 1+C(1,1)+C(2,2)+C(3,3);
tr1 = 1+C(1,1)-C(2,2)-C(3,3);
tr2 = 1-C(1,1)+C(2,2)-C(3,3);
tr3 = 1-C(1,1)-C(2,2)+C(3,3);

if ((tr0 >= tr1)&&(tr0 >= tr2)&&(tr0 >= tr3))
  S = 2*sqrt(tr0);
  S_inv = 1/S;
  
  q0 = 0.25*S;
  q1 = (C(2,3)-C(3,2))*S_inv;
  q2 = (C(3,1)-C(1,3))*S_inv;
  q3 = (C(1,2)-C(2,1))*S_inv;
elseif ((tr1 >= tr0)&&(tr1 >= tr2)&&(tr1 >= tr3))
  S = 2*sqrt(tr1);
  S_inv = 1/S;
  
  q0 = (C(2,3)-C(3,2))*S_inv;
  q1 = 0.25*S;
  q2 = (C(1,2)+C(2,1))*S_inv;
  q3 = (C(1,3)+C(3,1))*S_inv;
elseif ((tr2 >= tr0)&&(tr2 >= tr1)&&(tr2 >= tr3))
  S = 2*sqrt(tr2);
  S_inv = 1/S;
  
  q0 = (C(3,1)-C(1,3))*S_inv;
  q1 = (C(1,2)+C(2,1))*S_inv;
  q2 = 0.25*S;
  q3 = (C(2,3)+C(3,2))*S_inv;
else
  S = 2*sqrt(tr3);
  S_inv = 1/S;
  
  q0 = (C(1,2)-C(2,1))*S_inv;
  q1 = (C(1,3)+C(3,1))*S_inv;
  q2 = (C(2,3)+C(3,2))*S_inv;
  q3 = 0.25*S;
end

q = [q0 q1 q2 q3]';