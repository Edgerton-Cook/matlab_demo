function [data] = init_meas(inputs)
    data = struct;
    
    %for loading and saving data - change this path! -HOW???
    filepath = inputs.path_stc;
    data.output_file_name = strcat(filepath,'data_demo\',inputs.file_stc);
    data.port = inputs.port;
    
    %initialize time values
    data.counter = 0; %loop counter
    data.meas_counter = 0; %received measurements counter
    data.ms = .001;
    data.global_time = 0; 
    data.tf = inputs.tf; %final time
    data.delay = 0; %initialized to zero, measured at beginning of loop
    data.sampling_time = .005;
    
    %intialize measurement vectors (to store mocap data)
    data.t_meas = [];  
    data.r_NED_meas = [];
    data.quat_b_meas = [];
end