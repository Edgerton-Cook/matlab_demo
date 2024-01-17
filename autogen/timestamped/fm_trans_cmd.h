////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/fm_trans_cmd.h                                                    //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_FM_TRANS_CMD_H
#define AUTOGEN_TIMESTAMPED_FM_TRANS_CMD_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/fm_trans_cmd.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class fm_trans_cmd : public network::timestamped, public autogen::state::fm_trans_cmd {
      public:
        fm_trans_cmd(autogen::topic::fm_trans_cmd::TOPIC_T topic);
        fm_trans_cmd(autogen::topic::fm_trans_cmd::TOPIC_T topic, STATE_T s);
        virtual ~fm_trans_cmd();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        fm_trans_cmd& operator=(const autogen::state::fm_trans_cmd& rhs);
        fm_trans_cmd& operator=(const fm_trans_cmd& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
