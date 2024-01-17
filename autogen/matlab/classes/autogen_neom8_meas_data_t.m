%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_neom8_meas_data_t.m             %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_neom8_meas_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.NEOM8_MEAS_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_neom8_meas_data_t = autogen_topic_neom8_meas_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    i_tow_msec(1,1) uint32;
    f_tow_nsec(1,1) int32;
    week(1,1) int16;
    gps_fix(1,1) uint16;
    flags(1,1) uint16;
    px_ecef_cm(1,1) int32;
    py_ecef_cm(1,1) int32;
    pz_ecef_cm(1,1) int32;
    p_acc_cm(1,1) uint32;
    vx_ecef_cmps(1,1) int32;
    vy_ecef_cmps(1,1) int32;
    vz_ecef_cmps(1,1) int32;
    v_acc_cmps(1,1) uint32;
    p_dop_cm(1,1) uint16;
    num_sv(1,1) uint16;
    pos_ned(1,1) autogen_matrix_single_3_1_t;
    vel_ned(1,1) autogen_matrix_single_3_1_t;
  end
  methods (Static)
    function [n] = size()
      n = 11+74;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 74;
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
        buffer(i1+(0:(0+3))) = typecast(obj.i_tow_msec,'uint8');
        buffer(i1+(4:(4+3))) = typecast(obj.f_tow_nsec,'uint8');
        buffer(i1+(8:(8+1))) = typecast(obj.week,'uint8');
        buffer(i1+(10:(10+1))) = typecast(obj.gps_fix,'uint8');
        buffer(i1+(12:(12+1))) = typecast(obj.flags,'uint8');
        buffer(i1+(14:(14+3))) = typecast(obj.px_ecef_cm,'uint8');
        buffer(i1+(18:(18+3))) = typecast(obj.py_ecef_cm,'uint8');
        buffer(i1+(22:(22+3))) = typecast(obj.pz_ecef_cm,'uint8');
        buffer(i1+(26:(26+3))) = typecast(obj.p_acc_cm,'uint8');
        buffer(i1+(30:(30+3))) = typecast(obj.vx_ecef_cmps,'uint8');
        buffer(i1+(34:(34+3))) = typecast(obj.vy_ecef_cmps,'uint8');
        buffer(i1+(38:(38+3))) = typecast(obj.vz_ecef_cmps,'uint8');
        buffer(i1+(42:(42+3))) = typecast(obj.v_acc_cmps,'uint8');
        buffer(i1+(46:(46+1))) = typecast(obj.p_dop_cm,'uint8');
        buffer(i1+(48:(48+1))) = typecast(obj.num_sv,'uint8');
        buffer = obj.pos_ned.serialize_content(buffer,i1+50);
        buffer = obj.vel_ned.serialize_content(buffer,i1+62);
        i2 = i1+74;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.i_tow_msec = typecast(buffer(i1+(0:(0+3))),'uint32');
        obj.f_tow_nsec = typecast(buffer(i1+(4:(4+3))),'int32');
        obj.week = typecast(buffer(i1+(8:(8+1))),'int16');
        obj.gps_fix = typecast(buffer(i1+(10:(10+1))),'uint16');
        obj.flags = typecast(buffer(i1+(12:(12+1))),'uint16');
        obj.px_ecef_cm = typecast(buffer(i1+(14:(14+3))),'int32');
        obj.py_ecef_cm = typecast(buffer(i1+(18:(18+3))),'int32');
        obj.pz_ecef_cm = typecast(buffer(i1+(22:(22+3))),'int32');
        obj.p_acc_cm = typecast(buffer(i1+(26:(26+3))),'uint32');
        obj.vx_ecef_cmps = typecast(buffer(i1+(30:(30+3))),'int32');
        obj.vy_ecef_cmps = typecast(buffer(i1+(34:(34+3))),'int32');
        obj.vz_ecef_cmps = typecast(buffer(i1+(38:(38+3))),'int32');
        obj.v_acc_cmps = typecast(buffer(i1+(42:(42+3))),'uint32');
        obj.p_dop_cm = typecast(buffer(i1+(46:(46+1))),'uint16');
        obj.num_sv = typecast(buffer(i1+(48:(48+1))),'uint16');
        obj.pos_ned.deserialize_content(buffer,i1+50);
        obj.vel_ned.deserialize_content(buffer,i1+62);
        i2 = i1+74;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
