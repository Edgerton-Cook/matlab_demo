////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/neom8_state.cpp                                                         //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/neom8_state.h"
using autogen::state::neom8_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

neom8_state::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  neom8_state temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
neom8_state::state_machine::state_machine(const string& name, const neom8_state& s) :
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
neom8_state::state_machine::~state_machine() {
  // No-op.
}
neom8_state::STATE_T neom8_state::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
neom8_state::STATE_T neom8_state::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string neom8_state::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string neom8_state::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void neom8_state::state_machine::update(const neom8_state& ref_state) {
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

const bool neom8_state::s_transitions[4][4] = {
  {false,true,false,false},
  {false,false,true,false},
  {false,false,false,true},
  {true,false,false,false}
};

neom8_state::neom8_state() : network::state(autogen::type::NEOM8_STATE,BEGIN) {
  // No-op.
}
neom8_state::neom8_state(STATE_T s) : network::state(autogen::type::NEOM8_STATE,s) {
  // No-op.
}
neom8_state::~neom8_state() {
  // No-op.
}
neom8_state::type_t neom8_state::type_index() const {
  return mc_type;
}
string neom8_state::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void neom8_state::initialize() {
  clear();
}
void neom8_state::clear() {
  clear_content();
}
string neom8_state::print() const {
  return type_label()+","+print_content();
}
neom8_state::STATE_T neom8_state::index() const {
  return static_cast<STATE_T>(m_state);
}
string neom8_state::label() const {
  static const char* labels[] = {
    "IDLE",
    "INITIALIZE",
    "ACTIVE",
    "DEACTIVATE"
  };
  return labels[m_state];
}
neom8_state& neom8_state::operator=(const neom8_state& rhs) {
  m_state = rhs.m_state;
  return *this;
}
neom8_state& neom8_state::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool neom8_state::operator==(const neom8_state& rhs) const {
  return (index() == rhs.index());
}
bool neom8_state::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void neom8_state::clear_content() {
  operator=(BEGIN);
}
string neom8_state::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* neom8_state::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* neom8_state::deserialize_content(const uint8* buff) {
  operator=(autogen::state::neom8_state(static_cast<autogen::state::neom8_state::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
