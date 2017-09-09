#include "stdafx.h"
#include "str.h"

using namespace std;

string ReplaceSymbol(string& line, char symbol, string text)
{
	string newString = "";
	for (size_t pos = 0; pos < line.size(); ++pos)
	{
		if (line[pos] == symbol)
		{
			newString.append(text);
		}
		else
		{
			newString.push_back(line[pos]);
		}
	}
	return newString;
}

string HtmlEncode(string const& text)
{
	string changedString = text;
	changedString = ReplaceSymbol(changedString, '&', "&amp;");
	changedString = ReplaceSymbol(changedString, '"', "&quot;");
	changedString = ReplaceSymbol(changedString, '\'', "&apos;");
	changedString = ReplaceSymbol(changedString, '<', "&lt;");;
	changedString = ReplaceSymbol(changedString, '>', "&gt;");
	return changedString;
}