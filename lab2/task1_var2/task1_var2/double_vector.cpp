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
	
	for (int i = 0; i < numbers.size(); i++)
	{
		stream << setprecision(3) << fixed << numbers[i] << " ";
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
	//for_each(numbers.begin(), numbers.end(), [number](double &element) { element *= number;});
	transform(numbers.begin(), numbers.end(), numbers.begin(), [number](double& elem) {return elem *= number; });
}