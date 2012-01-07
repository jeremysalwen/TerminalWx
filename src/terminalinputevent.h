/*
TerminalWx - A wxWidgets terminal widget
Copyright (C) 2004  Mark Erikson
              2012  Jeremy Salwen

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
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
		TerminalInputEvent(wxString str);
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
