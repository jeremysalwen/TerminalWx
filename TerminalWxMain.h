// *** ADDED BY HEADER FIXUP ***
#include <wx/event.h>
#include <wx/window.h>
// *** END ***
/***************************************************************
 * Name:      TerminalWxMain.h
 * Purpose:   Defines Application Frame
 * Author:    Jeremy Salwen (jeremysalwen@gmail.com)
 * Created:   2012-01-05
 * Copyright: Jeremy Salwen ()
 * License:
 **************************************************************/

#ifndef TERMINALWXMAIN_H
#define TERMINALWXMAIN_H

//(*Headers(TerminalWxFrame)
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
//*)

#include "src/wxterm.h"

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
        wxStatusBar* StatusBar1;
        wxTerm* Term1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TERMINALWXMAIN_H
