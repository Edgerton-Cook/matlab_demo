////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/qcontrol_sig_data.h                                               //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_QCONTROL_SIG_DATA_H
#define AUTOGEN_TIMESTAMPED_QCONTROL_SIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/qcontrol_sig_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class qcontrol_sig_data : public network::timestamped, public autogen::packet::qcontrol_sig_data {
      public:
        qcontrol_sig_data(autogen::topic::qcontrol_sig_data::TOPIC_T topic);
        virtual ~qcontrol_sig_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        qcontrol_sig_data& operator=(const autogen::packet::qcontrol_sig_data& rhs);
        qcontrol_sig_data& operator=(const qcontrol_sig_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
