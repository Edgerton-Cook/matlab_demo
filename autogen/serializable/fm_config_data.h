////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/fm_config_data.h                                                 //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_FM_CONFIG_DATA_H
#define AUTOGEN_SERIALIZABLE_FM_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/fm_config_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::fm_config_data::TOPIC_T T> 
    class fm_config_data : public network::serializable, public autogen::timestamped::fm_config_data {
      public:
        fm_config_data() :
          serializable(),
          autogen::timestamped::fm_config_data(T) {
          // No-op.
        }
        fm_config_data(const std::string& filename) :
          serializable(),
          autogen::timestamped::fm_config_data(T,filename) {
          // No-op.
        }
        virtual ~fm_config_data() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +17;
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
        fm_config_data<T>& operator=(const autogen::parameter::fm_config_data& rhs) {
          autogen::parameter::fm_config_data::operator=(rhs);
          return *this;
        }
        fm_config_data<T>& operator=(const autogen::timestamped::fm_config_data& rhs) {
          autogen::timestamped::fm_config_data::operator=(rhs);
          return *this;
        }
        fm_config_data<T>& operator=(const fm_config_data<T>& rhs) {
          autogen::timestamped::fm_config_data::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
