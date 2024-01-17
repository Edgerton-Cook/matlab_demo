////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/deserializable/qcontrol_mode.h                                                //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_DESERIALIZABLE_QCONTROL_MODE_H
#define AUTOGEN_DESERIALIZABLE_QCONTROL_MODE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/qcontrol_mode.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace deserializable {
    template<autogen::topic::qcontrol_mode::TOPIC_T T> 
    class qcontrol_mode : public network::deserializable, public autogen::timestamped::qcontrol_mode {
      public:
        qcontrol_mode() :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::qcontrol_mode(T) {
          // No-op.
        }
        qcontrol_mode(STATE_T s) :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::qcontrol_mode(T,s) {
          // No-op.
        }
        virtual ~qcontrol_mode() {
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
        qcontrol_mode<T>& operator=(STATE_T rhs) {
          autogen::state::qcontrol_mode::operator=(rhs);
          return *this;
        }
        qcontrol_mode<T>& operator=(const autogen::state::qcontrol_mode& rhs) {
          autogen::state::qcontrol_mode::operator=(rhs);
          return *this;
        }
        qcontrol_mode<T>& operator=(const autogen::timestamped::qcontrol_mode& rhs) {
          autogen::timestamped::qcontrol_mode::operator=(rhs);
          return *this;
        }
        qcontrol_mode<T>& operator=(const qcontrol_mode<T>& rhs) {
          autogen::timestamped::qcontrol_mode::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
