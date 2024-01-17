%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_pca9685_local_data_t.m          %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_pca9685_local_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.PCA9685_LOCAL_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_pca9685_local_data_t = autogen_topic_pca9685_local_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    mode1_byte(1,1) uint8;
    mode2_byte(1,1) uint8;
    usec2counts(1,1) single;
    time_table_usec(16,2) uint16;
    calibration_complete(1,1) logical;
    i_calib_sample(1,1) uint32;
  end
  methods (Static)
    function [n] = size()
      n = 11+75;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 75;
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
        buffer(i1+0) = typecast(obj.mode1_byte,'uint8');
        buffer(i1+1) = typecast(obj.mode2_byte,'uint8');
        buffer(i1+(2:(2+3))) = typecast(obj.usec2counts,'uint8');
        for mpac_ijk0=1:16
          for mpac_ijk1=1:2
            buffer(i1+(6:(6+1))+2*((mpac_ijk0-1)*2+(mpac_ijk1-1))) = typecast(obj.time_table_usec(mpac_ijk0,mpac_ijk1),'uint8');
          end
        end
        buffer(i1+70) = typecast(uint8(obj.calibration_complete),'uint8');
        buffer(i1+(71:(71+3))) = typecast(obj.i_calib_sample,'uint8');
        i2 = i1+75;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.mode1_byte = typecast(buffer(i1+0),'uint8');
        obj.mode2_byte = typecast(buffer(i1+1),'uint8');
        obj.usec2counts = typecast(buffer(i1+(2:(2+3))),'single');
        for mpac_ijk0=1:16
          for mpac_ijk1=1:2
            obj.time_table_usec(mpac_ijk0,mpac_ijk1) = typecast(buffer(i1+(6:(6+1))+2*((mpac_ijk0-1)*2+(mpac_ijk1-1))),'uint16');
          end
        end
        obj.calibration_complete = typecast(buffer(i1+70),'uint8');
        obj.i_calib_sample = typecast(buffer(i1+(71:(71+3))),'uint32');
        i2 = i1+75;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
