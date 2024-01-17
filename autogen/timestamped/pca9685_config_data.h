////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/pca9685_config_data.h                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_PCA9685_CONFIG_DATA_H
#define AUTOGEN_TIMESTAMPED_PCA9685_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/pca9685_config_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class pca9685_config_data : public network::timestamped, public autogen::parameter::pca9685_config_data {
      public:
        pca9685_config_data(autogen::topic::pca9685_config_data::TOPIC_T topic);
        pca9685_config_data(autogen::topic::pca9685_config_data::TOPIC_T topic, const std::string& filename);
        virtual ~pca9685_config_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        pca9685_config_data& operator=(const autogen::parameter::pca9685_config_data& rhs);
        pca9685_config_data& operator=(const pca9685_config_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
