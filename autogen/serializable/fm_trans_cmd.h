////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/serializable/fm_trans_cmd.h                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_SERIALIZABLE_FM_TRANS_CMD_H
#define AUTOGEN_SERIALIZABLE_FM_TRANS_CMD_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/fm_trans_cmd.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace serializable {
    template<autogen::topic::fm_trans_cmd::TOPIC_T T> 
    class fm_trans_cmd : public network::serializable, public autogen::timestamped::fm_trans_cmd {
      public:
        fm_trans_cmd() :
          serializable(),
          autogen::timestamped::fm_trans_cmd(T) {
          // No-op.
        }
        fm_trans_cmd(STATE_T s) :
          serializable(),
          autogen::timestamped::fm_trans_cmd(T,s) {
          // No-op.
        }
        virtual ~fm_trans_cmd() {
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
        fm_trans_cmd<T>& operator=(STATE_T rhs) {
          autogen::state::fm_trans_cmd::operator=(rhs);
          return *this;
        }
        fm_trans_cmd<T>& operator=(const autogen::state::fm_trans_cmd& rhs) {
          autogen::state::fm_trans_cmd::operator=(rhs);
          return *this;
        }
        fm_trans_cmd<T>& operator=(const autogen::timestamped::fm_trans_cmd& rhs) {
          autogen::timestamped::fm_trans_cmd::operator=(rhs);
          return *this;
        }
        fm_trans_cmd<T>& operator=(const fm_trans_cmd<T>& rhs) {
          autogen::timestamped::fm_trans_cmd::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
