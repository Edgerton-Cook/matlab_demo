function [mag_dB,phi_deg] = mp_tf_eval(G,f_Hz)

% G can be a double or a 'tf', 'ss', or 'zpk' object.
if (isnumeric(G))||(isa(G,'tf'))||(isa(G,'ss'))||(isa(G,'zpk'))
  G_zpk = zpk(G);
  delay = G_zpk.IODelay+G_zpk.InputDelay+G_zpk.OutputDelay;
end

G = minreal(G);
if isequal(G_zpk.variable,'s')
  s = 1j*2*pi*f_Hz;
elseif isequal(G_zpk.variable,'z')
  f_nyq_Hz = 0.5/G_zpk.Ts;
  f_Hz(f_Hz > f_nyq_Hz) = NaN;
  s = exp(1j*pi*f_Hz/f_nyq_Hz);
end

K = G_zpk.K;
Z = G_zpk.Z{1};
P = G_zpk.P{1};

mag_dB = 20*log10(abs(K)*ones(size(f_Hz)));
phi_deg = -360*f_Hz*delay;

if (K < 0)
  phi_deg = phi_deg-180;
end

for i=1:length(Z)
  vz = s-Z(i);
  mag_dB = mag_dB+20*log10(abs(vz));
  phi_deg = phi_deg+atan2d(imag(vz),real(vz));
end
for i=1:length(P)
  vp = s-P(i);
  mag_dB = mag_dB-20*log10(abs(vp));
  phi_deg = phi_deg-atan2d(imag(vp),real(vp));
end
