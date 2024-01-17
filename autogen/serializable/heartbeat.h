////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/heartbeat.h                                                      //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_HEARTBEAT_H
#define AUTOGEN_SERIALIZABLE_HEARTBEAT_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/heartbeat.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::heartbeat::TOPIC_T T> 
    class heartbeat : public network::serializable, public autogen::timestamped::heartbeat {
      public:
        heartbeat() :
          serializable(),
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
