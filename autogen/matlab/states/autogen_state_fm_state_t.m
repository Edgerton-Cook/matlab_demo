%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/states/autogen_state_fm_state_t.m               %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_state_fm_state_t < uint8
  enumeration
    BOOT (0)
    IDLE (1)
    INITIALIZE (2)
    ACTIVE (3)
    TEST_MODE (4)
    DEACTIVATE (5)
    CALIBRATE_IMU (6)
    CALIBRATE_MAG (7)
    CALIBRATE_PWM (8)
    CALIBRATE_ESC (9)
    SHUTDOWN (10)
    BEGIN (autogen_state_fm_state_t.BOOT)
    END (autogen_state_fm_state_t.SHUTDOWN)
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
