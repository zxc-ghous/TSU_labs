// binary_tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "binary_tree.h"
#include <vector>
int main()
{
    BinaryTree bt;
	int treeSize = 8;
	for (int i = 19; i > treeSize; i--) 
	{ 
		bt.Add(i,bt.GetRoot());
	}
	cout << "full tree" << endl;
	bt.PrintTree(bt.GetRoot());
	cout << "full tree" << endl;
	bt.PrintTree(bt.GetRoot(), 5);
	cout <<"tree height: " << bt.getHeight(bt.GetRoot()) << endl;
	cout <<"number of nodes: " << bt.getNodeCount(bt.GetRoot()) << endl;
	vector<int> keys_vector = bt.getTreeKeysVector(bt.GetRoot());
	for (int i = 0; i < keys_vector.size(); i++)
	{
		cout << keys_vector[i] << " ";
	}
	cout << "\n pointer: " << bt.FindKey(5, bt.GetRoot()) << endl;
	cout << "number of nodes from 3: "<<bt.getNodeCount(bt.FindKey(3, bt.GetRoot())) << endl;
	cout << "\n";
	vector<Node*> nodes = bt.get_all_nodes(bt.GetRoot());
	for (int i = 0; i < nodes.size(); i++)
	{
		cout << nodes[i]->GetKey() << " ";
	}
	cout<<"\n"<<"check parent: " << bt.find_parent(bt.FindKey(12, bt.GetRoot()), nodes)->GetKey() << endl;
	//cout<<"delete leaf: " << bt.deleteNode(9)<<endl;
	//cout << "delete node with two childs: " << bt.deleteNode(14) << endl;
	cout << "delete node with one child: " << bt.deleteNode(17) << endl;
	puts("");
	bt.PrintTree(bt.GetRoot(), 5);

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
