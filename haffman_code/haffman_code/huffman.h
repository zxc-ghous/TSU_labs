#pragma once
#include<iostream>
#include <queue>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

class Node
{
public:
	char data;
	int freq;
	Node * left, * right;
	//Node() { data = '\0'; freq = 0; left = nullptr; right = nullptr; };
	Node(char _data, int _freq, Node* l, Node* r)
	{
		left = l;
		right = r;
		data = _data;
		freq = _freq;
	}
	friend class Huffman;
};


class Huffman
{
public:
	Node* root;
	unordered_map<char, string> huffmanCode;
	unordered_map<char, int> freq;
	Huffman() { root = nullptr; }
	~Huffman();
	void deleteTree(Node* p);
	void printTree(int k, Node* p);
	Node* getRoot() { return root; }
	// traverse the Huffman Tree and store Huffman Codes in a map.
	void encode(Node* root, string str, unordered_map<char, string>& huffmanCode);
	float encode(string originalText);
	// traverse the Huffman Tree and decode the encoded string
	void decode(Node* root, int& index, string str);
	bool decode(string codedText, string originalText);

	// Builds Huffman Tree and decode given input text
	string buildHuffmanTree(string text, bool print = false);
	struct comparator
	{
		bool operator()(Node* left, Node* right)
		{
			return (left->freq > right->freq);
		}
	};
};