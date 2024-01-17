////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/deserializable/led_cmd_spinning.h                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_DESERIALIZABLE_LED_CMD_SPINNING_H
#define AUTOGEN_DESERIALIZABLE_LED_CMD_SPINNING_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/led_cmd_spinning.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace deserializable {
    template<autogen::topic::led_cmd_spinning::TOPIC_T T> 
    class led_cmd_spinning : public network::deserializable, public autogen::timestamped::led_cmd_spinning {
      public:
        led_cmd_spinning() :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::led_cmd_spinning(T) {
          // No-op.
        }
        virtual ~led_cmd_spinning() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +40;
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
        led_cmd_spinning<T>& operator=(const autogen::packet::led_cmd_spinning& rhs) {
          autogen::packet::led_cmd_spinning::operator=(rhs);
          return *this;
        }
        led_cmd_spinning<T>& operator=(const autogen::timestamped::led_cmd_spinning& rhs) {
          autogen::timestamped::led_cmd_spinning::operator=(rhs);
          return *this;
        }
        led_cmd_spinning<T>& operator=(const led_cmd_spinning<T>& rhs) {
          autogen::timestamped::led_cmd_spinning::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
