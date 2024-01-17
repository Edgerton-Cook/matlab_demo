%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/states/autogen_state_cm_state_t.m               %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_state_cm_state_t < uint8
  enumeration
    INITIALIZE (0)
    DISCONNECTED (1)
    CONNECTED (2)
    OWNED (3)
    DEACTIVATE (4)
    IDLE (5)
    BEGIN (autogen_state_cm_state_t.INITIALIZE)
    END (autogen_state_cm_state_t.IDLE)
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
