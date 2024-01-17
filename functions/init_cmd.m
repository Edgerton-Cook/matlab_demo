function [data] = init_cmd(inputs)
global drone_ip;

    data = struct;
    
    %drone data address
    data.ip = num2str(drone_ip);
    
    data.Q.time = inputs.O.t;
    data.Q.r = UEN2NED(inputs.O.r);
    data.Q.v = UEN2NED(inputs.O.v);
    data.Q.accl = UEN2NED(inputs.O.accl) + [0; 0; 9.81];
    data.global_time = 0; 
    
    %for loading and saving data - change this path!
    filepath = inputs.path_stc;
    data.output_file_name = strcat(filepath,'data_demo\',inputs.file_stc);
    data.port = inputs.port;
    
    %initialize time values
    data.counter = 0; %loop counter   
end