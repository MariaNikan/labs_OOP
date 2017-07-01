#include "string.h"

using namespace std;

void PrintOutString(ostream& stream, string& text)
{ 
	stream << text;
}

void ReplaceSubstring(string& line, char symbol, string text)
{
	auto pos = line.find(symbol);
	if (pos != string::npos)
	{
		line.replace(pos, 1, text);
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