function [] = mp_nichols(G,varargin)
%% Handle Inputs
persistent mp_nichols_settings

if (exist('mp_nichols_settings','var') == 0)
  mp_nichols_settings = mp_set_nichols();
  clf
else
  if (~nichols_settings_valid(mp_nichols_settings))
    mp_nichols_settings = mp_set_nichols();
    clf
  end
end

arguments = cell(0,1);
for i=1:length(varargin)
  if (nichols_settings_valid(varargin{i}))
    mp_nichols_settings = varargin{i};
%     clf%DEBUG%
  else
    arguments{end+1,1} = varargin{i}; %#ok<AGROW>
  end
end

fontsize = mp_nichols_settings.fontsize;
f_norm_Hz = mp_nichols_settings.f_norm_Hz;
base = mp_nichols_settings.base;
exp_lb = mp_nichols_settings.exp_lb;
exp_ub = mp_nichols_settings.exp_ub;
exp_density = mp_nichols_settings.exp_density;
mag_lb = mp_nichols_settings.mag_lb;
mag_ub = mp_nichols_settings.mag_ub;
mag_delta = mp_nichols_settings.mag_delta;
phase_lb = mp_nichols_settings.phase_lb;
phase_ub = mp_nichols_settings.phase_ub;
phase_delta = mp_nichols_settings.phase_delta;
gain_margin_low = mp_nichols_settings.gain_margin_low;
gain_margin_high = mp_nichols_settings.gain_margin_high;
phase_margin = mp_nichols_settings.phase_margin;
margin_color = mp_nichols_settings.margin_color;
margin_linewidth = mp_nichols_settings.margin_linewidth;
marker_size = mp_nichols_settings.marker_size;
f_samp = mp_nichols_settings.f_samp;
show_pos_fb_region = mp_nichols_settings.show_pos_fb_region;
%% Preliminary Calculations
f_Hz = f_norm_Hz*base.^linspace(exp_lb,exp_ub,exp_density);
[G_mag_dB,G_phi_deg] = mp_tf_eval(G,f_Hz);

exponents = exp_lb:exp_ub;
f_Hz_points = f_norm_Hz*(base.^exponents);
G_mag_dB_points = interp1(f_Hz,G_mag_dB,f_Hz_points);
G_phi_deg_points = interp1(f_Hz,G_phi_deg,f_Hz_points);
%% Nichols Plot
hold on,grid(mp_nichols_settings.grid)

% Plot critical point.
plot(-180,0,'color',0.0*[1 1 1], ...
     'marker','.','markersize',20);

% Plot region of positive feedback.
if (show_pos_fb_region)
  for fb=0.0:0.1:1.0
    ang = linspace(0,360,1000);
    rad = fb;
    
    re = -1+rad.*cosd(ang);
    im =  0+rad.*sind(ang);
    
    ol_gain = 20*log10((re.^2+im.^2).^0.5);
    ol_phase = atan2d(im,re);
    
    ol_phase(ol_phase > 0) = ol_phase(ol_phase > 0)-360;
    
    if (fb == 1.0)
      plot(ol_phase,ol_gain, ...
           'color',0.50*[1 1 1], ...
           'linestyle',':', ...
           'linewidth',1)
    else
      plot(ol_phase,ol_gain, ...
           'color',0.90*[1 1 1], ...
           'linestyle',':', ...
           'linewidth',1)
    end
  end
end

% Plot phase/gain margin box.
plot(-180+phase_margin*[-1 1 1 -1 -1 1], ...
     [ gain_margin_high ...
       gain_margin_high ...
      -gain_margin_low ...
      -gain_margin_low ...
       gain_margin_high ...
       gain_margin_high], ...
       'color',margin_color, ...
       'linewidth',margin_linewidth)

% Plot Nichols plot.
plot(G_phi_deg,G_mag_dB,arguments{1:end})
h_points = plot(G_phi_deg_points,G_mag_dB_points,arguments{1:end});
set(h_points,'marker','.','linestyle','none','markersize',marker_size)

% Labels and settings.
xlabel('Loop Phase [deg]')
ylabel('Loop Magnitude [dB]')
set(gca,'xtick',phase_lb:phase_delta:phase_ub, ...
        'ytick',mag_lb:mag_delta:mag_ub, ...
        'xlim',[phase_lb phase_ub], ...
        'ylim',[mag_lb mag_ub], ...
        'fontsize',fontsize)
%% Sampling Frequency Marker
if ~isnan(f_samp)
  f_nyquist_Hz = 0.5*f_samp;
  mag_nyquist_dB = interp1(f_Hz,G_mag_dB,f_nyquist_Hz);
  phi_nyquist_deg = interp1(f_Hz,G_phi_deg,f_nyquist_Hz);
  lh1 = plot(phi_nyquist_deg,mag_nyquist_dB,arguments{1:end});
  lh2 = plot(phi_nyquist_deg,mag_nyquist_dB,arguments{1:end});
  set(lh1,'marker','o','linestyle','none')
  set(lh2,'marker','+','linestyle','none')
end
function [is_valid] = nichols_settings_valid(S)
if (isstruct(S))
  fields = fieldnames(S,'-full');
  expected_fields = {'fontsize','f_norm_Hz','base', ...
                     'exp_lb','exp_ub','exp_density', ...
                     'mag_lb','mag_ub','mag_delta', ...
                     'phase_lb','phase_ub','phase_delta', ...
										 'show_pos_fb_region'};
  checked = 0;
  for j=1:length(expected_fields)
    for k=1:length(fields)
      if (isequal(expected_fields{j},fields{k}))
        checked = checked+1;
      end
    end
  end
  is_valid = (checked == length(expected_fields));
else
  is_valid = false;
end
