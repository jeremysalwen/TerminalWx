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
