////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/fm_cmd_states.h                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_FM_CMD_STATES_H
#define AUTOGEN_TIMESTAMPED_FM_CMD_STATES_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/fm_cmd_states.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class fm_cmd_states : public network::timestamped, public autogen::packet::fm_cmd_states {
      public:
        fm_cmd_states(autogen::topic::fm_cmd_states::TOPIC_T topic);
        virtual ~fm_cmd_states();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        fm_cmd_states& operator=(const autogen::packet::fm_cmd_states& rhs);
        fm_cmd_states& operator=(const fm_cmd_states& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
