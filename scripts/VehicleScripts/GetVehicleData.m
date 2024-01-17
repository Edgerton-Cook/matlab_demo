%% Determines Vehicle Initial Data

global dest_ip dest_port n_vehicles;

dest_ip = strings(1,n_vehicles);

%determine all rover destination IP addresses
for i = 1:n_vehicles;
   dest_ip(1,i) = strcat('192.168.1.',num2str(rover_ip(1,i)));
end
dest_port = out_vehicle_port; % rover/autopilot port