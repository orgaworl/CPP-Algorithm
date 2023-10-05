#include<iostream>
using namespace std;
template<typename T>

class arrStack
{
public:
	//具体函数实现在arrStack.hpp文件中
	arrStack(int maxSize);
	~arrStack();
	void clear();
	bool isEmpty();
	bool isFull();
	bool push(T date);
	void pop();
	T getTop();
	int getCurSize();
	void show();

private:
	T* list;
	int maxSize;
	int curSize;
	//curP=curSize-1;
	
};

template<typename T>
arrStack<T>::arrStack(int maxSize)
{
	this->list = new T[maxSize];
	this->curSize = 0;
	this->maxSize = maxSize;
	//仅供测试
	
}

template<typename T>
arrStack<T>::~arrStack()
{
	delete this->list;
	this->list = NULL;
	this->curSize = 0;
	this->maxSize = 0;
}


template<typename T>
void  arrStack<T>::clear()
{
	//栈本身不变,其中元素改变
	this->curSize = 0;
	
}

template<typename T>
bool arrStack<T>::isEmpty()
{
	if (this->curSize ==0)
	{
		return 1;
	}
	else if(this->curSize >0&&this->curSize <=this->maxSize)
	{
		return 0;
	}
	else
	{
		throw runtime_error("error in func isEmpty");
	}
}

template<typename T>
bool arrStack<T>::isFull()
{
	if (this-> curSize ==this->maxSize)
	{
		return 1;
	}
	else if (this->curSize >=0&& this->curSize <this->maxSize)
	{
		return 0;
	}
	else
	{
		throw runtime_error("error in func isFull");
	}
}

template<typename T>
bool arrStack<T>::push(T date)
{
	if (!this->isFull())
	{
		this->list[this->curSize] = date;
		curSize++;
		return 1;
	}
	return 0;
}

template<typename T>
void arrStack<T>::pop()
{
	if (!this->isEmpty())
	{
		list[curSize - 1] = NULL;
		curSize--;
	}
	else
	{
		cout << "It is already empty " << endl;
	}
	
}


template<typename T>
T arrStack<T>::getTop()
{
	if (!this->isEmpty())
	{
		return this->list[curSize - 1];
	}
	else 
	{
		return NULL;
	}
	
}

template<typename T>
int arrStack<T>::getCurSize()
{
	return this->curSize;

}

template<typename T>
void arrStack<T>::show()
{
	for (int i = 0; i <= curSize - 1; i++)
	{
		cout << (T)list[i] << " ";
	}
}

void arrStack_test()
{
	arrStack<int> S1(6);
	cout << "curent size is" << S1.getCurSize() << endl;
	for (int i = 0; i <= 6; i++)
	{
		S1.push(i + 100);

		cout << "curent top is " << S1.getTop() << " curent size is " << S1.getCurSize() << endl << endl;
	}
	cout << endl;
	for (int i = 0; i <= 7; i++)
	{
		S1.pop();

		cout << "curent top is " << S1.getTop() << " curent size is " << S1.getCurSize() << endl << endl;
	}
}