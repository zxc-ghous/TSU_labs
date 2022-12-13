#include "HashTable.h"




HashTable::HashTable(int _size) 
{
	if (size <= 0)
		size = 1;

	size = _size;
	actual_size = 0;
	values.resize(size);
	keys.resize(size);
	is_filled.resize(size);
}

 bool HashTable::addValue(int K, int value)
{
	 if (actual_size + 1 > size)
	 {
		 return false;
	 }
	 if (checkKey(K))
	 {
		 return false;
	 }
	 actual_size++;
	 int index = 0;
	 while (true)
	 {
		 int hash = getHash(K, index);
		 if (!is_filled[hash])
		 {
			 keys[hash] = K;
			 values[hash] = value;
			 is_filled[hash] = 1;
			 return true;
		 }
		 else if (keys[hash] != K) { index++; }
	 }
}

void HashTable::print()
{
	for (int i = 0; i < size; i++)
	{
		if (is_filled[i] == 1)
		{
			cout << keys[i] << "	:	" << values[i]<<endl;
		}
	}
	cout << endl;
}

bool HashTable::checkKey(int K)
{
	int index = 0;
	int hash;
	while (true)
	{
		hash = getHash(K, index);
		if (is_filled[hash] == 0)
		{
			return false;
		}
		else if (keys[hash] == K)
		{
			return true;
		}
		else { index++; }
	}
	return false;
}

bool HashTable::deleteValue(int K)
{
	if (checkKey(K))
	{
		actual_size--;
		int index = 0;
		while (true)
		{
			int hash = getHash(K, index);
			if (is_filled[hash] == 0)
			{
				return false;
			}
			else if (keys[hash] == K)
			{
				is_filled[hash] = 0;
				return true;
			}
			else if (keys[hash] != K)
			{
				index++;
			}
		}
	}
	return false;
}