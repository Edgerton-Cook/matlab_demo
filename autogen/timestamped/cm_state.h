////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/cm_state.h                                                        //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_CM_STATE_H
#define AUTOGEN_TIMESTAMPED_CM_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/cm_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class cm_state : public network::timestamped, public autogen::state::cm_state {
      public:
        cm_state(autogen::topic::cm_state::TOPIC_T topic);
        cm_state(autogen::topic::cm_state::TOPIC_T topic, STATE_T s);
        virtual ~cm_state();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        cm_state& operator=(const autogen::state::cm_state& rhs);
        cm_state& operator=(const cm_state& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
