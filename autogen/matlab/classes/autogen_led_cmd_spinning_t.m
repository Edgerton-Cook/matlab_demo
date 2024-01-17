%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_led_cmd_spinning_t.m            %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_led_cmd_spinning_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.LED_CMD_SPINNING;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_led_cmd_spinning_t = autogen_topic_led_cmd_spinning_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    phi_r(1,1) single;
    phi_g(1,1) single;
    phi_b(1,1) single;
    ft_r(1,1) single;
    fs_r(1,1) single;
    ft_g(1,1) single;
    fs_g(1,1) single;
    ft_b(1,1) single;
    fs_b(1,1) single;
    global(1,1) uint8;
    red(1,1) uint8;
    green(1,1) uint8;
    blue(1,1) uint8;
  end
  methods (Static)
    function [n] = size()
      n = 11+40;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 40;
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
        buffer(i1+(0:(0+3))) = typecast(obj.phi_r,'uint8');
        buffer(i1+(4:(4+3))) = typecast(obj.phi_g,'uint8');
        buffer(i1+(8:(8+3))) = typecast(obj.phi_b,'uint8');
        buffer(i1+(12:(12+3))) = typecast(obj.ft_r,'uint8');
        buffer(i1+(16:(16+3))) = typecast(obj.fs_r,'uint8');
        buffer(i1+(20:(20+3))) = typecast(obj.ft_g,'uint8');
        buffer(i1+(24:(24+3))) = typecast(obj.fs_g,'uint8');
        buffer(i1+(28:(28+3))) = typecast(obj.ft_b,'uint8');
        buffer(i1+(32:(32+3))) = typecast(obj.fs_b,'uint8');
        buffer(i1+36) = typecast(obj.global,'uint8');
        buffer(i1+37) = typecast(obj.red,'uint8');
        buffer(i1+38) = typecast(obj.green,'uint8');
        buffer(i1+39) = typecast(obj.blue,'uint8');
        i2 = i1+40;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.phi_r = typecast(buffer(i1+(0:(0+3))),'single');
        obj.phi_g = typecast(buffer(i1+(4:(4+3))),'single');
        obj.phi_b = typecast(buffer(i1+(8:(8+3))),'single');
        obj.ft_r = typecast(buffer(i1+(12:(12+3))),'single');
        obj.fs_r = typecast(buffer(i1+(16:(16+3))),'single');
        obj.ft_g = typecast(buffer(i1+(20:(20+3))),'single');
        obj.fs_g = typecast(buffer(i1+(24:(24+3))),'single');
        obj.ft_b = typecast(buffer(i1+(28:(28+3))),'single');
        obj.fs_b = typecast(buffer(i1+(32:(32+3))),'single');
        obj.global = typecast(buffer(i1+36),'uint8');
        obj.red = typecast(buffer(i1+37),'uint8');
        obj.green = typecast(buffer(i1+38),'uint8');
        obj.blue = typecast(buffer(i1+39),'uint8');
        i2 = i1+40;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
