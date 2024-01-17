////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/estimation_sig_data.h                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_ESTIMATION_SIG_DATA_H
#define AUTOGEN_TIMESTAMPED_ESTIMATION_SIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/estimation_sig_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class estimation_sig_data : public network::timestamped, public autogen::packet::estimation_sig_data {
      public:
        estimation_sig_data(autogen::topic::estimation_sig_data::TOPIC_T topic);
        virtual ~estimation_sig_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        estimation_sig_data& operator=(const autogen::packet::estimation_sig_data& rhs);
        estimation_sig_data& operator=(const estimation_sig_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
