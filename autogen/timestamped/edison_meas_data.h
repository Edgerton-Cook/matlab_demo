////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/edison_meas_data.h                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_EDISON_MEAS_DATA_H
#define AUTOGEN_TIMESTAMPED_EDISON_MEAS_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/edison_meas_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class edison_meas_data : public network::timestamped, public autogen::packet::edison_meas_data {
      public:
        edison_meas_data(autogen::topic::edison_meas_data::TOPIC_T topic);
        virtual ~edison_meas_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        edison_meas_data& operator=(const autogen::packet::edison_meas_data& rhs);
        edison_meas_data& operator=(const edison_meas_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
