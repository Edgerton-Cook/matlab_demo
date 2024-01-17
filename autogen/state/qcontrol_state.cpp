////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/qcontrol_state.cpp                                                      //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/qcontrol_state.h"
using autogen::state::qcontrol_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

qcontrol_state::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  qcontrol_state temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
qcontrol_state::state_machine::state_machine(const string& name, const qcontrol_state& s) :
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
qcontrol_state::state_machine::~state_machine() {
  // No-op.
}
qcontrol_state::STATE_T qcontrol_state::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
qcontrol_state::STATE_T qcontrol_state::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string qcontrol_state::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string qcontrol_state::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void qcontrol_state::state_machine::update(const qcontrol_state& ref_state) {
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

const bool qcontrol_state::s_transitions[4][4] = {
  {false,true,false,false},
  {false,false,true,false},
  {false,false,false,true},
  {true,false,false,false}
};

qcontrol_state::qcontrol_state() : network::state(autogen::type::QCONTROL_STATE,BEGIN) {
  // No-op.
}
qcontrol_state::qcontrol_state(STATE_T s) : network::state(autogen::type::QCONTROL_STATE,s) {
  // No-op.
}
qcontrol_state::~qcontrol_state() {
  // No-op.
}
qcontrol_state::type_t qcontrol_state::type_index() const {
  return mc_type;
}
string qcontrol_state::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void qcontrol_state::initialize() {
  clear();
}
void qcontrol_state::clear() {
  clear_content();
}
string qcontrol_state::print() const {
  return type_label()+","+print_content();
}
qcontrol_state::STATE_T qcontrol_state::index() const {
  return static_cast<STATE_T>(m_state);
}
string qcontrol_state::label() const {
  static const char* labels[] = {
    "IDLE",
    "INITIALIZE",
    "ACTIVE",
    "DEACTIVATE"
  };
  return labels[m_state];
}
qcontrol_state& qcontrol_state::operator=(const qcontrol_state& rhs) {
  m_state = rhs.m_state;
  return *this;
}
qcontrol_state& qcontrol_state::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool qcontrol_state::operator==(const qcontrol_state& rhs) const {
  return (index() == rhs.index());
}
bool qcontrol_state::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void qcontrol_state::clear_content() {
  operator=(BEGIN);
}
string qcontrol_state::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* qcontrol_state::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* qcontrol_state::deserialize_content(const uint8* buff) {
  operator=(autogen::state::qcontrol_state(static_cast<autogen::state::qcontrol_state::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
