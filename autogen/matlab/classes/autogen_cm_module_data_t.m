%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_cm_module_data_t.m              %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_cm_module_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.CM_MODULE_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_cm_module_data_t = autogen_topic_cm_module_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    state(1,1) autogen_cm_state_t;
    uplink(1,1) autogen_cm_uplink_data_t;
    local(1,1) autogen_cm_local_data_t;
    config(1,1) autogen_cm_config_data_t;
  end
  methods (Static)
    function [n] = size()
      n = 11+2329;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 2329;
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
        buffer = obj.state.serialize_content(buffer,i1+0);
        buffer = obj.uplink.serialize_content(buffer,i1+1);
        buffer = obj.local.serialize_content(buffer,i1+2275);
        buffer = obj.config.serialize_content(buffer,i1+2296);
        i2 = i1+2329;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.state.deserialize_content(buffer,i1+0);
        obj.uplink.deserialize_content(buffer,i1+1);
        obj.local.deserialize_content(buffer,i1+2275);
        obj.config.deserialize_content(buffer,i1+2296);
        i2 = i1+2329;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
