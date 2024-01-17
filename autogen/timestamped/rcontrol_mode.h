////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/rcontrol_mode.h                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_RCONTROL_MODE_H
#define AUTOGEN_TIMESTAMPED_RCONTROL_MODE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/rcontrol_mode.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class rcontrol_mode : public network::timestamped, public autogen::state::rcontrol_mode {
      public:
        rcontrol_mode(autogen::topic::rcontrol_mode::TOPIC_T topic);
        rcontrol_mode(autogen::topic::rcontrol_mode::TOPIC_T topic, STATE_T s);
        virtual ~rcontrol_mode();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        rcontrol_mode& operator=(const autogen::state::rcontrol_mode& rhs);
        rcontrol_mode& operator=(const rcontrol_mode& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
