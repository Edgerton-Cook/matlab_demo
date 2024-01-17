function [f_Hz,mag_dB] = mp_power_spectrum(y,fs)

L = length(y);
if (mod(L,2) == 1)
  y = y(1:end-1);
  L = L-1;
end

Y = fft(y);
P2 = abs(Y/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

f_Hz = fs*(0:(L/2))/L;
mag_dB = 20*log10(P1);
