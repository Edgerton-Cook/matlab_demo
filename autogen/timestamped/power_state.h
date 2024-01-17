////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/power_state.h                                                     //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_POWER_STATE_H
#define AUTOGEN_TIMESTAMPED_POWER_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/power_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class power_state : public network::timestamped, public autogen::state::power_state {
      public:
        power_state(autogen::topic::power_state::TOPIC_T topic);
        power_state(autogen::topic::power_state::TOPIC_T topic, STATE_T s);
        virtual ~power_state();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        power_state& operator=(const autogen::state::power_state& rhs);
        power_state& operator=(const power_state& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
