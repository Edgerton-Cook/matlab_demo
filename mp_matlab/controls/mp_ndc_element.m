 function [W] = mp_ndc_element(C,P,T_E)

% This function computes the transfer function of the NDC anti-windup
% elemenet W (which is the transfer function G*P/T_p in Figures 
% 10.19-10.21 in Boris Lurie's "Classical Feedback Control"). The transfer
% functions C, P, and T_E represent the low-signal-level controller (i.e.
% the controller used when the actuator is not saturated), the plant (which
% can also include the actuator and sensor dynamics -- that is the 
% standard loop transfer function sans the controller), and the desired 
% transfer function of the saturated loop (i.e. from input of P to the
% output of C). For more details, see Section 10.7 in Boris Lurie's 
% textbook.

T_P = minreal(C*P);
G = minreal((T_P-T_E)/(1+T_E));
W = minreal(G/C);
