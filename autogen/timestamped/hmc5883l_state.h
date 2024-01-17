////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/hmc5883l_state.h                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_HMC5883L_STATE_H
#define AUTOGEN_TIMESTAMPED_HMC5883L_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/hmc5883l_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class hmc5883l_state : public network::timestamped, public autogen::state::hmc5883l_state {
      public:
        hmc5883l_state(autogen::topic::hmc5883l_state::TOPIC_T topic);
        hmc5883l_state(autogen::topic::hmc5883l_state::TOPIC_T topic, STATE_T s);
        virtual ~hmc5883l_state();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        hmc5883l_state& operator=(const autogen::state::hmc5883l_state& rhs);
        hmc5883l_state& operator=(const hmc5883l_state& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
