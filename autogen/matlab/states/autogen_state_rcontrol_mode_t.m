%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/states/autogen_state_rcontrol_mode_t.m          %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_state_rcontrol_mode_t < uint8
  enumeration
    SAFETIED (0)
    STANDBY (1)
    TEST_MODE (2)
    OPEN_LOOP (3)
    CLOSED_LOOP_VEL (4)
    CLOSED_LOOP_POS (5)
    BEGIN (autogen_state_rcontrol_mode_t.SAFETIED)
    END (autogen_state_rcontrol_mode_t.CLOSED_LOOP_POS)
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
