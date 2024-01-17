clear
clc

mp_udp_client('0.0.0.0',7000,@()init(),@loop,@term)

function [data] = init()
	data = struct;
  
  data.output_file_name = 'test_10hz.mat';
	data.counter = 0;

	data.gyro.fh = 2;
	figure(data.gyro.fh),clf(data.gyro.fh)
	labels = {'X','Y','Z'};
	for i=1:3
		subplot(3,1,i),hold on,grid on
		xlabel('Time [s]')
		ylabel(['Gyro ' labels{i} ' [deg/s]'])
		data.gyro.lh(i) = line(NaN,NaN,'color','r','marker','.');
	end
	data.gyro.tbuff = zeros(1,1);
	data.gyro.dbuff = zeros(1,3);
	data.gyro.ibuff = 1;
  data.gyro.t = zeros(0,1);
  data.gyro.data = zeros(0,3);
	
	data.pwm.fh = 1;
	figure(data.pwm.fh),clf(data.pwm.fh)
	labels = {'PWM1','PWM2','PWM3','PWM4'};
	for i=1:4
		subplot(4,1,i),hold on,grid on
		xlabel('Time [s]')
		ylabel([labels{i} ' [us]'])
		data.pwm.lh(i) = line(NaN,NaN,'color','r','marker','.');
	end
	data.pwm.tbuff = zeros(1,1);
	data.pwm.dbuff = zeros(1,4);
	data.pwm.ibuff = 1;
  data.pwm.t = zeros(0,1);
  data.pwm.data = zeros(0,4);
end
function [data,outgoing,run_loop] = loop(data,incoming)
	dest_addr_ip = '192.168.1.109';
	dest_addr_port = 6000;
	
  for i=1:length(incoming)
    if ~isempty(incoming(i).buffer)
			idx = 1;
			
			telemetry = autogen_telemetry_t;
			telemetry.topic = autogen_topic_telemetry_t.UNDEFINED;
			[success,idx] = telemetry.deserialize(incoming(i).buffer,idx);
			if (success)
				fprintf('| telemetry |')
			else
				fprintf('|           |')
			end
			
			imu_data = autogen_mpu6000_meas_data_t;
			imu_data.topic = autogen_topic_mpu6000_meas_data_t.UNDEFINED;
			[success,idx] = imu_data.deserialize(incoming(i).buffer,idx);
			if (success)
				data.gyro.tbuff(data.gyro.ibuff,1) = double(imu_data.ts)*1e-6;
				data.gyro.dbuff(data.gyro.ibuff,1) = imu_data.gyro.mat(1);
				data.gyro.dbuff(data.gyro.ibuff,2) = imu_data.gyro.mat(2);
				data.gyro.dbuff(data.gyro.ibuff,3) = imu_data.gyro.mat(3);
				data.gyro.ibuff = data.gyro.ibuff+1;
				
				if (data.gyro.ibuff > length(data.gyro.tbuff))
          for j=1:3
            set(data.gyro.lh(j),'xdata', ...
              [get(data.gyro.lh(j),'xdata') data.gyro.tbuff']);
            set(data.gyro.lh(j),'ydata', ...
              [get(data.gyro.lh(j),'ydata') data.gyro.dbuff(:,j)'*180/pi]);
          end
					
          data.gyro.t(end+1,1) = data.gyro.tbuff;
          data.gyro.data(end+1,:) = data.gyro.dbuff;
          
					data.gyro.tbuff = zeros(size(data.gyro.tbuff));
					data.gyro.dbuff = zeros(size(data.gyro.dbuff));
					data.gyro.ibuff = 1;
				end
				
				fprintf('| mpu6000_meas_data |')
			else
				fprintf('|                   |')
			end
			
			pwm_data = autogen_pca9685_cmd_data_t;
			pwm_data.topic = autogen_topic_pca9685_cmd_data_t.UNDEFINED;
			[success,~] = pwm_data.deserialize(incoming(i).buffer,idx);
			if (success)
				data.pwm.tbuff(data.pwm.ibuff,1) = double(pwm_data.ts)*1e-6;
				data.pwm.dbuff(data.pwm.ibuff,1) = pwm_data.pwm.mat(1);
				data.pwm.dbuff(data.pwm.ibuff,2) = pwm_data.pwm.mat(2);
				data.pwm.dbuff(data.pwm.ibuff,3) = pwm_data.pwm.mat(3);
				data.pwm.dbuff(data.pwm.ibuff,4) = pwm_data.pwm.mat(4);
				data.pwm.ibuff = data.pwm.ibuff+1;
				
				if (data.pwm.ibuff > length(data.pwm.tbuff))
          for j=1:4
            set(data.pwm.lh(j),'xdata', ...
              [get(data.pwm.lh(j),'xdata') data.pwm.tbuff']);
            set(data.pwm.lh(j),'ydata', ...
              [get(data.pwm.lh(j),'ydata') data.pwm.dbuff(:,j)']);
          end
          
          data.pwm.t(end+1,1) = data.pwm.tbuff;
          data.pwm.data(end+1,:) = data.pwm.dbuff;
					
					data.pwm.tbuff = zeros(size(data.pwm.tbuff));
					data.pwm.dbuff = zeros(size(data.pwm.dbuff));
					data.pwm.ibuff = 1;
				end
				
				fprintf('| pca9685_cmd_data |')
			else
				fprintf('|                  |')
			end
			
			fprintf('\n')
			drawnow
    end
  end
    
	heartbeat = autogen_heartbeat_t;
	heartbeat.request_ownership = false;
	heartbeat.emergency_shutdown = false;
	
  outgoing = mp_datagram_t.empty;
	outgoing(1).ip = dest_addr_ip;
	outgoing(1).port = dest_addr_port;
  outgoing(1).buffer = heartbeat.serialize(outgoing(1).buffer,1);
  
  subscriptions = autogen_cm_subscriptions_t;
  subscriptions.telemetry_rate = 0;
  subscriptions.mpu6000_meas_data_rate = 20;
  subscriptions.pca9685_cmd_data_rate = 20;
  
  outgoing(2).ip = dest_addr_ip;
  outgoing(2).port = dest_addr_port;
  outgoing(2).buffer = subscriptions.serialize(outgoing(2).buffer,1);
  
	data.counter = data.counter+1;
	run_loop = true;
end
function [] = term(data)
  if ~isempty(data.output_file_name)
    gyro_time = data.gyro.t; %#ok<NASGU>
    gyro_data = data.gyro.data; %#ok<NASGU>
    
    pwm_time = data.pwm.t; %#ok<NASGU>
    pwm_data = data.pwm.data; %#ok<NASGU>
    
    save(data.output_file_name,'gyro_time', ...
                               'gyro_data', ...
                               'pwm_time', ...
                               'pwm_data');
  end
end
