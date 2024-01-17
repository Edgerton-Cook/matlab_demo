////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/hmc5883l_config_data.h                                            //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_HMC5883L_CONFIG_DATA_H
#define AUTOGEN_TIMESTAMPED_HMC5883L_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/hmc5883l_config_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class hmc5883l_config_data : public network::timestamped, public autogen::parameter::hmc5883l_config_data {
      public:
        hmc5883l_config_data(autogen::topic::hmc5883l_config_data::TOPIC_T topic);
        hmc5883l_config_data(autogen::topic::hmc5883l_config_data::TOPIC_T topic, const std::string& filename);
        virtual ~hmc5883l_config_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        hmc5883l_config_data& operator=(const autogen::parameter::hmc5883l_config_data& rhs);
        hmc5883l_config_data& operator=(const hmc5883l_config_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
