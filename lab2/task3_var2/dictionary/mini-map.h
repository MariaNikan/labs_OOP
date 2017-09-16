#pragma once
#include "stdafx.h"

void ReadDictionary(std::string dictionaryFile, std::map<std::string, std::string> & EngRusDictionary);
void CommunicateWithUser(std::string dictionary);
void ReadDictionaryFromFile(std::istream& input, std::map<std::string, std::string> & Dictionary)
