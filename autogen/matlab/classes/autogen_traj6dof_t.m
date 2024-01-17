%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_traj6dof_t.m                    %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_traj6dof_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.TRAJ6DOF;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_traj6dof_t = autogen_topic_traj6dof_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    epoch(1,1) uint64;
    is_new(1,1) uint32;
    loop(1,1) uint32;
    K(1,1) uint32;
    time(1,1) autogen_matrix_single_1_50_t;
    pos_ned(1,1) autogen_matrix_single_3_50_t;
    vel_ned(1,1) autogen_matrix_single_3_50_t;
    accl_ned(1,1) autogen_matrix_single_3_50_t;
    omega_body(1,1) autogen_matrix_single_3_50_t;
    torque_body(1,1) autogen_matrix_single_3_50_t;
    clock_angle(1,1) autogen_matrix_single_1_50_t;
  end
  methods (Static)
    function [n] = size()
      n = 11+3420;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 3420;
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
        buffer(i1+(8:(8+3))) = typecast(obj.is_new,'uint8');
        buffer(i1+(12:(12+3))) = typecast(obj.loop,'uint8');
        buffer(i1+(16:(16+3))) = typecast(obj.K,'uint8');
        buffer = obj.time.serialize_content(buffer,i1+20);
        buffer = obj.pos_ned.serialize_content(buffer,i1+220);
        buffer = obj.vel_ned.serialize_content(buffer,i1+820);
        buffer = obj.accl_ned.serialize_content(buffer,i1+1420);
        buffer = obj.omega_body.serialize_content(buffer,i1+2020);
        buffer = obj.torque_body.serialize_content(buffer,i1+2620);
        buffer = obj.clock_angle.serialize_content(buffer,i1+3220);
        i2 = i1+3420;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.epoch = typecast(buffer(i1+(0:(0+7))),'uint64');
        obj.is_new = typecast(buffer(i1+(8:(8+3))),'uint32');
        obj.loop = typecast(buffer(i1+(12:(12+3))),'uint32');
        obj.K = typecast(buffer(i1+(16:(16+3))),'uint32');
        obj.time.deserialize_content(buffer,i1+20);
        obj.pos_ned.deserialize_content(buffer,i1+220);
        obj.vel_ned.deserialize_content(buffer,i1+820);
        obj.accl_ned.deserialize_content(buffer,i1+1420);
        obj.omega_body.deserialize_content(buffer,i1+2020);
        obj.torque_body.deserialize_content(buffer,i1+2620);
        obj.clock_angle.deserialize_content(buffer,i1+3220);
        i2 = i1+3420;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
