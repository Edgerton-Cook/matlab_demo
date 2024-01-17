%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_hmc5883l_config_data_t.m        %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_hmc5883l_config_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.HMC5883L_CONFIG_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_hmc5883l_config_data_t = autogen_topic_hmc5883l_config_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    op_mode(1,1) uint8;
    avg_samp(1,1) uint8;
    rate(1,1) uint8;
    meas_mode(1,1) uint8;
    fs_mag(1,1) uint8;
    n_calib_samples(1,1) uint32;
    dev2body_angle_1_deg(1,1) single;
    dev2body_angle_2_deg(1,1) single;
    dev2body_angle_3_deg(1,1) single;
  end
  methods (Static)
    function [n] = size()
      n = 11+21;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 21;
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
        buffer(i1+0) = typecast(obj.op_mode,'uint8');
        buffer(i1+1) = typecast(obj.avg_samp,'uint8');
        buffer(i1+2) = typecast(obj.rate,'uint8');
        buffer(i1+3) = typecast(obj.meas_mode,'uint8');
        buffer(i1+4) = typecast(obj.fs_mag,'uint8');
        buffer(i1+(5:(5+3))) = typecast(obj.n_calib_samples,'uint8');
        buffer(i1+(9:(9+3))) = typecast(obj.dev2body_angle_1_deg,'uint8');
        buffer(i1+(13:(13+3))) = typecast(obj.dev2body_angle_2_deg,'uint8');
        buffer(i1+(17:(17+3))) = typecast(obj.dev2body_angle_3_deg,'uint8');
        i2 = i1+21;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.op_mode = typecast(buffer(i1+0),'uint8');
        obj.avg_samp = typecast(buffer(i1+1),'uint8');
        obj.rate = typecast(buffer(i1+2),'uint8');
        obj.meas_mode = typecast(buffer(i1+3),'uint8');
        obj.fs_mag = typecast(buffer(i1+4),'uint8');
        obj.n_calib_samples = typecast(buffer(i1+(5:(5+3))),'uint32');
        obj.dev2body_angle_1_deg = typecast(buffer(i1+(9:(9+3))),'single');
        obj.dev2body_angle_2_deg = typecast(buffer(i1+(13:(13+3))),'single');
        obj.dev2body_angle_3_deg = typecast(buffer(i1+(17:(17+3))),'single');
        i2 = i1+21;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
