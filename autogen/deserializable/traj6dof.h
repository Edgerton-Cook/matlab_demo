////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/deserializable/traj6dof.h                                                     //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_DESERIALIZABLE_TRAJ6DOF_H
#define AUTOGEN_DESERIALIZABLE_TRAJ6DOF_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/traj6dof.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace deserializable {
    template<autogen::topic::traj6dof::TOPIC_T T> 
    class traj6dof : public network::deserializable, public autogen::timestamped::traj6dof {
      public:
        traj6dof() :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::traj6dof(T) {
          // No-op.
        }
        virtual ~traj6dof() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +3420;
        }
        node_t node_index() const {
          return m_node;
        }
        std::string node_label() const {
          return autogen::labels::node_labels[node_index()];
        }
        const uint8* deserialize(const uint8* buff) {
          if ((type_index() == buff[0]) and (topic_index() == buff[1])) {
            buff = buff+2;
            buff = network::packet::deserialize(buff,m_node,1);
            buff = network::packet::deserialize(buff,timestamp(),1);
            buff = deserialize_content(buff);
          }
          return buff;
        }
        void forget() {
          m_node = autogen::node::UNDEFINED;
        }
        void clear() {
          m_node = autogen::node::UNDEFINED;
          m_timestamp = 0;
          clear_content();
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
        traj6dof<T>& operator=(const autogen::packet::traj6dof& rhs) {
          autogen::packet::traj6dof::operator=(rhs);
          return *this;
        }
        traj6dof<T>& operator=(const autogen::timestamped::traj6dof& rhs) {
          autogen::timestamped::traj6dof::operator=(rhs);
          return *this;
        }
        traj6dof<T>& operator=(const traj6dof<T>& rhs) {
          autogen::timestamped::traj6dof::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
