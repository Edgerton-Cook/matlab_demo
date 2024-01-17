%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_estimation_sig_data_t.m         %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_estimation_sig_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.ESTIMATION_SIG_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_estimation_sig_data_t = autogen_topic_estimation_sig_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    pos_ned(1,1) autogen_matrix_single_3_1_t;
    vel_ned(1,1) autogen_matrix_single_3_1_t;
    q_i2b(1,1) autogen_quat_t;
    b_accl(1,1) autogen_matrix_single_3_1_t;
    b_gyro(1,1) autogen_matrix_single_3_1_t;
    accl_b(1,1) autogen_matrix_single_3_1_t;
    omega_b(1,1) autogen_matrix_single_3_1_t;
  end
  methods (Static)
    function [n] = size()
      n = 11+88;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 88;
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
        buffer = obj.pos_ned.serialize_content(buffer,i1+0);
        buffer = obj.vel_ned.serialize_content(buffer,i1+12);
        buffer = obj.q_i2b.serialize_content(buffer,i1+24);
        buffer = obj.b_accl.serialize_content(buffer,i1+40);
        buffer = obj.b_gyro.serialize_content(buffer,i1+52);
        buffer = obj.accl_b.serialize_content(buffer,i1+64);
        buffer = obj.omega_b.serialize_content(buffer,i1+76);
        i2 = i1+88;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.pos_ned.deserialize_content(buffer,i1+0);
        obj.vel_ned.deserialize_content(buffer,i1+12);
        obj.q_i2b.deserialize_content(buffer,i1+24);
        obj.b_accl.deserialize_content(buffer,i1+40);
        obj.b_gyro.deserialize_content(buffer,i1+52);
        obj.accl_b.deserialize_content(buffer,i1+64);
        obj.omega_b.deserialize_content(buffer,i1+76);
        i2 = i1+88;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
