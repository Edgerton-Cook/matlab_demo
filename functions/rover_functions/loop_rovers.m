function [data,outgoing,run_loop] = loop_rovers(data,incoming)
%{
This loop() function determines the IP addresses of all rover destinations,
    initializes data for the rovers, does the state transitioning for the
    rovers, and then runs a closed loop position trajectory for the rovers
    to follow. 
%}

global dest_ip dest_port;

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
% ~~ READ TELEM DATA ~~
            telemetry = autogen_telemetry_t;
            telemetry.topic = autogen_topic_telemetry_t.UNDEFINED;
            [success,idx] = telemetry.deserialize(incoming(i).buffer,idx);
        if (success)
            fprintf('| telemetry |')
        else
            fprintf('|           |')
        end
 % ~~ READ MOCAP DATA ~~
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
    
% ~~ Send data to rovers ~~
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
    
% ~~ BEGIN THE MAIN LOOP ~~
%for rest of loop calls, send trajectory to rover (in closed-loop mode)
elseif (100 < data.counter)
            
% ~~ FORMAT rcontrol ~~
rcontrol = autogen_rcontrol_cmd_t;
rcontrol.fm_trans_cmd.state = autogen_state_fm_trans_cmd_t.NOTHING;


% ~~ DELAY`~~
%measure delay to global time for first loop call
if data.counter == 101
    data.delay = data.global_time;
end

if (mocap_data_received)
% ~~ INCREMENT MEASUREMENT COUNTER ~~
    data.meas_counter = data.meas_counter+1;
    
    %record measured data
    data.t_meas(data.meas_counter) = data.global_time - data.delay;

    data.X_meas(data.meas_counter) = mocap.pos_ned.mat(1);
    data.Y_meas(data.meas_counter) = mocap.pos_ned.mat(2);
    data.theta_meas(data.meas_counter) = mp_quat2yaw( ...
                                    mp_quat_rectify(mocap.q_i2b.mat));
    state_meas = [data.X_meas(data.meas_counter); data.Y_meas(data.meas_counter); data.theta_meas(data.meas_counter)];
end


%generate reference trajectory, format message, and transmit to rovers
outgoing = mp_datagram_t.empty;
for rovNum = 1:data.num_rovers
% ~~ Trajectory command ~~
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


 % ~~ CLOSED LOOP CONTROL ~~
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

% ~~ INCREMENT COUNTER ~~
data.counter = data.counter+1;

fprintf('Global time is %f \n\n',data.global_time)
  

% ~~ EXIT LOOP AT FINAL TIME ~~
if data.global_time <= data.tf + data.delay %data.meas_counter <= length(data.ref_vec_rover1) 
    run_loop = true; %continue
else
    %shut off rover

    fprintf('Closing\n')
    run_loop = false; %exit
end

mp_pause(2) %nominal
end 