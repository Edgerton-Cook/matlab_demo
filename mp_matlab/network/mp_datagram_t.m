classdef mp_datagram_t
	properties
		ip(1,:) char = '0.0.0.0';
		port(1,1) uint16 = 0;
		buffer(:,1) uint8 = [];
	end
end
