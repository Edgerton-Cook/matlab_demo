%% Plot Optimal Trajectory

% This plots the optimal trajectory to a spacial map with the drones
% initial conditions as well as the obstacles

%% Plot 1: Trajectories
    % initialize figure
    figure(1),clf(1),hold on,grid on
    set(0,'defaulttextinterpreter','latex')

    % plot cases
    plot_traj(I,O);

    % set axis view, scales, and limits for figure 1
    axis equal
    set(gca,'xlim',[-2 2],'xtick',-10:1:10)
    set(gca,'ylim',[-3 4.5],'ytick',-10:1:10)
    set(gca,'zlim',[0 2.0],'ztick',-10:1.0:10)

    % save iso-view
    view(50,35)
    set(gca,'position',[0.05 0.05 0.95 0.95])
    set(1,'units','inches')
    set(1,'papersize',[18.25 11.75])

    % save top-view
    view(0,90)
    set(gca,'position',[0.065 0.08 0.90 0.90])
    set(get(gca,'xlabel'),'position',[0 -0.30 0.5])
    set(get(gca,'ylabel'),'position',[-3.25 3.0 -0.5])
    set(1,'units','inches')
    set(1,'papersize',[11.50 11.50])

    %% Plot 2: Thrust Commands
    % initialize figure
    figure(2),clf(2),hold on,grid on

    % plot cases
    plot_thrust(I,O);
    
    %% plot 3: velocities
    v_traj = O{end}.v;
    figure;
    plot(v_traj(1,:)); hold on
    plot(v_traj(2,:))
    plot(v_traj(3,:))
    legend('Z', 'Y' , 'X' )
    title('scvx velocities')

    %% plot 4: velocities
    a_traj = O{end}.u;
    figure;
    plot(a_traj(1,:)); hold on
    plot(a_traj(2,:))
    plot(a_traj(3,:))
    legend('Z', 'Y' , 'X' )
    title('scvx velocities')
    
    close 2 3 4