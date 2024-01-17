% Edge's rover template script
% Summer 2023
% ~~ WILL UPDATE ~~

global n_vehicles;

n_vehicles = length(rover_ip);
rover_ip = 100*ones(1,n_vehicles) + rover_ip;

GetVehicleData

mp_udp_client('0.0.0.0',7000,@()init_rovers(),@loop_rovers,@term)