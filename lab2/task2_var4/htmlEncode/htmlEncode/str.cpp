#include "str.h"

using namespace std;

void PrintOutString(ostream& stream, string& text)
{ 
	stream << text;
}

void ReplaceSubstring(string & line, char symbol, string text)
{
	for (size_t pos = 0; pos < line.size(); ++pos)
	{
		if (line[pos] == symbol)
		{
			line.replace(pos, 1, text);
		}
	}
}

string HtmlEncode(string const& text)
{
	string changedString = text;
	ReplaceSubstring(changedString, '&', "&amp;");
	ReplaceSubstring(changedString, '"', "&quot;");
	ReplaceSubstring(changedString, '\'', "&apos;");
	ReplaceSubstring(changedString, '<', "&lt;");
	ReplaceSubstring(changedString, '>', "&gt;");
	return changedString;
}