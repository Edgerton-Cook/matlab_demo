////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/estimation_state.h                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_ESTIMATION_STATE_H
#define AUTOGEN_TIMESTAMPED_ESTIMATION_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/estimation_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class estimation_state : public network::timestamped, public autogen::state::estimation_state {
      public:
        estimation_state(autogen::topic::estimation_state::TOPIC_T topic);
        estimation_state(autogen::topic::estimation_state::TOPIC_T topic, STATE_T s);
        virtual ~estimation_state();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        estimation_state& operator=(const autogen::state::estimation_state& rhs);
        estimation_state& operator=(const estimation_state& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
