function [T_zpk_concatenated] = mp_tf_convolve(T_zpk)

if iscell(T_zpk)
	T_zpk_concatenated = zpk(T_zpk{1});
	for i=2:length(T_zpk)
		T_zpk_concatenated = minreal(T_zpk_concatenated*zpk(T_zpk{i}));
	end
else
	T_zpk_concatenated = zpk(T_zpk);
end
