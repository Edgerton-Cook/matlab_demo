////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/mpu6000_local_data.h                                              //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_MPU6000_LOCAL_DATA_H
#define AUTOGEN_TIMESTAMPED_MPU6000_LOCAL_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/mpu6000_local_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class mpu6000_local_data : public network::timestamped, public autogen::packet::mpu6000_local_data {
      public:
        mpu6000_local_data(autogen::topic::mpu6000_local_data::TOPIC_T topic);
        virtual ~mpu6000_local_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        mpu6000_local_data& operator=(const autogen::packet::mpu6000_local_data& rhs);
        mpu6000_local_data& operator=(const mpu6000_local_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
