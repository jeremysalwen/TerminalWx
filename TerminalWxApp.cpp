/***************************************************************
 * Name:      TerminalWxApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Jeremy Salwen (jeremysalwen@gmail.com)
 * Created:   2012-01-05
 * Copyright: Jeremy Salwen ()
 * License:
 **************************************************************/

#include "TerminalWxApp.h"

//(*AppHeaders
#include "TerminalWxMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(TerminalWxApp);

bool TerminalWxApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	TerminalWxFrame* Frame = new TerminalWxFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
