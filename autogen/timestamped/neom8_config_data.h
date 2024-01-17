////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/neom8_config_data.h                                               //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_NEOM8_CONFIG_DATA_H
#define AUTOGEN_TIMESTAMPED_NEOM8_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/neom8_config_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class neom8_config_data : public network::timestamped, public autogen::parameter::neom8_config_data {
      public:
        neom8_config_data(autogen::topic::neom8_config_data::TOPIC_T topic);
        neom8_config_data(autogen::topic::neom8_config_data::TOPIC_T topic, const std::string& filename);
        virtual ~neom8_config_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        neom8_config_data& operator=(const autogen::parameter::neom8_config_data& rhs);
        neom8_config_data& operator=(const neom8_config_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
