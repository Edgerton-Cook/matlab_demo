////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/hmc5883l_state.cpp                                                      //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/hmc5883l_state.h"
using autogen::state::hmc5883l_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

hmc5883l_state::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  hmc5883l_state temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
hmc5883l_state::state_machine::state_machine(const string& name, const hmc5883l_state& s) :
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
hmc5883l_state::state_machine::~state_machine() {
  // No-op.
}
hmc5883l_state::STATE_T hmc5883l_state::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
hmc5883l_state::STATE_T hmc5883l_state::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string hmc5883l_state::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string hmc5883l_state::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void hmc5883l_state::state_machine::update(const hmc5883l_state& ref_state) {
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

const bool hmc5883l_state::s_transitions[5][5] = {
  {false,true,false,false,false},
  {false,false,true,true,false},
  {false,false,false,false,true},
  {false,false,false,false,true},
  {true,false,false,false,false}
};

hmc5883l_state::hmc5883l_state() : network::state(autogen::type::HMC5883L_STATE,BEGIN) {
  // No-op.
}
hmc5883l_state::hmc5883l_state(STATE_T s) : network::state(autogen::type::HMC5883L_STATE,s) {
  // No-op.
}
hmc5883l_state::~hmc5883l_state() {
  // No-op.
}
hmc5883l_state::type_t hmc5883l_state::type_index() const {
  return mc_type;
}
string hmc5883l_state::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void hmc5883l_state::initialize() {
  clear();
}
void hmc5883l_state::clear() {
  clear_content();
}
string hmc5883l_state::print() const {
  return type_label()+","+print_content();
}
hmc5883l_state::STATE_T hmc5883l_state::index() const {
  return static_cast<STATE_T>(m_state);
}
string hmc5883l_state::label() const {
  static const char* labels[] = {
    "IDLE",
    "INITIALIZE",
    "ACTIVE",
    "CALIBRATE",
    "DEACTIVATE"
  };
  return labels[m_state];
}
hmc5883l_state& hmc5883l_state::operator=(const hmc5883l_state& rhs) {
  m_state = rhs.m_state;
  return *this;
}
hmc5883l_state& hmc5883l_state::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool hmc5883l_state::operator==(const hmc5883l_state& rhs) const {
  return (index() == rhs.index());
}
bool hmc5883l_state::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void hmc5883l_state::clear_content() {
  operator=(BEGIN);
}
string hmc5883l_state::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* hmc5883l_state::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* hmc5883l_state::deserialize_content(const uint8* buff) {
  operator=(autogen::state::hmc5883l_state(static_cast<autogen::state::hmc5883l_state::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
