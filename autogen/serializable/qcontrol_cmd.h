////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/qcontrol_cmd.h                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_QCONTROL_CMD_H
#define AUTOGEN_SERIALIZABLE_QCONTROL_CMD_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/qcontrol_cmd.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::qcontrol_cmd::TOPIC_T T> 
    class qcontrol_cmd : public network::serializable, public autogen::timestamped::qcontrol_cmd {
      public:
        qcontrol_cmd() :
          serializable(),
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
        std::string node_label() const {
          return autogen::labels::node_labels[node_index()];
        }
        uint8* serialize(uint8* buff) const {
          buff = network::packet::serialize(buff,type_index(),1);
          buff = network::packet::serialize(buff,topic_index(),1);
          buff = network::packet::serialize(buff,node_index(),1);
          buff = network::packet::serialize(buff,timestamp(),1);
          buff = serialize_content(buff);
          return buff;
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
