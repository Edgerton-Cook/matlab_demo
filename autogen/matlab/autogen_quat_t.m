%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/autogen_quat_t.m                                %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_quat_t < handle
  properties (Access = public)
    mat(4,1) single = [1 0 0 0]';
  end
  methods (Sealed = true)
    function [buffer,i2] = serialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        buffer(i1+0+(0:3)) = typecast(obj.mat(1),'uint8');
        buffer(i1+4+(0:3)) = typecast(obj.mat(2),'uint8');
        buffer(i1+8+(0:3)) = typecast(obj.mat(3),'uint8');
        buffer(i1+12+(0:3)) = typecast(obj.mat(4),'uint8');
        i2 = i1+16;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.mat(1) = typecast(buffer(i1+0+(0:3)),'single');
        obj.mat(2) = typecast(buffer(i1+4+(0:3)),'single');
        obj.mat(3) = typecast(buffer(i1+8+(0:3)),'single');
        obj.mat(4) = typecast(buffer(i1+12+(0:3)),'single');
        i2 = i1+16;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
