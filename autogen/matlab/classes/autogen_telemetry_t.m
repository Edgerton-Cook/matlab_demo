%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_telemetry_t.m                   %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_telemetry_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.TELEMETRY;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_telemetry_t = autogen_topic_telemetry_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    veh_config(1,1) autogen_veh_config_state_t;
    ownership(1,1) autogen_ownership_state_t;
    fm_state(1,1) autogen_fm_state_t;
    qcontrol_mode(1,1) autogen_qcontrol_mode_t;
    rcontrol_mode(1,1) autogen_rcontrol_mode_t;
    battery_voltage(1,1) single;
    q_i2b(1,1) autogen_quat_t;
    q_i2r(1,1) autogen_quat_t;
    pos_ned(1,1) autogen_matrix_single_3_1_t;
    pos_ref_ned(1,1) autogen_matrix_single_3_1_t;
    vel_ned(1,1) autogen_matrix_single_3_1_t;
    accl_b(1,1) autogen_matrix_single_3_1_t;
    gps_nsv(1,1) uint16;
    gps_fix(1,1) uint16;
  end
  methods (Static)
    function [n] = size()
      n = 11+93;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 93;
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
        buffer = obj.veh_config.serialize_content(buffer,i1+0);
        buffer = obj.ownership.serialize_content(buffer,i1+1);
        buffer = obj.fm_state.serialize_content(buffer,i1+2);
        buffer = obj.qcontrol_mode.serialize_content(buffer,i1+3);
        buffer = obj.rcontrol_mode.serialize_content(buffer,i1+4);
        buffer(i1+(5:(5+3))) = typecast(obj.battery_voltage,'uint8');
        buffer = obj.q_i2b.serialize_content(buffer,i1+9);
        buffer = obj.q_i2r.serialize_content(buffer,i1+25);
        buffer = obj.pos_ned.serialize_content(buffer,i1+41);
        buffer = obj.pos_ref_ned.serialize_content(buffer,i1+53);
        buffer = obj.vel_ned.serialize_content(buffer,i1+65);
        buffer = obj.accl_b.serialize_content(buffer,i1+77);
        buffer(i1+(89:(89+1))) = typecast(obj.gps_nsv,'uint8');
        buffer(i1+(91:(91+1))) = typecast(obj.gps_fix,'uint8');
        i2 = i1+93;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.veh_config.deserialize_content(buffer,i1+0);
        obj.ownership.deserialize_content(buffer,i1+1);
        obj.fm_state.deserialize_content(buffer,i1+2);
        obj.qcontrol_mode.deserialize_content(buffer,i1+3);
        obj.rcontrol_mode.deserialize_content(buffer,i1+4);
        obj.battery_voltage = typecast(buffer(i1+(5:(5+3))),'single');
        obj.q_i2b.deserialize_content(buffer,i1+9);
        obj.q_i2r.deserialize_content(buffer,i1+25);
        obj.pos_ned.deserialize_content(buffer,i1+41);
        obj.pos_ref_ned.deserialize_content(buffer,i1+53);
        obj.vel_ned.deserialize_content(buffer,i1+65);
        obj.accl_b.deserialize_content(buffer,i1+77);
        obj.gps_nsv = typecast(buffer(i1+(89:(89+1))),'uint16');
        obj.gps_fix = typecast(buffer(i1+(91:(91+1))),'uint16');
        i2 = i1+93;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
