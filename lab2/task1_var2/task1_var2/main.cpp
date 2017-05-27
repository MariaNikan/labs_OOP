#include "stdafx.h"
#include "double_vector.h"

using namespace std;

int main()
{
	vector<double> numbers;
	ReadNumbers(cin, numbers);
	vector<double> emptyVector;
	if (numbers != emptyVector)
	{
		SortNumbers(numbers);
		double minNumber = FindMinNumber(numbers);
		MultiplyNumbersByNumber(numbers, minNumber);
		PrintOutResult(cout, numbers);
		return 0;
	}
	else
	{
		cout << "Empty vector, enter numbers again" << endl;
		return 1;
	}	
}