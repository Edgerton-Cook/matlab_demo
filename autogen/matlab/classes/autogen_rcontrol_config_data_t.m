%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_rcontrol_config_data_t.m        %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_rcontrol_config_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.RCONTROL_CONFIG_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_rcontrol_config_data_t = autogen_topic_rcontrol_config_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    test_mode_base_pwm(1,1) single;
    test_mode_delta_pwm(1,1) single;
    ol_base_pwm(1,1) single;
    ol_delta_pwm(1,1) single;
    cl_base_pwm(1,1) single;
    cl_max_vel(1,1) single;
    cl_max_ang_rate_dps(1,1) single;
    cl_kp_pos(1,1) single;
    cl_kp_hdg(1,1) single;
    cl_u_vf_sat(1,1) single;
    cl_u_vs_sat(1,1) single;
    cl_u_vh_sat(1,1) single;
  end
  methods (Static)
    function [n] = size()
      n = 11+48;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 48;
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
        buffer(i1+(0:(0+3))) = typecast(obj.test_mode_base_pwm,'uint8');
        buffer(i1+(4:(4+3))) = typecast(obj.test_mode_delta_pwm,'uint8');
        buffer(i1+(8:(8+3))) = typecast(obj.ol_base_pwm,'uint8');
        buffer(i1+(12:(12+3))) = typecast(obj.ol_delta_pwm,'uint8');
        buffer(i1+(16:(16+3))) = typecast(obj.cl_base_pwm,'uint8');
        buffer(i1+(20:(20+3))) = typecast(obj.cl_max_vel,'uint8');
        buffer(i1+(24:(24+3))) = typecast(obj.cl_max_ang_rate_dps,'uint8');
        buffer(i1+(28:(28+3))) = typecast(obj.cl_kp_pos,'uint8');
        buffer(i1+(32:(32+3))) = typecast(obj.cl_kp_hdg,'uint8');
        buffer(i1+(36:(36+3))) = typecast(obj.cl_u_vf_sat,'uint8');
        buffer(i1+(40:(40+3))) = typecast(obj.cl_u_vs_sat,'uint8');
        buffer(i1+(44:(44+3))) = typecast(obj.cl_u_vh_sat,'uint8');
        i2 = i1+48;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.test_mode_base_pwm = typecast(buffer(i1+(0:(0+3))),'single');
        obj.test_mode_delta_pwm = typecast(buffer(i1+(4:(4+3))),'single');
        obj.ol_base_pwm = typecast(buffer(i1+(8:(8+3))),'single');
        obj.ol_delta_pwm = typecast(buffer(i1+(12:(12+3))),'single');
        obj.cl_base_pwm = typecast(buffer(i1+(16:(16+3))),'single');
        obj.cl_max_vel = typecast(buffer(i1+(20:(20+3))),'single');
        obj.cl_max_ang_rate_dps = typecast(buffer(i1+(24:(24+3))),'single');
        obj.cl_kp_pos = typecast(buffer(i1+(28:(28+3))),'single');
        obj.cl_kp_hdg = typecast(buffer(i1+(32:(32+3))),'single');
        obj.cl_u_vf_sat = typecast(buffer(i1+(36:(36+3))),'single');
        obj.cl_u_vs_sat = typecast(buffer(i1+(40:(40+3))),'single');
        obj.cl_u_vh_sat = typecast(buffer(i1+(44:(44+3))),'single');
        i2 = i1+48;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
