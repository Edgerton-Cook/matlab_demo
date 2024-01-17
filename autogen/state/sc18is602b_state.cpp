////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/sc18is602b_state.cpp                                                    //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/sc18is602b_state.h"
using autogen::state::sc18is602b_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

sc18is602b_state::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  sc18is602b_state temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
sc18is602b_state::state_machine::state_machine(const string& name, const sc18is602b_state& s) :
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
sc18is602b_state::state_machine::~state_machine() {
  // No-op.
}
sc18is602b_state::STATE_T sc18is602b_state::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
sc18is602b_state::STATE_T sc18is602b_state::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string sc18is602b_state::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string sc18is602b_state::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void sc18is602b_state::state_machine::update(const sc18is602b_state& ref_state) {
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

const bool sc18is602b_state::s_transitions[4][4] = {
  {false,true,false,false},
  {false,false,true,false},
  {false,false,false,true},
  {true,false,false,false}
};

sc18is602b_state::sc18is602b_state() : network::state(autogen::type::SC18IS602B_STATE,BEGIN) {
  // No-op.
}
sc18is602b_state::sc18is602b_state(STATE_T s) : network::state(autogen::type::SC18IS602B_STATE,s) {
  // No-op.
}
sc18is602b_state::~sc18is602b_state() {
  // No-op.
}
sc18is602b_state::type_t sc18is602b_state::type_index() const {
  return mc_type;
}
string sc18is602b_state::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void sc18is602b_state::initialize() {
  clear();
}
void sc18is602b_state::clear() {
  clear_content();
}
string sc18is602b_state::print() const {
  return type_label()+","+print_content();
}
sc18is602b_state::STATE_T sc18is602b_state::index() const {
  return static_cast<STATE_T>(m_state);
}
string sc18is602b_state::label() const {
  static const char* labels[] = {
    "IDLE",
    "INITIALIZE",
    "ACTIVE",
    "DEACTIVATE"
  };
  return labels[m_state];
}
sc18is602b_state& sc18is602b_state::operator=(const sc18is602b_state& rhs) {
  m_state = rhs.m_state;
  return *this;
}
sc18is602b_state& sc18is602b_state::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool sc18is602b_state::operator==(const sc18is602b_state& rhs) const {
  return (index() == rhs.index());
}
bool sc18is602b_state::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void sc18is602b_state::clear_content() {
  operator=(BEGIN);
}
string sc18is602b_state::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* sc18is602b_state::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* sc18is602b_state::deserialize_content(const uint8* buff) {
  operator=(autogen::state::sc18is602b_state(static_cast<autogen::state::sc18is602b_state::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
