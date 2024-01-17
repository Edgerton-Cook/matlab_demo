////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/telemetry.h                                                       //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_TELEMETRY_H
#define AUTOGEN_TIMESTAMPED_TELEMETRY_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/telemetry.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class telemetry : public network::timestamped, public autogen::packet::telemetry {
      public:
        telemetry(autogen::topic::telemetry::TOPIC_T topic);
        virtual ~telemetry();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        telemetry& operator=(const autogen::packet::telemetry& rhs);
        telemetry& operator=(const telemetry& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
