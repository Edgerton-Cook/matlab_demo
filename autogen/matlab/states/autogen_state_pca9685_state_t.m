%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/states/autogen_state_pca9685_state_t.m          %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_state_pca9685_state_t < uint8
  enumeration
    IDLE (0)
    INITIALIZE (1)
    SAFE (2)
    ACTIVE (3)
    MIN (4)
    MAX (5)
    CALIBRATE (6)
    DEACTIVATE (7)
    BEGIN (autogen_state_pca9685_state_t.IDLE)
    END (autogen_state_pca9685_state_t.DEACTIVATE)
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
