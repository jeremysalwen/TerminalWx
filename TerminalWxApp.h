/***************************************************************
 * Name:      TerminalWxApp.h
 * Purpose:   Defines Application Class
 * Author:    Jeremy Salwen (jeremysalwen@gmail.com)
 * Created:   2012-01-05
 * Copyright: Jeremy Salwen ()
 * License:
 **************************************************************/

#ifndef TERMINALWXAPP_H
#define TERMINALWXAPP_H

#include <wx/app.h>

class TerminalWxApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // TERMINALWXAPP_H
