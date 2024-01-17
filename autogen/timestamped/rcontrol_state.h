////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/rcontrol_state.h                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_RCONTROL_STATE_H
#define AUTOGEN_TIMESTAMPED_RCONTROL_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/rcontrol_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class rcontrol_state : public network::timestamped, public autogen::state::rcontrol_state {
      public:
        rcontrol_state(autogen::topic::rcontrol_state::TOPIC_T topic);
        rcontrol_state(autogen::topic::rcontrol_state::TOPIC_T topic, STATE_T s);
        virtual ~rcontrol_state();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        rcontrol_state& operator=(const autogen::state::rcontrol_state& rhs);
        rcontrol_state& operator=(const rcontrol_state& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
