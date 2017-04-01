#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

typedef double arr[3][3];

void ReadMatrix(string const& file, arr matrix)
{
	ifstream input(file);
	if (!input.is_open())
	{
		cout << "Failed to open for reading\n";
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			input >> matrix[i][j];
		}
	}
}

void Print(arr matrix)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout <<  matrix[i][j] << fixed << setprecision(3);
			cout << " ";
		}
		cout << endl;
	}
}

void Multi(arr const& matrix1, arr const& matrix2, arr matrix3)
{
	/*
	1. �������� �������, ������������� 2 �������, �������� � ���� 2������ �������� � ������������ ��������� � � ��� 2������ �������.
	2.��� ����� ������������ � ����� ������.
	3.������ float double.
	4. ������ ��� matrix.
	5.�� ��������� printf and cout.
	6. � ������� ��������� ������ ������ ������� �������
	*/
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			double num = 0;
			for (int k = 0; k < 3; k++)
			{
				double n = (matrix1[i][k]) * (matrix2[k][j]);
				num = num + n;
			}
			matrix3[i][j] = num;
		}
	}
}

int main(int arg_c, char* arg_v[])
{
	if (arg_c != 3)
	{
		cout << "Enter arguments: multimatrix.exe <matrix file1> <matrix file2>\n";
		return 1;
	}
	string file1 = arg_v[1];
	string file2 = arg_v[2];
	arr matrix1;
	arr matrix2;
	arr matrix3;
	ReadMatrix(file1, matrix1);
	ReadMatrix(file2, matrix2);
	Multi(matrix1, matrix2, matrix3);
	Print(matrix3);
	return 0;
}