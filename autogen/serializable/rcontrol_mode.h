////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/rcontrol_mode.h                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_RCONTROL_MODE_H
#define AUTOGEN_SERIALIZABLE_RCONTROL_MODE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/rcontrol_mode.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::rcontrol_mode::TOPIC_T T> 
    class rcontrol_mode : public network::serializable, public autogen::timestamped::rcontrol_mode {
      public:
        rcontrol_mode() :
          serializable(),
          autogen::timestamped::rcontrol_mode(T) {
          // No-op.
        }
        rcontrol_mode(STATE_T s) :
          serializable(),
          autogen::timestamped::rcontrol_mode(T,s) {
          // No-op.
        }
        virtual ~rcontrol_mode() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +1;
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
        rcontrol_mode<T>& operator=(STATE_T rhs) {
          autogen::state::rcontrol_mode::operator=(rhs);
          return *this;
        }
        rcontrol_mode<T>& operator=(const autogen::state::rcontrol_mode& rhs) {
          autogen::state::rcontrol_mode::operator=(rhs);
          return *this;
        }
        rcontrol_mode<T>& operator=(const autogen::timestamped::rcontrol_mode& rhs) {
          autogen::timestamped::rcontrol_mode::operator=(rhs);
          return *this;
        }
        rcontrol_mode<T>& operator=(const rcontrol_mode<T>& rhs) {
          autogen::timestamped::rcontrol_mode::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
