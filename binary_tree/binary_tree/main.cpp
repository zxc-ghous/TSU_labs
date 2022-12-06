#include <iostream>
#include <vector>
#include "binary_tree.h"
#include "search_treeh.h"
using namespace std;

void testTree(BinaryTree& tree, const int treesize)
{
	//заполняем дерево 0,1,2,3.... и удаляем элементы в прямом порядке
	//for (int i = 0; i < treesize; i++)
	//{
	//	tree.addNode(i, tree.GetRoot());
	//}
	//vector<int> nodes = tree.getTreeKeysVector(tree.GetRoot());
	//for (int i = 0; i < nodes.size(); i++)
	//{
	//	tree.deleteNode(nodes[i]);
	//}
	//cout << "tree is empty: " << tree.isEmpty() << endl;
	////заполняем дерево 0,1,2,3.... и удаляем элементы в обратном порядке
	//for (int i = 0; i < treesize; i++)
	//{
	//	tree.addNode(i, tree.GetRoot());
	//}
	//for (int i = nodes.size()-1; i >= 0; i--)
	//{
	//	tree.deleteNode(nodes[i]);
	//}
	//cout << "tree is empty: " << tree.isEmpty() << endl;
	//заполняем дерево случайными числами и удаляем элементы в прямом порядке
	for (int i = 0; i < treesize; i++)
	{
		tree.addNode(rand()%50, tree.GetRoot());
	}
	vector<int> nodes = tree.getTreeKeysVector(tree.GetRoot());
	for (int i = 0; i < nodes.size(); i++)
	{
		tree.deleteNode(nodes[i]);
	}
	cout << "tree is empty: " << tree.isEmpty() << endl;
}

void testTree(const int treesize)
{
	BinaryTree bt;
	SearchTree st;
	cout << "binary tree test: " << endl;
	testTree(bt, treesize);
	cout << "--------------------------------" << endl;
	cout << "--------------------------------" << endl;
	cout << "search tree test: " << endl;
	testTree(st, treesize);
}

int main()
{
	//testTree(10);
	SearchTree bt1;
	SearchTree bt2;
	for (int i = 0; i < 8; i++)
	{
		bt1.addNode(rand() % 10, bt1.GetRoot());
	}
	bt1.PrintTree(bt1.GetRoot(), 5);
	cout << "---------------copy bt1 to bt2--------------" << endl;
	bt2 = bt1;
	bt2.PrintTree(bt1.GetRoot(), 5);

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
