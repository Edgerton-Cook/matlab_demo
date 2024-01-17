////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/traj6dof.h                                                        //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_TRAJ6DOF_H
#define AUTOGEN_TIMESTAMPED_TRAJ6DOF_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/traj6dof.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class traj6dof : public network::timestamped, public autogen::packet::traj6dof {
      public:
        traj6dof(autogen::topic::traj6dof::TOPIC_T topic);
        virtual ~traj6dof();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        traj6dof& operator=(const autogen::packet::traj6dof& rhs);
        traj6dof& operator=(const traj6dof& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
