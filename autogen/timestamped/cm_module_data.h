////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/cm_module_data.h                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_CM_MODULE_DATA_H
#define AUTOGEN_TIMESTAMPED_CM_MODULE_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/cm_module_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class cm_module_data : public network::timestamped, public autogen::packet::cm_module_data {
      public:
        cm_module_data(autogen::topic::cm_module_data::TOPIC_T topic);
        virtual ~cm_module_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        cm_module_data& operator=(const autogen::packet::cm_module_data& rhs);
        cm_module_data& operator=(const cm_module_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
