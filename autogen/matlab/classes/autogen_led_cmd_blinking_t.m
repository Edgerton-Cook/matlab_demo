%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_led_cmd_blinking_t.m            %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_led_cmd_blinking_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.LED_CMD_BLINKING;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_led_cmd_blinking_t = autogen_topic_led_cmd_blinking_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    t(1,1) single;
    freq(1,1) single;
    global(1,1) uint8;
    red(1,1) uint8;
    green(1,1) uint8;
    blue(1,1) uint8;
  end
  methods (Static)
    function [n] = size()
      n = 11+12;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 12;
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
        buffer(i1+(0:(0+3))) = typecast(obj.t,'uint8');
        buffer(i1+(4:(4+3))) = typecast(obj.freq,'uint8');
        buffer(i1+8) = typecast(obj.global,'uint8');
        buffer(i1+9) = typecast(obj.red,'uint8');
        buffer(i1+10) = typecast(obj.green,'uint8');
        buffer(i1+11) = typecast(obj.blue,'uint8');
        i2 = i1+12;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.t = typecast(buffer(i1+(0:(0+3))),'single');
        obj.freq = typecast(buffer(i1+(4:(4+3))),'single');
        obj.global = typecast(buffer(i1+8),'uint8');
        obj.red = typecast(buffer(i1+9),'uint8');
        obj.green = typecast(buffer(i1+10),'uint8');
        obj.blue = typecast(buffer(i1+11),'uint8');
        i2 = i1+12;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
