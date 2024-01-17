////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/fm_cmd_states.h                                                  //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_FM_CMD_STATES_H
#define AUTOGEN_SERIALIZABLE_FM_CMD_STATES_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/fm_cmd_states.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::fm_cmd_states::TOPIC_T T> 
    class fm_cmd_states : public network::serializable, public autogen::timestamped::fm_cmd_states {
      public:
        fm_cmd_states() :
          serializable(),
          autogen::timestamped::fm_cmd_states(T) {
          // No-op.
        }
        virtual ~fm_cmd_states() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +12;
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
        fm_cmd_states<T>& operator=(const autogen::packet::fm_cmd_states& rhs) {
          autogen::packet::fm_cmd_states::operator=(rhs);
          return *this;
        }
        fm_cmd_states<T>& operator=(const autogen::timestamped::fm_cmd_states& rhs) {
          autogen::timestamped::fm_cmd_states::operator=(rhs);
          return *this;
        }
        fm_cmd_states<T>& operator=(const fm_cmd_states<T>& rhs) {
          autogen::timestamped::fm_cmd_states::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
