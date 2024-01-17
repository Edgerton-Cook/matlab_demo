////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/fm_state.h                                                        //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_FM_STATE_H
#define AUTOGEN_TIMESTAMPED_FM_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/fm_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class fm_state : public network::timestamped, public autogen::state::fm_state {
      public:
        fm_state(autogen::topic::fm_state::TOPIC_T topic);
        fm_state(autogen::topic::fm_state::TOPIC_T topic, STATE_T s);
        virtual ~fm_state();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        fm_state& operator=(const autogen::state::fm_state& rhs);
        fm_state& operator=(const fm_state& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
