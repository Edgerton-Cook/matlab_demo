%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/autogen_matrix_single_16_1_t.m                  %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_matrix_single_16_1_t < handle
  properties (Access = public)
    mat(16,1) single;
  end
  methods (Sealed = true)
    function [buffer,i2] = serialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        buffer(i1+0+(0:3)) = typecast(obj.mat(1,1),'uint8');
        buffer(i1+4+(0:3)) = typecast(obj.mat(2,1),'uint8');
        buffer(i1+8+(0:3)) = typecast(obj.mat(3,1),'uint8');
        buffer(i1+12+(0:3)) = typecast(obj.mat(4,1),'uint8');
        buffer(i1+16+(0:3)) = typecast(obj.mat(5,1),'uint8');
        buffer(i1+20+(0:3)) = typecast(obj.mat(6,1),'uint8');
        buffer(i1+24+(0:3)) = typecast(obj.mat(7,1),'uint8');
        buffer(i1+28+(0:3)) = typecast(obj.mat(8,1),'uint8');
        buffer(i1+32+(0:3)) = typecast(obj.mat(9,1),'uint8');
        buffer(i1+36+(0:3)) = typecast(obj.mat(10,1),'uint8');
        buffer(i1+40+(0:3)) = typecast(obj.mat(11,1),'uint8');
        buffer(i1+44+(0:3)) = typecast(obj.mat(12,1),'uint8');
        buffer(i1+48+(0:3)) = typecast(obj.mat(13,1),'uint8');
        buffer(i1+52+(0:3)) = typecast(obj.mat(14,1),'uint8');
        buffer(i1+56+(0:3)) = typecast(obj.mat(15,1),'uint8');
        buffer(i1+60+(0:3)) = typecast(obj.mat(16,1),'uint8');
        i2 = i1+64;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        obj.mat(1,1) = typecast(buffer(i1+0+(0:3)),'single');
        obj.mat(2,1) = typecast(buffer(i1+4+(0:3)),'single');
        obj.mat(3,1) = typecast(buffer(i1+8+(0:3)),'single');
        obj.mat(4,1) = typecast(buffer(i1+12+(0:3)),'single');
        obj.mat(5,1) = typecast(buffer(i1+16+(0:3)),'single');
        obj.mat(6,1) = typecast(buffer(i1+20+(0:3)),'single');
        obj.mat(7,1) = typecast(buffer(i1+24+(0:3)),'single');
        obj.mat(8,1) = typecast(buffer(i1+28+(0:3)),'single');
        obj.mat(9,1) = typecast(buffer(i1+32+(0:3)),'single');
        obj.mat(10,1) = typecast(buffer(i1+36+(0:3)),'single');
        obj.mat(11,1) = typecast(buffer(i1+40+(0:3)),'single');
        obj.mat(12,1) = typecast(buffer(i1+44+(0:3)),'single');
        obj.mat(13,1) = typecast(buffer(i1+48+(0:3)),'single');
        obj.mat(14,1) = typecast(buffer(i1+52+(0:3)),'single');
        obj.mat(15,1) = typecast(buffer(i1+56+(0:3)),'single');
        obj.mat(16,1) = typecast(buffer(i1+60+(0:3)),'single');
        i2 = i1+64;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
