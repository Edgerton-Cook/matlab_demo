%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_fm_cmd_states_t.m               %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_fm_cmd_states_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.FM_CMD_STATES;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_fm_cmd_states_t = autogen_topic_fm_cmd_states_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    edison(1,1) autogen_edison_state_t;
    mpu6000(1,1) autogen_mpu6000_state_t;
    hmc5883l(1,1) autogen_hmc5883l_state_t;
    neom8(1,1) autogen_neom8_state_t;
    max11644eua(1,1) autogen_max11644eua_state_t;
    power(1,1) autogen_power_state_t;
    led(1,1) autogen_led_state_t;
    estimation(1,1) autogen_estimation_state_t;
    qcontrol(1,1) autogen_qcontrol_state_t;
    rcontrol(1,1) autogen_rcontrol_state_t;
    sc18is602b(1,1) autogen_sc18is602b_state_t;
    pca9685(1,1) autogen_pca9685_state_t;
  end
  methods (Static)
    function [n] = size()
      n = 11+12;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 12;
    end
  end
  methods (Sealed = true)
    function [buffer,i2] = serialize(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        buffer(i1+0) = uint8(obj.type);
        buffer(i1+1) = uint8(obj.topic);
        buffer(i1+2) = uint8(obj.node);
        buffer((i1+3):(i1+10)) = typecast(obj.ts,'uint8');
        [buffer,i2] = serialize_content(obj,buffer,i1+11);
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [success,i2] = deserialize(obj,buffer,i1)
      success = false;
      i2 = i1;
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        if ((length(buffer)-(i1-1)) >= obj.size())&& ...
           (obj.type == buffer(i1))&& ...
           (obj.topic == buffer(i1+1))
          obj.node = buffer(i1+2);
          obj.ts = typecast(buffer((i1+3):(i1+10)),'uint64');
          i2 = deserialize_content(obj,buffer,i1+11);
          success = (i2 > i1);
        end
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [buffer,i2] = serialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        buffer = obj.edison.serialize_content(buffer,i1+0);
        buffer = obj.mpu6000.serialize_content(buffer,i1+1);
        buffer = obj.hmc5883l.serialize_content(buffer,i1+2);
        buffer = obj.neom8.serialize_content(buffer,i1+3);
        buffer = obj.max11644eua.serialize_content(buffer,i1+4);
        buffer = obj.power.serialize_content(buffer,i1+5);
        buffer = obj.led.serialize_content(buffer,i1+6);
        buffer = obj.estimation.serialize_content(buffer,i1+7);
        buffer = obj.qcontrol.serialize_content(buffer,i1+8);
        buffer = obj.rcontrol.serialize_content(buffer,i1+9);
        buffer = obj.sc18is602b.serialize_content(buffer,i1+10);
        buffer = obj.pca9685.serialize_content(buffer,i1+11);
        i2 = i1+12;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.edison.deserialize_content(buffer,i1+0);
        obj.mpu6000.deserialize_content(buffer,i1+1);
        obj.hmc5883l.deserialize_content(buffer,i1+2);
        obj.neom8.deserialize_content(buffer,i1+3);
        obj.max11644eua.deserialize_content(buffer,i1+4);
        obj.power.deserialize_content(buffer,i1+5);
        obj.led.deserialize_content(buffer,i1+6);
        obj.estimation.deserialize_content(buffer,i1+7);
        obj.qcontrol.deserialize_content(buffer,i1+8);
        obj.rcontrol.deserialize_content(buffer,i1+9);
        obj.sc18is602b.deserialize_content(buffer,i1+10);
        obj.pca9685.deserialize_content(buffer,i1+11);
        i2 = i1+12;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
