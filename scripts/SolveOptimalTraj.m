%% Optimal Trajectory Generation

% This code reads in the obsticle type, obstacle locations, final time,
% and the initial and final conditions, and generates an optinal trajectory
% through the use of scvx generation.

if obs_type == 0
%% Inputs
r2d = 180/pi;

% Call the newly parsed hoop data from each of the structs
data_hoop = {};
quat_hoop = [];
r_h = [];
ang1 = [];
ang2 = [];
for idx = 1:length(hoop_des)
    hoop = hoop_des(idx);
    filename = ['data_hoop', num2str(hoop), '.mat'];
    load(filename);
    data_hoop{idx} = data; clear data;
    r_h(:, idx) = NED2UEN(data_hoop{idx}.r_NED_meas(:,1));  % We get hoop position in NED but this algorithm solves them in UEN
    quat_hoop(:, idx) = data_hoop{idx}.quat_b_meas(:,end);
    ang1(idx) = r2d.* mp_quat2yaw(quat_hoop(:, idx));
    ang2(idx) = r2d.* mp_quat2pitch(quat_hoop(:, idx));
end

load('drone_initial_condition.mat');
data_drone = data; clear data;

% Convert drone to UEN frame
r_drone = NED2UEN(data_drone.r_NED_meas(:,1));

%% Run Cases
fprintf('Running case \n')
I = inputs(r_h, ang1, ang2, t_f, r_drone, hoop_des);
[O, T] = scvx(I);

save('data_demo/scvx_gen.mat','O')

end

if obs_type == 1
    fprint('Keep Out Zones')
end