////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/traj3dof.h                                                       //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_TRAJ3DOF_H
#define AUTOGEN_SERIALIZABLE_TRAJ3DOF_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/traj3dof.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::traj3dof::TOPIC_T T> 
    class traj3dof : public network::serializable, public autogen::timestamped::traj3dof {
      public:
        traj3dof() :
          serializable(),
          autogen::timestamped::traj3dof(T) {
          // No-op.
        }
        virtual ~traj3dof() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +2213;
        }
        std::string node_label() const {
          return autogen::labels::node_labels[node_index()];
        }
        uint8* serialize(uint8* buff) const {
          buff = network::packet::serialize(buff,type_index(),1);
          buff = network::packet::serialize(buff,topic_index(),1);
          buff = network::packet::serialize(buff,node_index(),1);
          buff = network::packet::serialize(buff,timestamp(),1);
          buff = serialize_content(buff);
          return buff;
        }
        std::string print() const {
          std::ostringstream ss;
          ss << type_label() << ","
             << topic_label() << ","
             << node_label() << ","
             << std::setbase(10)
             << std::fixed
             << std::noshowpos
             << std::setprecision(0)
             << std::setfill('0')
             << std::setw(12)
             << timestamp() << ","
             << print_content();
          return ss.str();
        }
        traj3dof<T>& operator=(const autogen::packet::traj3dof& rhs) {
          autogen::packet::traj3dof::operator=(rhs);
          return *this;
        }
        traj3dof<T>& operator=(const autogen::timestamped::traj3dof& rhs) {
          autogen::timestamped::traj3dof::operator=(rhs);
          return *this;
        }
        traj3dof<T>& operator=(const traj3dof<T>& rhs) {
          autogen::timestamped::traj3dof::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
