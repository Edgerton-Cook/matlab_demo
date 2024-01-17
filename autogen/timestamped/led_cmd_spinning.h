////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/led_cmd_spinning.h                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_LED_CMD_SPINNING_H
#define AUTOGEN_TIMESTAMPED_LED_CMD_SPINNING_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/led_cmd_spinning.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class led_cmd_spinning : public network::timestamped, public autogen::packet::led_cmd_spinning {
      public:
        led_cmd_spinning(autogen::topic::led_cmd_spinning::TOPIC_T topic);
        virtual ~led_cmd_spinning();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        led_cmd_spinning& operator=(const autogen::packet::led_cmd_spinning& rhs);
        led_cmd_spinning& operator=(const led_cmd_spinning& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
