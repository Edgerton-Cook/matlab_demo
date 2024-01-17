function [t,X] = mp_rk4(fun,t,X_i)

K = length(t);
n = length(X_i);
X = zeros(n,K);

X(:,1) = X_i;

for k=1:K-1
  tk = t(k);
  xk = X(:,k);
  tkp1 = t(k+1);
  h = tkp1-tk;

  k1 = feval(fun,tk,xk);
  k2 = feval(fun,tk+h/2,xk+h/2*k1);
  k3 = feval(fun,tk+h/2,xk+h/2*k2);
  k4 = feval(fun,tk+h,xk+h*k3);

  X(:,k+1) = xk+h/6*(k1+2*k2+2*k3+k4);
end

X = X';
