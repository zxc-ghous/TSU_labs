// haffman_code.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "huffman.h"
using namespace std;

int main()
{
	Huffman huffman;
	string text = "aaaaaaaaaaaaaaabbbbbbbvvvvvvggggggddddd";
	cout << "original string:\n" << text<<endl;
	string coded_string="";
	cout<<"huffman coef: " << huffman.encode(text, coded_string) << endl;
	cout<<"coded string:\n" << coded_string << endl;
	string decoded_string = "";
	cout << "decode is: " << huffman.decode(coded_string, decoded_string) << endl;
	cout << "decoded string:\n" << decoded_string << endl;

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
