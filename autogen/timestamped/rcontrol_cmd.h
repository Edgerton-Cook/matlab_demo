////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/rcontrol_cmd.h                                                    //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_RCONTROL_CMD_H
#define AUTOGEN_TIMESTAMPED_RCONTROL_CMD_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/rcontrol_cmd.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class rcontrol_cmd : public network::timestamped, public autogen::packet::rcontrol_cmd {
      public:
        rcontrol_cmd(autogen::topic::rcontrol_cmd::TOPIC_T topic);
        virtual ~rcontrol_cmd();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        rcontrol_cmd& operator=(const autogen::packet::rcontrol_cmd& rhs);
        rcontrol_cmd& operator=(const rcontrol_cmd& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
