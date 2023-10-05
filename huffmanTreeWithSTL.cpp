#include<iostream>
#include <stdlib.h>       
#include<queue>
#include"huffmanTreeWithSTL.h"
using namespace std;



bool operator> (huffmanTreeNode one, huffmanTreeNode other) { return one.weight > other.weight; };


int huffmanTreeFunc(int* list, int listLength)
{


	priority_queue<huffmanTreeNode, vector<huffmanTreeNode>, greater<huffmanTreeNode> > minHeap;

	huffmanTreeNode* nodeList = new huffmanTreeNode[listLength];
	for (int i = 0; i < listLength; i++)
	{
		nodeList[i].weight = list[i];
		minHeap.push(nodeList[i]);
	}



	while (minHeap.size() != 1)
	{
		huffmanTreeNode* leftPoi = new huffmanTreeNode(minHeap.top());
		minHeap.pop();
		huffmanTreeNode* rightPoi = new huffmanTreeNode(minHeap.top());
		minHeap.pop();


		huffmanTreeNode* parentPoi = new huffmanTreeNode();
		parentPoi->leftChild = leftPoi;
		parentPoi->rightChild = rightPoi;
		parentPoi->weight = leftPoi->weight + rightPoi->weight;

		minHeap.push(*parentPoi);//传入复制的值
	}


	huffmanTreeNode* root = new huffmanTreeNode(minHeap.top());


	cout << "最小总路径权重为: " << root->weight<<endl;
	cout << endl;



	return 1;


}

