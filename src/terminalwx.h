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

#ifndef TERMINALWX_H
#define TERMINALWX_H

#include "taTelnet/wxterm.h"
#include "terminalinputevent.h"

/*! \mainpage TerminalWx
 *
 * \section intro_sec Introduction
 *
 * TerminalWx is a fully VT100 compatible virtual terminal widget for wxWindows
 *
 * The code is almost entirely from the Chameleon IDE by Mark Erikson,
 *  taTelnet by Derry Bryson, and GTerm by Timothy Miller.
 *
 * \section install_sec Use
 *
 * The public API for TerminalWx is the class TerminalWx.
 *  It is a wxWindow.  Simply add it to your gui as you would any other widget.
 *
 *
 */


/**
 *  Terminal Widget
 *
 *  To handle user input to the terminal, inherit this
 *  class and override the OnUserInput
 *
 *  To make the widget display new characters sent from your backend,
 *  use DisplayChars (or you may use DisplayCharsUnsafe, if you are
 *  calling from within the main event loop.
 */
class TerminalWx : public wxTerm
{
public:
    TerminalWx(wxWindow* parent, wxWindowID id,
                   const wxPoint& pos = wxDefaultPosition,
                   int width = 80, int height = 24,
                   const wxString& name = "TerminalWx");
    virtual ~TerminalWx();
    virtual void OnUserInput(wxString);
    virtual void DisplayChars(const wxString& text);
    virtual void DisplayCharsUnsafe(const wxString& text);
protected:
private:
  void OnTerminalInput(TerminalInputEvent&);
  virtual void SendBack(int len, char* data);
  virtual void SendBack(char* data);
  DECLARE_EVENT_TABLE()
};

#endif // TERMINALWX_H
