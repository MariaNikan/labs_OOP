#include <iostream>
#include <bitset>
#include <string>

using namespace std;

string Dec2bin(int number)
{
	string bin_number = "";
	for (int i = 7; i >= 0; i--)
	{
		if (number % 2 == 1)
		{
			bin_number = '1' + bin_number;
		}
		else
		{
			bin_number = '0' + bin_number;
		}
		number = number / 2;
	}
	return bin_number;
}

int Bin2dec(string bin_number)
{
	int number = 0;
	int k = 7;
	for (int i = 0; i < 8; i++)
	{
		if (bin_number[i] == '1')
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
	string bin_number = Dec2bin(number);
	string flip_bin_number  = FlipNumber(bin_number);
	number = Bin2dec(flip_bin_number);
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
		cout << "Enter correct number/n";
		return 1;
	}
	return 0;
}