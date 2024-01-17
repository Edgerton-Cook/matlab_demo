////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/deserializable/cm_subscriptions.h                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_DESERIALIZABLE_CM_SUBSCRIPTIONS_H
#define AUTOGEN_DESERIALIZABLE_CM_SUBSCRIPTIONS_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/cm_subscriptions.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace deserializable {
    template<autogen::topic::cm_subscriptions::TOPIC_T T> 
    class cm_subscriptions : public network::deserializable, public autogen::timestamped::cm_subscriptions {
      public:
        cm_subscriptions() :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::cm_subscriptions(T) {
          // No-op.
        }
        cm_subscriptions(const std::string& filename) :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::cm_subscriptions(T,filename) {
          // No-op.
        }
        virtual ~cm_subscriptions() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +6;
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
        cm_subscriptions<T>& operator=(const autogen::parameter::cm_subscriptions& rhs) {
          autogen::parameter::cm_subscriptions::operator=(rhs);
          return *this;
        }
        cm_subscriptions<T>& operator=(const autogen::timestamped::cm_subscriptions& rhs) {
          autogen::timestamped::cm_subscriptions::operator=(rhs);
          return *this;
        }
        cm_subscriptions<T>& operator=(const cm_subscriptions<T>& rhs) {
          autogen::timestamped::cm_subscriptions::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
