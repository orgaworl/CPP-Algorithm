#pragma once
#include<iostream>
#include<stack>
#include <algorithm>
#include<vector>
#include <queue>
#include"minHeap.hpp"
//#include"minHeap.hpp"
using namespace std;


template<typename T>
class huffmanTreeNode
{
private:
	huffmanTreeNode<T>*father;
	int weight;
	T *date;
	


public:
	huffmanTreeNode<T>*leftChild;
	huffmanTreeNode<T>*rightChild;


	huffmanTreeNode();
	huffmanTreeNode(int weight,T &date=NULL);
	~huffmanTreeNode();
	


	T& getDate();                                          //���ص�ǰ���ڵ����ݲ��ֵ� ����
	void setCurDate(T* date);                                //���� ������������ǰ�ڵ�����
	bool isLeaf();
	bool isDegreeOne();
	

	


};



template<typename T>
class huffmanTree
{
private:
	huffmanTreeNode<T>* root;
	bool removeTree(huffmanTreeNode<T>*root);
	bool mergeTree(huffmanTreeNode<T>*hf1, huffmanTreeNode<T>*hf2, huffmanTreeNode<T>*&parent);
public:
	

	huffmanTree();
	huffmanTree(T*list,int listLength);
	~huffmanTree();
	bool isEmpty();

	huffmanTreeNode<T>* getRoot();

	void deleteBinaryTree(huffmanTreeNode<T>* root);//������ڵ�������ӽڵ����delete

	int buildHuffmanTree();



};



template<typename T>
huffmanTreeNode<T>::huffmanTreeNode()
{
	this->father = NULL;
	this->leftChild = NULL;
	this->rightChild = NULL;
	this->weight = 0;
	this->date = NULL;
	
}


template<typename T>
huffmanTreeNode<T>::huffmanTreeNode(int weight,T &date)
{

	this->father = NULL;
	this->leftChild = NULL;
	this->rightChild = NULL;
	this->weight = weight;
	if (&date!=NULL)
	{
		this->date = new T(date);
	}
	else
	{
		this->date = NULL;
	}

}

template<typename T>
huffmanTreeNode<T>::~huffmanTreeNode()
{
	delete this->leftChild;
	delete this->rightChild;

}


template<typename T>
T& huffmanTreeNode<T>::getDate()
{
	return *this->date;
}



//***

template<typename T>
bool huffmanTree<T>::removeTree(huffmanTreeNode<T>*root)
{//�������
}
template<typename T>
bool huffmanTree<T>::mergeTree(huffmanTreeNode<T>* hf1, huffmanTreeNode<T>* hf2, huffmanTreeNode<T>*& parent)
{
	if (hf1!=NULL&&hf2!=NULL)
	{
		T temp = hf1->getDate() + hf2->getDate();
		parent = new huffmanTreeNode<T>(temp);
		parent->leftChild = hf1;
		parent->rightChild = hf2;
		return 1;
	}
	return 0;
	
}


template<typename T>
huffmanTree<T>::huffmanTree()
{

	this->buildHuffmanTree();

}


template<typename T>
huffmanTree<T>::huffmanTree(T* list, int listLength)
{
	
	huffmanTreeNode<T>* parent = NULL;
	huffmanTreeNode<T>* firstChild = NULL;
	huffmanTreeNode<T>*secondChild = NULL;//ָ��

	huffmanTreeNode<T>* treeRootList = new huffmanTreeNode<T>[listLength];//��(���ڵ�)����,��ʼȫΪҶ�ڵ�
	minHeap<huffmanTreeNode<T>>heap(listLength);//��ȨֵΪdate�Ľڵ����С��


	for (int i=0;i<=listLength-1;i++)
	{//�����ڵ㼯��,�����ڵ���ɵĶ�
		treeRootList[i].setCurDate(list[i]);//��Ȩֵ��ֵ���ڵ�date
		heap.insert(treeRootList[i]);//��huffman���ڵ�����
	}




	while (heap.getCurSize()!=1)
	{
		//ɾȥ��ȡ�ö�����С�ڵ�
		heap.removeMin(firstChild);
		heap.removeMin(secondChild);
		//�ںϳ�һ����
		mergeTree(firstChild, secondChild, parent);
	 
		//�ں����ĸ����²����
		heap.insert(*parent);

	}
	heap.removeMin(this->root);

	







}

template<typename T>
huffmanTree<T>::~huffmanTree()
{

}

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
void huffmanTreeNode<T>::setCurDate(T *date)
{
	this->date = new T(*date);
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

//template<typename T>
//int buildHuffmanTree() {
//
//
//	int size = 0;
//	cin >> size;
//
//	int tempWeight = 0;
//	T tempDate;
//	//std::priority_queue<huffmanTreeNode<T>* , vector<huffmanTreeNode<T>*> ,std::more<T> > minHeap;
//
//	priority_queue<int> maxHeap;
//
//	priority_queue<int, vector<int>,greater<int> > small_queue;
//
//	for (int i = 0; i < size; i++)
//	{
//		cin >> tempWeight;
//		cin >> tempDate;
//		huffmanTreeNode<T>*tempNode=new huffmanTreeNode(tempWeight, tempDate);
//		
//		
//	}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//	return 1;
//}
//
