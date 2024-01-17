%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/states/autogen_state_fm_trans_cmd_t.m           %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_state_fm_trans_cmd_t < uint8
  enumeration
    NOTHING (0)
    RUN (1)
    TEST_MODE (2)
    STOP (3)
    CALIBRATE_IMU (4)
    CALIBRATE_MAG (5)
    CALIBRATE_PWM (6)
    CALIBRATE_ESC (7)
    EXIT (8)
    BEGIN (autogen_state_fm_trans_cmd_t.NOTHING)
    END (autogen_state_fm_trans_cmd_t.EXIT)
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
