/*
TerminalWx - A wxWidgets terminal widget
Copyright (C) 2004  Mark Erikson
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

#ifndef TEXTMANAGER__H
#define TEXTMANAGER__H

#include <vector>
#include <deque>
#include <string>

using namespace std;

class GTerm;

class TextManager
{
public:
	TextManager(GTerm* parent = NULL, int width = 80, int height = 24, int maxWidth = 160, int maxHeight = 100);

	int GetSize();
	int GetMaxSize();
	int GetHeight();
	int GetNumLinesScrolled();
	int GetLinesReceived();
	string& GetLine(int index);
	string& GetLineAdjusted(int index);
	char GetCharAdjusted(int y, int x);
	unsigned short GetColor(int y, int x);
	unsigned short GetColorAdjusted(int y, int x);


	void CursorDown();
	void CursorUp();

	void SetMaxSize(int newSize);
	void SetCharAdjusted(int y, int x, char c);
	void SetCursorLine(int line);
	void SetLine(int index, string line);
	void SetLineAdjusted(int index, string line);
	void SetColor(int y, int x, unsigned short value);
	void SetColorAdjusted(int y, int x, unsigned short value);

	void SetHeight(const int newHeight);

	void PrintViewport();
	void PrintContents();
	void PrintToBitmap();

	void AddNewLine();
	void AddNewLine(string newline);
	void Scroll(int numLines, bool scrollUp);
	void Resize(int width, int height);
	void Reset();

	string& operator[](int index);

private:

	int AdjustIndex(int index);

	int m_topLine;
	int m_bottomLine;
	int m_numLinesScrolledUp;
	int m_viewportHeight;
	int m_viewportWidth;
	int m_linesReceived;
	int m_maxHeight;
	int m_maxWidth;
	int m_cursorLine;
	int m_blankColor;
	string m_blankline;

	deque< vector<unsigned short> > m_color;
	deque<string> m_text;

	GTerm* m_parent;
};








#endif
