////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/power_calib_data.h                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_POWER_CALIB_DATA_H
#define AUTOGEN_TIMESTAMPED_POWER_CALIB_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/parameter/power_calib_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class power_calib_data : public network::timestamped, public autogen::parameter::power_calib_data {
      public:
        power_calib_data(autogen::topic::power_calib_data::TOPIC_T topic);
        power_calib_data(autogen::topic::power_calib_data::TOPIC_T topic, const std::string& filename);
        virtual ~power_calib_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        power_calib_data& operator=(const autogen::parameter::power_calib_data& rhs);
        power_calib_data& operator=(const power_calib_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
