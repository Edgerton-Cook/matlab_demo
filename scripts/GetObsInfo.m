%% Extracts Obsticle Information

% This will read in the obstacle type and save the corrosponding data about
% the obstacle in order for the data to be used in the scvx generation.

obs_port = 7000 + obs_des;

if obs_type == 0
    hoop_port = obs_port;
    hoop_des = obs_des;
        
    if ~has_obs_pos
            for idx = 1:length(hoop_des)
     
            hoop = hoop_des(idx);
        
            disp(hoop)
            disp(idx)
        
            in_struct.file_stc = ['data_hoop', num2str(hoop), '.mat'];
            in_struct.port = hoop_port(idx);
            mp_udp_client('0.0.0.0',in_struct.port,@()init_meas(in_struct),@loop_meas,@term)
        
        end
    end
    
elseif obs_type == 1
        keep_out_port = obs_port;
        keep_out_des = obs_des;
end
