#include<iostream>
#include<iomanip>
using namespace std;

template<typename T>
class arrQueue
{
public:
	arrQueue(int Size);
	~arrQueue();

	void clear();
	bool isEmpty();
	bool isFull();
	int getCurSize();

	bool getFront();
	bool getFront(T& date);
	
	bool enQueue(const T date);
	bool deQueue();
	bool deQueue(T& date);
	bool showAll();


private:
	T* list;
	int maxSize;
	//int curSize;
	
	//前入后进
	int front;
	int rear;


};

template<typename T>
arrQueue<T>::arrQueue(int Size)
{
	this->maxSize = Size + 1;
	this->list = new T[this->maxSize];
	this->front=this->rear = 0;
	for (int i=0;i<=maxSize-1;i++)
	{
		list[i] = NULL;
	}
	//仅供测试

}

template<typename T>
arrQueue<T>::~arrQueue()
{
	delete this->list;
	this->list = NULL;
	this->front = this->rear = 0;
	this->maxSize = 0;
}


template<typename T>
void  arrQueue<T>::clear()
{
	//栈本身不变,其中元素改变
	for (int i=0;i<=maxSize-1;i++)
	{
		list[i] = NULL;
	}
	this->front = this->rear = 0;

}



template<typename T>
bool arrQueue<T>::isEmpty()
{
	if (this->front==this->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

template<typename T>
bool arrQueue<T>::isFull()
{
	//一种full
	if ((this->rear + 1 )%maxSize== this->front)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
	
}





template<typename T>
int arrQueue<T>::getCurSize()
{
	if (isEmpty())
	{
		return 0;
	}
	return (this->rear-this->front);

}

template<typename T>
bool arrQueue<T>::getFront()
{
	return list[front % maxSize];
};
template<typename T>
bool arrQueue<T>::getFront(T& date)
{
	date = list[front%maxSize];
};


template<typename T>
bool arrQueue<T>::enQueue(const T date)
{
	if (isFull())
	{
		return 0;
	}
	else
	{
		list[this->rear % maxSize] = date;
		rear++;
		return 1;
	}
	
};

template<typename T>
bool arrQueue<T>::deQueue()
{

	if (isEmpty())
	{
		return 0;
	}
	else
	{
		list[this->front % maxSize] = NULL;
		front++;
		return 1;
	}
};

template<typename T>
bool arrQueue<T>::deQueue(T& date)
{

	if (isEmpty())
	{
		return 0;
	}
	else
	{
		date = list[this->front % maxSize];
		list[this->front % maxSize] =NULL;
		front++;
		return 1;
	}
};


template<typename T>

bool arrQueue<T>::showAll()
{
	if (!isEmpty())
	{
		cout <<"tatal "<< this->getCurSize()<<" ";
		for (int i=0;i<=maxSize-1;i++)
		{
			
			
			cout <<left<<setw(2) << list[i];
		}
		//设为NULL的不输出
		
		cout << endl;
		return 1;
		
	}
	else
	{
		return 0;
	}
}

void arrQueue_test()
{
	arrQueue<char> temp(10);
	cout << temp.isEmpty() << endl;
	cout << endl;
	for (int i = 0; i <= 13; i++)
	{
		temp.enQueue((char)(i + 65));
		//temp.showAll();
		cout << temp.getFront();

	}
	cout << endl << "isFull? " << temp.isFull() << endl;
	for (int i = 0; i <= 4; i++)
	{
		temp.deQueue();
		temp.showAll();

	}
	while (!temp.isFull())
	{
		temp.enQueue('h');
		temp.showAll();
	}
	cout << "isFull? " << temp.isFull() << endl;
	temp.clear();
	temp.showAll();
	cout << temp.isEmpty() << endl;

}
