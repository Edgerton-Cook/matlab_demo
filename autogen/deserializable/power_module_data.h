////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/deserializable/power_module_data.h                                            //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_DESERIALIZABLE_POWER_MODULE_DATA_H
#define AUTOGEN_DESERIALIZABLE_POWER_MODULE_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/power_module_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace deserializable {
    template<autogen::topic::power_module_data::TOPIC_T T> 
    class power_module_data : public network::deserializable, public autogen::timestamped::power_module_data {
      public:
        power_module_data() :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::power_module_data(T) {
          // No-op.
        }
        virtual ~power_module_data() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +17;
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
        power_module_data<T>& operator=(const autogen::packet::power_module_data& rhs) {
          autogen::packet::power_module_data::operator=(rhs);
          return *this;
        }
        power_module_data<T>& operator=(const autogen::timestamped::power_module_data& rhs) {
          autogen::timestamped::power_module_data::operator=(rhs);
          return *this;
        }
        power_module_data<T>& operator=(const power_module_data<T>& rhs) {
          autogen::timestamped::power_module_data::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////