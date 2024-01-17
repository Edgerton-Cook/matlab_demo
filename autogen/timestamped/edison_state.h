////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/edison_state.h                                                    //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_EDISON_STATE_H
#define AUTOGEN_TIMESTAMPED_EDISON_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/edison_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class edison_state : public network::timestamped, public autogen::state::edison_state {
      public:
        edison_state(autogen::topic::edison_state::TOPIC_T topic);
        edison_state(autogen::topic::edison_state::TOPIC_T topic, STATE_T s);
        virtual ~edison_state();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        edison_state& operator=(const autogen::state::edison_state& rhs);
        edison_state& operator=(const edison_state& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
