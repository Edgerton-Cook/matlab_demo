////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/cm_config_data.h                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_CM_CONFIG_DATA_H
#define AUTOGEN_TIMESTAMPED_CM_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/cm_config_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class cm_config_data : public network::timestamped, public autogen::parameter::cm_config_data {
      public:
        cm_config_data(autogen::topic::cm_config_data::TOPIC_T topic);
        cm_config_data(autogen::topic::cm_config_data::TOPIC_T topic, const std::string& filename);
        virtual ~cm_config_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        cm_config_data& operator=(const autogen::parameter::cm_config_data& rhs);
        cm_config_data& operator=(const cm_config_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
