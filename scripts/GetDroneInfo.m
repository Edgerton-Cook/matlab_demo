%% Pulls Drone Mocap Data

% This will pull the mocap data for the drones current position and save it
% as the initial condition for the drone trajectory.

in_drone_port = drone_ip + 7000;
in_struct.port = in_drone_port;

if ~has_drone_pos
    in_struct.file_stc = 'drone_initial_condition.mat';
    mp_udp_client('0.0.0.0',in_struct.port,@()init_meas(in_struct),@loop_meas,@term)
end