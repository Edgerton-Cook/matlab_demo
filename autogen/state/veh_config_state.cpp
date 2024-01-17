////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/veh_config_state.cpp                                                    //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/veh_config_state.h"
using autogen::state::veh_config_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

veh_config_state::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  veh_config_state temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
veh_config_state::state_machine::state_machine(const string& name, const veh_config_state& s) :
  mc_name(name+"_sm"),
  m_previous_accepted_state_index(s.index()),
  m_current_accepted_state_index(s.index()),
  m_previous_accepted_state_label(s.label()),
  m_current_accepted_state_label(s.label()) {

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
veh_config_state::state_machine::~state_machine() {
  // No-op.
}
veh_config_state::STATE_T veh_config_state::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
veh_config_state::STATE_T veh_config_state::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string veh_config_state::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string veh_config_state::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void veh_config_state::state_machine::update(const veh_config_state& ref_state) {
  if (s_transitions[m_current_accepted_state_index][ref_state.index()]) {
    m_previous_accepted_state_index = m_current_accepted_state_index;
    m_previous_accepted_state_label = m_current_accepted_state_label;
    m_current_accepted_state_index = ref_state.index();
    m_current_accepted_state_label = ref_state.label();

    std::ostringstream msg;
    msg << "'" << mc_name << "' transition: "
        << "'" << m_previous_accepted_state_label
        << "' ---> '"
        << m_current_accepted_state_label << "'";
    utilities::print(msg," > ");
  }
}

const bool veh_config_state::s_transitions[3][3] = {
  {false,false,false},
  {false,false,false},
  {false,false,false}
};

veh_config_state::veh_config_state() : network::state(autogen::type::VEH_CONFIG_STATE,BEGIN) {
  // No-op.
}
veh_config_state::veh_config_state(STATE_T s) : network::state(autogen::type::VEH_CONFIG_STATE,s) {
  // No-op.
}
veh_config_state::~veh_config_state() {
  // No-op.
}
veh_config_state::type_t veh_config_state::type_index() const {
  return mc_type;
}
string veh_config_state::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void veh_config_state::initialize() {
  clear();
}
void veh_config_state::clear() {
  clear_content();
}
string veh_config_state::print() const {
  return type_label()+","+print_content();
}
veh_config_state::STATE_T veh_config_state::index() const {
  return static_cast<STATE_T>(m_state);
}
string veh_config_state::label() const {
  static const char* labels[] = {
    "INDOOR_ROVER",
    "INDOOR_QUAD",
    "OUTDOOR_QUAD"
  };
  return labels[m_state];
}
veh_config_state& veh_config_state::operator=(const veh_config_state& rhs) {
  m_state = rhs.m_state;
  return *this;
}
veh_config_state& veh_config_state::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool veh_config_state::operator==(const veh_config_state& rhs) const {
  return (index() == rhs.index());
}
bool veh_config_state::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void veh_config_state::clear_content() {
  operator=(BEGIN);
}
string veh_config_state::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* veh_config_state::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* veh_config_state::deserialize_content(const uint8* buff) {
  operator=(autogen::state::veh_config_state(static_cast<autogen::state::veh_config_state::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
