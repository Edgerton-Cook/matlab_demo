////////////////////////////////////////////////////////////////////////////////////////////////////
// TITLE:   autogen/state/led_state.cpp                                                           //
// AUTHOR:  Miki Szmuk                                                                            //
// LAB:     Autonomous Controls Lab (ACL)                                                         //
// LICENSE: Copyright 2016, 2017, All Rights Reserved                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autogen/state/led_state.h"
using autogen::state::led_state;
using std::string;

////////////////////////////////////////////////////////////////////////////////////////////////////

led_state::state_machine::state_machine(const string& name, STATE_T s) :
  mc_name(name+"_sm") {
  led_state temp_state(s);
  m_previous_accepted_state_index = temp_state.index();
  m_current_accepted_state_index = temp_state.index();
  m_previous_accepted_state_label = temp_state.label();
  m_current_accepted_state_label = temp_state.label();

  std::ostringstream msg;
  msg << "'" << mc_name << "' initialized to: '"
      << m_current_accepted_state_label << "'";
  utilities::print(msg," > ");
}
led_state::state_machine::state_machine(const string& name, const led_state& s) :
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
led_state::state_machine::~state_machine() {
  // No-op.
}
led_state::STATE_T led_state::state_machine::previous_state_index() const {
  return static_cast<STATE_T>(m_previous_accepted_state_index);
}
led_state::STATE_T led_state::state_machine::current_state_index() const {
  return static_cast<STATE_T>(m_current_accepted_state_index);
}
string led_state::state_machine::previous_state_label() const {
  return m_previous_accepted_state_label;
}
string led_state::state_machine::current_state_label() const {
  return m_current_accepted_state_label;
}
void led_state::state_machine::update(const led_state& ref_state) {
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

const bool led_state::s_transitions[9][9] = {
  {false,true,false,false,false,false,false,false,false},
  {false,false,true,true,true,true,true,true,false},
  {false,false,false,true,true,true,true,true,true},
  {false,false,true,false,true,true,true,true,true},
  {false,false,true,true,false,true,true,true,true},
  {false,false,true,true,true,false,true,true,true},
  {false,false,true,true,true,true,false,true,true},
  {false,false,true,true,true,true,true,false,true},
  {true,false,false,false,false,false,false,false,false}
};

led_state::led_state() : network::state(autogen::type::LED_STATE,BEGIN) {
  // No-op.
}
led_state::led_state(STATE_T s) : network::state(autogen::type::LED_STATE,s) {
  // No-op.
}
led_state::~led_state() {
  // No-op.
}
led_state::type_t led_state::type_index() const {
  return mc_type;
}
string led_state::type_label() const {
  return autogen::labels::type_labels[mc_type];
}
void led_state::initialize() {
  clear();
}
void led_state::clear() {
  clear_content();
}
string led_state::print() const {
  return type_label()+","+print_content();
}
led_state::STATE_T led_state::index() const {
  return static_cast<STATE_T>(m_state);
}
string led_state::label() const {
  static const char* labels[] = {
    "IDLE",
    "INITIALIZE",
    "ACTIVE",
    "ACTIVE_RGB_SOLID",
    "ACTIVE_RGB_BLINKING",
    "ACTIVE_RGB_SPINNING",
    "ACTIVE_RGB_PROGRESS",
    "ACTIVE_RGB_NAV",
    "DEACTIVATE"
  };
  return labels[m_state];
}
led_state& led_state::operator=(const led_state& rhs) {
  m_state = rhs.m_state;
  return *this;
}
led_state& led_state::operator=(STATE_T rhs) {
  m_state = rhs;
  return *this;
}
bool led_state::operator==(const led_state& rhs) const {
  return (index() == rhs.index());
}
bool led_state::operator==(STATE_T rhs) const {
  return (index() == rhs);
}

void led_state::clear_content() {
  operator=(BEGIN);
}
string led_state::print_content() const {
  std::ostringstream ss;
  ss << label() << ",";
  return ss.str();
}
uint8* led_state::serialize_content(uint8* buff) const {
  buff[0] = index();
  ++buff;
  return buff;
}
const uint8* led_state::deserialize_content(const uint8* buff) {
  operator=(autogen::state::led_state(static_cast<autogen::state::led_state::STATE_T>(buff[0])));
  ++buff;
  return buff;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
