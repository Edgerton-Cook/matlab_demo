////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/sc18is602b_state.h                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_SC18IS602B_STATE_H
#define AUTOGEN_TIMESTAMPED_SC18IS602B_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/sc18is602b_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class sc18is602b_state : public network::timestamped, public autogen::state::sc18is602b_state {
      public:
        sc18is602b_state(autogen::topic::sc18is602b_state::TOPIC_T topic);
        sc18is602b_state(autogen::topic::sc18is602b_state::TOPIC_T topic, STATE_T s);
        virtual ~sc18is602b_state();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        sc18is602b_state& operator=(const autogen::state::sc18is602b_state& rhs);
        sc18is602b_state& operator=(const sc18is602b_state& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
