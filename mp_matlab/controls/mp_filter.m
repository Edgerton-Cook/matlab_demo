function [varargout] = mp_filter(varargin)
%% Initialization Mode
% varargin{1} = 'init'
% varargin{2} = T_d_zpk
% varargout{1} = P

if isequal(varargin{1},'init')
  T_d_zpk = varargin{2};
  T_d_tf = tf(T_d_zpk);
  n = T_d_tf.num{1};
  d = T_d_tf.den{1};
  
  if (d(1) == 0)
    error('d(1) = 0.')
  end
  
  P = struct;
  P.n = n;
  P.d = d;
  P.u = zeros(size(P.n));
  P.y = zeros(size(P.d));
  
  varargout{1} = P;
end
%% Filter Mode
% varargin{1} = 'filt'
% varargin{2} = P
% varargin{3} = u
% varargout{1} = P
% varargout{2} = y

if isequal(varargin{1},'filt')
  P = varargin{2};
  u = varargin{3};
  y = zeros(size(u));
  
  for k=1:length(u)
    % Input shift register.
    P.u(2:end) = P.u(1:end-1);
    P.u(1) = u(k);
    
    % Output shift register.
    P.y(2:end) = P.y(1:end-1);
    P.y(1) = (sum(P.n.*P.u)-sum(P.d(2:end).*P.y(2:end)))/P.d(1);
    y(k) = P.y(1);
  end
  
  varargout{1} = P;
  varargout{2} = y;
end
%% Write Mode
% varargin{1} = 'write'
% varargin{2} = P
% varargin{3} = l_n_max
% varargin{4} = l_d_max
% varargin{5} = file_handle
% varargin{6} = filter_name

if isequal(varargin{1},'write')
  P = varargin{2};
  l_n_max = varargin{3};
  l_d_max = varargin{4};
  file_handle = varargin{5};
  filter_name = varargin{6};
  
  % Check that length of numerator is less than l_n_max.
  if (length(P.n) > l_n_max)
    error('num of %s is longer than l_n_max (%d > %d).', ...
      filter_name,length(P.n),l_n_max)
  end
  
  % Check that length of denominator is less than l_d_max.
  if (length(P.d) > l_d_max)
    error('den of %s is longer than l_d_max (%d > %d).', ...
      filter_name,length(P.d),l_d_max)
  end
  
  % Write numerator gains.
  for i=1:l_n_max
    if (i <= length(P.n))
      fprintf(file_handle,sprintf('%s.num(%d) = %8.7e\n', ...
        filter_name,i-1,P.n(i)));
    else
      fprintf(file_handle,sprintf('%s.num(%d) = 0.0\n', ...
        filter_name,i-1));
    end
  end
  
  % Write denomenator gains.
  for i=1:l_d_max
    if (i <= length(P.d))
      fprintf(file_handle,sprintf('%s.den(%d) = %8.7e\n', ...
        filter_name,i-1,P.d(i)));
    else
      fprintf(file_handle,sprintf('%s.den(%d) = 0.0\n', ...
        filter_name,i-1));
    end
  end
end
