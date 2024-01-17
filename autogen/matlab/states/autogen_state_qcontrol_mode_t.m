%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/states/autogen_state_qcontrol_mode_t.m          %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_state_qcontrol_mode_t < uint8
  enumeration
    SAFETIED (0)
    STANDBY (1)
    TORQUES (2)
    RATES (3)
    INERTIAL (4)
    ATTITUDE (5)
    ALT (6)
    POS (7)
    TRAJ (8)
    BEGIN (autogen_state_qcontrol_mode_t.SAFETIED)
    END (autogen_state_qcontrol_mode_t.TRAJ)
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
