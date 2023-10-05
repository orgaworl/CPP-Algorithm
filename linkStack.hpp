#pragma once
#include<iostream>
#include"node.hpp"
using namespace std;

//基于链表
//前进前出
//存在头节点(不储存数据)


template<typename T>
class linkStack
{
public:
	linkStack();
	~linkStack();
	void clear();
	bool isEmpty();					//只有头节点
	void push(T date);
	void pop();
	T &getTop();					//返回栈节点中数据部分的引用
	int &getCurSize();              //返回栈大小的引用
	Node<T>* getNode(int ordinal);  //返回栈指定节点的指针
	void copy(linkStack<T>&copy);   //?
	
private:
	Node<typename T>* head;
	Node<typename T>* tail;
	int curSize;
	//curP=curSize-1;

};


template<typename T>
linkStack<T>::linkStack()
{
	head = new Node<T>;
	tail = head;
	this->curSize = 0;
	//未计数头节点

}

template<typename T>
linkStack<T>::~linkStack()
{
	Node<T>* p = this->head;
	Node<T>* temp = this->head;
	while (p->next!=NULL)
	{
		temp = p;
		p = p->next;
		delete temp;
	}
	temp = p;
	delete temp;


	this->curSize = 0;
	
}


template<typename T>
void  linkStack<T>::clear()
{

	Node<T>* p = this->head;
	Node<T>* temp = this->head;
	while (p->next != NULL)
	{
		temp = p;
		p = p->next;
		delete temp;
	}
	//不delete head
	
	//栈本身不变,其中元素改变
	this->curSize = 0;
	this->head->next = NULL;
	this->tail = this->head;
}

template<typename T>
bool linkStack<T>::isEmpty()
{
	if (this->curSize == 0&&this->head->next==NULL&&this->tail==this->head)
	{
		return 1;
	}
	else if (this->curSize > 0 || this->head!=NULL||this->tail!=head)
	{
		return 0;
	}
	else
	{
		throw runtime_error("error from func isEmpty");
	}
}


template<typename T>
void linkStack<T>::push(T date)
{
	//链表(头节点不储存数据)
	Node<T>* temp = new Node<T>(date);
	if (isEmpty())
	{
		this->head->next = temp;
		this->tail = temp;
		
	}
	else 
	{
		//插入0位置
		temp->next = this->head->next;
		this->head->next = temp;
	}

	this->curSize++;
}

template<typename T>
void linkStack<T>::pop()
{
	if (this->isEmpty())
	{
		cout << "\"empty\" from func pop" << endl;
		
	}
	else if (this->curSize==1)
	{
		this->head->next = NULL;
		tail = head;
		curSize--;
	}
	else if(this->curSize>=2)
	{
		Node<T>* temp;
		temp = head->next;
		head->next = head->next->next;
		delete temp;
		curSize--;
	}

}


template<typename T>
T &linkStack<T>::getTop()
{
	if (!this->isEmpty())
	{
		return this->getNode(0)->getDate();
	}
	else
	{
		cout << "\"empty\" from func getTop"<<endl;
		//return NULL;
	}

}

template<typename T>
int& linkStack<T>::getCurSize()
{
	return this->curSize;

}

template<typename T>
Node<T>* linkStack<T>::getNode(int ordinal)
{
	if (ordinal<0 || (ordinal + 1)>this->curSize)
	{
		return this->head;
	}

	Node<T>* p = this->head;
	for (int i = 0; i <= ordinal; i++)
	{
		if (p->next != NULL)
		{
			p = p->next;
		}

	}
	return p;
};


template<typename T>

void linkStack<T>::copy(linkStack<T>&copy)
{
	Node<T>* pOrigin=this->head;
	Node<T>* pCopy=copy.head=new Node<T>(pOrigin->getDate());
	copy.getCurSize() = 0;
	//pCopy->date = pOrigin->date;
	

	
	for (int i=0;i<=this->getCurSize()-1;i++)
	{
		
		
		pOrigin = pOrigin->next;
		pCopy->next = new Node<T>(pOrigin->getDate());
		pCopy = pCopy->next;
		copy.getCurSize()++;
	}
	copy.tail = pCopy;
}

void linkStack_test()
{
	linkStack<char> s1;
	cout << s1.getTop();
	cout << endl;
	for (int i = 0; i <= 9; i++)
	{
		s1.push((char)(65 + i));
		cout << i << s1.getTop() << endl;
	}

	cout << "*************" << endl;
	for (int i = 0; i <= 16; i++)
	{
		s1.pop();
		cout << i << s1.getTop() << endl;
	}

}