#include "stdafx.h"
#include "double_vector.h"

using namespace std;

int main()
{
	vector<double> numbers;
	ReadNumbers(cin, numbers);
	ProcessVector(numbers);
	SortNumbers(numbers);
	PrintOutResult(cout, numbers);
}