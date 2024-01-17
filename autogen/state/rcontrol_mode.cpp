////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/rcontrol_mode.cpp                                                       //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/rcontrol_mode.h"
using autogen::state::rcontrol_mode;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

rcontrol_mode::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  rcontrol_mode temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
rcontrol_mode::state_machine::state_machine(const string& name, const rcontrol_mode& s) :
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
rcontrol_mode::state_machine::~state_machine() {
  // No-op.
}
rcontrol_mode::STATE_T rcontrol_mode::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
rcontrol_mode::STATE_T rcontrol_mode::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string rcontrol_mode::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string rcontrol_mode::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void rcontrol_mode::state_machine::update(const rcontrol_mode& ref_state) {
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

const bool rcontrol_mode::s_transitions[6][6] = {
  {false,true,false,false,false,false},
  {true,false,true,true,true,true},
  {true,true,false,true,true,true},
  {true,true,true,false,true,true},
  {true,true,true,true,false,true},
  {true,true,true,true,true,false}
};

rcontrol_mode::rcontrol_mode() : network::state(autogen::type::RCONTROL_MODE,BEGIN) {
  // No-op.
}
rcontrol_mode::rcontrol_mode(STATE_T s) : network::state(autogen::type::RCONTROL_MODE,s) {
  // No-op.
}
rcontrol_mode::~rcontrol_mode() {
  // No-op.
}
rcontrol_mode::type_t rcontrol_mode::type_index() const {
  return mc_type;
}
string rcontrol_mode::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void rcontrol_mode::initialize() {
  clear();
}
void rcontrol_mode::clear() {
  clear_content();
}
string rcontrol_mode::print() const {
  return type_label()+","+print_content();
}
rcontrol_mode::STATE_T rcontrol_mode::index() const {
  return static_cast<STATE_T>(m_state);
}
string rcontrol_mode::label() const {
  static const char* labels[] = {
    "SAFETIED",
    "STANDBY",
    "TEST_MODE",
    "OPEN_LOOP",
    "CLOSED_LOOP_VEL",
    "CLOSED_LOOP_POS"
  };
  return labels[m_state];
}
rcontrol_mode& rcontrol_mode::operator=(const rcontrol_mode& rhs) {
  m_state = rhs.m_state;
  return *this;
}
rcontrol_mode& rcontrol_mode::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool rcontrol_mode::operator==(const rcontrol_mode& rhs) const {
  return (index() == rhs.index());
}
bool rcontrol_mode::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void rcontrol_mode::clear_content() {
  operator=(BEGIN);
}
string rcontrol_mode::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* rcontrol_mode::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* rcontrol_mode::deserialize_content(const uint8* buff) {
  operator=(autogen::state::rcontrol_mode(static_cast<autogen::state::rcontrol_mode::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
