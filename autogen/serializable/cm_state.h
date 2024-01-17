////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/cm_state.h                                                       //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_CM_STATE_H
#define AUTOGEN_SERIALIZABLE_CM_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/cm_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::cm_state::TOPIC_T T> 
    class cm_state : public network::serializable, public autogen::timestamped::cm_state {
      public:
        cm_state() :
          serializable(),
          autogen::timestamped::cm_state(T) {
          // No-op.
        }
        cm_state(STATE_T s) :
          serializable(),
          autogen::timestamped::cm_state(T,s) {
          // No-op.
        }
        virtual ~cm_state() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +1;
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
        cm_state<T>& operator=(STATE_T rhs) {
          autogen::state::cm_state::operator=(rhs);
          return *this;
        }
        cm_state<T>& operator=(const autogen::state::cm_state& rhs) {
          autogen::state::cm_state::operator=(rhs);
          return *this;
        }
        cm_state<T>& operator=(const autogen::timestamped::cm_state& rhs) {
          autogen::timestamped::cm_state::operator=(rhs);
          return *this;
        }
        cm_state<T>& operator=(const cm_state<T>& rhs) {
          autogen::timestamped::cm_state::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
