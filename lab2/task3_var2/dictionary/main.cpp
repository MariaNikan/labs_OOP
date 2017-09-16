#include "stdafx.h"
#include "mini-map.h"

using namespace std;

int main(int arg_c, char* arg_v[])
{
	string dictionary;
	if (arg_c != 2)
	{
		if (arg_c != 1)
		{
			cout << "Enter arguments: dictionary.exe <dictionary file>\n";
			return 1;
		}
		else
		{
			ofstream File;
			File.open("dictionary.txt");
			File.close();
			dictionary = "dictionary.txt";
		}
	}
	else
	{
		dictionary = arg_v[1];
	}
	CommunicateWithUser(dictionary);
}