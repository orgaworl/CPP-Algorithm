#pragma once
#include<iostream>
#include"node.hpp"
using namespace std;
//有头节点,不计入总数


template<typename T>
class linkList//链表类
{
public:
	
	linkList();
	~linkList();
	bool isExist();
	void append(T date);
	void showAllNode();
	

	void insertNode(T date, int ordinal);//to do
	void deleteNode(int ordinal);//to do
	Node<T>* getNode(int ordinal);//输入下标(不计数的头节点下标抽象为-1)
	Node<T>*getHead();
	int getNumber();
	

private:
	Node<T>* head;
	Node<T>* tail;
	int nodeNumber;
	
	
};


template<typename T>
linkList<T>::linkList()
{

	head = new Node<T>;
	tail = head;
	//不计入总数的头节点
	nodeNumber = 0;
}

template<typename T>
linkList<T>::~linkList()
{

	Node<T>* p = this->head;
	Node<T>* temp = this->head;
	while (p->next != NULL)
	{
		temp = p;
		p = p->next;
		delete temp;
	}
	temp = p;
	delete temp;


	
	this->nodeNumber = 0;

}



template<typename T>
void linkList<T>::append(const T date)
{
	Node<T>* tempPosition=tail;
	tail= new Node<T>(date);
	tempPosition->next = tail;
	this->nodeNumber++;
}

template<typename T>
void linkList<T>::showAllNode()
{
	
	if (this->nodeNumber==0)
	{
		return ;
	}

	Node<T>* p = this->head;
	//cout << "head is " << p->next->getDate() << endl;
	cout << endl;
	for (int i=0;i<this->nodeNumber;i++)
	{
		p = p->next;
		cout << p->getDate()<<" ";
		if (i%2==1)
		{
			cout << " ";

		}
	}
	cout << endl;
	//cout << "tail is " << p->getDate() << endl;



};


template<typename T>
Node<T>*linkList<T>::getNode(int ordinal)
{
	if (ordinal<0||(ordinal+1)>this->nodeNumber)
	{
		return this->head;
	}

	Node<T>* p = this->head;
	for (int i = 0; i <=ordinal; i++)
	{
		if (p->next!=NULL)
		{
			p = p->next;
		}
		
	}
	return p;
};

template<typename T>
Node<T>*linkList<T>::getHead()
{
	return this->head;
}

template<typename T>
int linkList<T>::getNumber()
{
	return this->nodeNumber;
}




template<typename T>
bool linkList<T>::isExist()
{
	if (this->head->next == NULL && this->nodeNumber == 0 && this->tail->next == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
};

template<typename T>
void linkList<T>::insertNode(T date,int ordinal)
{
	if (ordinal<0||ordinal>this->nodeNumber)
	{
		return;
	}
	else if (ordinal==this->nodeNumber)
	{
		this->append(date);
		
		return;
	}
	else
	{
		Node<T>* p = this->getNode(ordinal - 1);
		Node<T>* q = new Node<T>(date);
		q->next = p->next;
		p->next = q;
		this->nodeNumber++;
	}
	
	


};

template<typename T>
void linkList<T>::deleteNode(int ordinal)
{
	Node* p=this->head;
	if (ordinal==this->nodeNumber-1)
	{
		this->tail =p = this->getNode(ordinal - 1);
		delete p.next;
		p.next = NULL;
		this->nodeNumber--;
		
	}
	else if (ordinal>=0&&ordinal<this->nodeNumber-1)
	{

		p = this->getNode(ordinal-1);
		Node* temp = p.next;
		p.next = p.next.next;
		delete temp;

		this->nodeNumber--;
	}
	else
	{
		cout << "error in func deleteNode" << endl;
	}


	

}