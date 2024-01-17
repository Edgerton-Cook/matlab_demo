////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/qcontrol_mode.cpp                                                       //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/qcontrol_mode.h"
using autogen::state::qcontrol_mode;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

qcontrol_mode::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  qcontrol_mode temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
qcontrol_mode::state_machine::state_machine(const string& name, const qcontrol_mode& s) :
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
qcontrol_mode::state_machine::~state_machine() {
  // No-op.
}
qcontrol_mode::STATE_T qcontrol_mode::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
qcontrol_mode::STATE_T qcontrol_mode::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string qcontrol_mode::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string qcontrol_mode::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void qcontrol_mode::state_machine::update(const qcontrol_mode& ref_state) {
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

const bool qcontrol_mode::s_transitions[9][9] = {
  {false,true,false,false,false,false,false,false,false},
  {true,false,true,true,true,true,true,true,true},
  {true,true,false,true,true,true,true,true,true},
  {true,true,true,false,true,true,true,true,true},
  {true,true,false,false,false,true,true,true,true},
  {true,true,false,false,true,false,true,true,true},
  {true,true,false,false,true,true,false,true,true},
  {true,true,false,false,true,true,true,false,true},
  {true,true,false,false,true,true,true,true,false}
};

qcontrol_mode::qcontrol_mode() : network::state(autogen::type::QCONTROL_MODE,BEGIN) {
  // No-op.
}
qcontrol_mode::qcontrol_mode(STATE_T s) : network::state(autogen::type::QCONTROL_MODE,s) {
  // No-op.
}
qcontrol_mode::~qcontrol_mode() {
  // No-op.
}
qcontrol_mode::type_t qcontrol_mode::type_index() const {
  return mc_type;
}
string qcontrol_mode::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void qcontrol_mode::initialize() {
  clear();
}
void qcontrol_mode::clear() {
  clear_content();
}
string qcontrol_mode::print() const {
  return type_label()+","+print_content();
}
qcontrol_mode::STATE_T qcontrol_mode::index() const {
  return static_cast<STATE_T>(m_state);
}
string qcontrol_mode::label() const {
  static const char* labels[] = {
    "SAFETIED",
    "STANDBY",
    "TORQUES",
    "RATES",
    "INERTIAL",
    "ATTITUDE",
    "ALT",
    "POS",
    "TRAJ"
  };
  return labels[m_state];
}
qcontrol_mode& qcontrol_mode::operator=(const qcontrol_mode& rhs) {
  m_state = rhs.m_state;
  return *this;
}
qcontrol_mode& qcontrol_mode::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool qcontrol_mode::operator==(const qcontrol_mode& rhs) const {
  return (index() == rhs.index());
}
bool qcontrol_mode::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void qcontrol_mode::clear_content() {
  operator=(BEGIN);
}
string qcontrol_mode::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* qcontrol_mode::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* qcontrol_mode::deserialize_content(const uint8* buff) {
  operator=(autogen::state::qcontrol_mode(static_cast<autogen::state::qcontrol_mode::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
