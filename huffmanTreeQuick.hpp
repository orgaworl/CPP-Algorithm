#pragma once
#include<iostream>
#include<stack>
#include <algorithm>
#include<vector>
#include <queue>
//#include"minHeap.hpp"
using namespace std;


template<typename T>
class huffmanTreeNode
{
private:
	huffmanTreeNode<T>* father;
	int weight;
	T* date;



public:
	huffmanTreeNode<T>* leftChild;
	huffmanTreeNode<T>* rightChild;


	huffmanTreeNode();
	huffmanTreeNode(int weight, T& date = NULL);
	~huffmanTreeNode();



	T& getDate();                                          //返回当前树节点数据部分的 引用
	void setCurDate(T& date);                                //引用 传入数据做当前节点数据
	bool isLeaf();
	bool isDegreeOne();





};



template<typename T>
class huffmanTree
{
private:
	huffmanTreeNode<T>* root;
	bool removeTree(huffmanTreeNode<T>* root);
	bool mergeTree(huffmanTreeNode<T>* hf1, huffmanTreeNode<T>* hf2, huffmanTreeNode<T>*& parent);
public:


	bool isEmpty();
	huffmanTreeNode<T>* getRoot();
	void deleteBinaryTree(huffmanTreeNode<T>* root);//将传入节点的所有子节点遍历delete
	int buildHuffmanTree();



};





template<typename T>
T& huffmanTreeNode<T>::getDate()
{
	return *this->date;
}



//***

template<typename T>
bool huffmanTree<T>::removeTree(huffmanTreeNode<T>* root)
{//清理该树
}
template<typename T>
bool huffmanTree<T>::mergeTree(huffmanTreeNode<T>* hf1, huffmanTreeNode<T>* hf2, huffmanTreeNode<T>*& parent)
{
	if (hf1 != NULL && hf2 != NULL)
	{
		T temp = hf1->getDate() + hf2->getDate();
		parent = new huffmanTreeNode<T>(temp);
		parent->leftChild = hf1;
		parent->rightChild = hf2;
		return 1;
	}
	return 0;

}




//template<typename T>
//huffmanTree<T>::huffmanTree(T* list, int listLength)
//{
//	
//	huffmanTreeNode<T>* parent = NULL;
//	huffmanTreeNode<T>* firstChild = NULL;
//	huffmanTreeNode<T>*secondChild = NULL;//指针
//
//	huffmanTreeNode<T>* treeRootList = new huffmanTreeNode<T>[listLength];//树(根节点)集合,开始全为叶节点
//	minHeap<huffmanTreeNode<T>>heap(listLength);//以权值为date的节点的最小堆
//
//
//	for (int i=0;i<=listLength-1;i++)
//	{//构建节点集合,构建节点组成的堆
//		treeRootList[i].setCurDate(list[i]);//将权值赋值给节点date
//		heap.insert(treeRootList[i]);//将huffman树节点插入堆
//	}
//	for (int i=0;i<=heap.getCurSize()-1;i++)
//	{
//		//cout<<heap.
//	}
//
//
//
//	while (heap.getCurSize()!=1)
//	{
//		//删去并取得堆两最小节点
//		heap.removeMin(firstChild);
//		heap.removeMin(secondChild);
//		//融合成一棵树
//		mergeTree(firstChild, secondChild, parent);
//	 
//		//融合树的根重新插入堆
//		heap.insert(*parent);
//
//	}
//	heap.removeMin(this->root);
//
//	
//
//
//
//
//
//
//
//}



template<typename T>
bool huffmanTree<T>::isEmpty()
{
	return this->root == NULL;
}

template<typename T>
huffmanTreeNode<T>* huffmanTree<T>::getRoot()
{
	return this->root;
}

template<typename T>
void huffmanTreeNode<T>::setCurDate(T& date)
{
	this->date = date;
}
template<typename T>
bool huffmanTreeNode<T>::isLeaf()
{
	return (this->leftChild == NULL && this->rightChild == NULL);
}

template<typename T>
bool operator>(huffmanTreeNode<T>& hfn1, huffmanTreeNode<T>& hfn2)
{
	if (hfn1.getDate() > hfn2.getDate())
	{
		return 1;
	}
	return 0;

}
template<typename T>
bool operator<(huffmanTreeNode<T>& hfn1, huffmanTreeNode<T>& hfn2)
{
	if (hfn1.getDate() < hfn2.getDate())
	{
		return 1;
	}
	return 0;

}

template<typename T>
bool more(huffmanTreeNode<T>* x, huffmanTreeNode<T>* y)
{
	return x->weight > y->weight ? 1 : 0;
}

template<typename T>
int buildHuffmanTree() {


	


	return 1;
}