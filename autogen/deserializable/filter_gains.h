////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/deserializable/filter_gains.h                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_DESERIALIZABLE_FILTER_GAINS_H
#define AUTOGEN_DESERIALIZABLE_FILTER_GAINS_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/filter_gains.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace deserializable {
    template<autogen::topic::filter_gains::TOPIC_T T> 
    class filter_gains : public network::deserializable, public autogen::timestamped::filter_gains {
      public:
        filter_gains() :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::filter_gains(T) {
          // No-op.
        }
        filter_gains(const std::string& filename) :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::filter_gains(T,filename) {
          // No-op.
        }
        virtual ~filter_gains() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +24;
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
        filter_gains<T>& operator=(const autogen::parameter::filter_gains& rhs) {
          autogen::parameter::filter_gains::operator=(rhs);
          return *this;
        }
        filter_gains<T>& operator=(const autogen::timestamped::filter_gains& rhs) {
          autogen::timestamped::filter_gains::operator=(rhs);
          return *this;
        }
        filter_gains<T>& operator=(const filter_gains<T>& rhs) {
          autogen::timestamped::filter_gains::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
