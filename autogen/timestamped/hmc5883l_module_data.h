////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/hmc5883l_module_data.h                                            //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_HMC5883L_MODULE_DATA_H
#define AUTOGEN_TIMESTAMPED_HMC5883L_MODULE_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/hmc5883l_module_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class hmc5883l_module_data : public network::timestamped, public autogen::packet::hmc5883l_module_data {
      public:
        hmc5883l_module_data(autogen::topic::hmc5883l_module_data::TOPIC_T topic);
        virtual ~hmc5883l_module_data();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        hmc5883l_module_data& operator=(const autogen::packet::hmc5883l_module_data& rhs);
        hmc5883l_module_data& operator=(const hmc5883l_module_data& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
