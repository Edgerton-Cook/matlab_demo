////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/veh_config_data.h                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_VEH_CONFIG_DATA_H
#define AUTOGEN_TIMESTAMPED_VEH_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/veh_config_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class veh_config_data : public network::timestamped, public autogen::parameter::veh_config_data {
      public:
        veh_config_data(autogen::topic::veh_config_data::TOPIC_T topic);
        veh_config_data(autogen::topic::veh_config_data::TOPIC_T topic, const std::string& filename);
        virtual ~veh_config_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        veh_config_data& operator=(const autogen::parameter::veh_config_data& rhs);
        veh_config_data& operator=(const veh_config_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
