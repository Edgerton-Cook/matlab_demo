%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/autogen_matrix_single_6_6_t.m                   %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_matrix_single_6_6_t < handle
  properties (Access = public)
    mat(6,6) single;
  end
  methods (Sealed = true)
    function [buffer,i2] = serialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        buffer(i1+0+(0:3)) = typecast(obj.mat(1,1),'uint8');
        buffer(i1+4+(0:3)) = typecast(obj.mat(1,2),'uint8');
        buffer(i1+8+(0:3)) = typecast(obj.mat(1,3),'uint8');
        buffer(i1+12+(0:3)) = typecast(obj.mat(1,4),'uint8');
        buffer(i1+16+(0:3)) = typecast(obj.mat(1,5),'uint8');
        buffer(i1+20+(0:3)) = typecast(obj.mat(1,6),'uint8');
        buffer(i1+24+(0:3)) = typecast(obj.mat(2,1),'uint8');
        buffer(i1+28+(0:3)) = typecast(obj.mat(2,2),'uint8');
        buffer(i1+32+(0:3)) = typecast(obj.mat(2,3),'uint8');
        buffer(i1+36+(0:3)) = typecast(obj.mat(2,4),'uint8');
        buffer(i1+40+(0:3)) = typecast(obj.mat(2,5),'uint8');
        buffer(i1+44+(0:3)) = typecast(obj.mat(2,6),'uint8');
        buffer(i1+48+(0:3)) = typecast(obj.mat(3,1),'uint8');
        buffer(i1+52+(0:3)) = typecast(obj.mat(3,2),'uint8');
        buffer(i1+56+(0:3)) = typecast(obj.mat(3,3),'uint8');
        buffer(i1+60+(0:3)) = typecast(obj.mat(3,4),'uint8');
        buffer(i1+64+(0:3)) = typecast(obj.mat(3,5),'uint8');
        buffer(i1+68+(0:3)) = typecast(obj.mat(3,6),'uint8');
        buffer(i1+72+(0:3)) = typecast(obj.mat(4,1),'uint8');
        buffer(i1+76+(0:3)) = typecast(obj.mat(4,2),'uint8');
        buffer(i1+80+(0:3)) = typecast(obj.mat(4,3),'uint8');
        buffer(i1+84+(0:3)) = typecast(obj.mat(4,4),'uint8');
        buffer(i1+88+(0:3)) = typecast(obj.mat(4,5),'uint8');
        buffer(i1+92+(0:3)) = typecast(obj.mat(4,6),'uint8');
        buffer(i1+96+(0:3)) = typecast(obj.mat(5,1),'uint8');
        buffer(i1+100+(0:3)) = typecast(obj.mat(5,2),'uint8');
        buffer(i1+104+(0:3)) = typecast(obj.mat(5,3),'uint8');
        buffer(i1+108+(0:3)) = typecast(obj.mat(5,4),'uint8');
        buffer(i1+112+(0:3)) = typecast(obj.mat(5,5),'uint8');
        buffer(i1+116+(0:3)) = typecast(obj.mat(5,6),'uint8');
        buffer(i1+120+(0:3)) = typecast(obj.mat(6,1),'uint8');
        buffer(i1+124+(0:3)) = typecast(obj.mat(6,2),'uint8');
        buffer(i1+128+(0:3)) = typecast(obj.mat(6,3),'uint8');
        buffer(i1+132+(0:3)) = typecast(obj.mat(6,4),'uint8');
        buffer(i1+136+(0:3)) = typecast(obj.mat(6,5),'uint8');
        buffer(i1+140+(0:3)) = typecast(obj.mat(6,6),'uint8');
        i2 = i1+144;
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
        obj.mat(1,4) = typecast(buffer(i1+12+(0:3)),'single');
        obj.mat(1,5) = typecast(buffer(i1+16+(0:3)),'single');
        obj.mat(1,6) = typecast(buffer(i1+20+(0:3)),'single');
        obj.mat(2,1) = typecast(buffer(i1+24+(0:3)),'single');
        obj.mat(2,2) = typecast(buffer(i1+28+(0:3)),'single');
        obj.mat(2,3) = typecast(buffer(i1+32+(0:3)),'single');
        obj.mat(2,4) = typecast(buffer(i1+36+(0:3)),'single');
        obj.mat(2,5) = typecast(buffer(i1+40+(0:3)),'single');
        obj.mat(2,6) = typecast(buffer(i1+44+(0:3)),'single');
        obj.mat(3,1) = typecast(buffer(i1+48+(0:3)),'single');
        obj.mat(3,2) = typecast(buffer(i1+52+(0:3)),'single');
        obj.mat(3,3) = typecast(buffer(i1+56+(0:3)),'single');
        obj.mat(3,4) = typecast(buffer(i1+60+(0:3)),'single');
        obj.mat(3,5) = typecast(buffer(i1+64+(0:3)),'single');
        obj.mat(3,6) = typecast(buffer(i1+68+(0:3)),'single');
        obj.mat(4,1) = typecast(buffer(i1+72+(0:3)),'single');
        obj.mat(4,2) = typecast(buffer(i1+76+(0:3)),'single');
        obj.mat(4,3) = typecast(buffer(i1+80+(0:3)),'single');
        obj.mat(4,4) = typecast(buffer(i1+84+(0:3)),'single');
        obj.mat(4,5) = typecast(buffer(i1+88+(0:3)),'single');
        obj.mat(4,6) = typecast(buffer(i1+92+(0:3)),'single');
        obj.mat(5,1) = typecast(buffer(i1+96+(0:3)),'single');
        obj.mat(5,2) = typecast(buffer(i1+100+(0:3)),'single');
        obj.mat(5,3) = typecast(buffer(i1+104+(0:3)),'single');
        obj.mat(5,4) = typecast(buffer(i1+108+(0:3)),'single');
        obj.mat(5,5) = typecast(buffer(i1+112+(0:3)),'single');
        obj.mat(5,6) = typecast(buffer(i1+116+(0:3)),'single');
        obj.mat(6,1) = typecast(buffer(i1+120+(0:3)),'single');
        obj.mat(6,2) = typecast(buffer(i1+124+(0:3)),'single');
        obj.mat(6,3) = typecast(buffer(i1+128+(0:3)),'single');
        obj.mat(6,4) = typecast(buffer(i1+132+(0:3)),'single');
        obj.mat(6,5) = typecast(buffer(i1+136+(0:3)),'single');
        obj.mat(6,6) = typecast(buffer(i1+140+(0:3)),'single');
        i2 = i1+144;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
