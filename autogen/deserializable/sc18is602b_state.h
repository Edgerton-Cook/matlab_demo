////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/deserializable/sc18is602b_state.h                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_DESERIALIZABLE_SC18IS602B_STATE_H
#define AUTOGEN_DESERIALIZABLE_SC18IS602B_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/sc18is602b_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace deserializable {
    template<autogen::topic::sc18is602b_state::TOPIC_T T> 
    class sc18is602b_state : public network::deserializable, public autogen::timestamped::sc18is602b_state {
      public:
        sc18is602b_state() :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::sc18is602b_state(T) {
          // No-op.
        }
        sc18is602b_state(STATE_T s) :
          network::deserializable(autogen::node::UNDEFINED),
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
