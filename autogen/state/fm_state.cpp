////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/fm_state.cpp                                                            //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/fm_state.h"
using autogen::state::fm_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

fm_state::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  fm_state temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
fm_state::state_machine::state_machine(const string& name, const fm_state& s) :
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
fm_state::state_machine::~state_machine() {
  // No-op.
}
fm_state::STATE_T fm_state::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
fm_state::STATE_T fm_state::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string fm_state::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string fm_state::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void fm_state::state_machine::update(const fm_state& ref_state) {
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

const bool fm_state::s_transitions[11][11] = {
  {false,true,false,false,false,false,false,false,false,false,false},
  {true,false,true,false,true,false,true,true,true,true,true},
  {false,false,false,true,false,false,false,false,false,false,false},
  {false,false,false,false,false,true,false,false,false,false,false},
  {false,false,false,false,false,true,false,false,false,false,false},
  {false,true,false,false,false,false,false,false,false,false,false},
  {false,true,false,false,false,false,false,false,false,false,false},
  {false,true,false,false,false,false,false,false,false,false,false},
  {false,true,false,false,false,false,false,false,false,false,false},
  {false,true,false,false,false,false,false,false,false,false,false},
  {false,false,false,false,false,false,false,false,false,false,false}
};

fm_state::fm_state() : network::state(autogen::type::FM_STATE,BEGIN) {
  // No-op.
}
fm_state::fm_state(STATE_T s) : network::state(autogen::type::FM_STATE,s) {
  // No-op.
}
fm_state::~fm_state() {
  // No-op.
}
fm_state::type_t fm_state::type_index() const {
  return mc_type;
}
string fm_state::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void fm_state::initialize() {
  clear();
}
void fm_state::clear() {
  clear_content();
}
string fm_state::print() const {
  return type_label()+","+print_content();
}
fm_state::STATE_T fm_state::index() const {
  return static_cast<STATE_T>(m_state);
}
string fm_state::label() const {
  static const char* labels[] = {
    "BOOT",
    "IDLE",
    "INITIALIZE",
    "ACTIVE",
    "TEST_MODE",
    "DEACTIVATE",
    "CALIBRATE_IMU",
    "CALIBRATE_MAG",
    "CALIBRATE_PWM",
    "CALIBRATE_ESC",
    "SHUTDOWN"
  };
  return labels[m_state];
}
fm_state& fm_state::operator=(const fm_state& rhs) {
  m_state = rhs.m_state;
  return *this;
}
fm_state& fm_state::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool fm_state::operator==(const fm_state& rhs) const {
  return (index() == rhs.index());
}
bool fm_state::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void fm_state::clear_content() {
  operator=(BEGIN);
}
string fm_state::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* fm_state::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* fm_state::deserialize_content(const uint8* buff) {
  operator=(autogen::state::fm_state(static_cast<autogen::state::fm_state::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
