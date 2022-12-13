#pragma once
#include<iostream>
#include <queue>
#include <unordered_map>
#include <queue>
#include <map>
#include <cassert>  
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
	void encode(Node* root, string str, unordered_map<char, string>& huffmanCode);
	bool decode(string codedText, string& decodeText);
	float encode(string stringIn, string& stringOut);

	// Builds Huffman Tree and decode given input text
	void buildHuffmanTree(string text);
	struct comparator
	{
		bool operator()(Node* left, Node* right)
		{
			return (left->freq > right->freq);
		}
	};
};