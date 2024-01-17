////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/mocap_data.h                                                      //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_MOCAP_DATA_H
#define AUTOGEN_TIMESTAMPED_MOCAP_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/mocap_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class mocap_data : public network::timestamped, public autogen::packet::mocap_data {
      public:
        mocap_data(autogen::topic::mocap_data::TOPIC_T topic);
        virtual ~mocap_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        mocap_data& operator=(const autogen::packet::mocap_data& rhs);
        mocap_data& operator=(const mocap_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
