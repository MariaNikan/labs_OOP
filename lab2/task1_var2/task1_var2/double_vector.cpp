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
	if (numbers.size() == 0)
	{
		stream << "Vector is empty";
	}
	else
	{
		copy(numbers.begin(), numbers.end(), ostream_iterator<double>(stream << setprecision(3) << fixed, " "));
	}
}

void SortNumbers(vector<double>& numbers)
{
	sort(numbers.begin(), numbers.end());
}

double FindMinNumber(const vector<double>& numbers)
{
	return *min_element(numbers.begin(), numbers.end());
}

void MultiplyNumbersByNumber(vector<double>& numbers, double number)
{
	transform(numbers.begin(), numbers.end(), numbers.begin(), [number](double elem) {return elem * number; });
}

void ProcessVector(vector<double>& numbers)
{
	if (numbers.size() != 0)
	{
		double minNumber = FindMinNumber(numbers);
		MultiplyNumbersByNumber(numbers, minNumber);
	}
}