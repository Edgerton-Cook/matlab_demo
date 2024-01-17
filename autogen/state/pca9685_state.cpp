////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/pca9685_state.cpp                                                       //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/pca9685_state.h"
using autogen::state::pca9685_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

pca9685_state::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  pca9685_state temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
pca9685_state::state_machine::state_machine(const string& name, const pca9685_state& s) :
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
pca9685_state::state_machine::~state_machine() {
  // No-op.
}
pca9685_state::STATE_T pca9685_state::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
pca9685_state::STATE_T pca9685_state::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string pca9685_state::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string pca9685_state::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void pca9685_state::state_machine::update(const pca9685_state& ref_state) {
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

const bool pca9685_state::s_transitions[8][8] = {
  {false,true,false,false,false,false,false,false},
  {false,false,true,false,false,false,false,false},
  {false,false,false,true,true,true,true,true},
  {false,false,true,false,false,false,false,false},
  {false,false,true,false,false,false,false,false},
  {false,false,true,false,true,false,false,false},
  {false,false,true,false,false,false,false,false},
  {true,false,false,false,false,false,false,false}
};

pca9685_state::pca9685_state() : network::state(autogen::type::PCA9685_STATE,BEGIN) {
  // No-op.
}
pca9685_state::pca9685_state(STATE_T s) : network::state(autogen::type::PCA9685_STATE,s) {
  // No-op.
}
pca9685_state::~pca9685_state() {
  // No-op.
}
pca9685_state::type_t pca9685_state::type_index() const {
  return mc_type;
}
string pca9685_state::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void pca9685_state::initialize() {
  clear();
}
void pca9685_state::clear() {
  clear_content();
}
string pca9685_state::print() const {
  return type_label()+","+print_content();
}
pca9685_state::STATE_T pca9685_state::index() const {
  return static_cast<STATE_T>(m_state);
}
string pca9685_state::label() const {
  static const char* labels[] = {
    "IDLE",
    "INITIALIZE",
    "SAFE",
    "ACTIVE",
    "MIN",
    "MAX",
    "CALIBRATE",
    "DEACTIVATE"
  };
  return labels[m_state];
}
pca9685_state& pca9685_state::operator=(const pca9685_state& rhs) {
  m_state = rhs.m_state;
  return *this;
}
pca9685_state& pca9685_state::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool pca9685_state::operator==(const pca9685_state& rhs) const {
  return (index() == rhs.index());
}
bool pca9685_state::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void pca9685_state::clear_content() {
  operator=(BEGIN);
}
string pca9685_state::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* pca9685_state::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* pca9685_state::deserialize_content(const uint8* buff) {
  operator=(autogen::state::pca9685_state(static_cast<autogen::state::pca9685_state::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
