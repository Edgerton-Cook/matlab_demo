////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/pca9685_calib_data.h                                             //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_PCA9685_CALIB_DATA_H
#define AUTOGEN_SERIALIZABLE_PCA9685_CALIB_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/pca9685_calib_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::pca9685_calib_data::TOPIC_T T> 
    class pca9685_calib_data : public network::serializable, public autogen::timestamped::pca9685_calib_data {
      public:
        pca9685_calib_data() :
          serializable(),
          autogen::timestamped::pca9685_calib_data(T) {
          // No-op.
        }
        pca9685_calib_data(const std::string& filename) :
          serializable(),
          autogen::timestamped::pca9685_calib_data(T,filename) {
          // No-op.
        }
        virtual ~pca9685_calib_data() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +4;
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
        pca9685_calib_data<T>& operator=(const autogen::parameter::pca9685_calib_data& rhs) {
          autogen::parameter::pca9685_calib_data::operator=(rhs);
          return *this;
        }
        pca9685_calib_data<T>& operator=(const autogen::timestamped::pca9685_calib_data& rhs) {
          autogen::timestamped::pca9685_calib_data::operator=(rhs);
          return *this;
        }
        pca9685_calib_data<T>& operator=(const pca9685_calib_data<T>& rhs) {
          autogen::timestamped::pca9685_calib_data::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
