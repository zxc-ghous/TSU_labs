#include "huffman.h"


Huffman::~Huffman()
{
	if (root)
	{
		deleteTree(root);
	}
}

void Huffman::deleteTree(Node* p)
{
	if (p == nullptr)
	{
		return;
	}

	if (p->left)
	{
		deleteTree(p->left);
	}

	if (p->right)
	{
		deleteTree(p->right);
	}

	if (p == root)
	{
		root = nullptr;
	}
	delete p;
}

void Huffman::printTree(int k, Node* p)
{
	if (p == NULL)
		return;
	printTree(k + 15, p->right);
	for (int i = 0; i < k; i++)
		cout << " ";
	cout << p->data << "'" << p->freq << "'" << endl;
	printTree(k + 15, p->left);
}


void Huffman::encode(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
	if (root == nullptr)
		return;

	// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->data] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}


float Huffman::encode(string originalText, string& coded)
{
	assert(!originalText.empty() && "string is empty");
	buildHuffmanTree(originalText);
	float originalBitSum = 0;
	float codedBitSum = 0;
	coded = "";
	for (int i = 0; i < originalText.size(); i++)
	{
		for (auto it = huffmanCode.begin(); it != huffmanCode.end(); ++it)
		{
			if (originalText[i] == it->first)
			{
				coded += it->second;
				codedBitSum += it->second.size();
			}
		}
		originalBitSum += 8;
	}
	return codedBitSum / originalBitSum;
}


bool Huffman::decode(string codedText, string& decodeText)
{
	assert(!codedText.empty() && "string is empty");
	decodeText = "";
	int main_counter = 0;
	for (int i = main_counter; i < codedText.size();)
	{
		Node* temp = root;
		while (true)
		{
			if (codedText[i] == '0')
			{
				if (temp->left != nullptr)
				{
					temp = temp->left;
				}
				else
				{
					decodeText += temp->data;
					break;
				}
			}
			else
			{
				if (temp->right != nullptr)
				{
					temp = temp->right;
				}
				else
				{
					decodeText += temp->data;
					break;
				}
			}
			i++;
			main_counter = i;
		}
	}
	return true;
}




void Huffman::buildHuffmanTree(string text)
{
	for (char ch : text) 
	{
		freq[ch]++;
	}
	priority_queue<Node*, vector<Node*>, comparator> pq;
	for (auto pair : freq) 
	{
		Node* temp = new Node(pair.first, pair.second, nullptr, nullptr);
		pq.push(temp);
	}
	while (pq.size() != 1)
	{
		Node* left = pq.top(); 
		pq.pop();

		Node* right = pq.top();	
		pq.pop();

		int sum = left->freq + right->freq;
		Node* top = new Node('\0', sum, left, right);
		top->left = left;
		top->right = right;
		pq.push(top);
	}
	root = pq.top();
	if (!root->left && !root->right)
	{
		encode(root, "0", huffmanCode);
	}
	else
	{
		encode(root, "", huffmanCode);
	}
}