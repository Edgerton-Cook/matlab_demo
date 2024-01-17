////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/estimation_config_data.h                                          //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_ESTIMATION_CONFIG_DATA_H
#define AUTOGEN_TIMESTAMPED_ESTIMATION_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/estimation_config_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class estimation_config_data : public network::timestamped, public autogen::parameter::estimation_config_data {
      public:
        estimation_config_data(autogen::topic::estimation_config_data::TOPIC_T topic);
        estimation_config_data(autogen::topic::estimation_config_data::TOPIC_T topic, const std::string& filename);
        virtual ~estimation_config_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        estimation_config_data& operator=(const autogen::parameter::estimation_config_data& rhs);
        estimation_config_data& operator=(const estimation_config_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
