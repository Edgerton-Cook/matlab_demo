function [h,dhdz] = expr_cstc(I,z,k,idx)

r = z(1:3);
r_h = feval(I.stc(idx).r_h,(k-1)/(I.K-1)*I.t_f);
l_c = I.stc(idx).l_c;
rho_g = I.stc(idx).rho_g;
rho_c = I.stc(idx).rho_c;
n_h_hat = I.stc(idx).n_h_hat;
N_h_hat = eye(3)-n_h_hat*n_h_hat';

g1 = n_h_hat'*(r_h-r)-l_c;
g2 = n_h_hat'*(r-r_h)-l_c;
if isnan(rho_g)
  g3 = -1;
else
  g3 = (r-r_h)'*(N_h_hat'*N_h_hat)*(r-r_h)-rho_g^2;
end
if (rho_c > 0)
  c1 = (r-r_h)'*(N_h_hat'*N_h_hat)*(r-r_h)-rho_c^2;
else
  c1 = N_h_hat*(r-r_h);
end

h1 = (-min(g1,0))*(-min(g2,0))*(-min(g3,0))*c1;

dg1dr = -n_h_hat';
dg2dr = n_h_hat';
if isnan(rho_g)
  dg3dr = zeros(1,3);
else
  dg3dr = 2*(r-r_h)'*(N_h_hat'*N_h_hat);
end
if (rho_c > 0)
  dc1dr = 2*(r-r_h)'*(N_h_hat'*N_h_hat);
else
  dc1dr = N_h_hat;
end

dg1dz = [dg1dr zeros(1,6)];
dg2dz = [dg2dr zeros(1,6)];
dg3dz = [dg3dr zeros(1,6)];
dc1dz = [dc1dr zeros(length(c1),6)];

h = h1;
dhdz = zeros(length(h),length(z));
if all([g1 g2 g3] < 0)
  dhdz = -c1*dg1dz*g2*g3 ...
		     -c1*g1*dg2dz*g3 ...
         -c1*g1*g2*dg3dz ...
		     -g1*g2*g3*dc1dz;
end