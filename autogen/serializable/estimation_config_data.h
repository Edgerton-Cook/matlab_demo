////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/estimation_config_data.h                                         //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_ESTIMATION_CONFIG_DATA_H
#define AUTOGEN_SERIALIZABLE_ESTIMATION_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/estimation_config_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::estimation_config_data::TOPIC_T T> 
    class estimation_config_data : public network::serializable, public autogen::timestamped::estimation_config_data {
      public:
        estimation_config_data() :
          serializable(),
          autogen::timestamped::estimation_config_data(T) {
          // No-op.
        }
        estimation_config_data(const std::string& filename) :
          serializable(),
          autogen::timestamped::estimation_config_data(T,filename) {
          // No-op.
        }
        virtual ~estimation_config_data() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +20;
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
        estimation_config_data<T>& operator=(const autogen::parameter::estimation_config_data& rhs) {
          autogen::parameter::estimation_config_data::operator=(rhs);
          return *this;
        }
        estimation_config_data<T>& operator=(const autogen::timestamped::estimation_config_data& rhs) {
          autogen::timestamped::estimation_config_data::operator=(rhs);
          return *this;
        }
        estimation_config_data<T>& operator=(const estimation_config_data<T>& rhs) {
          autogen::timestamped::estimation_config_data::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
