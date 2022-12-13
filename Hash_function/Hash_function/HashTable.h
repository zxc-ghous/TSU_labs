#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <list>
#include <vector>
#include <unordered_map>
using namespace std;


//вариант 1-3
//- открытая адресация
//hi(K) = (K mod N) + i × (1+ K mod (N – 2)) mod N.
//Во всех случаях N – размер таблицы(параметр конструктора), K – ключ, h0(K) = K mod N.
//При реализации архитектуры внешних / внутренних цепочек для вычисления хеша используется h1(K).
class HashTable
{
public:
	HashTable() { size = 1; actual_size=0; values.resize(size); keys.resize(size); is_filled.resize(size);}
	HashTable(int size);
	~HashTable() {};

	bool addValue(int K, int value);
	bool deleteValue(int K);
	bool checkKey(int K);
	void print();
	int size;
	int actual_size;
	vector<int> keys;
	vector<int> values;
	vector<int> is_filled; // 0 - не занятно, 1 - занято

	int getHash(int K, int i) 
	{
		return (K % size) + i * (1 + (K % (size - 2))) % size;
	}
};