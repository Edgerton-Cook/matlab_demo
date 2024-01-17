////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/edison_state.cpp                                                        //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/edison_state.h"
using autogen::state::edison_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

edison_state::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  edison_state temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
edison_state::state_machine::state_machine(const string& name, const edison_state& s) :
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
edison_state::state_machine::~state_machine() {
  // No-op.
}
edison_state::STATE_T edison_state::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
edison_state::STATE_T edison_state::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string edison_state::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string edison_state::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void edison_state::state_machine::update(const edison_state& ref_state) {
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

const bool edison_state::s_transitions[6][6] = {
  {false,true,false,false,false,false},
  {false,false,true,true,false,false},
  {false,false,false,true,false,true},
  {false,false,false,false,true,false},
  {false,false,true,false,false,true},
  {true,false,false,false,false,false}
};

edison_state::edison_state() : network::state(autogen::type::EDISON_STATE,BEGIN) {
  // No-op.
}
edison_state::edison_state(STATE_T s) : network::state(autogen::type::EDISON_STATE,s) {
  // No-op.
}
edison_state::~edison_state() {
  // No-op.
}
edison_state::type_t edison_state::type_index() const {
  return mc_type;
}
string edison_state::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void edison_state::initialize() {
  clear();
}
void edison_state::clear() {
  clear_content();
}
string edison_state::print() const {
  return type_label()+","+print_content();
}
edison_state::STATE_T edison_state::index() const {
  return static_cast<STATE_T>(m_state);
}
string edison_state::label() const {
  static const char* labels[] = {
    "IDLE",
    "INITIALIZE",
    "ACTIVE",
    "MEASURE",
    "CLEAN",
    "DEACTIVATE"
  };
  return labels[m_state];
}
edison_state& edison_state::operator=(const edison_state& rhs) {
  m_state = rhs.m_state;
  return *this;
}
edison_state& edison_state::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool edison_state::operator==(const edison_state& rhs) const {
  return (index() == rhs.index());
}
bool edison_state::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void edison_state::clear_content() {
  operator=(BEGIN);
}
string edison_state::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* edison_state::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* edison_state::deserialize_content(const uint8* buff) {
  operator=(autogen::state::edison_state(static_cast<autogen::state::edison_state::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
