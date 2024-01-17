////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/pca9685_state.h                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_PCA9685_STATE_H
#define AUTOGEN_TIMESTAMPED_PCA9685_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/pca9685_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class pca9685_state : public network::timestamped, public autogen::state::pca9685_state {
      public:
        pca9685_state(autogen::topic::pca9685_state::TOPIC_T topic);
        pca9685_state(autogen::topic::pca9685_state::TOPIC_T topic, STATE_T s);
        virtual ~pca9685_state();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        pca9685_state& operator=(const autogen::state::pca9685_state& rhs);
        pca9685_state& operator=(const pca9685_state& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
