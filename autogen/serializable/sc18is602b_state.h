////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/sc18is602b_state.h                                               //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_SC18IS602B_STATE_H
#define AUTOGEN_SERIALIZABLE_SC18IS602B_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/sc18is602b_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::sc18is602b_state::TOPIC_T T> 
    class sc18is602b_state : public network::serializable, public autogen::timestamped::sc18is602b_state {
      public:
        sc18is602b_state() :
          serializable(),
          autogen::timestamped::sc18is602b_state(T) {
          // No-op.
        }
        sc18is602b_state(STATE_T s) :
          serializable(),
          autogen::timestamped::sc18is602b_state(T,s) {
          // No-op.
        }
        virtual ~sc18is602b_state() {
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
        sc18is602b_state<T>& operator=(STATE_T rhs) {
          autogen::state::sc18is602b_state::operator=(rhs);
          return *this;
        }
        sc18is602b_state<T>& operator=(const autogen::state::sc18is602b_state& rhs) {
          autogen::state::sc18is602b_state::operator=(rhs);
          return *this;
        }
        sc18is602b_state<T>& operator=(const autogen::timestamped::sc18is602b_state& rhs) {
          autogen::timestamped::sc18is602b_state::operator=(rhs);
          return *this;
        }
        sc18is602b_state<T>& operator=(const sc18is602b_state<T>& rhs) {
          autogen::timestamped::sc18is602b_state::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////