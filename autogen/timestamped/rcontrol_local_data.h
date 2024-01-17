////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/rcontrol_local_data.h                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_RCONTROL_LOCAL_DATA_H
#define AUTOGEN_TIMESTAMPED_RCONTROL_LOCAL_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/rcontrol_local_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class rcontrol_local_data : public network::timestamped, public autogen::packet::rcontrol_local_data {
      public:
        rcontrol_local_data(autogen::topic::rcontrol_local_data::TOPIC_T topic);
        virtual ~rcontrol_local_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        rcontrol_local_data& operator=(const autogen::packet::rcontrol_local_data& rhs);
        rcontrol_local_data& operator=(const rcontrol_local_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
