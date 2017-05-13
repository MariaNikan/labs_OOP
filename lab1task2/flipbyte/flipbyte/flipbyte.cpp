#include <iostream>
#include <bitset>
#include <string>

using namespace std;

string Dec2bin(int number)
{
	string binNumber = "";
	for (int i = 7; i >= 0; i--)
	{
		if (number % 2 == 1)
		{
			binNumber = '1' + binNumber;
		}
		else
		{
			binNumber = '0' + binNumber;
		}
		number = number / 2;
	}
	return binNumber;
}

int Bin2dec(string binNumber)
{
	int number = 0;
	int k = 7;
	for (int i = 0; i < 8; i++)
	{
		if (binNumber[i] == '1')
		{
			int temp = 1;
			for (int j = 1; j <= k; j++)
			{
				temp = temp * 2;
			}
			number = number + temp;
		}
		k--;
	}
	return number;
}

string FlipNumber(string number)
{
	int j = 7;
	for (int i = 0; i < 4; i++)
	{
		char temp = number[i];
		number[i] = number[j];
		number[j] = temp;
		j--;
	}
	return number;
}

void Flip(int number)
{
	string binNumber = Dec2bin(number);
	string flipBinNumber  = FlipNumber(binNumber);	
	number = Bin2dec(flipBinNumber);
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
	int number = 0;
	int n = size(inputNumber);
	for (int i = 0; i < n; i++)
	{
		int k = int(inputNumber[i]) - 48;
		number = number * 10 + k;
	}
	if ((number >= 0)&&(number <= 255))
	{
		Flip(number);
	}
	else
	{
		cout << "Enter correct number" << endl;
		return 1;
	}
	return 0;
}