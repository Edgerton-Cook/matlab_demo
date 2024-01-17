////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/cm_subscriptions.h                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_CM_SUBSCRIPTIONS_H
#define AUTOGEN_TIMESTAMPED_CM_SUBSCRIPTIONS_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/cm_subscriptions.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class cm_subscriptions : public network::timestamped, public autogen::parameter::cm_subscriptions {
      public:
        cm_subscriptions(autogen::topic::cm_subscriptions::TOPIC_T topic);
        cm_subscriptions(autogen::topic::cm_subscriptions::TOPIC_T topic, const std::string& filename);
        virtual ~cm_subscriptions();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        cm_subscriptions& operator=(const autogen::parameter::cm_subscriptions& rhs);
        cm_subscriptions& operator=(const cm_subscriptions& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
