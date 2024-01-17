////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/power_state.cpp                                                         //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/power_state.h"
using autogen::state::power_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

power_state::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  power_state temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
power_state::state_machine::state_machine(const string& name, const power_state& s) :
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
power_state::state_machine::~state_machine() {
  // No-op.
}
power_state::STATE_T power_state::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
power_state::STATE_T power_state::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string power_state::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string power_state::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void power_state::state_machine::update(const power_state& ref_state) {
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

const bool power_state::s_transitions[4][4] = {
  {false,true,false,false},
  {false,false,true,false},
  {false,false,false,true},
  {true,false,false,false}
};

power_state::power_state() : network::state(autogen::type::POWER_STATE,BEGIN) {
  // No-op.
}
power_state::power_state(STATE_T s) : network::state(autogen::type::POWER_STATE,s) {
  // No-op.
}
power_state::~power_state() {
  // No-op.
}
power_state::type_t power_state::type_index() const {
  return mc_type;
}
string power_state::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void power_state::initialize() {
  clear();
}
void power_state::clear() {
  clear_content();
}
string power_state::print() const {
  return type_label()+","+print_content();
}
power_state::STATE_T power_state::index() const {
  return static_cast<STATE_T>(m_state);
}
string power_state::label() const {
  static const char* labels[] = {
    "IDLE",
    "INITIALIZE",
    "ACTIVE",
    "DEACTIVATE"
  };
  return labels[m_state];
}
power_state& power_state::operator=(const power_state& rhs) {
  m_state = rhs.m_state;
  return *this;
}
power_state& power_state::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool power_state::operator==(const power_state& rhs) const {
  return (index() == rhs.index());
}
bool power_state::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void power_state::clear_content() {
  operator=(BEGIN);
}
string power_state::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* power_state::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* power_state::deserialize_content(const uint8* buff) {
  operator=(autogen::state::power_state(static_cast<autogen::state::power_state::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
