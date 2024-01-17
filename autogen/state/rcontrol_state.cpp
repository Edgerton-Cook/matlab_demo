////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/rcontrol_state.cpp                                                      //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/rcontrol_state.h"
using autogen::state::rcontrol_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

rcontrol_state::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  rcontrol_state temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
rcontrol_state::state_machine::state_machine(const string& name, const rcontrol_state& s) :
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
rcontrol_state::state_machine::~state_machine() {
  // No-op.
}
rcontrol_state::STATE_T rcontrol_state::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
rcontrol_state::STATE_T rcontrol_state::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string rcontrol_state::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string rcontrol_state::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void rcontrol_state::state_machine::update(const rcontrol_state& ref_state) {
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

const bool rcontrol_state::s_transitions[4][4] = {
  {false,true,false,false},
  {false,false,true,false},
  {false,false,false,true},
  {true,false,false,false}
};

rcontrol_state::rcontrol_state() : network::state(autogen::type::RCONTROL_STATE,BEGIN) {
  // No-op.
}
rcontrol_state::rcontrol_state(STATE_T s) : network::state(autogen::type::RCONTROL_STATE,s) {
  // No-op.
}
rcontrol_state::~rcontrol_state() {
  // No-op.
}
rcontrol_state::type_t rcontrol_state::type_index() const {
  return mc_type;
}
string rcontrol_state::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void rcontrol_state::initialize() {
  clear();
}
void rcontrol_state::clear() {
  clear_content();
}
string rcontrol_state::print() const {
  return type_label()+","+print_content();
}
rcontrol_state::STATE_T rcontrol_state::index() const {
  return static_cast<STATE_T>(m_state);
}
string rcontrol_state::label() const {
  static const char* labels[] = {
    "IDLE",
    "INITIALIZE",
    "ACTIVE",
    "DEACTIVATE"
  };
  return labels[m_state];
}
rcontrol_state& rcontrol_state::operator=(const rcontrol_state& rhs) {
  m_state = rhs.m_state;
  return *this;
}
rcontrol_state& rcontrol_state::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool rcontrol_state::operator==(const rcontrol_state& rhs) const {
  return (index() == rhs.index());
}
bool rcontrol_state::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void rcontrol_state::clear_content() {
  operator=(BEGIN);
}
string rcontrol_state::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* rcontrol_state::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* rcontrol_state::deserialize_content(const uint8* buff) {
  operator=(autogen::state::rcontrol_state(static_cast<autogen::state::rcontrol_state::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
