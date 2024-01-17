function [nodes] = plot_traj(I,O,varargin)

% plot formatting parameters.
fs = 20; % font size
lw = 2; % line width
ms = 20; % marker size
f_u = 0.02; % thrust plotting factor [m/N]
l_c_plot = 0.10; % corridor half-length for plotting [m]
rho_g_plot = 0.35; % trigger corridor radius for plotting [m]
rho_c_plot = 0.10; % constraint corridor raidus for plotting [m]
rho_h_plot = 0.20; % hoop radius for plotting [m]

% time instance of hoop (assumes stationary hoop)
k_plot = 1;
t_plot = (k_plot-1)/(I.K-1)*I.t_f;

if (nargin == 2)
  traj_color = [0 0.8 0];
  node_color = [0 0 1];
  thrust_color = NaN(1,3);%[1 0 0];
  i = length(O);
elseif (nargin == 3)
  traj_color = varargin{1};
  node_color = varargin{1};
  thrust_color = NaN(1,3);
  i = length(O);
elseif (nargin == 4)
  traj_color = varargin{1};
  node_color = varargin{1};
  thrust_color = NaN(1,3);
  i = varargin{2};
end

% select figure
figure(1)

% plot thrust vectors
for k=1:I.K
  if all(~isnan(thrust_color))
    plot3(O{i}.r(2,k)+f_u*[0 O{i}.u(2,k)], ...
          O{i}.r(3,k)+f_u*[0 O{i}.u(3,k)], ...
          O{i}.r(1,k)+f_u*[0 O{i}.u(1,k)], ...
          'color',thrust_color, ...
          'linewidth',lw,'linestyle','-', ...
          'markersize',ms,'marker','none')
  end
end

% plot temporal nodes
nodes = plot3(O{i}.r(2,:), ...
      O{i}.r(3,:), ...
      O{i}.r(1,:), ...
      'color','g', ...
      'linewidth',lw,'linestyle','-', ...
      'markersize',ms,'marker','.','MarkerEdgeColor', node_color);

  
for i=1:length(I.stc)
    % plot trigger corridor
    draw_corridor(I.stc(i).r_h(t_plot), ...
                  l_c_plot, ...
                  I.stc(i).n_h_hat, ...
                  rho_g_plot,'k','r',0.15);

    % plot constraint corridor
    draw_corridor(I.stc(i).r_h(t_plot), ...
                  l_c_plot+0.01, ...
                  I.stc(i).n_h_hat, ...
                  rho_c_plot,'k','b',0.25);

    % plot hoop
    draw_corridor(I.stc(i).r_h(t_plot), ...
                  0, ...
                  I.stc(i).n_h_hat, ...
                  rho_h_plot,'k','k',0.0);
end

xlabel('East Position [m]','fontsize',fs)
ylabel('North Position [m]','fontsize',fs)
zlabel('Altitude [m]','fontsize',fs)
set(gca,'fontsize',fs)