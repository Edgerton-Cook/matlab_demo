function [S] = mp_set_nichols()

S = struct;
S.fontsize = 10; % Font Size
S.f_norm_Hz = 1.0; % Normalization frequency [Hz]
S.base = 2; % Base (e.g. base-10, base-2)
S.exp_lb = -8; % Lower-bound of decades, octaves, etc.
S.exp_ub = 8; % Upper-bound of decades, octaves, etc.
S.exp_density = 1000; % Number of points in plot
S.mag_lb = -30; % Magnitude lower-bound [dB]
S.mag_ub = 30; % Magnitude upper-bound [dB]
S.mag_delta = 10; % Magnitude tick intervals [dB]
S.phase_lb = -360; % Phase lower-bound [deg]
S.phase_ub = -90; % Phase upper-bound [deg]
S.phase_delta = 45; % Phase tick intervals [deg]
S.gain_margin_low = 6; % Gain margin lower-bound [dB]
S.gain_margin_high = 10; % Gain margin upper-bound [dB]
S.phase_margin = 35; % Phase margin [deg]
S.margin_color = 0.4*[1 1 1]; % Margin boundary color
S.margin_linewidth = 2; % Margin boundary line width
S.marker_size = 10; % Frequency marker size
S.f_samp = NaN; % Sampling frequency (NaN = off) [Hz]
S.show_pos_fb_region = true; % Show region of positive feedback
S.grid = 'on';
