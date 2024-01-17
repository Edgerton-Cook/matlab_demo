////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/telemetry.h                                                      //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_TELEMETRY_H
#define AUTOGEN_SERIALIZABLE_TELEMETRY_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/telemetry.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::telemetry::TOPIC_T T> 
    class telemetry : public network::serializable, public autogen::timestamped::telemetry {
      public:
        telemetry() :
          serializable(),
          autogen::timestamped::telemetry(T) {
          // No-op.
        }
        virtual ~telemetry() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +93;
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
        telemetry<T>& operator=(const autogen::packet::telemetry& rhs) {
          autogen::packet::telemetry::operator=(rhs);
          return *this;
        }
        telemetry<T>& operator=(const autogen::timestamped::telemetry& rhs) {
          autogen::timestamped::telemetry::operator=(rhs);
          return *this;
        }
        telemetry<T>& operator=(const telemetry<T>& rhs) {
          autogen::timestamped::telemetry::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
