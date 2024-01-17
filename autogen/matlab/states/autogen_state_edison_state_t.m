%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/states/autogen_state_edison_state_t.m           %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_state_edison_state_t < uint8
  enumeration
    IDLE (0)
    INITIALIZE (1)
    ACTIVE (2)
    MEASURE (3)
    CLEAN (4)
    DEACTIVATE (5)
    BEGIN (autogen_state_edison_state_t.IDLE)
    END (autogen_state_edison_state_t.DEACTIVATE)
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
