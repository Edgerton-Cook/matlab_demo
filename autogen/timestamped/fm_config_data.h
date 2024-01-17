////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/fm_config_data.h                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_FM_CONFIG_DATA_H
#define AUTOGEN_TIMESTAMPED_FM_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/fm_config_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class fm_config_data : public network::timestamped, public autogen::parameter::fm_config_data {
      public:
        fm_config_data(autogen::topic::fm_config_data::TOPIC_T topic);
        fm_config_data(autogen::topic::fm_config_data::TOPIC_T topic, const std::string& filename);
        virtual ~fm_config_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        fm_config_data& operator=(const autogen::parameter::fm_config_data& rhs);
        fm_config_data& operator=(const fm_config_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
