////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/ownership_state.cpp                                                     //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/ownership_state.h"
using autogen::state::ownership_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

ownership_state::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  ownership_state temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
ownership_state::state_machine::state_machine(const string& name, const ownership_state& s) :
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
ownership_state::state_machine::~state_machine() {
  // No-op.
}
ownership_state::STATE_T ownership_state::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
ownership_state::STATE_T ownership_state::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string ownership_state::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string ownership_state::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void ownership_state::state_machine::update(const ownership_state& ref_state) {
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

const bool ownership_state::s_transitions[3][3] = {
  {false,true,true},
  {true,false,true},
  {true,true,false}
};

ownership_state::ownership_state() : network::state(autogen::type::OWNERSHIP_STATE,BEGIN) {
  // No-op.
}
ownership_state::ownership_state(STATE_T s) : network::state(autogen::type::OWNERSHIP_STATE,s) {
  // No-op.
}
ownership_state::~ownership_state() {
  // No-op.
}
ownership_state::type_t ownership_state::type_index() const {
  return mc_type;
}
string ownership_state::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void ownership_state::initialize() {
  clear();
}
void ownership_state::clear() {
  clear_content();
}
string ownership_state::print() const {
  return type_label()+","+print_content();
}
ownership_state::STATE_T ownership_state::index() const {
  return static_cast<STATE_T>(m_state);
}
string ownership_state::label() const {
  static const char* labels[] = {
    "NOT_OWNED",
    "OWNED_BY_THIS_GCS",
    "OWNED_BY_OTHER_GCS"
  };
  return labels[m_state];
}
ownership_state& ownership_state::operator=(const ownership_state& rhs) {
  m_state = rhs.m_state;
  return *this;
}
ownership_state& ownership_state::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool ownership_state::operator==(const ownership_state& rhs) const {
  return (index() == rhs.index());
}
bool ownership_state::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void ownership_state::clear_content() {
  operator=(BEGIN);
}
string ownership_state::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* ownership_state::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* ownership_state::deserialize_content(const uint8* buff) {
  operator=(autogen::state::ownership_state(static_cast<autogen::state::ownership_state::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
