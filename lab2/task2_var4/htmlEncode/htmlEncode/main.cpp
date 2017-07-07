#include "stdafx.h"
#include "str.h"

using namespace std;

int main()
{
	string line = "";
	while (getline(cin, line))
	{
		string changedLine = HtmlEncode(line);
		PrintOutString(cout, changedLine);
	}
}