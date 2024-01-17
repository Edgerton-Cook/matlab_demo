////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/edison_state.h                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_EDISON_STATE_H
#define AUTOGEN_SERIALIZABLE_EDISON_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/edison_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::edison_state::TOPIC_T T> 
    class edison_state : public network::serializable, public autogen::timestamped::edison_state {
      public:
        edison_state() :
          serializable(),
          autogen::timestamped::edison_state(T) {
          // No-op.
        }
        edison_state(STATE_T s) :
          serializable(),
          autogen::timestamped::edison_state(T,s) {
          // No-op.
        }
        virtual ~edison_state() {
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
        edison_state<T>& operator=(STATE_T rhs) {
          autogen::state::edison_state::operator=(rhs);
          return *this;
        }
        edison_state<T>& operator=(const autogen::state::edison_state& rhs) {
          autogen::state::edison_state::operator=(rhs);
          return *this;
        }
        edison_state<T>& operator=(const autogen::timestamped::edison_state& rhs) {
          autogen::timestamped::edison_state::operator=(rhs);
          return *this;
        }
        edison_state<T>& operator=(const edison_state<T>& rhs) {
          autogen::timestamped::edison_state::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
