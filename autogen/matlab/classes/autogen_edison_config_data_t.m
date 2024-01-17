%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_edison_config_data_t.m          %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_edison_config_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.EDISON_CONFIG_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_edison_config_data_t = autogen_topic_edison_config_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    altimeter_i2c_en(1,1) logical;
    i2c_1_en(1,1) logical;
    i2c_2_en(1,1) logical;
    spi_1_en(1,1) logical;
    spi_2_en(1,1) logical;
    uart_en(1,1) logical;
    pwm_gpio_ch(1,1) uint8;
    timeout_msec(1,1) uint8;
  end
  methods (Static)
    function [n] = size()
      n = 11+8;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 8;
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
        buffer(i1+0) = typecast(uint8(obj.altimeter_i2c_en),'uint8');
        buffer(i1+1) = typecast(uint8(obj.i2c_1_en),'uint8');
        buffer(i1+2) = typecast(uint8(obj.i2c_2_en),'uint8');
        buffer(i1+3) = typecast(uint8(obj.spi_1_en),'uint8');
        buffer(i1+4) = typecast(uint8(obj.spi_2_en),'uint8');
        buffer(i1+5) = typecast(uint8(obj.uart_en),'uint8');
        buffer(i1+6) = typecast(obj.pwm_gpio_ch,'uint8');
        buffer(i1+7) = typecast(obj.timeout_msec,'uint8');
        i2 = i1+8;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.altimeter_i2c_en = typecast(buffer(i1+0),'uint8');
        obj.i2c_1_en = typecast(buffer(i1+1),'uint8');
        obj.i2c_2_en = typecast(buffer(i1+2),'uint8');
        obj.spi_1_en = typecast(buffer(i1+3),'uint8');
        obj.spi_2_en = typecast(buffer(i1+4),'uint8');
        obj.uart_en = typecast(buffer(i1+5),'uint8');
        obj.pwm_gpio_ch = typecast(buffer(i1+6),'uint8');
        obj.timeout_msec = typecast(buffer(i1+7),'uint8');
        i2 = i1+8;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
