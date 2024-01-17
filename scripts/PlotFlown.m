%% Plot Flight vs Trajectory

% This plots the flown path by the drone ontop of the previously solved for
% optimal trajectory.

scvx_gen_mat = load('scvx_gen.mat');

t_f = scvx_gen_mat.O{end}.t(end);
Op = scvx_gen_mat.O;

flight_data_mat = load('flight_data.mat');
r_flight = NED2UEN(flight_data_mat.data.r_NED_meas);

%% Inputs

r2d = 180/pi;

data_hoop = {};
quat_hoop = [];
r_h = [];
ang1 = [];
ang2 = [];

for idx = 1:length(hoop_des)
    hoop = hoop_des(idx);
    filename = ['data_hoop', num2str(hoop), '.mat'];
    load(filename);
    data_hoop{idx} = data; clear data; %#ok<*SAGROW>
    r_h(:, idx) = NED2UEN(data_hoop{idx}.r_NED_meas(:,1));
    quat_hoop(:, idx) = data_hoop{idx}.quat_b_meas(:,end);
    ang1(idx) = r2d.* mp_quat2yaw(quat_hoop(:, idx));
    ang2(idx) = r2d.* mp_quat2pitch(quat_hoop(:, idx));
end

load('drone_initial_condition.mat');
data_drone = data; clear data;

r_drone = NED2UEN(data_drone.r_NED_meas(:,1));

Ip = inputs(r_h, ang1, ang2, t_f, r_drone, hoop_des);

%% Plot trajectory

% initialize figure
fig_hdl = figure(1); clf(1),hold on,grid on
set(fig_hdl, 'Renderer', 'painters');
set(0,'defaulttextinterpreter','latex')

ax = gca;
ax.GridColor = [75, 75, 75]/100;

% plot cases
I = Ip;
O = Op;
nodes = plot_traj(I, O);
hold on
traj = plot3(r_flight(2, :), r_flight(3, :), r_flight(1, :), 'k', 'LineWidth', 2);
hold on

leg = legend([nodes, traj], 'Guidance', 'Closed-loop', 'location', 'northeast');

% set axis view, scales, and limits for figure 1
axis equal

set(gca,'ylim',[-3 3.5],'ytick',-10:1:10)
set(gca,'zlim',[0 2.0],'ztick',-10:1:10)

set(gca,'xlim',[-2 2],'xtick',-10:1:10)

% save iso-view
view(50,27.5)
set(1,'units','inches')
set(1,'papersize',[11.25 7.5])


set(leg, 'visible', 'off')

set(gca,'xlim',[-1.5 1.5],'xtick',-10:1:10)

% save top-view
view(0,90)
set(1,'units','inches')
set(1,'papersize',[4.25 8.125])
