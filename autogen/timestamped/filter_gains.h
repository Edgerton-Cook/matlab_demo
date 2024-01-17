////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/filter_gains.h                                                    //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_FILTER_GAINS_H
#define AUTOGEN_TIMESTAMPED_FILTER_GAINS_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/filter_gains.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class filter_gains : public network::timestamped, public autogen::parameter::filter_gains {
      public:
        filter_gains(autogen::topic::filter_gains::TOPIC_T topic);
        filter_gains(autogen::topic::filter_gains::TOPIC_T topic, const std::string& filename);
        virtual ~filter_gains();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        filter_gains& operator=(const autogen::parameter::filter_gains& rhs);
        filter_gains& operator=(const filter_gains& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
