////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/fm_local_data.h                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_FM_LOCAL_DATA_H
#define AUTOGEN_TIMESTAMPED_FM_LOCAL_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/fm_local_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class fm_local_data : public network::timestamped, public autogen::packet::fm_local_data {
      public:
        fm_local_data(autogen::topic::fm_local_data::TOPIC_T topic);
        virtual ~fm_local_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        fm_local_data& operator=(const autogen::packet::fm_local_data& rhs);
        fm_local_data& operator=(const fm_local_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
