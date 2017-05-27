#include "stdafx.h"
#include "double_vector.h"

using namespace std;

int main()
{
	vector<double> numbers;
	ReadNumbers(cin, numbers);
	SortNumbers(numbers);
	double minNumber = *FindMinNumberIterator(numbers);
	MultiplyNumbersByNumber(numbers, minNumber);
	PrintOutResult(cout, numbers);
	return 0;
}