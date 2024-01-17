////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/qcontrol_state.h                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_QCONTROL_STATE_H
#define AUTOGEN_TIMESTAMPED_QCONTROL_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/qcontrol_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class qcontrol_state : public network::timestamped, public autogen::state::qcontrol_state {
      public:
        qcontrol_state(autogen::topic::qcontrol_state::TOPIC_T topic);
        qcontrol_state(autogen::topic::qcontrol_state::TOPIC_T topic, STATE_T s);
        virtual ~qcontrol_state();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        qcontrol_state& operator=(const autogen::state::qcontrol_state& rhs);
        qcontrol_state& operator=(const qcontrol_state& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
