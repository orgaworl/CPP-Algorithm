#pragma once
#include<iostream>
//#include"huffmanTree.hpp"
using namespace std;
//#include"huffmanTree.hpp"
//  cur/2-1Ϊ���һ����Ҷ�ڵ�
//  cur/2Ϊ��һ��Ҷ�ڵ�
//to do build�г�����ͬ��ֵ

//template<typename classT>
//bool operator>(classT class1,classT class2)
//{
//	return class1.getDate() > class2.getDate();
//}


template<typename T>
class minHeap
{

	
private:
	T* heap;
	int curSize;
	int maxSize;
	bool swap(int i, int j);
	
public:
	bool buildHeap();
	bool buildHeap(int last = this->curSize);
	minHeap(const int maxSize);
	~minHeap();
	
	int parent(int pos);
	int leftChild(int pos);
	int rightChild(int pos);
	int getCurSize();
	T getMin();
	T* getHeap();
	bool isEmpty();
	bool isLeaf(int pos);
	

	bool shiftUp(int pos);
	bool shiftDown(int pos);
	bool shiftDown(int pos, int last);
	bool addNode(T node);
	bool replaceMin(T node);

	bool insert(const T nodeToInsert);
	bool remove(int pos);
	bool remove(int pos, T& date);
	T removeMin();
	bool removeMin(T* poi);
	bool setNode(int pos, T node);

	bool showAll();
};
template<typename T>
minHeap<T>::minHeap(const int maxSize)
{
	if (maxSize<=0)
	{
		this->heap = NULL;
		this->maxSize = 0;
		this->curSize = 0;
	}
	else
	{
		this->heap = new T[maxSize];
		this->maxSize = maxSize;
		this->curSize = 0;

		
	}
	



}

template<typename T>
minHeap<T>::~minHeap()
{
	delete[] this->heap;
}

template<typename T>
int minHeap<T>::parent(int pos)
{
	return (pos - 1) / 2 ;
}

template<typename T>
int minHeap<T>::leftChild(int pos)
{
	return pos * 2 + 1;
}

template<typename T>
int minHeap<T>::rightChild(int pos)
{
	return pos * 2 + 2;
}

template<typename T>
int minHeap<T>::getCurSize()
{
	return this->curSize;
}

template<typename T>
bool minHeap<T>::isEmpty()
{
	return this->curSize == 0;
}

template<typename T>
bool minHeap<T>::isLeaf(int pos) 
{
	return pos<curSize&&pos>=curSize/2;
}

template<typename T>
bool minHeap<T>::buildHeap()
{
	for (int i = curSize/ 2 - 1; i >= 0; i--)
	{
		shiftDown(i);

	}
	return 1;


}


template<typename T>
bool minHeap<T>::buildHeap(int last)
{
	for (int i= last/2-1;i>=0;i--)
	{
		shiftDown(i,last);

	}
	return 1;


}

template<typename T>
bool minHeap<T>::swap(int i,int j)
{
	if (i<0||j<0||i>=curSize||j>=curSize)
	{//�ٶ���ʱcurSize<=maxSize
		return 0;
	}

	T temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
	return 1;
}


template<typename T>
bool minHeap<T>::shiftUp(int pos)
{
	if (pos <= 0 || pos >= curSize)
	{//�������ڵ����
		return 0;
	}


	T temp = heap[pos];//�����λ����ֵ
	int curPos = pos;
	while (curPos > 0&&  (heap[parent(curPos)] > temp)   )
	{
		heap[curPos] = heap[parent(curPos)];//�±��ϸ���
		curPos = parent(curPos);

	}
	heap[curPos] = temp;
	return 1;
}


template<typename T>
bool minHeap<T>::shiftDown(int pos)
{//��pos����������Ϊ��ʱ,��pos shiftDown���ʹ��������ɶ�

	if (pos < 0 || pos >= curSize) {//���ڵ�������ų�
		return 0;
	}
	else if (pos >= curSize / 2) {//Ҷ�ڵ�������в���
		return 1;
	}




	T temp = heap[pos];//�����λ����ֵ
	int curPos = pos;
	int toCompare = curPos * 2 + 1;//��ڵ� //����һ��cur��������һ��toCompare
	while (toCompare < curSize)
	{

		if (toCompare + 1 < curSize && heap[toCompare] > heap[toCompare + 1])
		{//���ӽڵ���������ӽڵ��С,���ȽϽڵ������л�����
			toCompare++;
		}


		if (temp > heap[toCompare])
		{//���滻
			heap[curPos] = heap[toCompare];//�ϱ��¸���
			curPos = toCompare;
			toCompare = curPos * 2 + 1;
		}
		else if (temp < heap[toCompare])
		{//������
			break;
		}

	}

	heap[curPos] = temp;
	return 1;
}


template<typename T>
bool minHeap<T>::shiftDown(int pos,int curSize)
{//��pos����������Ϊ��ʱ,��pos shiftDown���ʹ��������ɶ�

	if (pos <  0 || pos >= curSize){//���ڵ�������ų�
		return 0;
	}
	else if(pos>=curSize/2){//Ҷ�ڵ�������в���
		return 1;
	}




	T temp = heap[pos];//�����λ����ֵ
	int curPos = pos;
	int toCompare = curPos * 2 + 1;//��ڵ� //����һ��cur��������һ��toCompare
	while (toCompare<curSize)
	{

		if (toCompare + 1 < curSize&&heap[toCompare]>heap[toCompare+1])
		{//���ӽڵ���������ӽڵ��С,���ȽϽڵ������л�����
			toCompare++;
		}


		if (temp>heap[toCompare])
		{//���滻
			heap[curPos] = heap[toCompare];//�ϱ��¸���
			curPos = toCompare;
			toCompare = curPos * 2 + 1;
		}
		else if(temp < heap[toCompare])
		{//������
			break;
		}
		
	}

	heap[curPos] = temp;
	return 1;

}


template<typename T>
bool minHeap<T>::insert(const T nodeToInsert)
{
	if (curSize==maxSize)
	{
		return 0;
	}

	//���������
	heap[curSize] = nodeToInsert;
	curSize++;
	
	//����ȥ���ʺ�λ��
	this->shiftUp(curSize-1);

	return 1;





}

template<typename T>
bool minHeap<T>::remove(int pos)
{
	if (curSize <= 0 || pos<0 || pos >= curSize || curSize>maxSize)
	{
		return 0;
	}
	heap[pos] = heap[curSize - 1];
	curSize--;
	this->shiftDown(pos);
	return 1;




}

template<typename T>
bool minHeap<T>::remove(int pos,T &date)
{
	if (curSize <= 0||pos<0||pos>=curSize||curSize>maxSize)
	{
		return 0;
	}
	date = heap[pos];//������ɾ��λ����ֵ
	heap[pos] = heap[curSize - 1];
	curSize--;
	this->shiftDown(pos);
	return 1;




}

template<typename T>
bool minHeap<T>::showAll()
{
	for (int i=0;i<=curSize-1;i++)
	{
		cout << heap[i] << ' ';
	}
	cout << endl;
	return 1;
}

template<typename T>
T minHeap<T>::removeMin()
{
	if (curSize<=0)
	{
		return 0;
	}
	T *min =new T (heap[0]);//�˴���ǳ����
	heap[0] = heap[curSize - 1];
	curSize--;
	this->shiftDown(0);
	return *min;
	
}
template<typename T>
bool minHeap<T>::removeMin(T* poi)
{
	if (curSize <= 0)
	{
		return 0;
	}

	poi = new T(heap[0]);//�˴���ǳ����
	heap[0] = heap[curSize - 1];
	curSize--;
	this->shiftDown(0);
	return 1;
}



//void test_minHeap()
//{
//
//	minHeap<int>minH(7);
//	minH.showAll();
//
//
//	minH.insert(-1);
//	minH.showAll();
//
//
//	int a = 0;
//	minH.remove(0, a);//����Ҫɾ���ڵ�λ��,������ֵ
//	minH.showAll();
//	cout << endl << a;
//
//
//
//	minH.showAll();
//
//
//}

template<typename T>
bool minHeap<T>::addNode(T node)
{
	
	heap[curSize] = node;
	curSize++;
	//buildHeap();

	return 1;

}

template<typename T>
bool minHeap<T>::replaceMin(T node)
{
	if (curSize==0)
	{
		return 0;
	}

	heap[0] = node;
	return 1;
}


template<typename T>
T minHeap<T>::getMin()
{
	return heap[0];
}


template<typename T>
bool minHeap<T>::setNode(int pos, T node)
{

	if (pos<0||pos>=curSize)
	{
		return 0;
	}
	heap[pos] = node;
	return 1;

}


template<typename T>
T* minHeap<T>::getHeap()
{
	return this->heap;
}