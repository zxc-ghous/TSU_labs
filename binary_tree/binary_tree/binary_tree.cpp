#include "binary_tree.h"
#include<iostream>
#include <vector>
#include <queue>
using namespace std;


void BinaryTree::deleteTree(Node* p)
{

	if (p == nullptr) { return; }
	deleteTree(p->left);
	deleteTree(p->right);
	if (p == root)
	{
		root = nullptr;
	}
	delete p;
}


BinaryTree::~BinaryTree()
{
	if (root)
		deleteTree(root);
}


void BinaryTree::Add(int k, Node* p) //���������� ���� � ������ k � ������ � ������ p
{
	if (p == nullptr)
	{
		root = new Node(k);
		return;
	}

	if (p->left == nullptr)
	{
		Node* q = new Node(k);
		p->left = q;
		return;
	}

	if (p->right == nullptr)
	{
		Node* q = new Node(k);
		p->right = q;
		return;
	}
	if (rand() % 2)
	{
		Add(k, p->left);
	}
	else Add(k, p->right);
}

//������-����-�����
int BinaryTree::getHeight(Node* p)
{
	if (p == nullptr) return 0;
	if ((p->left == nullptr) && (p->right == nullptr)) return 1;
	int heightL = 0, heightR = 0;
	if (p->left != nullptr) heightL = getHeight(p->left);
	if (p->right != nullptr) heightR = getHeight(p->right);
	int height;
	if (heightL > heightR)
		height = heightL;
	else height = heightR;
	return height + 1;
}


//������-����-�����
int BinaryTree::getNodeCount(Node* p)
{
	if (p == nullptr) return 0;
	if ((p->left == nullptr) && (p->right == nullptr)) return 1;
	int CountL = 0, CountR = 0;
	if (p->left != nullptr) CountL = getNodeCount(p->left);
	if (p->right != nullptr) CountR = getNodeCount(p->right);
	return CountL + CountR + 1;
}


// � ������
std::vector<int> BinaryTree::getTreeKeysVector(Node* p)
{
	if (p == nullptr) return vector<int>();
	queue <Node*> q;
	vector<int> keys;
	q.push(p);
	while (q.size() != 0)
	{
		Node* z = q.front(); //���������� ������ �� ������ ������� � �������
		q.pop();
		keys.push_back(z->key);
		if (z->left) q.push(z->left);
		if (z->right) q.push(z->right);
	}
	return keys;

}



//Node is a terminal node : In this case, if the node is a left child of its parent, then the left pointer of its parent is set to NULL.
//Otherwise if the node is a right child of its parent, then the right pointer of its parent is set to NULL
//Node has only one child : In this case, the appropriate pointer of its parent is set to child node.
//Node has two children : Predecessor replaces the node value, and then the predecessor of the node is deleted.


bool BinaryTree::deleteNode(int item)
{
	vector<Node*> nodes = get_all_nodes(root);
	Node* p = FindKey(item, GetRoot());
	Node* parent = find_parent(p, nodes);
	if (p == root)
	{
		deleteTree(p);
		return true;
	}
	//�������� �����
	if ((p->left == nullptr) && (p->right == nullptr))
	{
		// ���� ��������� ���� �� �������� �������� �����, �� ������������� ���
		// ������������ �����/������ �������� ������� � nullptr
		if (p != root)
		{
			if (parent->left == p)
			{
				parent->left = nullptr;
			}
			else
			{
				parent->right = nullptr;
			}
		}
		delete(p);
		return true;
	}
	// ��������� ���� ����� ���� ��������
	// ����� � ������ ��������� ����������� ������� � ����������� ��� �� ����� ���������� ����.
	else if (p->left && p->right)
	{
		//������� ����������� ���� ��������
		Node* successor = getMinimumKey(p->right);
		// ��������� ����������� ��������
		int val = successor->key;
		// ���������� ������� ���������.
		deleteNode(successor->key);
		// �������� �������� ��������� � ������� ����
		p->key = val;
		return true;
	}
	// ��������� ���� ����� ������ ������ �������
	else
	{
		Node* child = (p->left) ? p->left : p->right;
		// ���� ��������� ���� �� �������� �������� �����, ������������� ��� ��������
		// ������ �������
		if (p == parent->left)
		{
			parent->left = child;
		}
		else
		{
			parent->right = child;
		}
		delete(p);
		return true;
	}

}


void BinaryTree::printLevel(int level)
{
	vector<Node*> currentLevelNodes;
	currentLevelNodes.push_back(root);
	for (int i = 0; i < level; i++)
	{
		vector<Node*> nextLevelNodes;
		for (Node* Node : currentLevelNodes)
		{
			if (Node)
			{
				nextLevelNodes.push_back(Node->left);
				nextLevelNodes.push_back(Node->right);
			}
			else
			{
				nextLevelNodes.push_back(nullptr);
				nextLevelNodes.push_back(nullptr);
			}
		}
		currentLevelNodes.swap(nextLevelNodes);
	}

	for (int i = 0; i < currentLevelNodes.size(); i++)
	{
		if (currentLevelNodes[i]) { cout << currentLevelNodes[i]->key << " "; }
		else { cout << "None" << " "; }
	}
	puts("");

}


void BinaryTree::PrintTree(Node* p)
{
	if (p == nullptr) { return; }
	int height = getHeight(root);
	for (int i = 0; i < height; i++)
	{
		printLevel(i);
	}
	puts("");

}


Node* BinaryTree::FindKey(int k, Node* p)
{
	if (p == nullptr) return nullptr;
	if (p->key == k) return p;
	Node* FindLeft = FindKey(k, p->left);
	Node* FindRight = FindKey(k, p->right);
	if (FindLeft != nullptr)
		return FindLeft;
	if (FindRight != nullptr)
		return FindRight;
}

vector<Node*> BinaryTree::get_all_nodes(Node* p)
{
	if (p == nullptr) return vector<Node*>();
	queue <Node*> q;
	vector<Node*> nodes;
	q.push(p);
	while (q.size() != 0)
	{
		Node* z = q.front(); //���������� ������ �� ������ ������� � �������
		q.pop();
		nodes.push_back(z);
		if (z->left) q.push(z->left);
		if (z->right) q.push(z->right);
	}
	return nodes;
}

Node* BinaryTree::find_parent(Node* child, vector<Node*> nodes)
{
	if (child == root) { return root; }
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i]->left == child) { return nodes[i]; }
		if (nodes[i]->right == child) { return nodes[i]; }
	}
}
Node* BinaryTree::getMinimumKey(Node* p)
{
	while (p->left != nullptr)
	{
		p = p->left;
	}
	return p;
}
void BinaryTree::PrintTree(Node* p, int k)
{
	if (p == nullptr) return;
	PrintTree(p->right, k + 5);
	for (int i = 0; i < k; i++) cout << ' ';
	cout << p->key << endl;
	PrintTree(p->left, k + 5);
}