// haffman_code.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "huffman.h"
using namespace std;

int main()
{
	Huffman huffman;
	string text = "aaaaaaaaaaaaaaabbbbbbbvvvvvvggggggddddd";
	//string coded = huffman.buildHuffmanTree(text,true);
	cout<<"decode is: "<<huffman.decode(coded,text);
	//unordered_map<char, string> temp;
	//huffman.encode(huffman.getRoot(), text, temp);
	//for (auto pair : temp)
	//{
	//	cout << pair.second;
	//}
	//cout <<"huffman coef: " <<huffman.encode(text)<<endl;
	//huffman.decode(text);
	//unordered_map<char, int>::iterator fr = huffman.freq.begin();
	//while (fr != huffman.freq.end())    // пока не дойдем до конца
	//{
	//	std::cout << fr->second << std::endl;// получаем элементы через итератор
	//	++fr;             // перемещаемся вперед на один элемент
	//}
	//cout << "\n\n";
	//huffman.printTree(5, huffman.getRoot());
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
