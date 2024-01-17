////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/qcontrol_config_data.h                                            //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_QCONTROL_CONFIG_DATA_H
#define AUTOGEN_TIMESTAMPED_QCONTROL_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/qcontrol_config_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class qcontrol_config_data : public network::timestamped, public autogen::parameter::qcontrol_config_data {
      public:
        qcontrol_config_data(autogen::topic::qcontrol_config_data::TOPIC_T topic);
        qcontrol_config_data(autogen::topic::qcontrol_config_data::TOPIC_T topic, const std::string& filename);
        virtual ~qcontrol_config_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        qcontrol_config_data& operator=(const autogen::parameter::qcontrol_config_data& rhs);
        qcontrol_config_data& operator=(const qcontrol_config_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
