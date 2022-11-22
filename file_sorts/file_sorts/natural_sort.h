#pragma once
#include <iostream>
#include "createfile.h"
using namespace std;



void split(string fileName, string fileB, string fileC)
{
	int x1=0, x2=0;
	ifstream A(fileName);
	ofstream B(fileB);
	ofstream C(fileC);
	A >> x1;
	while (!A.eof())
	{
		if (!A.eof())
		{
			B << x1 << " ";
			A >> x2;
			while (!(A.eof()) && x1 <= x2)
			{
				x1 = x2;
				B << x1 << " ";
				A >> x2;
			}
		}
		x1 = x2;
		if (!A.eof())
		{
			C << x1 << " ";
			A >> x2;
			while (!(A.eof()) && x1 <= x2)
			{
				x1 = x2;
				C << x1 << " ";
				A >> x2;
			}
		}
		x1 = x2;
	}
	A.close(); B.close(); C.close();
}


void merge(string fileName, string fileB, string fileC)
{
	int x1, x2, y1, y2;
	ifstream B(fileB);
	ifstream C(fileC);
	ofstream A(fileName);
	B >> x1;
	C >> y1;
	while (!(B.eof()) && !(C.eof()))
	{
		if (x1 < y1)
		{
			A << x1 << " ";
			B >> x2;
			if (!(B.eof()) && x1 > x2)
			{
				A << y1 << " ";
				C >> y2;
				while (!(C.eof()) && y1 <= y2)
				{
					y1 = y2;
					A << y1 << " ";
					C >> y2;
				}
				y1 = y2;
			}
			x1 = x2;
		}
		else
		{
			A << y1 << " ";
			C >> y2;
			if (!(C.eof()) && y1 > y2)
			{
				A << x1 << " ";
				B >> x2;
				while (!(B.eof()) && x1 <= x2)
				{
					x1 = x2;
					A << x1 << " ";
					B >> x2;
				}
				x1 = x2;
			}
			y1 = y2;
		}
	}
	while (!(B.eof()))
	{
		A << x1 << " ";
		B >> x1;
	}
	while (!(C.eof()))
	{
		A << y1 << " ";
		C >> y1;
	}
	A.close(); B.close(); C.close();
}




// естественное слияние на трех файлах
int natural_sort(string originFile, const int numberscount, const int maxnumbervalue)
{
	string fileB = "fileB.txt";
	string fileC = "fileC.txt";
	if (!(createFileWithRandomNumbers(originFile, numberscount, maxnumbervalue))) return -1;
	while (true)
	{
		split(originFile, fileB, fileC);
		if (isempty(fileC)) break;
		merge(originFile, fileB, fileC);
	}
	if (isFileContainsSortedArray(originFile)) return 1;
	else return 0;
}