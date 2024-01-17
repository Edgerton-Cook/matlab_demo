function [T_ss] = mp_cascade2ss(T_zpk_cascade)

% This function converts a cascaded controller (obtained using the 
% mp_tf_cascade() function) into a state-space object.

M = length(T_zpk_cascade);
N = 0;
for m=1:M
  N = N+length(T_zpk_cascade{m}.P{1});
end

A = zeros(N,N);
B = zeros(N,1);
C = zeros(1,N);
D = zeros(1,1);

sys = cell(size(T_zpk_cascade));
n = cell(size(T_zpk_cascade));
for m=1:M
  sys{m} = ss(minreal(T_zpk_cascade{m}));
  if isempty(sys{m}.A)
    n{m} = 0;
  else
    n{m} = length(sys{m}.A);
  end
end

j = 0;
for m=1:M
  jj = j+n{m};
  A(j+(1:n{m}),j+(1:n{m})) = sys{m}.A;
  for i=(m+1):M
    elem = sys{i}.B*sys{m}.C;
    for ii=(m+1):(i-1)
      elem = elem*sys{ii}.D;
    end
    A(jj+(1:n{i}),j+(1:n{m})) = elem;
    jj = jj+n{i};
  end
  
  B(j+(1:n{m}),1) = sys{m}.B;
  for i=1:(m-1)
    B(j+(1:n{m}),1) = B(j+(1:n{m}),1)*sys{i}.D;
  end
  
  C(1,j+(1:n{m})) = sys{m}.C;
  for i=(m+1):M
    C(1,j+(1:n{m})) = C(1,j+(1:n{m}))*sys{i}.D;
	end
  
	if (m == 1)
		D(1,1) = sys{m}.D;
	else
		D(1,1) = D(1,1)*sys{m}.D;
	end
  
  j = j+n{m};
end

T_ss = ss(A,B,C,D);
