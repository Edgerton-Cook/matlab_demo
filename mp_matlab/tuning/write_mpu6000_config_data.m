fid = fopen('../../config/mpu6000_config_data.txt','w+');
%% Configuration Parameters
fprintf(fid,'\n');
fprintf(fid,'spi_bus_speed = %d\n',10000000);
fprintf(fid,'dlpf_cfg = %d\n',5);
fprintf(fid,'sample_rate_div = %d\n',0);
fprintf(fid,'accl_fs = %d\n',1);
fprintf(fid,'gyro_fs = %d\n',2);
fprintf(fid,'n_calib_samples = %d\n',5000);
fprintf(fid,'dev2body_angle_1_deg = %f\n',180);
fprintf(fid,'dev2body_angle_2_deg = %f\n',0);
fprintf(fid,'dev2body_angle_3_deg = %f\n',90);
fprintf(fid,'\n');
%% Close File
fclose(fid);