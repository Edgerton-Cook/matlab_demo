%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TITLE:   autogen/matlab/classes/autogen_pca9685_config_data_t.m         %
% AUTHOR:  Miki Szmuk                                                     %
% LAB:     Autonomous Controls Lab (ACL)                                  %
% LICENSE: Copyright 2016, 2017, All Rights Reserved                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef autogen_pca9685_config_data_t < handle
  properties (Access = public, Constant = true)
    type(1,1) autogen_type_t = autogen_type_t.PCA9685_CONFIG_DATA;
  end
  properties (Access = public)
    topic(1,1) autogen_topic_pca9685_config_data_t = autogen_topic_pca9685_config_data_t.UNDEFINED;
    node(1,1) autogen_node_t = autogen_node_t.UNDEFINED;
    ts(1,1) uint64;
    min_pwm(16,1) single;
    max_pwm(16,1) single;
    update_rate(1,1) single;
    calib_update_rate(1,1) single;
    calib_ch(1,1) uint8;
    n_calib_samples(1,1) uint32;
    nominal_calib_pwm(1,1) single;
    pwm_dlpf_factor(1,1) single;
    pwm_meas_outlier_margin(1,1) single;
  end
  methods (Static)
    function [n] = size()
      n = 11+153;
    end
    function [n] = size_hdr()
      n = 11;
    end
    function [n] = size_pl()
      n = 153;
    end
  end
  methods (Sealed = true)
    function [buffer,i2] = serialize(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        buffer(i1+0) = uint8(obj.type);
        buffer(i1+1) = uint8(obj.topic);
        buffer(i1+2) = uint8(obj.node);
        buffer((i1+3):(i1+10)) = typecast(obj.ts,'uint8');
        [buffer,i2] = serialize_content(obj,buffer,i1+11);
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [success,i2] = deserialize(obj,buffer,i1)
      success = false;
      i2 = i1;
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        if ((length(buffer)-(i1-1)) >= obj.size())&& ...
           (obj.type == buffer(i1))&& ...
           (obj.topic == buffer(i1+1))
          obj.node = buffer(i1+2);
          obj.ts = typecast(buffer((i1+3):(i1+10)),'uint64');
          i2 = deserialize_content(obj,buffer,i1+11);
          success = (i2 > i1);
        end
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [buffer,i2] = serialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        for mpac_ijk0=1:16
          buffer(i1+(0:(0+3))+4*(mpac_ijk0-1)) = typecast(obj.min_pwm(mpac_ijk0),'uint8');
        end
        for mpac_ijk0=1:16
          buffer(i1+(64:(64+3))+4*(mpac_ijk0-1)) = typecast(obj.max_pwm(mpac_ijk0),'uint8');
        end
        buffer(i1+(128:(128+3))) = typecast(obj.update_rate,'uint8');
        buffer(i1+(132:(132+3))) = typecast(obj.calib_update_rate,'uint8');
        buffer(i1+136) = typecast(obj.calib_ch,'uint8');
        buffer(i1+(137:(137+3))) = typecast(obj.n_calib_samples,'uint8');
        buffer(i1+(141:(141+3))) = typecast(obj.nominal_calib_pwm,'uint8');
        buffer(i1+(145:(145+3))) = typecast(obj.pwm_dlpf_factor,'uint8');
        buffer(i1+(149:(149+3))) = typecast(obj.pwm_meas_outlier_margin,'uint8');
        i2 = i1+153;
      else
        error('Buffer must be a uint8 array.')
      end
    end
    function [i2] = deserialize_content(obj,buffer,i1)
      mustBeInteger(i1)
      mustBePositive(i1)
      if (all(isa(buffer,'uint8')))&&(isvector(buffer))
        for mpac_ijk0=1:16
          obj.min_pwm(mpac_ijk0) = typecast(buffer(i1+(0:(0+3))+4*(mpac_ijk0-1)),'single');
        end
        for mpac_ijk0=1:16
          obj.max_pwm(mpac_ijk0) = typecast(buffer(i1+(64:(64+3))+4*(mpac_ijk0-1)),'single');
        end
        obj.update_rate = typecast(buffer(i1+(128:(128+3))),'single');
        obj.calib_update_rate = typecast(buffer(i1+(132:(132+3))),'single');
        obj.calib_ch = typecast(buffer(i1+136),'uint8');
        obj.n_calib_samples = typecast(buffer(i1+(137:(137+3))),'uint32');
        obj.nominal_calib_pwm = typecast(buffer(i1+(141:(141+3))),'single');
        obj.pwm_dlpf_factor = typecast(buffer(i1+(145:(145+3))),'single');
        obj.pwm_meas_outlier_margin = typecast(buffer(i1+(149:(149+3))),'single');
        i2 = i1+153;
      else
        error('Buffer must be a uint8 array.')
      end
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
