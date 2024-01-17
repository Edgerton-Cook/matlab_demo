////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/led_cmd_data.h                                                    //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_LED_CMD_DATA_H
#define AUTOGEN_TIMESTAMPED_LED_CMD_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/led_cmd_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class led_cmd_data : public network::timestamped, public autogen::packet::led_cmd_data {
      public:
        led_cmd_data(autogen::topic::led_cmd_data::TOPIC_T topic);
        virtual ~led_cmd_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        led_cmd_data& operator=(const autogen::packet::led_cmd_data& rhs);
        led_cmd_data& operator=(const led_cmd_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
