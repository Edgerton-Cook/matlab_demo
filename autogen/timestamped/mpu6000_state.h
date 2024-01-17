////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/mpu6000_state.h                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_MPU6000_STATE_H
#define AUTOGEN_TIMESTAMPED_MPU6000_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/mpu6000_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class mpu6000_state : public network::timestamped, public autogen::state::mpu6000_state {
      public:
        mpu6000_state(autogen::topic::mpu6000_state::TOPIC_T topic);
        mpu6000_state(autogen::topic::mpu6000_state::TOPIC_T topic, STATE_T s);
        virtual ~mpu6000_state();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        mpu6000_state& operator=(const autogen::state::mpu6000_state& rhs);
        mpu6000_state& operator=(const mpu6000_state& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
