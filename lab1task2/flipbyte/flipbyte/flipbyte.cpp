#include <iostream>
#include <bitset>
#include <string>

using namespace std;

void Dec2bin(int number,string bin_number)
{
	for (int i = 0; i < 8; i++)
	{
		if (number % 2 == 1)
		{
			bin_number[i] = '1';
		}
		else
		{
			bin_number[i] = '0';
		}
		number = number / 2;
	}
}

void Bin2dec(string bin_number, int number)
{
	int k = 7;
	for (int i = 0; i < 8; i++)
	{
		if (bin_number[i] == '1')
		{
			number = +(2 ^ k);
		}
		k--;
	}
}

void Flip(int number)
{
	string twoBitNumber = "";
	Dec2bin(number, twoBitNumber);
	int j = 7;
	for (int i = 0; i < 4; i++)
	{
		char temp = twoBitNumber[i];
		twoBitNumber[i] = twoBitNumber[j];
		twoBitNumber[j] = temp;
		j--;
	}
	Bin2dec(twoBitNumber, number);
	cout << number << endl;
}

int main(int arg_c, char * arg_v[])
{
	if (arg_c != 2)
	{
		cout << "Enter arguments: flipbyte.exe <number>\n";
		return 1;
	}
	string inputNumber = arg_v[1];
	int number;
	int n = size(inputNumber);
	for (int i = 0; i <= n; i++)
	{
		int k = int(inputNumber[i]);
		number = number * 10 + k;
	}
	if ((number >= 0)&&(number <= 255))
	{
		Flip(number);
	}
	else
	{
		cout << "Enter correct number/n";
		return 1;
	}
	return 0;
}