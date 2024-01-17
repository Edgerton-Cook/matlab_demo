function [A] = mp_model_actuator(model,order)

if isequal(model,'thrust')
  if isequal(order,'1st')
    A = mp_ctrl_pole(2.75,1);
  elseif isequal(order,'2nd')
    A = mp_ctrl_pole(2.75,1)*mp_ctrl_pole(8.0,1);
  elseif isequal(order,'3rd')
    A = mp_ctrl_pole(2.75,1)*mp_ctrl_pole(8.0,1)*mp_ctrl_pole(20.0,1);
  end
elseif isequal(model,'torque')
  if isequal(order,'1st')
    A = mp_ctrl_zero(1.0,1)*mp_ctrl_pole(3.0,1);
  end
end
