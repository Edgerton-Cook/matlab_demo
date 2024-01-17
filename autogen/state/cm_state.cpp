////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/cm_state.cpp                                                            //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/cm_state.h"
using autogen::state::cm_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

cm_state::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  cm_state temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
cm_state::state_machine::state_machine(const string& name, const cm_state& s) :
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
cm_state::state_machine::~state_machine() {
  // No-op.
}
cm_state::STATE_T cm_state::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
cm_state::STATE_T cm_state::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string cm_state::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string cm_state::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void cm_state::state_machine::update(const cm_state& ref_state) {
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

const bool cm_state::s_transitions[6][6] = {
  {false,true,false,false,false,false},
  {false,false,true,false,true,false},
  {false,true,false,true,true,false},
  {false,false,true,false,true,false},
  {false,false,false,false,false,true},
  {false,false,false,false,false,false}
};

cm_state::cm_state() : network::state(autogen::type::CM_STATE,BEGIN) {
  // No-op.
}
cm_state::cm_state(STATE_T s) : network::state(autogen::type::CM_STATE,s) {
  // No-op.
}
cm_state::~cm_state() {
  // No-op.
}
cm_state::type_t cm_state::type_index() const {
  return mc_type;
}
string cm_state::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void cm_state::initialize() {
  clear();
}
void cm_state::clear() {
  clear_content();
}
string cm_state::print() const {
  return type_label()+","+print_content();
}
cm_state::STATE_T cm_state::index() const {
  return static_cast<STATE_T>(m_state);
}
string cm_state::label() const {
  static const char* labels[] = {
    "INITIALIZE",
    "DISCONNECTED",
    "CONNECTED",
    "OWNED",
    "DEACTIVATE",
    "IDLE"
  };
  return labels[m_state];
}
cm_state& cm_state::operator=(const cm_state& rhs) {
  m_state = rhs.m_state;
  return *this;
}
cm_state& cm_state::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool cm_state::operator==(const cm_state& rhs) const {
  return (index() == rhs.index());
}
bool cm_state::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void cm_state::clear_content() {
  operator=(BEGIN);
}
string cm_state::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* cm_state::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* cm_state::deserialize_content(const uint8* buff) {
  operator=(autogen::state::cm_state(static_cast<autogen::state::cm_state::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
