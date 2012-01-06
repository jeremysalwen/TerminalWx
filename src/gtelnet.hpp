/*
TerminalWx - A wxWidgets terminal widget
Copyright (C) 1999  Derry Bryson
              2004  Mark Erikson
              2012  Jeremy Salwen

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

#ifndef INCLUDED_GTELNET_H
#define INCLUDED_GTELNET_H

#ifdef __GNUG__
#pragma interface
#endif

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "gterm.hpp"

class GTelnet : public GTerm
{
public:
  enum
  {
    IAC = 255,       // start of telnet command (interpret as command)
    SE = 240,        // end of subnegotiation params
    NOP = 241,       // no operation
    DATAMARK = 242,  // data stream portion of sync
    BREAK = 243,     // nvt character break
    IP = 244,        // interrupt process
    AO = 245,        // abort output
    AYT = 246,       // are you there?
    EC = 247,        // erase character
    EL = 248,        // erase line
    GA = 249,        // go ahead
    SB = 250,        // start of subnegotiation parms
    WILL = 251,      // will do option
    WONT = 252,      // won't do option
    DO = 253,        // do option
    DONT = 254       // don't do option
  } TELNET_CMDS;

  enum
  {
    TRANSMIT_BINARY = 0,        // RFC 856
    TERMINAL_TYPE = 24          // RFC 884
  } TELNET_OPTIONS;

private:
  typedef void
    (GTelnet::*StateFunc)();

  typedef struct Option
  {
    int byte;	// char value to look for; -1==end/default
    StateFunc action;
    Option *next_state;
  } StateOption;

  // terminal state
  StateOption *telnet_current_state;

  int telnet_lastcmd;
  int telnet_binary_recv;
  int telnet_binary_send;
  int telnet_process_data;
  char *telnet_termid;
  unsigned char *telnet_input_data;

  //
  //  Define state tables
  //
  static StateOption telnet_normal_state[];
  static StateOption telnet_cmd_state[];
  static StateOption telnet_sub_state[];
  static StateOption telnet_do_state[];
  static StateOption telnet_will_state[];
  static StateOption telnet_dont_state[];

  //
  //  Define Actions
  //
  void telnet_iac(void);
  void telnet_binary_iac(void);
  void telnet_eat(void);
  void telnet_cmd(void);
  void telnet_do(void);
  void telnet_will(void);
  void telnet_dont(void);
  void telnet_wont(void);

public:
  GTelnet(int w, int h);
  virtual ~GTelnet();

  // function to control terminal
  virtual void ProcessInput(int len, unsigned char *data);
  virtual void ProcessOutput(int len, unsigned char *data);
  virtual void ModeChange(int state);
  virtual void Reset();

  void SetTermID(char *termId);
  char *GetTermID(void) { return telnet_termid; }

  void SendDo(int cmd);
  void SendWill(int cmd);
  void SendDont(int cmd);
  void SendWont(int cmd);
};

#endif
