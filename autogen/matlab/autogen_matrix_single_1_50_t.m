%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/autogen_matrix_single_1_50_t.m                  %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_matrix_single_1_50_t < handle
  properties (Access = public)
    mat(1,50) single;
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
        buffer(i1+24+(0:3)) = typecast(obj.mat(1,7),'uint8');
        buffer(i1+28+(0:3)) = typecast(obj.mat(1,8),'uint8');
        buffer(i1+32+(0:3)) = typecast(obj.mat(1,9),'uint8');
        buffer(i1+36+(0:3)) = typecast(obj.mat(1,10),'uint8');
        buffer(i1+40+(0:3)) = typecast(obj.mat(1,11),'uint8');
        buffer(i1+44+(0:3)) = typecast(obj.mat(1,12),'uint8');
        buffer(i1+48+(0:3)) = typecast(obj.mat(1,13),'uint8');
        buffer(i1+52+(0:3)) = typecast(obj.mat(1,14),'uint8');
        buffer(i1+56+(0:3)) = typecast(obj.mat(1,15),'uint8');
        buffer(i1+60+(0:3)) = typecast(obj.mat(1,16),'uint8');
        buffer(i1+64+(0:3)) = typecast(obj.mat(1,17),'uint8');
        buffer(i1+68+(0:3)) = typecast(obj.mat(1,18),'uint8');
        buffer(i1+72+(0:3)) = typecast(obj.mat(1,19),'uint8');
        buffer(i1+76+(0:3)) = typecast(obj.mat(1,20),'uint8');
        buffer(i1+80+(0:3)) = typecast(obj.mat(1,21),'uint8');
        buffer(i1+84+(0:3)) = typecast(obj.mat(1,22),'uint8');
        buffer(i1+88+(0:3)) = typecast(obj.mat(1,23),'uint8');
        buffer(i1+92+(0:3)) = typecast(obj.mat(1,24),'uint8');
        buffer(i1+96+(0:3)) = typecast(obj.mat(1,25),'uint8');
        buffer(i1+100+(0:3)) = typecast(obj.mat(1,26),'uint8');
        buffer(i1+104+(0:3)) = typecast(obj.mat(1,27),'uint8');
        buffer(i1+108+(0:3)) = typecast(obj.mat(1,28),'uint8');
        buffer(i1+112+(0:3)) = typecast(obj.mat(1,29),'uint8');
        buffer(i1+116+(0:3)) = typecast(obj.mat(1,30),'uint8');
        buffer(i1+120+(0:3)) = typecast(obj.mat(1,31),'uint8');
        buffer(i1+124+(0:3)) = typecast(obj.mat(1,32),'uint8');
        buffer(i1+128+(0:3)) = typecast(obj.mat(1,33),'uint8');
        buffer(i1+132+(0:3)) = typecast(obj.mat(1,34),'uint8');
        buffer(i1+136+(0:3)) = typecast(obj.mat(1,35),'uint8');
        buffer(i1+140+(0:3)) = typecast(obj.mat(1,36),'uint8');
        buffer(i1+144+(0:3)) = typecast(obj.mat(1,37),'uint8');
        buffer(i1+148+(0:3)) = typecast(obj.mat(1,38),'uint8');
        buffer(i1+152+(0:3)) = typecast(obj.mat(1,39),'uint8');
        buffer(i1+156+(0:3)) = typecast(obj.mat(1,40),'uint8');
        buffer(i1+160+(0:3)) = typecast(obj.mat(1,41),'uint8');
        buffer(i1+164+(0:3)) = typecast(obj.mat(1,42),'uint8');
        buffer(i1+168+(0:3)) = typecast(obj.mat(1,43),'uint8');
        buffer(i1+172+(0:3)) = typecast(obj.mat(1,44),'uint8');
        buffer(i1+176+(0:3)) = typecast(obj.mat(1,45),'uint8');
        buffer(i1+180+(0:3)) = typecast(obj.mat(1,46),'uint8');
        buffer(i1+184+(0:3)) = typecast(obj.mat(1,47),'uint8');
        buffer(i1+188+(0:3)) = typecast(obj.mat(1,48),'uint8');
        buffer(i1+192+(0:3)) = typecast(obj.mat(1,49),'uint8');
        buffer(i1+196+(0:3)) = typecast(obj.mat(1,50),'uint8');
        i2 = i1+200;
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
        obj.mat(1,7) = typecast(buffer(i1+24+(0:3)),'single');
        obj.mat(1,8) = typecast(buffer(i1+28+(0:3)),'single');
        obj.mat(1,9) = typecast(buffer(i1+32+(0:3)),'single');
        obj.mat(1,10) = typecast(buffer(i1+36+(0:3)),'single');
        obj.mat(1,11) = typecast(buffer(i1+40+(0:3)),'single');
        obj.mat(1,12) = typecast(buffer(i1+44+(0:3)),'single');
        obj.mat(1,13) = typecast(buffer(i1+48+(0:3)),'single');
        obj.mat(1,14) = typecast(buffer(i1+52+(0:3)),'single');
        obj.mat(1,15) = typecast(buffer(i1+56+(0:3)),'single');
        obj.mat(1,16) = typecast(buffer(i1+60+(0:3)),'single');
        obj.mat(1,17) = typecast(buffer(i1+64+(0:3)),'single');
        obj.mat(1,18) = typecast(buffer(i1+68+(0:3)),'single');
        obj.mat(1,19) = typecast(buffer(i1+72+(0:3)),'single');
        obj.mat(1,20) = typecast(buffer(i1+76+(0:3)),'single');
        obj.mat(1,21) = typecast(buffer(i1+80+(0:3)),'single');
        obj.mat(1,22) = typecast(buffer(i1+84+(0:3)),'single');
        obj.mat(1,23) = typecast(buffer(i1+88+(0:3)),'single');
        obj.mat(1,24) = typecast(buffer(i1+92+(0:3)),'single');
        obj.mat(1,25) = typecast(buffer(i1+96+(0:3)),'single');
        obj.mat(1,26) = typecast(buffer(i1+100+(0:3)),'single');
        obj.mat(1,27) = typecast(buffer(i1+104+(0:3)),'single');
        obj.mat(1,28) = typecast(buffer(i1+108+(0:3)),'single');
        obj.mat(1,29) = typecast(buffer(i1+112+(0:3)),'single');
        obj.mat(1,30) = typecast(buffer(i1+116+(0:3)),'single');
        obj.mat(1,31) = typecast(buffer(i1+120+(0:3)),'single');
        obj.mat(1,32) = typecast(buffer(i1+124+(0:3)),'single');
        obj.mat(1,33) = typecast(buffer(i1+128+(0:3)),'single');
        obj.mat(1,34) = typecast(buffer(i1+132+(0:3)),'single');
        obj.mat(1,35) = typecast(buffer(i1+136+(0:3)),'single');
        obj.mat(1,36) = typecast(buffer(i1+140+(0:3)),'single');
        obj.mat(1,37) = typecast(buffer(i1+144+(0:3)),'single');
        obj.mat(1,38) = typecast(buffer(i1+148+(0:3)),'single');
        obj.mat(1,39) = typecast(buffer(i1+152+(0:3)),'single');
        obj.mat(1,40) = typecast(buffer(i1+156+(0:3)),'single');
        obj.mat(1,41) = typecast(buffer(i1+160+(0:3)),'single');
        obj.mat(1,42) = typecast(buffer(i1+164+(0:3)),'single');
        obj.mat(1,43) = typecast(buffer(i1+168+(0:3)),'single');
        obj.mat(1,44) = typecast(buffer(i1+172+(0:3)),'single');
        obj.mat(1,45) = typecast(buffer(i1+176+(0:3)),'single');
        obj.mat(1,46) = typecast(buffer(i1+180+(0:3)),'single');
        obj.mat(1,47) = typecast(buffer(i1+184+(0:3)),'single');
        obj.mat(1,48) = typecast(buffer(i1+188+(0:3)),'single');
        obj.mat(1,49) = typecast(buffer(i1+192+(0:3)),'single');
        obj.mat(1,50) = typecast(buffer(i1+196+(0:3)),'single');
        i2 = i1+200;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
