function [y] = mp_saturation(u_min,u,u_max)

y = ((u_min <= u)&(u <= u_max)).*u+(u < u_min).*u_min+(u_max < u).*u_max;
