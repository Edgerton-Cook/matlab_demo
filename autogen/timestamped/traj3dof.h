////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/timestamped/traj3dof.h                                                        //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_TIMESTAMPED_TRAJ3DOF_H
#define AUTOGEN_TIMESTAMPED_TRAJ3DOF_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/packet/traj3dof.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace timestamped {
    class traj3dof : public network::timestamped, public autogen::packet::traj3dof {
      public:
        traj3dof(autogen::topic::traj3dof::TOPIC_T topic);
        virtual ~traj3dof();
        topic_t topic_index() const;
        std::string topic_label() const;
        ts_t& timestamp();
        const ts_t& timestamp() const;
        virtual void clear();
        virtual std::string print() const;
        traj3dof& operator=(const autogen::packet::traj3dof& rhs);
        traj3dof& operator=(const traj3dof& rhs);
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
