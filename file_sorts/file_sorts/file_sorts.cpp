// file_sorts.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include "straight_sort.h"
#include "natural_sort.h"
using namespace std;

int main()
{
    int straight_result=-100, natural_result=-100;

    straight_result = straight_sort("straight_sort.txt",1000, 100);
	cout << "straight file sort" << endl;
	switch (straight_result)
	{
	case 1:
		cout << "array sorted" << endl;
		break;
	case 0:
		cout << "array isnt sorted" << endl;
		break;
	case -1:
		cout << "file creation problems" << endl;
		break;
	}

	natural_result = natural_sort("natural_sort.txt", 1000, 100);
	cout << "natural file sort" << endl;
	switch (natural_result)
	{
	case 1:
		cout << "array sorted" << endl;
		break;
	case 0:
		cout << "array isnt sorted" << endl;
		break;
	case -1:
		cout << "file creation problems" << endl;
		break;
	}

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
