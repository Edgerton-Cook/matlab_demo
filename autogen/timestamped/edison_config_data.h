////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/edison_config_data.h                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_EDISON_CONFIG_DATA_H
#define AUTOGEN_TIMESTAMPED_EDISON_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/edison_config_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class edison_config_data : public network::timestamped, public autogen::parameter::edison_config_data {
      public:
        edison_config_data(autogen::topic::edison_config_data::TOPIC_T topic);
        edison_config_data(autogen::topic::edison_config_data::TOPIC_T topic, const std::string& filename);
        virtual ~edison_config_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        edison_config_data& operator=(const autogen::parameter::edison_config_data& rhs);
        edison_config_data& operator=(const edison_config_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
