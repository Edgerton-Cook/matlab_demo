function [data,outgoing,run_loop] = loop_cmd_2dof(data, incoming)
    if (data.counter==0)
        dest_ip = strcat('192.168.1.',data.ip);
        dest_port = 6000; % rover/autopilot port
        outgoing = mp_datagram_t.empty;
        
        outgoing(end+1).ip = dest_ip;
        outgoing(end).port = dest_port;
        
        traj2dof_quad = autogen_traj2dof_t;
%         traj2dof_quad.ts = 
%         traj2dof_quad.epoch = 
        K = length(data.Q.r);
        traj2dof_quad.K = K;
%         traj2dof_quad.loop = 0;
        traj2dof_quad.time.mat(:,1:K) = data.Q.time(1:2,:);        
        traj2dof_quad.pos_ned.mat(:,1:K) =  data.Q.r(1:2,:);
        traj2dof_quad.vel_ned.mat(:,1:K) =  data.Q.v(1:2,:);
        traj2dof_quad.accl_ned.mat(:,1:K) = data.Q.accl(1:2,:);
     
        outgoing(end).buffer = traj2dof_quad.serialize(outgoing(end).buffer,1);
        fprintf('Sent A 2DOF Traj m8 \n')
    end

    run_loop = false;
end