#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <random>
#include <time.h>
using namespace std;

bool createFileWithRandomNumbers(const std::string& fileName, const int numbersCount, const int maxNumberValue)
{
	ofstream file(fileName);
	if (!file.is_open())
	{
		cout << "cant open file" << endl;
		return false;
	}

	/*uncomment to use a non-deterministic seed*/
   //random_device rd;
	mt19937_64 generator(0);
	uniform_int_distribution<int> distribution(-maxNumberValue, maxNumberValue);
	for (int i = 0; i < numbersCount; i++)
		file << distribution(generator) << " ";

	file.close();
	return true;
}


bool isFileContainsSortedArray(const std::string& fileName)
{
	ifstream file(fileName);

	int number1, number2;
	file >> number1;

	for (file >> number2; !file.eof(); file >> number2)
	{
		if (number2 < number1) return false;
		number1 = number2;
	}
	return true;
}


bool isempty(string fileName)
{
	ifstream file(fileName);
	if (file.peek() == EOF) return true;
	else return false;
}