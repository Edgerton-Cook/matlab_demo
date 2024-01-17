%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/states/autogen_state_led_state_t.m              %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_state_led_state_t < uint8
  enumeration
    IDLE (0)
    INITIALIZE (1)
    ACTIVE (2)
    ACTIVE_RGB_SOLID (3)
    ACTIVE_RGB_BLINKING (4)
    ACTIVE_RGB_SPINNING (5)
    ACTIVE_RGB_PROGRESS (6)
    ACTIVE_RGB_NAV (7)
    DEACTIVATE (8)
    BEGIN (autogen_state_led_state_t.IDLE)
    END (autogen_state_led_state_t.DEACTIVATE)
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
