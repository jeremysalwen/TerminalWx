/*
TerminalWx - A wxWidgets terminal widget
Copyright (C) 2012 Jeremy Salwen

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

#include "simpleterminal.h"

#include <wx/log.h>
/**
    Constructor for the terminal widget.

    @param width The width of the terminal in characters
    @param height The height of the terminal in character

    @param name
        The terminal name, which is not displayed but stored
        internally, and might be changed by VT commands.

*/
SimpleTerminal::SimpleTerminal(wxWindow* parent, wxWindowID id,
                               const wxPoint& pos,
                               int width, int height,
                               const wxString& name):  wxTerm(parent,id,pos,width,height,name)
{
    //ctor
}
/**
    Called whenever the user has input additional text.
        By default it does nothing.
*/
void SimpleTerminal::OnUserInput(wxString input) {
    wxLogDebug("GotInput! %s",input);
    //By default do nothing.
}

void SimpleTerminal::SendBack(int len,char* data) {
    OnUserInput(wxString(data,len));
}
void SimpleTerminal::SendBack(char* data) {
    OnUserInput(wxString(data));
}
/**
 *  Processes characters sent from the backend.
 *
 *  This function is thread safe and can be called from any thread at any time.
 *
*/
void SimpleTerminal::DisplayChars(const wxString& str) {
     this->QueueEvent(new TerminalInputEvent(str));
}

/**
 *  Processes characters sent from the backend
 *
 *  This function is not thread safe and can *only*
 *  safely be called from the main event loop
*/
void SimpleTerminal::DisplayCharsUnsafe(const wxString& str) {
     ProcessInput(str.length(),(unsigned char*)const_cast<char*>((const char*)str.mb_str()));
}

void SimpleTerminal::OnTerminalInput(TerminalInputEvent& evt) {
    DisplayCharsUnsafe(evt.GetString());
}

SimpleTerminal::~SimpleTerminal()
{
    //dtor
}


wxBEGIN_EVENT_TABLE(SimpleTerminal, wxTerm)

EVT_TERMINAL_INPUT(SimpleTerminal::OnTerminalInput)

wxEND_EVENT_TABLE()
