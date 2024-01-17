////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/led_cmd_solid.h                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_LED_CMD_SOLID_H
#define AUTOGEN_TIMESTAMPED_LED_CMD_SOLID_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/led_cmd_solid.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class led_cmd_solid : public network::timestamped, public autogen::packet::led_cmd_solid {
      public:
        led_cmd_solid(autogen::topic::led_cmd_solid::TOPIC_T topic);
        virtual ~led_cmd_solid();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        led_cmd_solid& operator=(const autogen::packet::led_cmd_solid& rhs);
        led_cmd_solid& operator=(const led_cmd_solid& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
