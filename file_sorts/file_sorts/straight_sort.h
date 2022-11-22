#pragma once
#include <iostream>
#include "createfile.h"
using namespace std;


void split(string fileName, string fileB, string fileC, int p)
{
	int x;
	ifstream A(fileName);
	ofstream B(fileB);
	ofstream C(fileC);
	A >> x;
	while (!A.eof())
	{
		for (int i = 0; !(A.eof()) && i < p; i++)
		{
			B << x << " ";
			A >> x;
		}

		for (int i = 0; !(A.eof()) && i < p; i++)
		{
			C << x << " ";
			A >> x;
		}
	}
	A.close(); B.close(); C.close();
}




void merge(string fileName, string fileB, string fileC, int p)
{
	int x, y;

	ofstream A(fileName);
	ifstream B(fileB);
	ifstream C(fileC);
	B >> x; C >> y;
	while (!(B.eof()) && !(C.eof()))
	{
		int i = 0, j = 0;
		while (!(B.eof()) && !(C.eof()) && i < p && j < p)
		{
			if (x < y)
			{
				A << x << " ";
				B >> x;
				i++;
			}
			else
			{
				A << y << " ";
				C >> y;
				j++;
			}
		}
		while (!(B.eof()) && i < p)
		{
			A << x << " ";
			B >> x;
			i++;
		}
		while (!(C.eof()) && j < p)
		{
			A << y << " ";
			C >> y;
			j++;
		}
	}

	while (!(B.eof()))
	{
		A << x << " ";
		B >> x;
	}

	while (!(C.eof()))
	{
		A << y << " ";
		C >> y;
	}

	A.close(); B.close(); C.close();
}



// прямое слияние на трех файлах
int straight_sort(string originFile, const int numberscount, const int maxnumbervalue)
{
	string fileB = "fileB.txt";
	string fileC = "fileC.txt";
	int p = 1;
	if (!(createFileWithRandomNumbers(originFile, numberscount, maxnumbervalue))) return -1;
	split(originFile, fileB, fileC, p);
	while (!isempty(fileC))
	{
		merge(originFile, fileB, fileC, p);
		p *= 2;
		split(originFile, fileB, fileC, p);
	}

	if (isFileContainsSortedArray(originFile)) return 1; 
	else return 0;

}