%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_gcs_agent_config_data_t.m       %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_gcs_agent_config_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.GCS_AGENT_CONFIG_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_gcs_agent_config_data_t = autogen_topic_gcs_agent_config_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    rover_min_battery_voltage(1,1) single;
    rover_max_battery_voltage(1,1) single;
    quadrotor_min_battery_voltage(1,1) single;
    quadrotor_max_battery_voltage(1,1) single;
    pix_margin(1,1) uint32;
    southwest_pos_n(1,1) single;
    southwest_pos_e(1,1) single;
    northeast_pos_n(1,1) single;
    northeast_pos_e(1,1) single;
    display_text(1,1) logical;
  end
  methods (Static)
    function [n] = size()
      n = 11+37;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 37;
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
        buffer(i1+(0:(0+3))) = typecast(obj.rover_min_battery_voltage,'uint8');
        buffer(i1+(4:(4+3))) = typecast(obj.rover_max_battery_voltage,'uint8');
        buffer(i1+(8:(8+3))) = typecast(obj.quadrotor_min_battery_voltage,'uint8');
        buffer(i1+(12:(12+3))) = typecast(obj.quadrotor_max_battery_voltage,'uint8');
        buffer(i1+(16:(16+3))) = typecast(obj.pix_margin,'uint8');
        buffer(i1+(20:(20+3))) = typecast(obj.southwest_pos_n,'uint8');
        buffer(i1+(24:(24+3))) = typecast(obj.southwest_pos_e,'uint8');
        buffer(i1+(28:(28+3))) = typecast(obj.northeast_pos_n,'uint8');
        buffer(i1+(32:(32+3))) = typecast(obj.northeast_pos_e,'uint8');
        buffer(i1+36) = typecast(uint8(obj.display_text),'uint8');
        i2 = i1+37;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.rover_min_battery_voltage = typecast(buffer(i1+(0:(0+3))),'single');
        obj.rover_max_battery_voltage = typecast(buffer(i1+(4:(4+3))),'single');
        obj.quadrotor_min_battery_voltage = typecast(buffer(i1+(8:(8+3))),'single');
        obj.quadrotor_max_battery_voltage = typecast(buffer(i1+(12:(12+3))),'single');
        obj.pix_margin = typecast(buffer(i1+(16:(16+3))),'uint32');
        obj.southwest_pos_n = typecast(buffer(i1+(20:(20+3))),'single');
        obj.southwest_pos_e = typecast(buffer(i1+(24:(24+3))),'single');
        obj.northeast_pos_n = typecast(buffer(i1+(28:(28+3))),'single');
        obj.northeast_pos_e = typecast(buffer(i1+(32:(32+3))),'single');
        obj.display_text = typecast(buffer(i1+36),'uint8');
        i2 = i1+37;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
