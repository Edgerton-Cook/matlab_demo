function [H] = mp_model_mpu6000(model,dlpf)

accl_fc_hz = [260 184 94 44 21 10 5]'; % [Hz]
gyro_fc_hz = [256 188 98 42 20 10 5]'; % [Hz]

accl_fc = 2*pi*accl_fc_hz;
gyro_fc = 2*pi*gyro_fc_hz;

if isequal(model,'accl')
  H = zpk([],-accl_fc(dlpf+1),accl_fc(dlpf+1));
elseif isequal(model,'gyro')
  H = zpk([],-gyro_fc(dlpf+1),gyro_fc(dlpf+1));
end
