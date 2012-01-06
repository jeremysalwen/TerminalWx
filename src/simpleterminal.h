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

#ifndef SIMPLETERMINAL_H
#define SIMPLETERMINAL_H

#include "wxterm.h"
#include "terminalinputevent.h"
class SimpleTerminal : public wxTerm
{
public:
    SimpleTerminal(wxWindow* parent, wxWindowID id,
                   const wxPoint& pos = wxDefaultPosition,
                   int width = 80, int height = 24,
                   const wxString& name = "simpleTerm");
    virtual ~SimpleTerminal();
    virtual void SendBack(int len, char* data);
    void OnTerminalInput(TerminalInputEvent&);
protected:
private:

  DECLARE_EVENT_TABLE()
};

#endif // SIMPLETERMINAL_H
