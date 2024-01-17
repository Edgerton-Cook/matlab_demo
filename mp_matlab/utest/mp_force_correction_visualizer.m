clear
clc

n = 5000;
f_nominal = 0.5;

tilt_error = linspace(-180,180,n)*(pi/180);
cone_angle = 30*(pi/180);
q_i2d = [1 0 0 0]';
q_i2b = [cos(tilt_error/2); sin(tilt_error/2); zeros(1,n); zeros(1,n)];

f_adjusted = zeros(1,n);
for i=1:n
  f_adjusted(i) = ...
    mp_force_correction(f_nominal,q_i2b(:,i),q_i2d,cone_angle);
end

figure(1),clf(1),hold on,grid on
plot(f_adjusted.*sin(tilt_error), ...
     f_adjusted.*cos(tilt_error), ...
     'color','r', ...
     'marker','none', ...
     'markersize',20, ...
     'linestyle','-');
plot(f_nominal/cos(cone_angle)*sind(linspace(0,360,n)), ...
     f_nominal/cos(cone_angle)*cosd(linspace(0,360,n)), ...
     'color','k', ...
     'linestyle','--')
xlabel('Lateral Force in R-Frame [N]')
ylabel('Vertical Force in R-Frame [N]')
axis equal
axis(2*[-1 1 -1 1])

figure(2),clf(2),hold on,grid on
plot(tilt_error*(180/pi),f_adjusted./f_nominal,'r')
plot( cone_angle*[1 1]*(180/pi),[0 10],'color','k','linestyle','--')
plot(-cone_angle*[1 1]*(180/pi),[0 10],'color','k','linestyle','--')
xlabel('Tilt Error [deg]')
ylabel('Amplification Factor')
set(gca,'ylim',[0 2.0])
