#pragma once
#include<iostream>
using namespace std;


template<typename T>
class arrList
{
public:
	
	arrList(const int maxSize);
	~arrList();

	void clearList();
	int getCurentLenth();
	int getCurentPosition();
	T getElement(int ordinal);
	void appendElement(T element);
	void insertElement(T element,int ordinal);
	void showAllElement();
	void deleteElement(int ordinal);
	void setValue(T element,int ordinal);
	bool checkListExist();

private:
	
	T* list;
	int maxSize;
	int curLen;
	int curPos;




};

template<typename T>
bool arrList<T>::checkListExist()
{
	if (this->list == NULL)
	{
		cout << "List is nullptr" << endl;
		return 0;
	}
	else
	{
		return 1;
	}
}

template<typename T>
arrList<T>::arrList(const int maxSize)
{
	this->maxSize = maxSize;
	this->list = new T[maxSize];
	curLen = curPos = 0;
}

template<typename T>
arrList<T>::~arrList()
{
	delete[] this->list;
}

template<typename T>
void arrList<T>::clearList()
{
	delete[]list;
	list = NULL;
	maxSize = 0;
	curLen = 0;
	curPos = 0;
}

template<typename T>
int arrList<T>::getCurentLenth()
{
	return this->curLen;
}

template<typename T>
int arrList<T>::getCurentPosition()
{
	return this->curPos;
}

template<typename T>
void arrList<T>::appendElement(T element)
{
	if (!this->checkListExist())
	{
		return;
	}

	if (curLen <= maxSize && curPos <= maxSize)
	{
		list[curPos] = element;
		curPos++;//顺序表满后curent_postion超出max1
		if (curLen < maxSize && curPos < maxSize)
		{
			curLen++;

		}

	}
	else
	{
		cout << "Full from appendElement" << endl;
	}

}

template<typename T>
T arrList<T>::getElement(int ordinal)
{
	if (this->checkListExist())
	{
		return this->list[ordinal];
	}
	


}

template<typename T>
void arrList<T>::insertElement(T element, int ordinal)
{
	if (this->checkListExist())
	{
		return;
	}

	if (ordinal>this->maxSize||ordinal<0)
	{
		throw runtime_error("超出顺序表最大范围");
	}
	else if (ordinal>this->curPos&&ordinal<=this->maxSize)
	{
		cout << "S2";
	}
	else if (ordinal == this->curPos)
	{
		cout << "S3";
	}
	else if(ordinal < this->curPos&&ordinal>=0)
	{
		if (curPos>=maxSize)
		{
			cout<<"顺序表已满,不可插入"<<endl;
			return;
		}

		for (int i= curPos;i>=ordinal+1;i--)
		{
			this->list[i] = this->list[i-1];
		}
		this->list[ordinal] = element;
		this->curLen++;
		this->curPos++;


	}
	else
	{
		throw runtime_error("Unknow error");
	}


}

template<typename T>
void arrList<T>::showAllElement()
{
	if (!this->checkListExist())
	{
		return;
	}

	if (curPos==0)
	{
		return;
	}

	for (int i=0;i<=this->curPos-1;i++)
	{
		cout << list[i] << "  ";

	}
	cout << endl;
}

template<typename T>
void arrList<T>::deleteElement(int ordinal)
{
	if (this->checkListExist())
	{
		return;
	}

	for (int i=ordinal;i<=curPos-2;i++)
	{
		list[i] = list[i + 1];
	}
	//保险

	curLen--;
	curPos--;

}

template<typename T>
void arrList<T>::setValue(T element, int ordinal)
{
	if (this->checkListExist())
	{
		return;
	}
	if (ordinal>=0&&ordinal<=curPos-1)
	{
		list[ordinal] = element;
	}








}