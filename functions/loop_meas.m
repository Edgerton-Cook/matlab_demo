function [data,outgoing,run_loop] = loop_meas(data,incoming)
    %measure delay to global time for first loop call
    if data.counter == 1
        data.delay = data.global_time ;
    end
    outgoing = mp_datagram_t.empty;


    % read mocap data
    mocap_data_received = false;
    for i=1:length(incoming)
        if ~isempty(incoming(i).buffer)
            idx = 1;
            mocap = autogen_mocap_data_t;
            mocap.topic = autogen_topic_mocap_data_t.UNDEFINED;
            [success,idx] = mocap.deserialize(incoming(i).buffer,idx);

            if (success)
%                 fprintf('| mocap | %08d',mocap.ts)
                mocap_data_received = true;
            else
%                 fprintf('|       |')
            end

%             fprintf('\n')
        end
    end
    
    if (mocap_data_received)
        %% INCREMENT MEASUREMENT COUNTER
        data.meas_counter = data.meas_counter+1;
        
        % record measured time
        data.t_meas(data.meas_counter) = data.global_time - data.delay;

        % record measured data
        data.r_NED_meas(:, data.meas_counter) = mocap.pos_ned.mat;
        data.quat_b_meas(:, data.meas_counter) = mp_quat_rectify(mocap.q_i2b.mat);
    end
    
    % increment counter
    data.counter = data.counter+1;
    
%     fprintf('Global time is %f \n\n',data.global_time)
    
    % exit loop at final time
    if data.global_time <= data.tf + data.delay 
        run_loop = true; %continue
    else
        fprintf('Closing\n')
        run_loop = false; %exit
    end
end