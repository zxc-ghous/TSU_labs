#pragma once
#include<iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
	int key = 0;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int k = 0, Node* L = nullptr, Node* R = nullptr)
	{
		key = k;
		left = L;
		right = R;
	}

	int GetKey()
    {
        if (this==nullptr)
        {
            return -1;
        }
        return key;

	}
	friend class BinaryTree;
};

class BinaryTree
{
public:
	Node* root;

	BinaryTree()
	{
		root = nullptr;
	}
	virtual ~BinaryTree();


	Node* GetRoot() //получение корня дерева;
	{
		return root;
	}
	bool isEmpty() //  isEmpty (возвращает true, если дерево пусто);
	{
		if (root == nullptr) { return true; }
		else return false;

	}
	void deleteTree(Node* p);   //очистка дерева (удаление всех узлов);
	virtual void addNode(int k, Node* p); 	//добавление узла в дерево
	void PrintTree(Node* p); // вывод в консоль дерева по уровням (через последовательные вызовы предыдущего метода);
	int getHeight(Node* p); // получение высоты дерева;
	int getNodeCount(Node* p); //получение количества узлов дерева;
	virtual bool deleteNode(int item); //удаление узла из дерева по ключу (возвращает true, если узел был удалён);
	vector<int> getTreeKeysVector(Node* p);  //получение вектора (std::vector<int>), содержащего все ключи дерева (обход вершин производить любым способом;
	void printLevel(int level); // вывод в консоль уровня дерева
    virtual Node* FindKey(int k, Node* p);
	vector<Node*> get_all_nodes(Node* p);
	Node* find_parent(Node* child, vector<Node*> nodes);
	Node* getMinimumKey(Node* p); 
	void PrintTree(Node* p, int k); //вывод дерева на консоль, k - отступ от левой границы консоли
	void copy(Node* subTreeRoot, Node*& copyRoot); //копирование
	BinaryTree& operator = (BinaryTree& CopyTree); //перегрузка
};


