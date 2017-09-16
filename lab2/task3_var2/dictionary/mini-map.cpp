#include "mini-map.h"

using namespace std;

void ReadDictionaryFromFile(istream& input, map<string, string> & Dictionary)
{
	string line = "";
	while (input >> line)
	{
		string engWord = "";
		string rusWord = "";
		size_t pos = line.find(":");
		for (size_t i = 0; i < pos; i++)
		{
			engWord = engWord + line[i];
		}
		for (size_t i = pos + 1; i < line.size(); i++)
		{
			rusWord = rusWord + line[i];
		}
		Dictionary.insert(pair<string, string>(engWord, rusWord));
	}
}

void ReadDictionary(string dictionaryFile, map<string, string> & EngRusDictionary)
{
	ifstream dictionary(dictionaryFile);
	if (!dictionary.is_open())
	{
		cout << "Failed to open " << dictionaryFile << " for reading\n";
		return;
	}
	ReadDictionaryFromFile(dictionary, EngRusDictionary);
}

void CommunicateWithUser(string dictionary)
{
	map<string, string> EngRusDictionary;
	ReadDictionary(dictionary, EngRusDictionary);
	string line = "";
	map <string, string> TempEngRusDictionary = EngRusDictionary;
	while (getline(cin, line))
	{
		if (line != "...")
		{
			auto translation = EngRusDictionary.find(line)->second;
			if (translation != EngRusDictionary.end()->second)
			{
				cout << translation << endl;
			}
			else
			{
				cout << "Unknown word. Enter your translation" << endl;
				string str = "";
				cin >> str;
				if (str.size() != 0)
				{
					TempEngRusDictionary.insert(pair<string, string>(line, str));
					cout << "Word " << line << "saved as " << str << endl;
				}
			}
		}
		else
		{
			if (TempEngRusDictionary != EngRusDictionary)
			{
				cout << "The dictionary changes were made. Enter y to save before exiting." << endl;
				string out = "";
				cin >> out;
				if ((out == "y") || (out == "Y"))
				{
					EngRusDictionary = TempEngRusDictionary;
					cout << "The changes are saved. Goodbye." << endl;
				}
			}
		}
	}
}