////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/gcs_agent_config_data.h                                           //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_GCS_AGENT_CONFIG_DATA_H
#define AUTOGEN_TIMESTAMPED_GCS_AGENT_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/gcs_agent_config_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class gcs_agent_config_data : public network::timestamped, public autogen::parameter::gcs_agent_config_data {
      public:
        gcs_agent_config_data(autogen::topic::gcs_agent_config_data::TOPIC_T topic);
        gcs_agent_config_data(autogen::topic::gcs_agent_config_data::TOPIC_T topic, const std::string& filename);
        virtual ~gcs_agent_config_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        gcs_agent_config_data& operator=(const autogen::parameter::gcs_agent_config_data& rhs);
        gcs_agent_config_data& operator=(const gcs_agent_config_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
