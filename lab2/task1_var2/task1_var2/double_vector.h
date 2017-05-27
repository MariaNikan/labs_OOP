#pragma once
#include "stdafx.h"

void ReadNumbers(std::istream& stream, std::vector<double> & numbers);
void PrintOutResult(std::ostream& stream, std::vector<double>& numbers);
void SortNumbers(std::vector<double>& numbers);
std::vector<double>::const_iterator FindMinNumberIterator(const std::vector<double>& numbers);
void MultiplyNumbersByNumber(std::vector<double>& numbers, double number);