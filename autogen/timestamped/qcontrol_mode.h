////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/qcontrol_mode.h                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_QCONTROL_MODE_H
#define AUTOGEN_TIMESTAMPED_QCONTROL_MODE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/qcontrol_mode.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class qcontrol_mode : public network::timestamped, public autogen::state::qcontrol_mode {
      public:
        qcontrol_mode(autogen::topic::qcontrol_mode::TOPIC_T topic);
        qcontrol_mode(autogen::topic::qcontrol_mode::TOPIC_T topic, STATE_T s);
        virtual ~qcontrol_mode();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        qcontrol_mode& operator=(const autogen::state::qcontrol_mode& rhs);
        qcontrol_mode& operator=(const qcontrol_mode& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
