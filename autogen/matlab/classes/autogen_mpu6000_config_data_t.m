%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_mpu6000_config_data_t.m         %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_mpu6000_config_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.MPU6000_CONFIG_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_mpu6000_config_data_t = autogen_topic_mpu6000_config_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    spi_bus_speed(1,1) uint32;
    dlpf_cfg(1,1) uint8;
    sample_rate_div(1,1) uint8;
    accl_fs(1,1) uint8;
    gyro_fs(1,1) uint8;
    n_calib_samples(1,1) uint32;
    dev2body_angle_1_deg(1,1) single;
    dev2body_angle_2_deg(1,1) single;
    dev2body_angle_3_deg(1,1) single;
  end
  methods (Static)
    function [n] = size()
      n = 11+24;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 24;
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
        buffer(i1+(0:(0+3))) = typecast(obj.spi_bus_speed,'uint8');
        buffer(i1+4) = typecast(obj.dlpf_cfg,'uint8');
        buffer(i1+5) = typecast(obj.sample_rate_div,'uint8');
        buffer(i1+6) = typecast(obj.accl_fs,'uint8');
        buffer(i1+7) = typecast(obj.gyro_fs,'uint8');
        buffer(i1+(8:(8+3))) = typecast(obj.n_calib_samples,'uint8');
        buffer(i1+(12:(12+3))) = typecast(obj.dev2body_angle_1_deg,'uint8');
        buffer(i1+(16:(16+3))) = typecast(obj.dev2body_angle_2_deg,'uint8');
        buffer(i1+(20:(20+3))) = typecast(obj.dev2body_angle_3_deg,'uint8');
        i2 = i1+24;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.spi_bus_speed = typecast(buffer(i1+(0:(0+3))),'uint32');
        obj.dlpf_cfg = typecast(buffer(i1+4),'uint8');
        obj.sample_rate_div = typecast(buffer(i1+5),'uint8');
        obj.accl_fs = typecast(buffer(i1+6),'uint8');
        obj.gyro_fs = typecast(buffer(i1+7),'uint8');
        obj.n_calib_samples = typecast(buffer(i1+(8:(8+3))),'uint32');
        obj.dev2body_angle_1_deg = typecast(buffer(i1+(12:(12+3))),'single');
        obj.dev2body_angle_2_deg = typecast(buffer(i1+(16:(16+3))),'single');
        obj.dev2body_angle_3_deg = typecast(buffer(i1+(20:(20+3))),'single');
        i2 = i1+24;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
