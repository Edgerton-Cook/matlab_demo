////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/ownership_state.h                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_OWNERSHIP_STATE_H
#define AUTOGEN_TIMESTAMPED_OWNERSHIP_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/ownership_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class ownership_state : public network::timestamped, public autogen::state::ownership_state {
      public:
        ownership_state(autogen::topic::ownership_state::TOPIC_T topic);
        ownership_state(autogen::topic::ownership_state::TOPIC_T topic, STATE_T s);
        virtual ~ownership_state();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        ownership_state& operator=(const autogen::state::ownership_state& rhs);
        ownership_state& operator=(const ownership_state& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
