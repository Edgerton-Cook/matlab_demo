%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/autogen_dcm_t.m                                 %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_dcm_t < handle
  properties (Access = public)
    mat(3,3) single = eye(3,3);
  end
  methods (Sealed = true)
    function [buffer,i2] = serialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        buffer(i1+0+(0:3)) = typecast(obj.mat(1,1),'uint8');
        buffer(i1+4+(0:3)) = typecast(obj.mat(1,2),'uint8');
        buffer(i1+8+(0:3)) = typecast(obj.mat(1,3),'uint8');
        buffer(i1+12+(0:3)) = typecast(obj.mat(2,1),'uint8');
        buffer(i1+16+(0:3)) = typecast(obj.mat(2,2),'uint8');
        buffer(i1+20+(0:3)) = typecast(obj.mat(2,3),'uint8');
        buffer(i1+24+(0:3)) = typecast(obj.mat(3,1),'uint8');
        buffer(i1+28+(0:3)) = typecast(obj.mat(3,2),'uint8');
        buffer(i1+32+(0:3)) = typecast(obj.mat(3,3),'uint8');
        i2 = i1+36;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.mat(1,1) = typecast(buffer(i1+0+(0:3)),'single');
        obj.mat(1,2) = typecast(buffer(i1+4+(0:3)),'single');
        obj.mat(1,3) = typecast(buffer(i1+8+(0:3)),'single');
        obj.mat(2,1) = typecast(buffer(i1+12+(0:3)),'single');
        obj.mat(2,2) = typecast(buffer(i1+16+(0:3)),'single');
        obj.mat(2,3) = typecast(buffer(i1+20+(0:3)),'single');
        obj.mat(3,1) = typecast(buffer(i1+24+(0:3)),'single');
        obj.mat(3,2) = typecast(buffer(i1+28+(0:3)),'single');
        obj.mat(3,3) = typecast(buffer(i1+32+(0:3)),'single');
        i2 = i1+36;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
