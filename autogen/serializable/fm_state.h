////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/fm_state.h                                                       //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_FM_STATE_H
#define AUTOGEN_SERIALIZABLE_FM_STATE_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/fm_state.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::fm_state::TOPIC_T T> 
    class fm_state : public network::serializable, public autogen::timestamped::fm_state {
      public:
        fm_state() :
          serializable(),
          autogen::timestamped::fm_state(T) {
          // No-op.
        }
        fm_state(STATE_T s) :
          serializable(),
          autogen::timestamped::fm_state(T,s) {
          // No-op.
        }
        virtual ~fm_state() {
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
        fm_state<T>& operator=(STATE_T rhs) {
          autogen::state::fm_state::operator=(rhs);
          return *this;
        }
        fm_state<T>& operator=(const autogen::state::fm_state& rhs) {
          autogen::state::fm_state::operator=(rhs);
          return *this;
        }
        fm_state<T>& operator=(const autogen::timestamped::fm_state& rhs) {
          autogen::timestamped::fm_state::operator=(rhs);
          return *this;
        }
        fm_state<T>& operator=(const fm_state<T>& rhs) {
          autogen::timestamped::fm_state::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
