////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/led_cmd_nav.h                                                     //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_LED_CMD_NAV_H
#define AUTOGEN_TIMESTAMPED_LED_CMD_NAV_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/led_cmd_nav.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class led_cmd_nav : public network::timestamped, public autogen::packet::led_cmd_nav {
      public:
        led_cmd_nav(autogen::topic::led_cmd_nav::TOPIC_T topic);
        virtual ~led_cmd_nav();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        led_cmd_nav& operator=(const autogen::packet::led_cmd_nav& rhs);
        led_cmd_nav& operator=(const led_cmd_nav& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
