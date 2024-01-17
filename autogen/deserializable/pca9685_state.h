////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/deserializable/pca9685_state.h                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_DESERIALIZABLE_PCA9685_STATE_H
#define AUTOGEN_DESERIALIZABLE_PCA9685_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/pca9685_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace deserializable {
    template<autogen::topic::pca9685_state::TOPIC_T T> 
    class pca9685_state : public network::deserializable, public autogen::timestamped::pca9685_state {
      public:
        pca9685_state() :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::pca9685_state(T) {
          // No-op.
        }
        pca9685_state(STATE_T s) :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::pca9685_state(T,s) {
          // No-op.
        }
        virtual ~pca9685_state() {
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
        pca9685_state<T>& operator=(STATE_T rhs) {
          autogen::state::pca9685_state::operator=(rhs);
          return *this;
        }
        pca9685_state<T>& operator=(const autogen::state::pca9685_state& rhs) {
          autogen::state::pca9685_state::operator=(rhs);
          return *this;
        }
        pca9685_state<T>& operator=(const autogen::timestamped::pca9685_state& rhs) {
          autogen::timestamped::pca9685_state::operator=(rhs);
          return *this;
        }
        pca9685_state<T>& operator=(const pca9685_state<T>& rhs) {
          autogen::timestamped::pca9685_state::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
