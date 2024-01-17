function [] = mp_bode(G,varargin)
%% Handle Inputs
persistent mp_bode_settings

if (exist('mp_bode_settings','var') == 0)
  mp_bode_settings = mp_set_bode();
  clf
else
  if (~bode_settings_valid(mp_bode_settings))
    mp_bode_settings = mp_set_bode();
    clf
  end
end

arguments = cell(0,1);
for i=1:length(varargin)
  if (bode_settings_valid(varargin{i}))
    mp_bode_settings = varargin{i};
%     clf%DEBUG%
  else
    arguments{end+1,1} = varargin{i}; %#ok<AGROW>
  end
end

fontsize = mp_bode_settings.fontsize;
f_norm_Hz = mp_bode_settings.f_norm_Hz;
base = mp_bode_settings.base;
exp_lb = mp_bode_settings.exp_lb;
exp_ub = mp_bode_settings.exp_ub;
exp_density = mp_bode_settings.exp_density;
mag_lb = mp_bode_settings.mag_lb;
mag_ub = mp_bode_settings.mag_ub;
mag_delta = mp_bode_settings.mag_delta;
phase_lb = mp_bode_settings.phase_lb;
phase_ub = mp_bode_settings.phase_ub;
phase_delta = mp_bode_settings.phase_delta;
xscale = mp_bode_settings.xscale;
%% Preliminary Calculations
f_Hz = f_norm_Hz*base.^linspace(exp_lb,exp_ub,exp_density);
[G_mag_dB,G_phi_deg] = mp_tf_eval(G,f_Hz);

if isequal(xscale,'linear')
	f_norm = f_Hz/f_norm_Hz;
	f_norm_low = min(f_norm);
	f_norm_high = max(f_norm);
elseif isequal(xscale,'log')
	f_norm = log10(f_Hz/f_norm_Hz)/log10(2);
	f_norm_low = min(f_norm);
	f_norm_high = max(f_norm);
end
exponents = exp_lb:exp_ub;
mags = mag_lb:mag_delta:mag_ub;
phases = phase_lb:phase_delta:phase_ub;

if isequal(xscale,'linear')
	xticks = base.^exponents;
elseif isequal(xscale,'log')
	xticks = exponents;
end
xticklabel = cell(length(exponents),1);
for i = 1:length(xticklabel)
  if (exponents(i) < 0)
    xticklabel{i} = sprintf('1/%1.0f',base^(abs(exponents(i))));
  else
    xticklabel{i} = sprintf('%1.0f',base^(abs(exponents(i))));
  end
end

if isequal(get(0,'defaulttextinterpreter'),'latex')
  xlabelstr = sprintf('$f / %1.2f$ [Hz]',f_norm_Hz);
else
  xlabelstr = sprintf('f / %1.2f [Hz]',f_norm_Hz);
end

if (mp_bode_settings.mag_plot)&&(mp_bode_settings.phase_plot)
  n_plots = 2;
elseif (mp_bode_settings.mag_plot)
  n_plots = 1;
elseif (mp_bode_settings.phase_plot)
  n_plots = 1;
end
%% Magnitude Plot
if (mp_bode_settings.mag_plot)
  if (n_plots == 1)
    subplot(n_plots,1,1);
  else
    ax_mag = subplot(n_plots,1,1);
  end
  hold on,grid(mp_bode_settings.grid)
  
  % Plot magnitude.
  plot(f_norm,G_mag_dB,arguments{1:end})
  
  % Labels and settings.
  xlabel(xlabelstr)
  ylabel('Magnitude [dB]')
  set(gca,'xscale','linear', ...
          'xtick',xticks, ...
          'xticklabel',xticklabel, ...
          'ytick',mags, ...
          'xlim',[f_norm_low f_norm_high], ...
          'ylim',[min(mags) max(mags)], ...
          'fontsize',fontsize)
end
%% Phase Plot
if (mp_bode_settings.phase_plot)
  if (n_plots == 1)
    subplot(n_plots,1,1);
  else
    ax_phase = subplot(n_plots,1,2);
  end
  hold on,grid(mp_bode_settings.grid)
  
  % Plot phase.
  plot(f_norm,G_phi_deg,arguments{1:end})
  
  % Labels and settings.
  xlabel(xlabelstr)
  ylabel('Phase [deg]')
  set(gca,'xscale','linear', ...
          'xtick',xticks, ...
          'xticklabel',xticklabel, ...
          'ytick',phases, ...
          'xlim',[f_norm_low f_norm_high], ...
          'ylim',[min(phases) max(phases)], ...
          'fontsize',fontsize)
end

if (n_plots == 2)
  % Link frequency axes.
  linkaxes([ax_mag ax_phase],'x')
end
function [is_valid] = bode_settings_valid(S)
if (isstruct(S))
  fields = fieldnames(S,'-full');
  expected_fields = {'fontsize','f_norm_Hz','base', ...
                     'exp_lb','exp_ub','exp_density', ...
                     'mag_lb','mag_ub','mag_delta', ...
                     'phase_lb','phase_ub','phase_delta', ...
                     'xscale'};
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
