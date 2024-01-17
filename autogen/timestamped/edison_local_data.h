////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/edison_local_data.h                                               //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_EDISON_LOCAL_DATA_H
#define AUTOGEN_TIMESTAMPED_EDISON_LOCAL_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/edison_local_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class edison_local_data : public network::timestamped, public autogen::packet::edison_local_data {
      public:
        edison_local_data(autogen::topic::edison_local_data::TOPIC_T topic);
        virtual ~edison_local_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        edison_local_data& operator=(const autogen::packet::edison_local_data& rhs);
        edison_local_data& operator=(const edison_local_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
