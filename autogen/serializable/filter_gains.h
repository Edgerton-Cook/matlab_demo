////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/filter_gains.h                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_FILTER_GAINS_H
#define AUTOGEN_SERIALIZABLE_FILTER_GAINS_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/filter_gains.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::filter_gains::TOPIC_T T> 
    class filter_gains : public network::serializable, public autogen::timestamped::filter_gains {
      public:
        filter_gains() :
          serializable(),
          autogen::timestamped::filter_gains(T) {
          // No-op.
        }
        filter_gains(const std::string& filename) :
          serializable(),
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
