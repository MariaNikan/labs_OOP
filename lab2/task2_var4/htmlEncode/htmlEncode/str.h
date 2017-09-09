#pragma once

std::string ReplaceSymbol(std::string& line, char symbol, std::string text);
std::string HtmlEncode(std::string const& text);
void PrintOutString(std::ostream& stream, std::string& text);
