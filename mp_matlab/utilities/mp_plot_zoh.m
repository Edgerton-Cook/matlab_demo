function [] = mp_plot_zoh(x,y,varargin)

n_x = length(x);
n_y = length(y);

x_zoh = zeros(2*n_x-1,1);
x_zoh(2*(1:n_x)-1) = x;
x_zoh(2*(1:n_x-1)) = x(2:end);

y_zoh = zeros(2*n_y-1,1);
y_zoh(2*(1:n_x)-1) = y;
y_zoh(2*(1:n_y-1)) = y(1:end-1);

plot(x_zoh,y_zoh,varargin{1:end})