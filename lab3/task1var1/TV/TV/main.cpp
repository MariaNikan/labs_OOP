#include "stdafx.h"
#include "TVSet.h"
#include "control.h"

using namespace std;

int main()
{
	CTVSet tv;
	CControl control(tv, cin, cout);

	while (!cin.eof())
	{
		if (!control.HandleCommands())
		{
			cout << "You input unknown command. Enter again." << endl;
		}
	}
}
