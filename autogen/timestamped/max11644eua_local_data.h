////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/max11644eua_local_data.h                                          //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_MAX11644EUA_LOCAL_DATA_H
#define AUTOGEN_TIMESTAMPED_MAX11644EUA_LOCAL_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/max11644eua_local_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class max11644eua_local_data : public network::timestamped, public autogen::packet::max11644eua_local_data {
      public:
        max11644eua_local_data(autogen::topic::max11644eua_local_data::TOPIC_T topic);
        virtual ~max11644eua_local_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        max11644eua_local_data& operator=(const autogen::packet::max11644eua_local_data& rhs);
        max11644eua_local_data& operator=(const max11644eua_local_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
