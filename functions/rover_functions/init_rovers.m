function [data] = init_rovers()
%{
Creates the structure "data". It also initializes and defines all
    necessary variables for use in the main loop function loop(). Any
    variables needed for trajectory generated or measured-value storage for
    post-processing must be contained within the structure "data" or it will
    be otherwise deleted.
%}

global t_f n_vehicles v_max pwm_convert;

data = struct;
    
%for loading and saving data - change this path!
filepath = strcat(pwd, '/data_demo/'); 
data.output_file_name = strcat(filepath,'vehicle_data.mat');
    
%integrators
data.f_int = 0; 
data.s_int = 0;
data.h_int = 0;
    
%initialize time values
                            data.counter = 0; %loop counter
data.meas_counter = 0; %received measurements counter
data.ms = .001;
data.global_time = 0; 
data.tf = t_f; 
data.delay = 0; %initialized to zero, measured at beginning of loop
data.sampling_time = .005;
    
%initialize multirover values
data.origin = [0; 0; 0]; 
data.num_rovers = n_vehicles;   
data.initial_cond = {}; %cell array of rover initial condtions
    
    
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

%initialize plant parameters (determined experimentally)
data.max_vel = v_max; 
data.pwm_conv = pwm_convert;

%intialize measurement vectors (to store mocap data)
data.t_meas = [];  
data.X_meas = [];
data.Y_meas = [];
data.theta_meas = [];
data.errors = [];

end