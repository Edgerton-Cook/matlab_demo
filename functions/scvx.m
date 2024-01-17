function [O,solve_time] = scvx(I)

% initialization
I = {I};
I{1}.r0 = [linspace(I{1}.r_i(1),I{1}.r_f(1),I{1}.K)
           linspace(I{1}.r_i(2),I{1}.r_f(2),I{1}.K)
           linspace(I{1}.r_i(3),I{1}.r_f(3),I{1}.K)];
I{1}.v0 = zeros(3,I{1}.K);
I{1}.u0 = -I{1}.m*I{1}.g*ones(1,I{1}.K);

% successive convexification loop
O = cell(0,1);
solve_time = 0;
for i=1:I{1}.n_scvx_max
  O{i,1} = socp(I{i,1},i);
  solve_time = solve_time+O{i}.timing(5);
  
  if (O{i}.converged)&&(O{i}.lossless)
    fprintf('converged & lossless, total solve time = %04d [ms]\n', ...
      ceil(1000*solve_time))
    fprintf('\n')
    break
  elseif (i < I{1}.n_scvx_max)
    I{i+1,1} = I{i};
    I{i+1,1}.r0 = O{i,1}.r;
    I{i+1,1}.v0 = O{i,1}.v;
    I{i+1,1}.u0 = O{i,1}.u;
  end
end
