////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/fm_cmd_data.h                                                     //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_FM_CMD_DATA_H
#define AUTOGEN_TIMESTAMPED_FM_CMD_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/fm_cmd_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class fm_cmd_data : public network::timestamped, public autogen::packet::fm_cmd_data {
      public:
        fm_cmd_data(autogen::topic::fm_cmd_data::TOPIC_T topic);
        virtual ~fm_cmd_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        fm_cmd_data& operator=(const autogen::packet::fm_cmd_data& rhs);
        fm_cmd_data& operator=(const fm_cmd_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
