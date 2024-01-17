////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/veh_config_state.h                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_VEH_CONFIG_STATE_H
#define AUTOGEN_TIMESTAMPED_VEH_CONFIG_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/veh_config_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class veh_config_state : public network::timestamped, public autogen::state::veh_config_state {
      public:
        veh_config_state(autogen::topic::veh_config_state::TOPIC_T topic);
        veh_config_state(autogen::topic::veh_config_state::TOPIC_T topic, STATE_T s);
        virtual ~veh_config_state();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        veh_config_state& operator=(const autogen::state::veh_config_state& rhs);
        veh_config_state& operator=(const veh_config_state& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
