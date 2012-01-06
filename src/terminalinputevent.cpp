#include "terminalinputevent.h"


DEFINE_EVENT_TYPE(chEVT_TERMINAL_INPUT)

TerminalInputEvent::TerminalInputEvent()
	: wxEvent(0, chEVT_TERMINAL_INPUT)
{
	//
}

TerminalInputEvent::TerminalInputEvent(const TerminalInputEvent& otherEvent)
: wxEvent(otherEvent)
{
	this->SetString(otherEvent.GetString());
}
