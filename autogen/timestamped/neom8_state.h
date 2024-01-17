////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/neom8_state.h                                                     //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_NEOM8_STATE_H
#define AUTOGEN_TIMESTAMPED_NEOM8_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/neom8_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class neom8_state : public network::timestamped, public autogen::state::neom8_state {
      public:
        neom8_state(autogen::topic::neom8_state::TOPIC_T topic);
        neom8_state(autogen::topic::neom8_state::TOPIC_T topic, STATE_T s);
        virtual ~neom8_state();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        neom8_state& operator=(const autogen::state::neom8_state& rhs);
        neom8_state& operator=(const neom8_state& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
