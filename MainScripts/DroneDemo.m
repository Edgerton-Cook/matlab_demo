% Edge's drone template script

%% Pull Obsticle Information

GetObsInfo

%% Pull Drone Mocap Data

GetDroneInfo

%% Planned Trajectory

if ~has_optimal_traj
   SolveOptimalTraj
end

if plot_optimal_traj
    PlotPlan
end

%% Safety Check
switch deg_freedom
    case '2'
        fprintf('Sending 2DOF trajectory to drone \n')
    case '3'
        fprintf('Sending 3DOF trajectory to drone \n')
end

keyboard

%% Send Trajectory to Drone + Save Flight Data

if send_drone_traj 
    SendTraj
end

%% Plot Flight Path of Drone

if plot_executed_traj
    PlotFlown
end


