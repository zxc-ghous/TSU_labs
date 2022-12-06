#pragma once
#include "binary_tree.h"


class SearchTree : public BinaryTree
{
public:
	SearchTree() : BinaryTree() {}; //конструкторы (по умолчанию)
	~SearchTree() = default;  //деструктор
	void addNode(int k, Node* p); //добавление узла в дерево
	Node* getMin(Node* p);  //получение минимального
	Node* getMax(Node* p);  //максимального ключа 
	Node* deleteStNode(Node* p, int k); //удаление узла из дерева по ключу рекурсивная реализация
};



void SearchTree::addNode(int k, Node* p)
{
	if (p == nullptr)
	{
		root = new Node(k);
		return;
	}
	if (k < p->GetKey())
	{
		if (p->left==nullptr)
		{
			Node* q = new Node(k);
			p->left = q;
			return;
		}
		else
		{
			addNode(k, p->left);
		}

	}
	else
	{
		if (p->right==nullptr)
		{
			Node* q = new Node(k);
			p->right = q;
			return;
		}
		else
		{
			addNode(k, p->right);
		}
	}
}

Node* SearchTree::getMin(Node* p)
{
	if (p == nullptr)
	{
		return nullptr;
	}
	while (p->left)
	{
		p = p->left;
	}
	return p;
}

Node* SearchTree::getMax(Node* p)
{
	if (p == nullptr)
	{
		return nullptr;
	}
	while (p->right)
	{
		p = p->right;
	}
	return p;
}


Node* SearchTree::deleteStNode(Node* p, int k)
{
	if (p == nullptr)
	{
		return nullptr;
	}
	if (k < p->GetKey())
	{
		p->left = deleteStNode(p->left, k);
	}
	else if (k > p->GetKey())
	{
		p->right = deleteStNode(p->right, k);
	}
	else if ((p->left) && (p->right))
	{
		p->key = getMin(p->right)->key;
		p->right = deleteStNode(p->right, p->key);
	}
	else if (p == GetRoot() && p->left == nullptr && p->right == nullptr)
	{
		deleteTree(root);
		return nullptr;
	}
	else
	{
		if (p->left)
		{
			Node* tmp = p->left;
			delete(p);
			return tmp;
		}
		else if (p->right)
		{
			Node* tmp = p->right;
			delete(p);
			return tmp;
		}
		else
		{
			delete(p);
			return nullptr;
		}
	}
	return p;
}



