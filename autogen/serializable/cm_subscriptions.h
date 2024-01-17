////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/cm_subscriptions.h                                               //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_CM_SUBSCRIPTIONS_H
#define AUTOGEN_SERIALIZABLE_CM_SUBSCRIPTIONS_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/cm_subscriptions.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::cm_subscriptions::TOPIC_T T> 
    class cm_subscriptions : public network::serializable, public autogen::timestamped::cm_subscriptions {
      public:
        cm_subscriptions() :
          serializable(),
          autogen::timestamped::cm_subscriptions(T) {
          // No-op.
        }
        cm_subscriptions(const std::string& filename) :
          serializable(),
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
