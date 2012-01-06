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

SimpleTerminal::SimpleTerminal(wxWindow* parent, wxWindowID id,
                               const wxPoint& pos,
                               int width, int height,
                               const wxString& name):  wxTerm(parent,id,pos,width,height,name)
{
    //ctor
}

void SimpleTerminal::SendBack(int len,char* data) {
    char* tmp=new char[len+1];
    memcpy(tmp,data,len);
    tmp[len]='\0';
    wxLogDebug("Recieved data! %s",tmp);
    delete[] tmp;
}


void SimpleTerminal::OnTerminalInput(TerminalInputEvent& evt) {
    wxString str=evt.GetString();
    ProcessInput(str.length(),(unsigned char*)const_cast<char*>((const char*)str.mb_str()));
}

SimpleTerminal::~SimpleTerminal()
{
    //dtor
}


wxBEGIN_EVENT_TABLE(SimpleTerminal, wxTerm)

EVT_TERMINAL_INPUT(SimpleTerminal::OnTerminalInput)

wxEND_EVENT_TABLE()
