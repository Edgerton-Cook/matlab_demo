%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_led_cmd_data_t.m                %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_led_cmd_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.LED_CMD_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_led_cmd_data_t = autogen_topic_led_cmd_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    apa102c_buffer(72,1) uint8;
    apa102c_n_bytes(1,1) uint32;
    ir_led_pwm(1,1) autogen_matrix_single_12_1_t;
  end
  methods (Static)
    function [n] = size()
      n = 11+124;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 124;
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
        for mpac_ijk0=1:72
          buffer(i1+0+1*(mpac_ijk0-1)) = typecast(obj.apa102c_buffer(mpac_ijk0),'uint8');
        end
        buffer(i1+(72:(72+3))) = typecast(obj.apa102c_n_bytes,'uint8');
        buffer = obj.ir_led_pwm.serialize_content(buffer,i1+76);
        i2 = i1+124;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        for mpac_ijk0=1:72
          obj.apa102c_buffer(mpac_ijk0) = typecast(buffer(i1+0+1*(mpac_ijk0-1)),'uint8');
        end
        obj.apa102c_n_bytes = typecast(buffer(i1+(72:(72+3))),'uint32');
        obj.ir_led_pwm.deserialize_content(buffer,i1+76);
        i2 = i1+124;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
