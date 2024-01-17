%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_fm_cmd_data_t.m                 %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_fm_cmd_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.FM_CMD_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_fm_cmd_data_t = autogen_topic_fm_cmd_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    exit_loop(1,1) logical;
    states(1,1) autogen_fm_cmd_states_t;
    led_solid(1,1) autogen_led_cmd_solid_t;
    led_blinking(1,1) autogen_led_cmd_blinking_t;
    led_spinning(1,1) autogen_led_cmd_spinning_t;
    led_progress(1,1) autogen_led_cmd_progress_t;
    led_nav(1,1) autogen_led_cmd_nav_t;
  end
  methods (Static)
    function [n] = size()
      n = 11+83;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 83;
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
        buffer(i1+0) = typecast(uint8(obj.exit_loop),'uint8');
        buffer = obj.states.serialize_content(buffer,i1+1);
        buffer = obj.led_solid.serialize_content(buffer,i1+13);
        buffer = obj.led_blinking.serialize_content(buffer,i1+17);
        buffer = obj.led_spinning.serialize_content(buffer,i1+29);
        buffer = obj.led_progress.serialize_content(buffer,i1+69);
        buffer = obj.led_nav.serialize_content(buffer,i1+77);
        i2 = i1+83;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.exit_loop = typecast(buffer(i1+0),'uint8');
        obj.states.deserialize_content(buffer,i1+1);
        obj.led_solid.deserialize_content(buffer,i1+13);
        obj.led_blinking.deserialize_content(buffer,i1+17);
        obj.led_spinning.deserialize_content(buffer,i1+29);
        obj.led_progress.deserialize_content(buffer,i1+69);
        obj.led_nav.deserialize_content(buffer,i1+77);
        i2 = i1+83;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
