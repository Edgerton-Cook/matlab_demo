////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/cm_uplink_data.h                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_CM_UPLINK_DATA_H
#define AUTOGEN_TIMESTAMPED_CM_UPLINK_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/cm_uplink_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class cm_uplink_data : public network::timestamped, public autogen::packet::cm_uplink_data {
      public:
        cm_uplink_data(autogen::topic::cm_uplink_data::TOPIC_T topic);
        virtual ~cm_uplink_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        cm_uplink_data& operator=(const autogen::packet::cm_uplink_data& rhs);
        cm_uplink_data& operator=(const cm_uplink_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
