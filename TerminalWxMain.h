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

#ifndef TERMINALWXMAIN_H
#define TERMINALWXMAIN_H

//(*Headers(TerminalWxFrame)
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
//*)

#include <wx/event.h>
#include <wx/window.h>

#include "src/simpleterminal.h"

class TerminalWxFrame: public wxFrame
{
    public:

        TerminalWxFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~TerminalWxFrame();

    private:

        //(*Handlers(TerminalWxFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnCustom1Paint(wxPaintEvent& event);
        //*)

        //(*Identifiers(TerminalWxFrame)
        static const long ID_TERM;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(TerminalWxFrame)
        SimpleTerminal* Term1;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TERMINALWXMAIN_H
