%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_qcontrol_sig_data_t.m           %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_qcontrol_sig_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.QCONTROL_SIG_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_qcontrol_sig_data_t = autogen_topic_qcontrol_sig_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    clock_ref(1,1) single;
    pos_ref_ned(1,1) autogen_matrix_single_3_1_t;
    vel_ref_ned(1,1) autogen_matrix_single_3_1_t;
    accl_ref_ned(1,1) autogen_matrix_single_3_1_t;
    q_i2r(1,1) autogen_quat_t;
    omega_r(1,1) autogen_matrix_single_3_1_t;
    tau_r(1,1) autogen_matrix_single_3_1_t;
    w_req(1,1) autogen_matrix_single_4_1_t;
    w_alloc(1,1) autogen_matrix_single_4_1_t;
    f_alloc(1,1) autogen_matrix_single_4_1_t;
    u(1,1) autogen_matrix_single_4_1_t;
  end
  methods (Static)
    function [n] = size()
      n = 11+144;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 144;
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
        buffer(i1+(0:(0+3))) = typecast(obj.clock_ref,'uint8');
        buffer = obj.pos_ref_ned.serialize_content(buffer,i1+4);
        buffer = obj.vel_ref_ned.serialize_content(buffer,i1+16);
        buffer = obj.accl_ref_ned.serialize_content(buffer,i1+28);
        buffer = obj.q_i2r.serialize_content(buffer,i1+40);
        buffer = obj.omega_r.serialize_content(buffer,i1+56);
        buffer = obj.tau_r.serialize_content(buffer,i1+68);
        buffer = obj.w_req.serialize_content(buffer,i1+80);
        buffer = obj.w_alloc.serialize_content(buffer,i1+96);
        buffer = obj.f_alloc.serialize_content(buffer,i1+112);
        buffer = obj.u.serialize_content(buffer,i1+128);
        i2 = i1+144;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.clock_ref = typecast(buffer(i1+(0:(0+3))),'single');
        obj.pos_ref_ned.deserialize_content(buffer,i1+4);
        obj.vel_ref_ned.deserialize_content(buffer,i1+16);
        obj.accl_ref_ned.deserialize_content(buffer,i1+28);
        obj.q_i2r.deserialize_content(buffer,i1+40);
        obj.omega_r.deserialize_content(buffer,i1+56);
        obj.tau_r.deserialize_content(buffer,i1+68);
        obj.w_req.deserialize_content(buffer,i1+80);
        obj.w_alloc.deserialize_content(buffer,i1+96);
        obj.f_alloc.deserialize_content(buffer,i1+112);
        obj.u.deserialize_content(buffer,i1+128);
        i2 = i1+144;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
