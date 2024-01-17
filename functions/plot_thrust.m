function [] = plot_thrust(I,O,varargin)

% plot formatting parameters.
fs = 20; % font size
lw1 = 2; % data line width
lw2 = 1; % bounds line width
ms = 20; % marker size

if (nargin == 2)
  c1 = 'r';
  c2 = 'b';
  i = length(O);
elseif (nargin == 3)
  c1 = varargin{1};
  c2 = varargin{1};
  i = length(O);
elseif (nargin == 4)
  c1 = varargin{1};
  c2 = varargin{1};
  i = varargin{2};
end

% select figure
figure(2)

plot([-1e2 1e2],I.u_min*[1 1], ...
  'color','k', ...
  'linewidth',lw1,'linestyle','-', ...
  'marker','none','markersize',ms)
plot([-1e2 1e2],I.u_max*[1 1], ...
  'color','k', ...
  'linewidth',lw1,'linestyle','-', ...
  'marker','none','markersize',ms)
plot(O{i}.t,sum(O{i}.u.^2,1).^0.5, ...
  'color',c1, ...
  'linewidth',lw2,'linestyle','-', ...
  'marker','.','markersize',ms)
plot(O{i}.t,O{i}.s, ...
  'color',c2, ...
  'linewidth',lw2,'linestyle','none', ...
  'marker','o','markersize',ms)

xlabel('Time [s]','fontsize',fs)
ylabel('Thrust [N]','fontsize',fs)
set(gca,'fontsize',fs)

