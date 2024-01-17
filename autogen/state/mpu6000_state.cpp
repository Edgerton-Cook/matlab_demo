////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/mpu6000_state.cpp                                                       //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/mpu6000_state.h"
using autogen::state::mpu6000_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

mpu6000_state::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  mpu6000_state temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
mpu6000_state::state_machine::state_machine(const string& name, const mpu6000_state& s) :
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
mpu6000_state::state_machine::~state_machine() {
  // No-op.
}
mpu6000_state::STATE_T mpu6000_state::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
mpu6000_state::STATE_T mpu6000_state::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string mpu6000_state::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string mpu6000_state::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void mpu6000_state::state_machine::update(const mpu6000_state& ref_state) {
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

const bool mpu6000_state::s_transitions[5][5] = {
  {false,true,false,false,false},
  {false,false,true,true,false},
  {false,false,false,false,true},
  {false,false,false,false,true},
  {true,false,false,false,false}
};

mpu6000_state::mpu6000_state() : network::state(autogen::type::MPU6000_STATE,BEGIN) {
  // No-op.
}
mpu6000_state::mpu6000_state(STATE_T s) : network::state(autogen::type::MPU6000_STATE,s) {
  // No-op.
}
mpu6000_state::~mpu6000_state() {
  // No-op.
}
mpu6000_state::type_t mpu6000_state::type_index() const {
  return mc_type;
}
string mpu6000_state::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void mpu6000_state::initialize() {
  clear();
}
void mpu6000_state::clear() {
  clear_content();
}
string mpu6000_state::print() const {
  return type_label()+","+print_content();
}
mpu6000_state::STATE_T mpu6000_state::index() const {
  return static_cast<STATE_T>(m_state);
}
string mpu6000_state::label() const {
  static const char* labels[] = {
    "IDLE",
    "INITIALIZE",
    "ACTIVE",
    "CALIBRATE",
    "DEACTIVATE"
  };
  return labels[m_state];
}
mpu6000_state& mpu6000_state::operator=(const mpu6000_state& rhs) {
  m_state = rhs.m_state;
  return *this;
}
mpu6000_state& mpu6000_state::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool mpu6000_state::operator==(const mpu6000_state& rhs) const {
  return (index() == rhs.index());
}
bool mpu6000_state::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void mpu6000_state::clear_content() {
  operator=(BEGIN);
}
string mpu6000_state::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* mpu6000_state::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* mpu6000_state::deserialize_content(const uint8* buff) {
  operator=(autogen::state::mpu6000_state(static_cast<autogen::state::mpu6000_state::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
