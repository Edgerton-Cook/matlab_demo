////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/mpu6000_config_data.h                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_MPU6000_CONFIG_DATA_H
#define AUTOGEN_TIMESTAMPED_MPU6000_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/mpu6000_config_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class mpu6000_config_data : public network::timestamped, public autogen::parameter::mpu6000_config_data {
      public:
        mpu6000_config_data(autogen::topic::mpu6000_config_data::TOPIC_T topic);
        mpu6000_config_data(autogen::topic::mpu6000_config_data::TOPIC_T topic, const std::string& filename);
        virtual ~mpu6000_config_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        mpu6000_config_data& operator=(const autogen::parameter::mpu6000_config_data& rhs);
        mpu6000_config_data& operator=(const mpu6000_config_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
