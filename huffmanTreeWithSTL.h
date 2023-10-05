#pragma once
#include<iostream>



class huffmanTreeNode
{
public:

	int weight;
	huffmanTreeNode* leftChild;
	huffmanTreeNode* rightChild;
	huffmanTreeNode() { this->leftChild = this->rightChild = NULL; this->weight = 0; };
	bool operator< (huffmanTreeNode other) { return this->weight < other.weight; };
	bool operator> (huffmanTreeNode other) { return this->weight > other.weight; };

};


bool operator> (huffmanTreeNode one, huffmanTreeNode other);

int huffmanTreeFunc(int* list, int listLength);