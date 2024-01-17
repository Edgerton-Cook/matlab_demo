function [T_approx] = mp_tf_approx(T,num_order,den_order)

% This function assumes that T is a proper transfer function.
if (num_order > den_order)||(den_order == 0)
  T_approx = T;
  return;
end

f_Hz = 10.^linspace(-3,3,1000);
[T_mag_dB,T_phi_deg] = mp_tf_eval(T,f_Hz);

w = 2*pi*f_Hz';
Rw = (10.^(T_mag_dB'/20)).*cosd(T_phi_deg');
Iw = (10.^(T_mag_dB'/20)).*sind(T_phi_deg');

a_powers = num_order:-1:0;
b_powers = (den_order-1):-1:0;

Ha = (1j*w).^a_powers;
Hb = (1j*w).^b_powers;

yR = Rw.*real(1j^(den_order  )*w.^den_order) ...
    +Iw.*real(1j^(den_order+1)*w.^den_order);
yI = Rw.*imag(1j^(den_order  )*w.^den_order) ...
    +Iw.*imag(1j^(den_order+1)*w.^den_order);

HRa = real(Ha);
HIa = imag(Ha);
HRb = real(Hb);
HIb = imag(Hb);

y = [yR; yI];
H = [HRa -(Rw*ones(1,den_order)).*HRb+(Iw*ones(1,den_order)).*HIb
     HIa -(Iw*ones(1,den_order)).*HRb-(Rw*ones(1,den_order)).*HIb];

x_hat = (H'*H)\H'*y;
x_hat(abs(x_hat) < 1e-15) = 0;

a_hat = x_hat(1:num_order+1);
b_hat = x_hat((1:den_order)+(num_order+1));
T_approx = zpk(tf(a_hat',[1 b_hat']));
