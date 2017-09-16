#include "mini-map.h"

using namespace std;

void ReadDictionary(istream& dictionaryFile, map<string, string> & EngRusDictionary)
{
	string line = "";
	while (dictionaryFile >> line)
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
		EngRusDictionary.insert(pair<string, string>(engWord, rusWord));
	}
}

void SaveChanges(ostream& dictionaryFile, map <string, string> Dictionary)
{
	for (auto i = Dictionary.begin(); i != Dictionary.end(); ++i)
	{
		dictionaryFile << i->first << " : " << i->second << endl;
	}
}

void CommunicateWithUser(string dictionaryFile)
{
	map<string, string> EngRusDictionary;
	ifstream dictionary(dictionaryFile);
	if (!dictionary.is_open())
	{
		cout << "Failed to open " << dictionaryFile << " for reading\n";
		return;
	}
	ReadDictionary(dictionary, EngRusDictionary);
	dictionary.close();
	string line = "";
	map <string, string> TempEngRusDictionary = EngRusDictionary;
	while (getline(cin, line))
	{
		if (line != "...") 
		{
			if (EngRusDictionary.find(line) != EngRusDictionary.end())
			{
				cout << EngRusDictionary.find(line)->second << endl;
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
				cin >> line;
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
					ofstream dictionary(dictionaryFile);
					SaveChanges(dictionary, TempEngRusDictionary);
					cout << "The changes are saved. Goodbye." << endl;
				}
			}
			else
			{
				cout << "Goodbye!" << endl;
				return;
			}
		}
	}
}