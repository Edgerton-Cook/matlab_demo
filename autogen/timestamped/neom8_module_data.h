////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/neom8_module_data.h                                               //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_NEOM8_MODULE_DATA_H
#define AUTOGEN_TIMESTAMPED_NEOM8_MODULE_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/neom8_module_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class neom8_module_data : public network::timestamped, public autogen::packet::neom8_module_data {
      public:
        neom8_module_data(autogen::topic::neom8_module_data::TOPIC_T topic);
        virtual ~neom8_module_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        neom8_module_data& operator=(const autogen::packet::neom8_module_data& rhs);
        neom8_module_data& operator=(const neom8_module_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
