////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/deserializable/rcontrol_mode.h                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_DESERIALIZABLE_RCONTROL_MODE_H
#define AUTOGEN_DESERIALIZABLE_RCONTROL_MODE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/rcontrol_mode.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace deserializable {
    template<autogen::topic::rcontrol_mode::TOPIC_T T> 
    class rcontrol_mode : public network::deserializable, public autogen::timestamped::rcontrol_mode {
      public:
        rcontrol_mode() :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::rcontrol_mode(T) {
          // No-op.
        }
        rcontrol_mode(STATE_T s) :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::rcontrol_mode(T,s) {
          // No-op.
        }
        virtual ~rcontrol_mode() {
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
        rcontrol_mode<T>& operator=(STATE_T rhs) {
          autogen::state::rcontrol_mode::operator=(rhs);
          return *this;
        }
        rcontrol_mode<T>& operator=(const autogen::state::rcontrol_mode& rhs) {
          autogen::state::rcontrol_mode::operator=(rhs);
          return *this;
        }
        rcontrol_mode<T>& operator=(const autogen::timestamped::rcontrol_mode& rhs) {
          autogen::timestamped::rcontrol_mode::operator=(rhs);
          return *this;
        }
        rcontrol_mode<T>& operator=(const rcontrol_mode<T>& rhs) {
          autogen::timestamped::rcontrol_mode::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
