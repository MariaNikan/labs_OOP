#include "double_vector.h"

using namespace std;

void ReadNumbers(istream& stream, vector<double>& numbers)
{
	double number = 0;
	while (stream >> number)
	{
		numbers.push_back(number);
	}
	if (!stream.eof())
	{
		numbers.clear();
	}
}

void PrintOutResult(ostream& stream, vector<double>& numbers)
{
	for_each(numbers.begin(), numbers.end(), [](double &element) { element = floor(element * 1000.0 + 0.5) / 1000.0;});
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(stream, " "));
}

void SortNumbers(vector<double>& numbers)
{
	sort(numbers.begin(), numbers.end());
}

vector<double>::const_iterator FindMinNumberIterator(const vector<double>& numbers)
{
	return min_element(numbers.begin(), numbers.end());
}

void MultiplyNumbersByNumber(vector<double>& numbers, double number)
{
	for_each(numbers.begin(), numbers.end(), [number](double &element) { element *= number;});
}