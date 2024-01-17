%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_estimation_local_data_t.m       %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_estimation_local_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.ESTIMATION_LOCAL_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_estimation_local_data_t = autogen_topic_estimation_local_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    x(1,1) autogen_matrix_single_7_1_t;
    gyro_bias_integral(1,1) autogen_matrix_single_3_1_t;
    previous_mag_vec_meas(1,1) autogen_matrix_single_3_1_t;
    x_kf(1,1) autogen_matrix_single_6_1_t;
    P_kf(1,1) autogen_matrix_single_6_6_t;
  end
  methods (Static)
    function [n] = size()
      n = 11+220;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 220;
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
        buffer = obj.x.serialize_content(buffer,i1+0);
        buffer = obj.gyro_bias_integral.serialize_content(buffer,i1+28);
        buffer = obj.previous_mag_vec_meas.serialize_content(buffer,i1+40);
        buffer = obj.x_kf.serialize_content(buffer,i1+52);
        buffer = obj.P_kf.serialize_content(buffer,i1+76);
        i2 = i1+220;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.x.deserialize_content(buffer,i1+0);
        obj.gyro_bias_integral.deserialize_content(buffer,i1+28);
        obj.previous_mag_vec_meas.deserialize_content(buffer,i1+40);
        obj.x_kf.deserialize_content(buffer,i1+52);
        obj.P_kf.deserialize_content(buffer,i1+76);
        i2 = i1+220;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
