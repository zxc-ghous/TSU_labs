#include <iostream>
#include <vector>
#include "binary_tree.h"
#include "search_treeh.h"
using namespace std;

void testTree(BinaryTree& tree, const int treesize)
{
	BinaryTree& tree1 = tree;
	BinaryTree& tree2 = tree;
	BinaryTree& tree3 = tree;
	//заполняем дерево tree1 0,1,2,3.... и удаляем элементы в прямом порядке
	for (int i = 0; i < treesize; i++)
	{
		tree1.addNode(i, tree1.GetRoot());
	}
	vector<int> tree1_nodes = tree1.getTreeKeysVector(tree1.GetRoot());
	for (int i = 0; i < tree1_nodes.size(); i++)
	{
		tree1.deleteNode(tree1_nodes[i]);
	}
	cout << "tree1 is empty: " << tree1.isEmpty() << endl;
	//заполняем дерево tree2 0,1,2,3.... и удаляем элементы в обратном порядке
	for (int i = 0; i < treesize; i++)
	{
		tree2.addNode(i, tree2.GetRoot());
	}
	vector<int> tree2_nodes = tree2.getTreeKeysVector(tree2.GetRoot());
	for (int i = tree2_nodes.size()-1; i >= 0; i--)
	{
		tree2.deleteNode(tree2_nodes[i]);
	}
	cout << "tree2 is empty: " << tree2.isEmpty() << endl;
	//заполняем дерево tree3 случайными числами и удаляем элементы в прямом порядке
	for (int i = 0; i < treesize; i++)
	{
		tree3.addNode(rand()%50, tree3.GetRoot());
	}
	vector<int> tree3_nodes = tree3.getTreeKeysVector(tree3.GetRoot());
	for (int i = 0; i < tree3_nodes.size(); i++)
	{
		tree3.deleteNode(tree3_nodes[i]);
	}
	cout << "tree3 is empty: " << tree3.isEmpty() << endl;
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
	testTree(400);
	//int treesize = 250;
	//SearchTree tree3;
	//for (int i = 0; i < treesize; i++)
	//{
	//	tree3.addNode(rand() % 50, tree3.GetRoot());
	//}
	//tree3.PrintTree(tree3.GetRoot(), 5);
	//vector<int> tree3_nodes = tree3.getTreeKeysVector(tree3.GetRoot());
	//for (int i = 0; i < tree3_nodes.size(); i++)
	//{
	//	cout<<tree3.deleteNode(tree3_nodes[i])<<endl;
	//}
	//cout << "tree3 is empty: " << tree3.isEmpty() << endl;
	//SearchTree bt1;
	//SearchTree bt2;
	//for (int i = 0; i < 8; i++)
	//{
	//	bt1.addNode(rand() % 10, bt1.GetRoot());
	//}
	//bt1.PrintTree(bt1.GetRoot(), 5);
	//cout << "---------------copy bt1 to bt2--------------" << endl;
	//bt2 = bt1;
	//bt2.PrintTree(bt1.GetRoot(), 5);

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
