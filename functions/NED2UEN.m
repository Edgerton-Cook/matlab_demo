function r_out = NED2UEN(r)
%UNTITLED2 Summary of this function goes here
%   Everything that comes into here must be 3x something

    sz = size(r);
    r_out = zeros(sz);
    
    if sz(1) ~= 3
        r = r.';
    end
    
    for i = 1:sz(2)
        r_out(:,i) = [-r(3,i) r(2,i) r(1,i)]';
    end

end