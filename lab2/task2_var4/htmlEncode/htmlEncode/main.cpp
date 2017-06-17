#include "stdafx.h"
#include "string.h"

using namespace std;

int main()
{
	string line = "";
	for (size_t i = 0; getline(cin, line); ++i)
	{
		string changedLine = HtmlEncode(line);
		PrintOutString(cout, changedLine);
	}
}