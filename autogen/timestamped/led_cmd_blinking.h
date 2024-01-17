////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/led_cmd_blinking.h                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_LED_CMD_BLINKING_H
#define AUTOGEN_TIMESTAMPED_LED_CMD_BLINKING_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/led_cmd_blinking.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class led_cmd_blinking : public network::timestamped, public autogen::packet::led_cmd_blinking {
      public:
        led_cmd_blinking(autogen::topic::led_cmd_blinking::TOPIC_T topic);
        virtual ~led_cmd_blinking();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        led_cmd_blinking& operator=(const autogen::packet::led_cmd_blinking& rhs);
        led_cmd_blinking& operator=(const led_cmd_blinking& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
