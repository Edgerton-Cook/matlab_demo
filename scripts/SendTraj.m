%% Transmits the Trajectory to the drone

% This transmits the trajectory to the drone for flight
in_struct.O = O{end};
    
in_struct.file_stc = 'data_traj.mat';

switch deg_freedom
    case '2'

        mp_udp_client('0.0.0.0',in_struct.port,@()init_cmd(in_struct),@loop_cmd_2dof,@term)

    case '3'

        mp_udp_client('0.0.0.0',in_struct.port,@()init_cmd(in_struct),@loop_cmd_3dof,@term)
        
end
    
%% Extract mocap data for the drone
% This takes the drone flight and captures mocap data for it and saves it
in_struct.file_stc = 'flight_data.mat';
in_struct.tf = 5 + t_f; 
mp_udp_client('0.0.0.0',in_struct.port,@()init_meas(in_struct),@loop_meas,@term)