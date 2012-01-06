//////////////////////////////////////////////////////////////////////
//
//   ChameleonProcessEvent
//
//////////////////////////////////////////////////////////////////////

#ifndef __TERMINAL_INPUT_EVENT__H__
#define __TERMINAL_INPUT_EVENT__H__

#include <wx/process.h>
#include <wx/event.h>

// -------------------------------------------------------------------
// ProcessEvent
// -------------------------------------------------------------------
DECLARE_EVENT_TYPE(chEVT_TERMINAL_INPUT, wxID_ANY)


class TerminalInputEvent : public wxEvent
{
	public:
		TerminalInputEvent();
		TerminalInputEvent(const TerminalInputEvent& event);

		void SetString(wxString s) { m_string = s; }

		wxString GetString() const { return m_string; }

		virtual wxEvent *Clone() const { return new TerminalInputEvent(*this); }

	private:
		wxString m_string;

};

typedef void (wxEvtHandler::*TerminalInputEventFunction)(TerminalInputEvent&);


#define EVT_TERMINAL_INPUT(fn) \
	DECLARE_EVENT_TABLE_ENTRY( \
			chEVT_TERMINAL_INPUT, wxID_ANY, wxID_ANY, \
			(wxObjectEventFunction)(wxEventFunction)(TerminalInputEventFunction)&fn, \
			(wxObject *) NULL),


#endif // __TERMINAL_INPUT_EVENT__H__
