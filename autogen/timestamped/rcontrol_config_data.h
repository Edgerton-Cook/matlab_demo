////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/rcontrol_config_data.h                                            //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_RCONTROL_CONFIG_DATA_H
#define AUTOGEN_TIMESTAMPED_RCONTROL_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/rcontrol_config_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class rcontrol_config_data : public network::timestamped, public autogen::parameter::rcontrol_config_data {
      public:
        rcontrol_config_data(autogen::topic::rcontrol_config_data::TOPIC_T topic);
        rcontrol_config_data(autogen::topic::rcontrol_config_data::TOPIC_T topic, const std::string& filename);
        virtual ~rcontrol_config_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        rcontrol_config_data& operator=(const autogen::parameter::rcontrol_config_data& rhs);
        rcontrol_config_data& operator=(const rcontrol_config_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
