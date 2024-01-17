function [] = mp_udp_client(local_ip,local_port,fcn_init,fcn_loop,fcn_term)
  global data
  
  if ~isempty(instrfindall)
    fclose(instrfindall);
  end
  
  udp_socket = udp;
  set(udp_socket,'Name',['mp-' local_ip ':' num2str(local_port)], ...
                 'LocalPortMode','manual', ...
                 'LocalHost',local_ip, ...
                 'LocalPort',local_port, ...
                 'InputBufferSize',4096, ...
                 'OutputBufferSize',4096, ...
                 'ReadAsyncMode','continuous');
  fopen(udp_socket);
  flushinput(udp_socket);
	flushoutput(udp_socket);
	
  data = feval(fcn_init);
  run_loop = true;
  cleanup_obj = onCleanup(@()cleanup_fcn(fcn_term,udp_socket));
  
  while (run_loop)
    tic
    incoming = mp_datagram_t.empty;
    while (udp_socket.BytesAvailable > 0)
      incoming(end+1).ip = udp_socket.DatagramAddress; %#ok<AGROW>
      incoming(end).port = udp_socket.DatagramPort;
      incoming(end).buffer = uint8(fread(udp_socket,1,'uint8'));
    end
%     t_downlink = toc;
		
% 		tic
    [data,outgoing,run_loop] = feval(fcn_loop,data,incoming);
    t_parsing = toc;
		
% 		tic
		if ~isempty(outgoing)
      for i=1:length(outgoing)
        set(udp_socket,'RemoteHost',outgoing(i).ip, ...
                       'RemotePort',outgoing(i).port);
        fwrite(udp_socket,outgoing(i).buffer,'uint8');
      end
		end
		t_uplink = toc;
        data.global_time = data.global_time + t_uplink;
		
% 		fprintf('downlink: %07d [us], ',round(t_downlink*1e6))
% 		fprintf('uplink: %07d [us], ',round(t_uplink*1e6))
% 		fprintf('parsing: %07d [us]\n',round(t_parsing*1e6))
  end
end

function [] = cleanup_fcn(fcn_term,udp_socket)
  global data
  
  feval(fcn_term,data);
  fclose(udp_socket);
end
