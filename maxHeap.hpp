#include<iostream>
using namespace std;
template<typename T>
//  cur/2-1Ϊ���һ����Ҷ�ڵ�
//  cur/2Ϊ��һ��Ҷ�ڵ�
//to do build�г�����ͬ��ֵ
class maxHeap
{
private:
	T* heap;
	int curSize;
	int maxSize;
	bool swap(int i, int j);
	bool buildHeap();
public:
	maxHeap(const int maxSize);
	~maxHeap();

	int parent(int pos);
	int leftChild(int pos);
	int rightChild(int pos);

	bool isEmpty();
	bool isLeaf(int pos);


	bool shiftUp(int pos);
	bool shiftDown(int pos);
	bool insert(const T nodeToInsert);
	bool remove(int pos);
	bool remove(int pos, T& date);
	bool removeMax();


	bool showAll();
};
template<typename T>
maxHeap<T>::maxHeap(const int maxSize)
{
	if (maxSize <= 0)
	{
		this->heap = NULL;
		this->maxSize = 0;
		this->curSize = 0;
	}
	else
	{
		this->heap = new T[maxSize]();
		this->maxSize = maxSize;
		this->curSize = 0;

		while (curSize != maxSize)
		{
			if (cin.peek() == '\n')
			{
				break;
			}
			cin >> heap[curSize];
			curSize++;


		}

		this->buildHeap();
	}




}

template<typename T>
maxHeap<T>::~maxHeap()
{
	delete[] this->heap;
}

template<typename T>
int maxHeap<T>::parent(int pos)
{
	return (pos % 2 == 1 && pos != 0) ? (pos - 1) / 2 : (pos - 2) / 2;
}

template<typename T>
int maxHeap<T>::leftChild(int pos)
{
	return pos * 2 + 1;
}

template<typename T>
int maxHeap<T>::rightChild(int pos)
{
	return pos * 2 + 2;
}

template<typename T>
bool maxHeap<T>::isEmpty()
{
	return this->curSize == 0;
}

template<typename T>
bool maxHeap<T>::isLeaf(int pos)
{
	return pos < curSize&& pos >= curSize / 2;
}

template<typename T>
bool maxHeap<T>::buildHeap()
{

	for (int i = curSize / 2 - 1; i >= 0; i--)
	{
		shiftDown(i);

	}
	return 1;


}

template<typename T>
bool maxHeap<T>::swap(int i, int j)
{
	if (i < 0 || j < 0 || i >= curSize || j >= curSize)
	{//�ٶ���ʱcurSize<=maxSize
		return 0;
	}

	T temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
	return 1;
}


template<typename T>
bool maxHeap<T>::shiftUp(int pos)
{
	if (pos <= 0 || pos >= curSize)
	{//�������ڵ����
		return 0;
	}


	T temp = heap[pos];//�����λ����ֵ
	int curPos = pos;
	while (curPos > 0 && heap[parent(curPos)] < temp)
	{
		heap[curPos] = heap[parent(curPos)];//�±��ϸ���
		curPos = parent(curPos);

	}
	heap[curPos] = temp;
	return 1;
}


template<typename T>
bool maxHeap<T>::shiftDown(int pos)
{//��pos����������Ϊ��ʱ,��pos shiftDown���ʹ��������ɶ�

	if (pos < 0 || pos >= curSize)
	{//���ڵ�������ų�
		return 0;
	}
	else if (pos >= curSize / 2)
	{//Ҷ�ڵ�������в���
		return 1;
	}


	T temp = heap[pos];//�����λ����ֵ
	int curPos = pos;
	int toCompare = curPos * 2 + 1;//��ڵ� //����һ��cur��������һ��toCompare
	while (toCompare < curSize)
	{
		


		if (toCompare + 1 < curSize && heap[toCompare] < heap[toCompare + 1])
		{//���ӽڵ���������ӽڵ��С,���ȽϽڵ������л�����
			toCompare++;
		}
		if (temp < heap[toCompare])
		{//���滻
			heap[curPos] = heap[toCompare];//�ϱ��¸���
			curPos = toCompare;
			toCompare = curPos * 2 + 1;
		}
		else if (temp > heap[toCompare])
		{//������
			break;
		}

	}

	heap[curPos] = temp;
	return 1;
}


template<typename T>
bool maxHeap<T>::insert(const T nodeToInsert)
{
	if (curSize == maxSize)
	{
		return 0;
	}

	//���������
	heap[curSize] = nodeToInsert;
	curSize++;

	//����ȥ���ʺ�λ��
	this->shiftUp(curSize - 1);

	return 1;





}

template<typename T>
bool maxHeap<T>::remove(int pos)
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
bool maxHeap<T>::remove(int pos, T& date)
{
	if (curSize <= 0 || pos<0 || pos >= curSize || curSize>maxSize)
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
bool maxHeap<T>::showAll()
{
	for (int i = 0; i <= curSize - 1; i++)
	{
		cout << heap[i] << ' ';
	}
	cout << endl;
	return 1;
}

template<typename T>
bool maxHeap<T>::removeMax()
{
	if (curSize <= 0)
	{
		return 0;
	}
	heap[0] = heap[curSize - 1];
	curSize--;
	this->shiftDown(0);
	return 1;

}



void test_maxHeap()
{
	maxHeap<int>maxH(7);
	maxH.showAll();


	maxH.insert(-1);
	maxH.showAll();


	int a = 0;
	maxH.remove(0, a);//����Ҫɾ���ڵ�λ��,������ֵ
	maxH.showAll();
	cout << endl << a;



	maxH.showAll();
}