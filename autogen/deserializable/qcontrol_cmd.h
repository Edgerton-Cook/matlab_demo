////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/deserializable/qcontrol_cmd.h                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_DESERIALIZABLE_QCONTROL_CMD_H
#define AUTOGEN_DESERIALIZABLE_QCONTROL_CMD_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/qcontrol_cmd.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace deserializable {
    template<autogen::topic::qcontrol_cmd::TOPIC_T T> 
    class qcontrol_cmd : public network::deserializable, public autogen::timestamped::qcontrol_cmd {
      public:
        qcontrol_cmd() :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::qcontrol_cmd(T) {
          // No-op.
        }
        virtual ~qcontrol_cmd() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +18;
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
        qcontrol_cmd<T>& operator=(const autogen::packet::qcontrol_cmd& rhs) {
          autogen::packet::qcontrol_cmd::operator=(rhs);
          return *this;
        }
        qcontrol_cmd<T>& operator=(const autogen::timestamped::qcontrol_cmd& rhs) {
          autogen::timestamped::qcontrol_cmd::operator=(rhs);
          return *this;
        }
        qcontrol_cmd<T>& operator=(const qcontrol_cmd<T>& rhs) {
          autogen::timestamped::qcontrol_cmd::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
