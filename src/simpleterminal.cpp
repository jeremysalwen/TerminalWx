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
