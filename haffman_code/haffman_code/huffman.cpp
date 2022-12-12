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

float Huffman::encode(string originalText)
{
	float originalBitSum = 0;
	float codedBitSum = 0;
	for (char letter : originalText)
	{
		originalBitSum += 3;
	}
	unordered_map<char, string>::iterator hf = huffmanCode.begin();
	unordered_map<char, int>::iterator fr = freq.begin();
	while (hf != huffmanCode.end())
	{
		codedBitSum += hf->second.size() * fr->second;
		++hf; ++fr;
	}
	return codedBitSum / originalBitSum;
}

void Huffman::decode(Node* root, int& index, string str)
{
	if (root == nullptr)
	{
		return;
	}

	// found a leaf node
	if (!root->left && !root->right)
	{
		cout << root->data;
		return;
	}

	index++;

	if (str[index] == '0')
	{
		decode(root->left, index, str);
	}
	else
	{
		decode(root->right, index, str);
	}
}

bool Huffman::decode(string codedText, string originalText)
{
	string decode = "";
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
					decode += temp->data;
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
					decode += temp->data;
					break;
				}
			}
			i++;
			main_counter = i;
		}
	}
	if (decode == originalText) { return true; }
	else { return false; }
}

string Huffman::buildHuffmanTree(string text, bool print)
{
	// count frequency of appearance of each character
	// and store it in a map
	for (char ch : text) 
	{
		freq[ch]++;
	}
	// Create a priority queue to store live nodes of Huffman tree;
	priority_queue<Node*, vector<Node*>, comparator> pq;
	// Create a leaf node for each character and add it to the priority queue.
	for (auto pair : freq) 
	{
		Node* temp = new Node(pair.first, pair.second, nullptr, nullptr);
		pq.push(temp);
	}
	// do till there is more than one node in the queue
	while (pq.size() != 1)
	{
		// Remove the two nodes of highest priority
		// (lowest frequency) from the queue
		Node* left = pq.top(); pq.pop();
		Node* right = pq.top();	pq.pop();

		// Create a new internal node with these two nodes
		// as children and with frequency equal to the sum
		// of the two nodes' frequencies. Add the new node to the priority queue.
		int sum = left->freq + right->freq;
		Node* temp = new Node('\0', sum, left, right);
		pq.push(temp);
	}
	// root stores pointer to root of Huffman Tree
	root = pq.top();

	// traverse the Huffman Tree and store Huffman Codes
	// in a map. Also prints them
	if (!root->left && !root->right)
	{
		encode(root, "0", huffmanCode);
	}
	else
	{
		encode(root, "", huffmanCode);
	}

	string str = "";
	for (char ch : text) 
	{
		str += huffmanCode[ch];
	}
	if (print)
	{
		cout << "huffman codes are :\n" << '\n';
		for (auto pair : huffmanCode) {
			cout << pair.first << " " << pair.second << '\n';
		}

		cout << "\noriginal string was :\n" << text << '\n';
		cout << "\nencoded string is :\n" << str << '\n';
		// traverse the huffman tree again and this time
		// decode the encoded string
		int index = -1;
		cout << "\ndecoded string is: \n";
		while (index < (int)str.size() - 1) {
			decode(root, index, str);
		}
		cout << "\n\n";
	}
	return str;
}