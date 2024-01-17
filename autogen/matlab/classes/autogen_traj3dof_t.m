%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_traj3dof_t.m                    %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_traj3dof_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.TRAJ3DOF;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_traj3dof_t = autogen_topic_traj3dof_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    epoch(1,1) uint64;
    K(1,1) uint32;
    loop(1,1) logical;
    time(1,1) autogen_matrix_single_1_50_t;
    pos_ned(1,1) autogen_matrix_single_3_50_t;
    vel_ned(1,1) autogen_matrix_single_3_50_t;
    accl_ned(1,1) autogen_matrix_single_3_50_t;
    clock_angle(1,1) autogen_matrix_single_1_50_t;
  end
  methods (Static)
    function [n] = size()
      n = 11+2213;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 2213;
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
        buffer(i1+(0:(0+7))) = typecast(obj.epoch,'uint8');
        buffer(i1+(8:(8+3))) = typecast(obj.K,'uint8');
        buffer(i1+12) = typecast(uint8(obj.loop),'uint8');
        buffer = obj.time.serialize_content(buffer,i1+13);
        buffer = obj.pos_ned.serialize_content(buffer,i1+213);
        buffer = obj.vel_ned.serialize_content(buffer,i1+813);
        buffer = obj.accl_ned.serialize_content(buffer,i1+1413);
        buffer = obj.clock_angle.serialize_content(buffer,i1+2013);
        i2 = i1+2213;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.epoch = typecast(buffer(i1+(0:(0+7))),'uint64');
        obj.K = typecast(buffer(i1+(8:(8+3))),'uint32');
        obj.loop = typecast(buffer(i1+12),'uint8');
        obj.time.deserialize_content(buffer,i1+13);
        obj.pos_ned.deserialize_content(buffer,i1+213);
        obj.vel_ned.deserialize_content(buffer,i1+813);
        obj.accl_ned.deserialize_content(buffer,i1+1413);
        obj.clock_angle.deserialize_content(buffer,i1+2013);
        i2 = i1+2213;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
