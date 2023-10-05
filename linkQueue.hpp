#pragma once
#include<iostream>
#include<iomanip>
#include"node.hpp"
using namespace std;
//链表未设置头节点
//链表前为front后为rear,后(rear)进,前(front)出
//

template<typename T>
class linkQueue
{
public:
	linkQueue();
	~linkQueue();

	void clear();
	bool isEmpty();
	//bool isFull();
	int getCurSize();

	T getFront();
	bool getFront(T& date);
	T getRear();


	bool enQueue(const T date);
	bool deQueue();
	bool deQueue(T& date);
	bool showAll();
	bool deRear();

private:

	Node<T>* front;
	Node<T>* rear;
	int curSize;

};

template<typename T>
linkQueue<T>::linkQueue()
{
	rear = front=NULL;
	curSize = 0;
}


template<typename T>
linkQueue<T>::~linkQueue()
{
	clear();
}



template<typename T>
void  linkQueue<T>::clear()
{
	if (!isEmpty())
	{

		Node<T>* p = this->front;
		Node<T>* temp = this->front;
		while (p->next != NULL)
		{
			temp = p;
			p = p->next;
			delete temp;
		}
		temp = p;
		delete temp;


		front = NULL;
		rear = NULL;
		this->curSize = 0;
	}
	
}


template<typename T>
bool linkQueue<T>::isEmpty()
{
	if (this->curSize==0)//this->rear==NULL&&this->front==NULL&&
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



template<typename T>
int linkQueue<T>::getCurSize()
{
	return this->curSize;
}


template<typename T>
T linkQueue<T>::getFront()
{
	if (!isEmpty())
	{
		return front->getDate();
	}
	
}

template<typename T>
bool linkQueue<T>::getFront(T& date)
{
	if (!isEmpty())
	{
		date=front->getDate();
		return 1;
	}
	else
	{
		return 0;
	}
	
}

template<typename T>
T linkQueue<T>::getRear()
{
	if (!isEmpty())
	{
		return rear->getDate();
	}
}

template<typename T>
bool linkQueue<T>::enQueue(const T date)
{
	if (!isEmpty())
	{
		Node<T>* tempPosition = rear;
		rear = new Node<T>(date);
		tempPosition->next = rear;
		this->curSize++;
		return 1;
	}
	else if(isEmpty())
	{
		front=rear = new Node<T>(date);
		this->curSize++;
		return 1;
	}
	else
	{
		return 0;
	}
	
}


template<typename T>
bool linkQueue<T>::deQueue()
{
	if (!isEmpty())
	{
		if (front!=rear)
		{
			//元素数大于等于2时
			Node<T>* tempPosition = front->next;
			delete front;
			front = tempPosition;

			this->curSize--;
			return 1;
		}
		else if (front == rear )
		{//仅有一个元素时
			delete front;
			front = NULL;
			rear = NULL;
			this->curSize--;
			return 1;
		}
		
	}
	else
	{
		return 0;
	}
	return 0;
	
}


template<typename T>
bool linkQueue<T>::deRear()
{
	if (!isEmpty())
	{
		if (front != rear)
		{

			//元素数大于等于2时
			Node<T>* tempPosition = this->front;
			for(int i=0;i<=getCurSize()-3;i++)
			{
				tempPosition = tempPosition->next;
			}
			rear = tempPosition;
			delete tempPosition->next;
			tempPosition->next = NULL;

			this->curSize--;
			return 1;
		}
		else if (getCurSize()==2)
		{
			delete front->next;
			front->next = NULL;
			rear = front;
			this->curSize--;
			return 1;


		}
		else if (front == rear)
		{//仅有一个元素时
			delete rear;
			front = NULL;
			rear = NULL;
			this->curSize--;
			return 1;
		}

	}
	else
	{
		return 0;
	}
	return 0;



}


template<typename T>
bool linkQueue<T>::deQueue(T& date)
{
	if (getFront(date)&&deQueue())
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}



template<typename T>

bool linkQueue<T>::showAll()
{

	if (this->curSize == 0)
	{
		return 0;
	}
	
	Node<T>* p = this->front;
	//cout << "front is " << p->next->getDate() << endl;
	cout << endl;
	for (int i = 0; i < this->curSize; i++)
	{
		
		if (p!=NULL)
		{
			cout << p->getDate() << " ";
			p = p->next;
		}
		//最后一次P为NULL
	}
	cout << endl;
	return 1;
}









void linkQueue_test()
{

	linkQueue<char> temp;
	cout << "is empty ? " << temp.isEmpty() << endl;

	for (int i = 0; i <= 13; i++)
	{
		temp.enQueue((char)(i + 65));
		cout << temp.getCurSize() << " ";



	}
	cout << endl << temp.getFront() << endl;
	for (int i = 0; i <= 30; i++)
	{
		temp.deQueue();
		temp.showAll();

	}
	cout << "is empty ? " << temp.isEmpty() << endl;

	temp.clear();
	temp.showAll();
	cout << "is empty ? " << temp.isEmpty() << endl;


}