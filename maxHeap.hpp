#include<iostream>
using namespace std;
template<typename T>
//  cur/2-1为最后一个非叶节点
//  cur/2为第一个叶节点
//to do build中出现相同数值
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
	{//假定此时curSize<=maxSize
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
	{//包含根节点情况
		return 0;
	}


	T temp = heap[pos];//保存该位置数值
	int curPos = pos;
	while (curPos > 0 && heap[parent(curPos)] < temp)
	{
		heap[curPos] = heap[parent(curPos)];//下被上覆盖
		curPos = parent(curPos);

	}
	heap[curPos] = temp;
	return 1;
}


template<typename T>
bool maxHeap<T>::shiftDown(int pos)
{//当pos左右子树都为堆时,令pos shiftDown则可使整个树变成堆

	if (pos < 0 || pos >= curSize)
	{//根节点情况不排除
		return 0;
	}
	else if (pos >= curSize / 2)
	{//叶节点无需进行操作
		return 1;
	}


	T temp = heap[pos];//保存该位置数值
	int curPos = pos;
	int toCompare = curPos * 2 + 1;//左节点 //重设一遍cur则须重设一次toCompare
	while (toCompare < curSize)
	{
		


		if (toCompare + 1 < curSize && heap[toCompare] < heap[toCompare + 1])
		{//右子节点存在且右子节点更小,待比较节点又左切换到右
			toCompare++;
		}
		if (temp < heap[toCompare])
		{//若替换
			heap[curPos] = heap[toCompare];//上被下覆盖
			curPos = toCompare;
			toCompare = curPos * 2 + 1;
		}
		else if (temp > heap[toCompare])
		{//若不变
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

	//插入树最后
	heap[curSize] = nodeToInsert;
	curSize++;

	//令其去到适合位置
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
	date = heap[pos];//传出被删除位置数值
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
	maxH.remove(0, a);//传入要删除节点位置,而非数值
	maxH.showAll();
	cout << endl << a;



	maxH.showAll();
}