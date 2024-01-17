////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/fm_trans_cmd.cpp                                                        //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/fm_trans_cmd.h"
using autogen::state::fm_trans_cmd;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

fm_trans_cmd::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  fm_trans_cmd temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
fm_trans_cmd::state_machine::state_machine(const string& name, const fm_trans_cmd& s) :
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
fm_trans_cmd::state_machine::~state_machine() {
  // No-op.
}
fm_trans_cmd::STATE_T fm_trans_cmd::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
fm_trans_cmd::STATE_T fm_trans_cmd::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string fm_trans_cmd::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string fm_trans_cmd::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void fm_trans_cmd::state_machine::update(const fm_trans_cmd& ref_state) {
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

const bool fm_trans_cmd::s_transitions[9][9] = {
  {false,true,true,true,true,true,true,true,true},
  {true,false,true,true,true,true,true,true,true},
  {true,true,false,true,true,true,true,true,true},
  {true,true,true,false,true,true,true,true,true},
  {true,true,true,true,false,true,true,true,true},
  {true,true,true,true,true,false,true,true,true},
  {true,true,true,true,true,true,false,true,true},
  {true,true,true,true,true,true,true,false,true},
  {true,true,true,true,true,true,true,true,false}
};

fm_trans_cmd::fm_trans_cmd() : network::state(autogen::type::FM_TRANS_CMD,BEGIN) {
  // No-op.
}
fm_trans_cmd::fm_trans_cmd(STATE_T s) : network::state(autogen::type::FM_TRANS_CMD,s) {
  // No-op.
}
fm_trans_cmd::~fm_trans_cmd() {
  // No-op.
}
fm_trans_cmd::type_t fm_trans_cmd::type_index() const {
  return mc_type;
}
string fm_trans_cmd::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void fm_trans_cmd::initialize() {
  clear();
}
void fm_trans_cmd::clear() {
  clear_content();
}
string fm_trans_cmd::print() const {
  return type_label()+","+print_content();
}
fm_trans_cmd::STATE_T fm_trans_cmd::index() const {
  return static_cast<STATE_T>(m_state);
}
string fm_trans_cmd::label() const {
  static const char* labels[] = {
    "NOTHING",
    "RUN",
    "TEST_MODE",
    "STOP",
    "CALIBRATE_IMU",
    "CALIBRATE_MAG",
    "CALIBRATE_PWM",
    "CALIBRATE_ESC",
    "EXIT"
  };
  return labels[m_state];
}
fm_trans_cmd& fm_trans_cmd::operator=(const fm_trans_cmd& rhs) {
  m_state = rhs.m_state;
  return *this;
}
fm_trans_cmd& fm_trans_cmd::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool fm_trans_cmd::operator==(const fm_trans_cmd& rhs) const {
  return (index() == rhs.index());
}
bool fm_trans_cmd::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void fm_trans_cmd::clear_content() {
  operator=(BEGIN);
}
string fm_trans_cmd::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* fm_trans_cmd::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* fm_trans_cmd::deserialize_content(const uint8* buff) {
  operator=(autogen::state::fm_trans_cmd(static_cast<autogen::state::fm_trans_cmd::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
