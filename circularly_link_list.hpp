#pragma once
#include<iostream>
#include"linkList.hpp"
using namespace std;



template<typename T>
class clinkList
{
public:
	clinkList();
	~clinkList();
	bool isExist();
	void append(T date);
	void showAllNode();


	void insertNode(T date, int ordinal);//to do
	void deleteNode(int ordinal);//to do
	Node<T>* getNode(int ordinal);
	int getNumber();
private:
	Node<typename T>* head;
	Node<typename T>* tail;
	int nodeNumber;
};




template<typename T>
clinkList<T>::clinkList()
{

	head = new Node<T>;
	tail = head;
	//不计入总数的头节点
	nodeNumber = 0;
}

template<typename T>
clinkList<T>::~clinkList()
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
void clinkList<T>::append(const T date)
{
	Node<T>* tempPosition = tail;
	tail = new Node<T>(date);
	tempPosition->next = tail;
	this->nodeNumber++;
	tail->next = head;
}

template<typename T>
void clinkList<T>::showAllNode()
{

	if (this->nodeNumber == 0)
	{
		return;
	}

	Node<T>* p = this->head;
	//cout << "head is " << p->next->getDate() << endl;
	cout << endl;
	for (int i = 0; i < this->nodeNumber; i++)
	{
		p = p->next;
		cout << p->getDate() << " ";
		if (i % 2 == 1)
		{
			cout << " ";

		}
	}
	cout << endl;
	//cout << "tail is " << p->getDate() << endl;



};


template<typename T>
Node<T>* clinkList<T>::getNode(int ordinal)
{
	if (ordinal<0 || (ordinal + 1)>this->nodeNumber)
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
int clinkList<T>::getNumber()
{
	return this->nodeNumber;
}




template<typename T>
bool clinkList<T>::isExist()
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
void clinkList<T>::insertNode(T date, int ordinal)
{
	if (ordinal<0 || ordinal>this->nodeNumber)
	{
		return;
	}
	else if (ordinal == this->nodeNumber)
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
void clinkList<T>::deleteNode(int ordinal)
{
	Node* p = this->head;
	if (ordinal == this->nodeNumber - 1)
	{
		this->tail = p = this->getNode(ordinal - 1);
		delete p.next;
		p.next = NULL;
		this->nodeNumber--;
		tail = head;

	}
	else if (ordinal >= 0 && ordinal < this->nodeNumber - 1)
	{

		p = this->getNode(ordinal - 1);
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