////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/deserializable/gcs_agent_config_data.h                                        //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AUTOGEN_DESERIALIZABLE_GCS_AGENT_CONFIG_DATA_H
#define AUTOGEN_DESERIALIZABLE_GCS_AGENT_CONFIG_DATA_H

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/timestamped/gcs_agent_config_data.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace autogen {
  namespace deserializable {
    template<autogen::topic::gcs_agent_config_data::TOPIC_T T> 
    class gcs_agent_config_data : public network::deserializable, public autogen::timestamped::gcs_agent_config_data {
      public:
        gcs_agent_config_data() :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::gcs_agent_config_data(T) {
          // No-op.
        }
        gcs_agent_config_data(const std::string& filename) :
          network::deserializable(autogen::node::UNDEFINED),
          autogen::timestamped::gcs_agent_config_data(T,filename) {
          // No-op.
        }
        virtual ~gcs_agent_config_data() {
          // No-op.
        }
        uint32 size() const {
          return sizeof(type_t)
                +sizeof(topic_t)
                +sizeof(node_t)
                +sizeof(ts_t)
                +37;
        }
        node_t node_index() const {
          return m_node;
        }
        std::string node_label() const {
          return autogen::labels::node_labels[node_index()];
        }
        const uint8* deserialize(const uint8* buff) {
          if ((type_index() == buff[0]) and (topic_index() == buff[1])) {
            buff = buff+2;
            buff = network::packet::deserialize(buff,m_node,1);
            buff = network::packet::deserialize(buff,timestamp(),1);
            buff = deserialize_content(buff);
          }
          return buff;
        }
        void forget() {
          m_node = autogen::node::UNDEFINED;
        }
        void clear() {
          m_node = autogen::node::UNDEFINED;
          m_timestamp = 0;
          clear_content();
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
        gcs_agent_config_data<T>& operator=(const autogen::parameter::gcs_agent_config_data& rhs) {
          autogen::parameter::gcs_agent_config_data::operator=(rhs);
          return *this;
        }
        gcs_agent_config_data<T>& operator=(const autogen::timestamped::gcs_agent_config_data& rhs) {
          autogen::timestamped::gcs_agent_config_data::operator=(rhs);
          return *this;
        }
        gcs_agent_config_data<T>& operator=(const gcs_agent_config_data<T>& rhs) {
          autogen::timestamped::gcs_agent_config_data::operator=(rhs);
          return *this;
        }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
