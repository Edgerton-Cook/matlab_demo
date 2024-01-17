////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/heartbeat.h                                                       //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_HEARTBEAT_H
#define AUTOGEN_TIMESTAMPED_HEARTBEAT_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/heartbeat.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class heartbeat : public network::timestamped, public autogen::packet::heartbeat {
      public:
        heartbeat(autogen::topic::heartbeat::TOPIC_T topic);
        virtual ~heartbeat();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        heartbeat& operator=(const autogen::packet::heartbeat& rhs);
        heartbeat& operator=(const heartbeat& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
