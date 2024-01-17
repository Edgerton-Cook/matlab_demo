clear
clc

figure(1),clf(1),hold on,grid on
hx = line([0 0],[0 0],[0 0],'color','r');
hy = line([0 0],[0 0],[0 0],'color',[0 0.7 0]);
hz = line([0 0],[0 0],[0 0],'color','b');
ht = line([0 0],[0 0],[0 0],'color','b','linewidth',3);
axis equal
xlabel('N')
ylabel('E')
zlabel('D')
set(gca,'ydir','reverse')
set(gca,'zdir','reverse')
set(gca,'xlim',1.5*[-1 1],'ylim',1.5*[-1 1],'zlim',1.5*[-1 1])
view(3)

clock_angle = 90*(pi/180);

n = 1000;
rpy = [linspace(0,360,n)
       linspace(0,0,n)
       linspace(1,1,n)*45]*(pi/180);

pnt_vec = zeros(3,n);
for i=1:n
  C_i2b = mp_R1(rpy(1,i))*mp_R2(rpy(2,i))*mp_R3(rpy(3,i));
  pnt_vec(:,i) = C_i2b'*[0 0 -1]';
end
q_i2r = mp_vec2quat(pnt_vec,clock_angle*ones(1,n));

for i=1:n
  q_i2r_i = q_i2r(:,i);
  pnt_vec_i = pnt_vec(:,i);
  
  C_i2r = mp_quat2dcm(q_i2r_i);
  x_axis = C_i2r'*[1 0 0]';
  y_axis = C_i2r'*[0 1 0]';
  z_axis = C_i2r'*[0 0 1]';
  
  set(hx,'xdata',[0 x_axis(1)], ...
         'ydata',[0 x_axis(2)], ...
         'zdata',[0 x_axis(3)])
  set(hy,'xdata',[0 y_axis(1)], ...
         'ydata',[0 y_axis(2)], ...
         'zdata',[0 y_axis(3)])
  set(hz,'xdata',[0 z_axis(1)], ...
         'ydata',[0 z_axis(2)], ...
         'zdata',[0 z_axis(3)])
  set(ht,'xdata',[0 pnt_vec_i(1)], ...
         'ydata',[0 pnt_vec_i(2)], ...
         'zdata',[0 pnt_vec_i(3)])
  drawnow
end
