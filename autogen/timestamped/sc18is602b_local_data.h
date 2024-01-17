////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/sc18is602b_local_data.h                                           //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_SC18IS602B_LOCAL_DATA_H
#define AUTOGEN_TIMESTAMPED_SC18IS602B_LOCAL_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/sc18is602b_local_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class sc18is602b_local_data : public network::timestamped, public autogen::packet::sc18is602b_local_data {
      public:
        sc18is602b_local_data(autogen::topic::sc18is602b_local_data::TOPIC_T topic);
        virtual ~sc18is602b_local_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        sc18is602b_local_data& operator=(const autogen::packet::sc18is602b_local_data& rhs);
        sc18is602b_local_data& operator=(const sc18is602b_local_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
