#pragma once
#include "stdafx.h"

using namespace std;

void ReplaceSubstring(std::string& line, char symbol, std::string text);
string HtmlEncode(std::string const& text);
void PrintOutString(std::ostream& stream, std::string& text);
