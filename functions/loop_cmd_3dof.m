function [data,outgoing,run_loop] = loop_cmd_3dof(data, incoming)
    if (data.counter==0)
        dest_ip = strcat('192.168.1.',data.ip);
        dest_port = 6000; % rover/autopilot port
        outgoing = mp_datagram_t.empty;
        
        outgoing(end+1).ip = dest_ip;
        outgoing(end).port = dest_port;
        
        traj3dof_quad = autogen_traj3dof_t;
%         traj3dof_quad.ts = 
%         traj3dof_quad.epoch = 
        K = length(data.Q.r);
        traj3dof_quad.K = K;
%         traj3dof_quad.loop = 0;
        traj3dof_quad.time.mat(:,1:K) = data.Q.time;        
        traj3dof_quad.pos_ned.mat(:,1:K) =  data.Q.r;
        traj3dof_quad.vel_ned.mat(:,1:K) =  data.Q.v;
        traj3dof_quad.accl_ned.mat(:,1:K) = data.Q.accl;
     
        outgoing(end).buffer = traj3dof_quad.serialize(outgoing(end).buffer,1);
        fprintf('Sent A 3DOF Traj m8 \n')
    end

    run_loop = false;
end