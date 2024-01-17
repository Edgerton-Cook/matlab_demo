////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/led_state.h                                                       //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_LED_STATE_H
#define AUTOGEN_TIMESTAMPED_LED_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/led_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class led_state : public network::timestamped, public autogen::state::led_state {
      public:
        led_state(autogen::topic::led_state::TOPIC_T topic);
        led_state(autogen::topic::led_state::TOPIC_T topic, STATE_T s);
        virtual ~led_state();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        led_state& operator=(const autogen::state::led_state& rhs);
        led_state& operator=(const led_state& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
