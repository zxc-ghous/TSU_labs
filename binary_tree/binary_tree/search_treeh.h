#pragma once
#include "binary_tree.h"


class SearchTree : public BinaryTree
{
public:
	SearchTree() : BinaryTree() {}; //конструкторы (по умолчанию)
	~SearchTree() override = default;  //деструктор
	void addNode(int k, Node* p) override; //добавление узла в дерево
	Node* getMin(Node* p);  //получение минимального
	Node* getMax(Node* p);  //максимального ключа 
	Node* deleteStNode(Node* p, int k); //удаление узла из дерева по ключу рекурсивная реализация
	bool deleteNode(int item) override; //удаление узла из дерева по ключу (возвращает true, если узел был удалён);
};

bool SearchTree::deleteNode(int item)
{
	vector<Node*> nodes = get_all_nodes(root);
	Node* p = FindKey(item, GetRoot());
	Node* parent = find_parent(p, nodes);
	if (!p) { return false; }
	if (p == root)
	{
		if (p->right)
		{
			root = p->right;
			if (p->left)
			{
				Node* temp = p->right;
				while (temp->left)
				{
					temp = temp->left;
				}
				temp->left = p->left;
			}
			delete(p);
			return true;
		}
		if (p->left)
		{
			root = p->left;
			delete(p);
			return true;
		}
		delete(root);
		root = nullptr;
		return true;
	}
	if (p->left == nullptr && p->right == nullptr)
	{
		if (parent && parent->left == p)
		{
			parent->left = nullptr;
		}
		if (parent && parent->right == p)
		{
			parent->right = nullptr;
		}
		if (!parent)
		{
			root = nullptr;
		}
		delete(p);
		return true;
	}
	if (p->left == nullptr && p->right != nullptr)
	{
		if (parent && parent->left == p)
		{
			parent->left = p->right;
		}
		if (parent && parent->right == p)
		{
			parent->right = p->right;
		}
		if (!parent)
		{
			root = p->right;
		}
		delete(p);
		return true;
	}
	if (p->left != nullptr && p->right == nullptr)
	{
		if (parent && parent->left == p)
		{
			parent->left = p->left;
		}
		if (parent && parent->right == p)
		{
			parent->right = p->left;
		}
		if (!parent)
		{
			root = p->left;
		}
		delete(p);
		return true;
	}
	if (p->left && p->right)
	{
		Node* for_insert = getMin(p->right);
		Node* parent_insert = find_parent(for_insert, nodes);
		if (parent_insert)
		{
			parent_insert->left = for_insert->right;
			for_insert->left = p->left;
			for_insert->right = p->right;
		}
		else
		{
			for_insert->left = p->left;
		}
		if (parent && parent->left == p) { parent->left = for_insert; }
		if (parent && parent->right == p) { parent->right = for_insert; }
		if (!parent) { root = for_insert; }
		delete(p);
		return true;
	}
	return false;
}

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
	else if ((k=p->GetKey()) && (p->left) && (p->right))
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



