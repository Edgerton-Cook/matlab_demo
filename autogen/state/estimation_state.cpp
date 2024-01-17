////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/estimation_state.cpp                                                    //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/estimation_state.h"
using autogen::state::estimation_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

estimation_state::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  estimation_state temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
estimation_state::state_machine::state_machine(const string& name, const estimation_state& s) :
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
estimation_state::state_machine::~state_machine() {
  // No-op.
}
estimation_state::STATE_T estimation_state::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
estimation_state::STATE_T estimation_state::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string estimation_state::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string estimation_state::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void estimation_state::state_machine::update(const estimation_state& ref_state) {
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

const bool estimation_state::s_transitions[5][5] = {
  {false,true,false,true,false},
  {false,false,true,false,false},
  {false,false,false,false,true},
  {true,false,false,false,false},
  {true,false,false,false,false}
};

estimation_state::estimation_state() : network::state(autogen::type::ESTIMATION_STATE,BEGIN) {
  // No-op.
}
estimation_state::estimation_state(STATE_T s) : network::state(autogen::type::ESTIMATION_STATE,s) {
  // No-op.
}
estimation_state::~estimation_state() {
  // No-op.
}
estimation_state::type_t estimation_state::type_index() const {
  return mc_type;
}
string estimation_state::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void estimation_state::initialize() {
  clear();
}
void estimation_state::clear() {
  clear_content();
}
string estimation_state::print() const {
  return type_label()+","+print_content();
}
estimation_state::STATE_T estimation_state::index() const {
  return static_cast<STATE_T>(m_state);
}
string estimation_state::label() const {
  static const char* labels[] = {
    "IDLE",
    "INITIALIZE",
    "ACTIVE",
    "PASSIVE",
    "DEACTIVATE"
  };
  return labels[m_state];
}
estimation_state& estimation_state::operator=(const estimation_state& rhs) {
  m_state = rhs.m_state;
  return *this;
}
estimation_state& estimation_state::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool estimation_state::operator==(const estimation_state& rhs) const {
  return (index() == rhs.index());
}
bool estimation_state::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void estimation_state::clear_content() {
  operator=(BEGIN);
}
string estimation_state::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* estimation_state::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* estimation_state::deserialize_content(const uint8* buff) {
  operator=(autogen::state::estimation_state(static_cast<autogen::state::estimation_state::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
