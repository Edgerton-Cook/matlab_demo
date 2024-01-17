%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_cm_config_data_t.m              %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_cm_config_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.CM_CONFIG_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_cm_config_data_t = autogen_topic_cm_config_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    master_ip1(1,1) uint8;
    master_ip2(1,1) uint8;
    master_ip3(1,1) uint8;
    master_ip4(1,1) uint8;
    master_port(1,1) uint16;
    max_mocap_data_counter(1,1) uint32;
    max_heartbeat_counter(1,1) uint32;
    guidance_computer_config(1,1) logical;
    default_quad_subs(1,1) autogen_cm_subscriptions_t;
    default_rover_subs(1,1) autogen_cm_subscriptions_t;
    tablet_ip1(1,1) uint8;
    tablet_ip2(1,1) uint8;
    tablet_ip3(1,1) uint8;
    tablet_ip4(1,1) uint8;
    tablet_port(1,1) uint16;
  end
  methods (Static)
    function [n] = size()
      n = 11+33;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 33;
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
        buffer(i1+0) = typecast(obj.master_ip1,'uint8');
        buffer(i1+1) = typecast(obj.master_ip2,'uint8');
        buffer(i1+2) = typecast(obj.master_ip3,'uint8');
        buffer(i1+3) = typecast(obj.master_ip4,'uint8');
        buffer(i1+(4:(4+1))) = typecast(obj.master_port,'uint8');
        buffer(i1+(6:(6+3))) = typecast(obj.max_mocap_data_counter,'uint8');
        buffer(i1+(10:(10+3))) = typecast(obj.max_heartbeat_counter,'uint8');
        buffer(i1+14) = typecast(uint8(obj.guidance_computer_config),'uint8');
        buffer = obj.default_quad_subs.serialize_content(buffer,i1+15);
        buffer = obj.default_rover_subs.serialize_content(buffer,i1+21);
        buffer(i1+27) = typecast(obj.tablet_ip1,'uint8');
        buffer(i1+28) = typecast(obj.tablet_ip2,'uint8');
        buffer(i1+29) = typecast(obj.tablet_ip3,'uint8');
        buffer(i1+30) = typecast(obj.tablet_ip4,'uint8');
        buffer(i1+(31:(31+1))) = typecast(obj.tablet_port,'uint8');
        i2 = i1+33;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.master_ip1 = typecast(buffer(i1+0),'uint8');
        obj.master_ip2 = typecast(buffer(i1+1),'uint8');
        obj.master_ip3 = typecast(buffer(i1+2),'uint8');
        obj.master_ip4 = typecast(buffer(i1+3),'uint8');
        obj.master_port = typecast(buffer(i1+(4:(4+1))),'uint16');
        obj.max_mocap_data_counter = typecast(buffer(i1+(6:(6+3))),'uint32');
        obj.max_heartbeat_counter = typecast(buffer(i1+(10:(10+3))),'uint32');
        obj.guidance_computer_config = typecast(buffer(i1+14),'uint8');
        obj.default_quad_subs.deserialize_content(buffer,i1+15);
        obj.default_rover_subs.deserialize_content(buffer,i1+21);
        obj.tablet_ip1 = typecast(buffer(i1+27),'uint8');
        obj.tablet_ip2 = typecast(buffer(i1+28),'uint8');
        obj.tablet_ip3 = typecast(buffer(i1+29),'uint8');
        obj.tablet_ip4 = typecast(buffer(i1+30),'uint8');
        obj.tablet_port = typecast(buffer(i1+(31:(31+1))),'uint16');
        i2 = i1+33;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
