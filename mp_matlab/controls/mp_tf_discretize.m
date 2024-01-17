function [C_zpk_d] = mp_tf_discretize(C_zpk_c,f_samp_Hz,method)

if ~iscell(C_zpk_c)
  C_zpk_d = c2d(C_zpk_c,1/f_samp_Hz,method);
else
  C_zpk_d = cell(size(C_zpk_c));
  for i=1:length(C_zpk_c)
    C_zpk_d{i} = c2d(C_zpk_c{i},1/f_samp_Hz,method);
  end
end
