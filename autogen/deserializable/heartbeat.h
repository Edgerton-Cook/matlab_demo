////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/deserializable/heartbeat.h                                                    //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_DESERIALIZABLE_HEARTBEAT_H
#define AUTOGEN_DESERIALIZABLE_HEARTBEAT_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/heartbeat.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace deserializable {
    template<autogen::topic::heartbeat::TOPIC_T T> 
    class heartbeat : public network::deserializable, public autogen::timestamped::heartbeat {
      public:
        heartbeat() :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::heartbeat(T) {
          // No-op.
        }
        virtual ~heartbeat() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +2;
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
        heartbeat<T>& operator=(const autogen::packet::heartbeat& rhs) {
          autogen::packet::heartbeat::operator=(rhs);
          return *this;
        }
        heartbeat<T>& operator=(const autogen::timestamped::heartbeat& rhs) {
          autogen::timestamped::heartbeat::operator=(rhs);
          return *this;
        }
        heartbeat<T>& operator=(const heartbeat<T>& rhs) {
          autogen::timestamped::heartbeat::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
