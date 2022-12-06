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
	~BinaryTree();


	Node* GetRoot() //��������� ����� ������;
	{
		return root;
	}
	bool isEmpty() //  isEmpty (���������� true, ���� ������ �����);
	{
		if (root == nullptr) { return true; }
		else return false;

	}
	void deleteTree(Node* p);   //������� ������ (�������� ���� �����);
	void Add(int k, Node* p); 	//���������� ���� � ������
	void PrintTree(Node* p); // ����� � ������� ������ �� ������� (����� ���������������� ������ ����������� ������);
	int getHeight(Node* p); // ��������� ������ ������;
	int getNodeCount(Node* p); //��������� ���������� ����� ������;
	bool deleteNode(int item); //�������� ���� �� ������ �� ����� (���������� true, ���� ���� ��� �����);
	vector<int> getTreeKeysVector(Node* p);  //��������� ������� (std::vector<int>), ����������� ��� ����� ������ (����� ������ ����������� ����� ��������;
	void printLevel(int level); // ����� � ������� ������ ������
	Node* FindKey(int k, Node* p);
	vector<Node*> get_all_nodes(Node* p);
	Node* find_parent(Node* child, vector<Node*> nodes);
	Node* getMinimumKey(Node* p); 
	void PrintTree(Node* p, int k); //����� ������ �� �������, k - ������ �� ����� ������� �������
};


