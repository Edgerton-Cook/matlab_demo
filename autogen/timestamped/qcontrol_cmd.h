////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/qcontrol_cmd.h                                                    //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_QCONTROL_CMD_H
#define AUTOGEN_TIMESTAMPED_QCONTROL_CMD_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/qcontrol_cmd.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class qcontrol_cmd : public network::timestamped, public autogen::packet::qcontrol_cmd {
      public:
        qcontrol_cmd(autogen::topic::qcontrol_cmd::TOPIC_T topic);
        virtual ~qcontrol_cmd();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        qcontrol_cmd& operator=(const autogen::packet::qcontrol_cmd& rhs);
        qcontrol_cmd& operator=(const qcontrol_cmd& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
