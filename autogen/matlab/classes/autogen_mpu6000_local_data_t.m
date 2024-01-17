%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_mpu6000_local_data_t.m          %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_mpu6000_local_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.MPU6000_LOCAL_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_mpu6000_local_data_t = autogen_topic_mpu6000_local_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    inv_accl_scale(1,1) single;
    inv_gyro_scale(1,1) single;
    calibration_complete(1,1) logical;
    i_calib_sample(1,1) uint32;
    accl_bias_sum(1,1) autogen_matrix_single_3_1_t;
    gyro_bias_sum(1,1) autogen_matrix_single_3_1_t;
    C_dev2body(1,1) autogen_dcm_t;
  end
  methods (Static)
    function [n] = size()
      n = 11+73;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 73;
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
        buffer(i1+(0:(0+3))) = typecast(obj.inv_accl_scale,'uint8');
        buffer(i1+(4:(4+3))) = typecast(obj.inv_gyro_scale,'uint8');
        buffer(i1+8) = typecast(uint8(obj.calibration_complete),'uint8');
        buffer(i1+(9:(9+3))) = typecast(obj.i_calib_sample,'uint8');
        buffer = obj.accl_bias_sum.serialize_content(buffer,i1+13);
        buffer = obj.gyro_bias_sum.serialize_content(buffer,i1+25);
        buffer = obj.C_dev2body.serialize_content(buffer,i1+37);
        i2 = i1+73;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.inv_accl_scale = typecast(buffer(i1+(0:(0+3))),'single');
        obj.inv_gyro_scale = typecast(buffer(i1+(4:(4+3))),'single');
        obj.calibration_complete = typecast(buffer(i1+8),'uint8');
        obj.i_calib_sample = typecast(buffer(i1+(9:(9+3))),'uint32');
        obj.accl_bias_sum.deserialize_content(buffer,i1+13);
        obj.gyro_bias_sum.deserialize_content(buffer,i1+25);
        obj.C_dev2body.deserialize_content(buffer,i1+37);
        i2 = i1+73;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
