////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/deserializable/fm_cmd_states.h                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_DESERIALIZABLE_FM_CMD_STATES_H
#define AUTOGEN_DESERIALIZABLE_FM_CMD_STATES_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/fm_cmd_states.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace deserializable {
    template<autogen::topic::fm_cmd_states::TOPIC_T T> 
    class fm_cmd_states : public network::deserializable, public autogen::timestamped::fm_cmd_states {
      public:
        fm_cmd_states() :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::fm_cmd_states(T) {
          // No-op.
        }
        virtual ~fm_cmd_states() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +12;
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
        fm_cmd_states<T>& operator=(const autogen::packet::fm_cmd_states& rhs) {
          autogen::packet::fm_cmd_states::operator=(rhs);
          return *this;
        }
        fm_cmd_states<T>& operator=(const autogen::timestamped::fm_cmd_states& rhs) {
          autogen::timestamped::fm_cmd_states::operator=(rhs);
          return *this;
        }
        fm_cmd_states<T>& operator=(const fm_cmd_states<T>& rhs) {
          autogen::timestamped::fm_cmd_states::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
