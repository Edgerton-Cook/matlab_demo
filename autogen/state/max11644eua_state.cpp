////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/max11644eua_state.cpp                                                   //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/max11644eua_state.h"
using autogen::state::max11644eua_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

max11644eua_state::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  max11644eua_state temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
max11644eua_state::state_machine::state_machine(const string& name, const max11644eua_state& s) :
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
max11644eua_state::state_machine::~state_machine() {
  // No-op.
}
max11644eua_state::STATE_T max11644eua_state::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
max11644eua_state::STATE_T max11644eua_state::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string max11644eua_state::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string max11644eua_state::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void max11644eua_state::state_machine::update(const max11644eua_state& ref_state) {
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

const bool max11644eua_state::s_transitions[4][4] = {
  {false,true,false,false},
  {false,false,true,false},
  {false,false,false,true},
  {true,false,false,false}
};

max11644eua_state::max11644eua_state() : network::state(autogen::type::MAX11644EUA_STATE,BEGIN) {
  // No-op.
}
max11644eua_state::max11644eua_state(STATE_T s) : network::state(autogen::type::MAX11644EUA_STATE,s) {
  // No-op.
}
max11644eua_state::~max11644eua_state() {
  // No-op.
}
max11644eua_state::type_t max11644eua_state::type_index() const {
  return mc_type;
}
string max11644eua_state::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void max11644eua_state::initialize() {
  clear();
}
void max11644eua_state::clear() {
  clear_content();
}
string max11644eua_state::print() const {
  return type_label()+","+print_content();
}
max11644eua_state::STATE_T max11644eua_state::index() const {
  return static_cast<STATE_T>(m_state);
}
string max11644eua_state::label() const {
  static const char* labels[] = {
    "IDLE",
    "INITIALIZE",
    "ACTIVE",
    "DEACTIVATE"
  };
  return labels[m_state];
}
max11644eua_state& max11644eua_state::operator=(const max11644eua_state& rhs) {
  m_state = rhs.m_state;
  return *this;
}
max11644eua_state& max11644eua_state::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool max11644eua_state::operator==(const max11644eua_state& rhs) const {
  return (index() == rhs.index());
}
bool max11644eua_state::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void max11644eua_state::clear_content() {
  operator=(BEGIN);
}
string max11644eua_state::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* max11644eua_state::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* max11644eua_state::deserialize_content(const uint8* buff) {
  operator=(autogen::state::max11644eua_state(static_cast<autogen::state::max11644eua_state::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
