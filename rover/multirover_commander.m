clear
clc

%README: Update the filepath in line 7 and line 20.
%To search for other important instructions, search for the keyword "README" 
%   in the comments below.

%adding all subfolders to path - README change this path!
cd 'C:\Users\Skye Mceowen\Dropbox\mikipilot_rovers'
matlab_path = genpath('matlab');
addpath(matlab_path)
autogen_path = genpath('autogen\matlab');
addpath(autogen_path)
cd 'matlab\'

mp_udp_client('0.0.0.0',7000,@()init(),@loop,@term)

function [data] = init()
    data = struct;
    
    %for loading and saving data - change this path!
    filepath = 'C:\Users\Skye Mceowen\Dropbox\mikipilot_rovers\matlab\rovers\data\'; 
    data.output_file_name = strcat(filepath,'test1_data.mat');
    
    %integrators
    data.f_int = 0; 
    data.s_int = 0;
    data.h_int = 0;
    
    %initialize time values
    data.counter = 0; %loop counter
    data.meas_counter = 0; %received measurements counter
    data.ms = .001;
    data.global_time = 0; 
    data.tf = 10; %final time
    data.delay = 0; %initialized to zero, measured at beginning of loop
    data.sampling_time = .005;
    
    %initialize multirover values
    data.origin = [0; 0; 0]; 
    data.num_rovers = 10;   %specify the number of rovers in swarm
    data.initial_cond = {}; %cell array of rover initial condtions
    
    for i = 1:data.num_rovers
        %generate rover IP addresses for each rover in swarm
        data.ip_vec{i} = num2str(110 + i);  
    end
    
    %Generate reference signal [X,Y,theta] at each time
    %   where (X,Y) indiciate position and theta indicates heading
    data.t_ref = []; %for use with time-varying reference signals
    data.ref_signals = {[0;0;0],... rover 1 trajectory 
                        [-1;0;0],...
                        [-1.5;0;0],...
                        [-2;0;0],...
                        [-2.5;0;0],... 
                        [1;0;0],... 
                        [1.5;0;0],... 
                        [2;0;0],... 
                        [2.5;0;0],... 
                        [3;0;0]}; %rover n trajectory
    %{ 
        README: 
        Reference signal generation shown here is intended to be modified.
        This placeholder merely uses a simple static reference signal for 
            each rover to show the structure. It is assumed that each cell
            in the ref_signals array contains a trajectory for a
            corresponding rover. Within each cell, each column vector is a
            single waypoint in the trajectory. The first row in each column
            vector contains X-position, the second row contains Y-position,
            and the third row contains angle theta (heading). 
                        
        If instead this variable were used to store a pregenerated, 
            time-varying trajectory for m corresponding times, each cell in 
            the ref_signal array would contain m column vectors. 
            This could then be used as a look-up table later on in the main 
            loop to interpolate the appropriate [X; Y; theta] command to 
            each rover at the time the command is sent. In this case, it
            might also be helpful for the user to initialize and track the
            actual times that the commands were sent within the loop, as
            well as the actual corresponding reference commands sent via
            interpolation from the lookup table. In this case, there would
            be two sets of references times and state vectors; the look-up
            table values and the interpolated values used.
                        
        Another example of how to generate trajectories in real-time would 
            be to instead use a function or algorithm to generate a new
            command to each rover for each iteration of the main loop. This
            script has the ability to pass in the approximate current time,
            and the current measured stat to any function you provide.
             
        e.g.:
        load('C:\ ... \mikipilot_rovers\matlab\rovers\data\ref_file.mat') 
    %}
    
    %initialize plant parameters
    data.max_vel = 1; %m/s, determine experimentally
    data.pwm_conv = 1; %determine experimentally
    
    %intialize measurement vectors (to store mocap data)
    data.t_meas = [];  
    data.X_meas = [];
    data.Y_meas = [];
    data.theta_meas = [];
    data.errors = [];
    
    %{
        README:
        This init() function creates the structure "data". It also
        initializes and defines all necessary variables for use in the main
        loop function loop(). Any variables needed for trajectory generated
        or measured-value storage for post-processing must be contained
        within the structure "data", or it will otherwise be deleted.
    %}

end

function [data,outgoing,run_loop] = loop(data,incoming)
    %determine all rover destination IP addresses
    for rovNum = 1:data.num_rovers
       dest_ip{rovNum} = strcat('192.168.1.',data.ip_vec{rovNum});
    end
    dest_port = 6000; % rover/autopilot port

    %initialize heartbeat
    heartbeat = autogen_heartbeat_t;
    heartbeat.request_ownership = true;
    heartbeat.emergency_shutdown = false;

    %initialize subscriptions
    subscriptions = autogen_cm_subscriptions_t;
    subscriptions.telemetry_rate = 0;
    subscriptions.mpu6000_meas_data_rate = 0;
    subscriptions.pca9685_cmd_data_rate = 0;

    %read mocap data
    mocap_data_received = false;
    for i=1:length(incoming)
        if ~isempty(incoming(i).buffer)
                idx = 1;
                %% READ TELEM DATA
                telemetry = autogen_telemetry_t;
                telemetry.topic = autogen_topic_telemetry_t.UNDEFINED;
                [success,idx] = telemetry.deserialize(incoming(i).buffer,idx);
            if (success)
                fprintf('| telemetry |')
            else
                fprintf('|           |')
            end
            %% READ MOCAP DATA
            mocap = autogen_mocap_data_t;
            mocap.topic = autogen_topic_mocap_data_t.UNDEFINED;
            [success,idx] = mocap.deserialize(incoming(i).buffer,idx);

            if (success)
                fprintf('| mocap | %08d',mocap.ts)
                mocap_data_received = true;
            else
                fprintf('|       |')
            end

            fprintf('\n')
        end
    end

    
    %for first 50 loop calls, send rover into Run and Safety modes
    if (data.counter <= 50)
        rcontrol = autogen_rcontrol_cmd_t;
        rcontrol.fm_trans_cmd.state = autogen_state_fm_trans_cmd_t.RUN;
        rcontrol.mode.state = autogen_state_rcontrol_mode_t.SAFETIED;
        rcontrol.ch.mat = zeros(3,1);
        
        %Send data to rovers
        outgoing = mp_datagram_t.empty;
        for rovNum = 1:data.num_rovers
            if (mod(data.counter,1) == 0)
                outgoing(end+1).ip = dest_ip{rovNum};
                outgoing(end).port = dest_port;
                outgoing(end).buffer = heartbeat.serialize(outgoing(end).buffer,1);

                outgoing(end+1).ip = dest_ip{rovNum};
                outgoing(end).port = dest_port;
                outgoing(end).buffer = subscriptions.serialize(outgoing(end).buffer,1);

                if (mocap_data_received)
                  outgoing(end+1).ip = dest_ip{rovNum};
                  outgoing(end).port = dest_port;
                  outgoing(end).buffer = rcontrol.serialize(outgoing(end).buffer,1);
                end
            end
        end
        
    %for the next 50 loop calls, send rover into Standby mode
    elseif (50 < data.counter)&&(data.counter <= 100)
        rcontrol = autogen_rcontrol_cmd_t;
        rcontrol.fm_trans_cmd.state = autogen_state_fm_trans_cmd_t.NOTHING;
        rcontrol.mode.state = autogen_state_rcontrol_mode_t.STANDBY;
        rcontrol.ch.mat = zeros(3,1);  
        
        %send data to rovers
        outgoing = mp_datagram_t.empty;
        for rovNum = 1:data.num_rovers
            if (mod(data.counter,1) == 0)
                outgoing(end+1).ip = dest_ip{rovNum};
                outgoing(end).port = dest_port;
                outgoing(end).buffer = heartbeat.serialize(outgoing(end).buffer,1);

                outgoing(end+1).ip = dest_ip{rovNum};
                outgoing(end).port = dest_port;
                outgoing(end).buffer = subscriptions.serialize(outgoing(end).buffer,1);

                if (mocap_data_received)
                  outgoing(end+1).ip = dest_ip{rovNum};
                  outgoing(end).port = dest_port;
                  outgoing(end).buffer = rcontrol.serialize(outgoing(end).buffer,1);
                end
            end
        end
        
    %% BEGIN THE MAIN LOOP
    %for rest of loop calls, send trajectory to rover (in closed-loop mode)
    elseif (100 < data.counter)
                
    %% FORMAT rcontrol
    rcontrol = autogen_rcontrol_cmd_t;
    rcontrol.fm_trans_cmd.state = autogen_state_fm_trans_cmd_t.NOTHING;


    %% DELAY
    %measure delay to global time for first loop call
    if data.counter == 101
        data.delay = data.global_time 
    end

    if (mocap_data_received)
        %% INCREMENT MEASUREMENT COUNTER
        data.meas_counter = data.meas_counter+1;
        
        %Record measured data
        data.t_meas(data.meas_counter) = data.global_time - data.delay;

        data.X_meas(data.meas_counter) = mocap.pos_ned.mat(1);
        data.Y_meas(data.meas_counter) = mocap.pos_ned.mat(2);
        data.theta_meas(data.meas_counter) = mp_quat2yaw( ...
                                        mp_quat_rectify(mocap.q_i2b.mat));
        state_meas = [data.X_meas(data.meas_counter); data.Y_meas(data.meas_counter); data.theta_meas(data.meas_counter)];
    end
    
    
    %Generate reference trajectory, format message, and transmit to rovers
    outgoing = mp_datagram_t.empty;
    for rovNum = 1:data.num_rovers
        %% Trajectory command
        ref_vec = data.ref_signals{1,rovNum};  
        
        %{
            README: 
            This is where you will integrate the appropriate reference
            signal as a function or lookup table. Please see lines 60-90
            within the init() function above.
        
            The reference signal for each rover is sent via WiFi to the
            appropriate controller computer for each iteration of this main
            loop function. This loop repeats until the current time,
            specified by "data.global_time - data.delay", is greater than 
            or equal to the final time, specified by data.tf. Because the
            main loop is itself a function called iteratively by the parent
            function "mp_udp_client", every value used must be contained 
            within the structure "data", and initialized within the init() 
            function.
        %}
    

        %% CLOSED LOOP CONTROL
        %%{
        rcontrol.mode.state = autogen_state_rcontrol_mode_t.CLOSED_LOOP_POS;

        %send reference command to vehicle
        rcontrol.ch.mat = ...
          [ref_vec(1);... % north position [m]
           ref_vec(2);... % east position [m]
           ref_vec(3)]; % heading [rad];
        %}
        if (mod(data.counter,1) == 0)
            outgoing(end+1).ip = dest_ip{rovNum};
            outgoing(end).port = dest_port;
            outgoing(end).buffer = heartbeat.serialize(outgoing(end).buffer,1);

            outgoing(end+1).ip = dest_ip{rovNum};
            outgoing(end).port = dest_port;
            outgoing(end).buffer = subscriptions.serialize(outgoing(end).buffer,1);

            if (mocap_data_received)
              outgoing(end+1).ip = dest_ip{rovNum};
              outgoing(end).port = dest_port;
              outgoing(end).buffer = rcontrol.serialize(outgoing(end).buffer,1);
            end
        end
    end
    end
    
    %% INCREMENT COUNTER
    data.counter = data.counter+1;

    fprintf('Global time is %f \n\n',data.global_time)
      

    %% EXIT LOOP AT FINAL TIME
    if data.global_time <= data.tf + data.delay %data.meas_counter <= length(data.ref_vec_rover1) 
        run_loop = true; %continue
    else
        %shut off rover
  
        fprintf('Closing\n')
        run_loop = false; %exit
    end

    mp_pause(2) %nominal
end %function loop


function [] = term(data)
    fprintf('Terminated!\n')
    if ~isempty(data.output_file_name)
        save(data.output_file_name,'data')
    end
    
    %{
        README:
        The term() function stores the values within structure "data". All
        other variables in the workspace are permanently deleted after this
        multirover script terminates.
    %}
end
