////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/max11644eua_state.h                                               //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_MAX11644EUA_STATE_H
#define AUTOGEN_TIMESTAMPED_MAX11644EUA_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/max11644eua_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class max11644eua_state : public network::timestamped, public autogen::state::max11644eua_state {
      public:
        max11644eua_state(autogen::topic::max11644eua_state::TOPIC_T topic);
        max11644eua_state(autogen::topic::max11644eua_state::TOPIC_T topic, STATE_T s);
        virtual ~max11644eua_state();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        max11644eua_state& operator=(const autogen::state::max11644eua_state& rhs);
        max11644eua_state& operator=(const max11644eua_state& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
