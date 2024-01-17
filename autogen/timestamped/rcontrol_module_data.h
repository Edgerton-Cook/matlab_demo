////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/rcontrol_module_data.h                                            //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_RCONTROL_MODULE_DATA_H
#define AUTOGEN_TIMESTAMPED_RCONTROL_MODULE_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/rcontrol_module_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class rcontrol_module_data : public network::timestamped, public autogen::packet::rcontrol_module_data {
      public:
        rcontrol_module_data(autogen::topic::rcontrol_module_data::TOPIC_T topic);
        virtual ~rcontrol_module_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        rcontrol_module_data& operator=(const autogen::packet::rcontrol_module_data& rhs);
        rcontrol_module_data& operator=(const rcontrol_module_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
