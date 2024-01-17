function [] = draw_corridor(r,l,n_hat,rho,cline,cface,aface)

lwc = 1;
lwh = 2;
ms = 15;
thetas = linspace(0,360,100);

ring = [cosd(thetas); sind(thetas); zeros(size(thetas))];
n_hat_0 = [0 0 1]';

if (dot(n_hat,n_hat_0) < 0)
  n_hat = -n_hat;
end

ang = acosd(dot(n_hat_0,n_hat));
if (abs(ang) == 0)
  q = [1 0 0 0]';
else
  m_vec = cross(n_hat_0,n_hat);
  m_hat = m_vec/norm(m_vec,2);
  q = [cosd(ang/2) m_hat'*sind(ang/2)]';
end
  
q0 = q(1);
q1 = q(2);
q2 = q(3);
q3 = q(4);

R = zeros(3);
R(1,1) = 1-2*(q2^2+q3^2);
R(1,2) = 2*(q1*q2+q0*q3);
R(1,3) = 2*(q1*q3-q0*q2);
R(2,1) = 2*(q1*q2-q0*q3);
R(2,2) = 1-2*(q1^2+q3^2);
R(2,3) = 2*(q2*q3+q0*q1);
R(3,1) = 2*(q1*q3+q0*q2);
R(3,2) = 2*(q2*q3-q0*q1);
R(3,3) = 1-2*(q1^2+q2^2);

ring1 = R'*(  0*ring+l*n_hat_0)+r;
ring2 = R'*(rho*ring+l*n_hat_0)+r;
ring3 = R'*(rho*ring-l*n_hat_0)+r;
ring4 = R'*(  0*ring-l*n_hat_0)+r;

if (l > 0)
  surf([ring1(2,:); ring2(2,:); ring3(2,:); ring4(2,:)], ...
       [ring1(3,:); ring2(3,:); ring3(3,:); ring4(3,:)], ...
       [ring1(1,:); ring2(1,:); ring3(1,:); ring4(1,:)], ...
       'facealpha',aface,'facecolor',cface,'linestyle','none')
  plot3(ring2(2,:),ring2(3,:),ring2(1,:), ...
    'color',cline,'linewidth',lwc,'linestyle','-')
  plot3(ring3(2,:),ring3(3,:),ring3(1,:), ...
    'color',cline,'linewidth',lwc,'linestyle','-')
else
  plot3(ring1(2,1),ring1(3,1),ring1(1,1), ...
    'color',cline,'marker','.','markersize',ms)
  plot3(ring2(2,:),ring2(3,:),ring2(1,:), ...
    'color',cline,'linewidth',lwh,'linestyle','-')
end
