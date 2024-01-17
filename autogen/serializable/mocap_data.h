////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/mocap_data.h                                                     //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_MOCAP_DATA_H
#define AUTOGEN_SERIALIZABLE_MOCAP_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/mocap_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::mocap_data::TOPIC_T T> 
    class mocap_data : public network::serializable, public autogen::timestamped::mocap_data {
      public:
        mocap_data() :
          serializable(),
          autogen::timestamped::mocap_data(T) {
          // No-op.
        }
        virtual ~mocap_data() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +29;
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
        mocap_data<T>& operator=(const autogen::packet::mocap_data& rhs) {
          autogen::packet::mocap_data::operator=(rhs);
          return *this;
        }
        mocap_data<T>& operator=(const autogen::timestamped::mocap_data& rhs) {
          autogen::timestamped::mocap_data::operator=(rhs);
          return *this;
        }
        mocap_data<T>& operator=(const mocap_data<T>& rhs) {
          autogen::timestamped::mocap_data::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
