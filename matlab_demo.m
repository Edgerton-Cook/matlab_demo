% Edge's Matlab Demo Script
% Summer 2023
clc, clear all, close all;
global t_f v_max pwm_convert drone_ip;

%% Drone or Vehicle
vehicleType = 'droneType';        % 'droneType' will run the Drone demo, 'vehicleType' will run the Vehicle demo

switch vehicleType
    case 'droneType'

% Drone User Defined Parameters
        deg_freedom = '3';          % 3 = send 3dof traj, 2 = send 2dof traj
        has_drone_pos = true;       % true = need NEW drone initial condition, false = use pre-populated drone inital condition position
        has_obs_pos = true;         % true = ned NEW obsticle postions, false = use pre-populated locations for the hoops
        has_optimal_traj = false;   % true = solve NEW optimal trajectory using designated hoops, false = use pre-populated drone trajectory
        plot_optimal_traj = true;   % true = plot the trajectory, false = don't plot trajectory
        send_drone_traj = false;    % true = send trajectory to drone and re-populate the flight data, false = leave flight data alone
        plot_executed_traj = true;  % true = plot trajectory vs flown path
        
        
% Problem Statement
        obs_type = 0;           % keep as 0 for hoop until keep out zones work
        t_f = 15;               % total time for drone flight
        obs_des = [2, 3, 4];    % obsticles used
        out_drone_port = 6000;  % drone port
        drone_ip = 104;         % drone ip

        
    case 'vehicleType'

 % Vehicle User Defined Parameters
        do_state_transition = false;    % true = MATLAB will automatically state transition into Stadby mode
        do_legacy_trajectory = true;    % true = This will use the old type of trajectory generation for vehicle demo
        
 % Problem Statement 
        t_f = 10;                           % total time of vehicle trajectory
        v_max = 1;                          % maximum velocity (determined experimentally)
        pwm_convert = 1;                    % (determined experimentally)
        out_vehicle_port = 6000;            % vehicle port
        rover_ip = [11, 12, 13, 14, 15,...
                    16, 17, 18, 19, 10];

end

%% Set Pathing

in_struct.tf = 1;
in_struct.path_stc = strcat(pwd, '/');      % This currently doesn't do anything yet (NEED TO CHANGE)
cd(in_struct.path_stc) 
addpath(genpath('MainScripts'),genpath('mp_matlab'),genpath('data_demo'), genpath('autogen'),genpath('functions'),genpath('scripts'))

%% Run Script

switch vehicleType
    case 'droneType'

        DroneDemo

    case 'vehicleType'

        fprintf('Run Vehicle Demo?')
        keyboard
        VehicleDemo
end