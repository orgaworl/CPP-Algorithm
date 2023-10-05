#pragma once
#include<iostream>

using namespace std;
template<typename T>
class dNode//节点类
{
public:
	dNode* next;
	dNode* prev;
	dNode<T>()
	{
		this->date = NULL;
		next = NULL;
		prev = NULL;
	}
	dNode<T>(T date)
	{
		this->date = date;
		next = NULL;
		prev = NULL;
	}
	T& getDate()
	{
		if (this != NULL)
		{
			return this->date;
		}
		
	}


protected:

private:
	T date;

};


template<typename T>
class dlinkList
{
public:
	dlinkList();
	~dlinkList();
	bool isExist();
	void append(T date);
	void showAllNode();


	void insertNode(T date, int ordinal);//to do
	void deleteNode(int ordinal);//to do
	dNode<T>* getNode(int ordinal);
	int getNumber();
private:
	dNode<typename T>* head;
	dNode<typename T>* tail;
	int nodeNumber;
};




template<typename T>
dlinkList<T>::dlinkList()
{

	head = new dNode<T>;
	tail = head;
	//不计入总数的头节点
	nodeNumber = 0;
}

template<typename T>
dlinkList<T>::~dlinkList()
{

	dNode<T>* p = this->head;
	dNode<T>* temp = this->head;
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
void dlinkList<T>::append(const T date)
{
	dNode<T>* tempPosition = tail;
	tail = new dNode<T>(date);
	tempPosition->next = tail;
	this->nodeNumber++;
	//add
	tail->prev = tempPosition;
}

template<typename T>
void dlinkList<T>::showAllNode()
{

	if (this->nodeNumber == 0)
	{
		return;
	}

	dNode<T>* p = this->head;
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
dNode<T>* dlinkList<T>::getNode(int ordinal)
{
	if (ordinal<0 || (ordinal + 1)>this->nodeNumber)
	{
		return this->head;
	}

	dNode<T>* p = this->head;
	for (int i = 0; i <= ordinal; i++)
	{
		if (p->next != NULL)
		{
			p = p->next;
		}

	}
	return p;
};
//可优化


template<typename T>
int dlinkList<T>::getNumber()
{
	return this->nodeNumber;
}




template<typename T>
bool dlinkList<T>::isExist()
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
void dlinkList<T>::insertNode(T date, int ordinal)
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
		dNode<T>* p = this->getNode(ordinal - 1);
		dNode<T>* q = new dNode<T>(date);
		q->next = p->next;
		p->next = q;
		this->nodeNumber++;
		//add
		tail->prev = q;
		q->prev = p;
	}




};

template<typename T>
void dlinkList<T>::deleteNode(int ordinal)
{
	dNode<T>* p = this->head;
	if (ordinal == this->nodeNumber - 1)
	{
		this->tail = p = this->getNode(ordinal - 1);
		delete p->next;
		p->next = NULL;
		this->nodeNumber--;

	}
	else if (ordinal >= 0 && ordinal < this->nodeNumber - 1)
	{

		p = this->getNode(ordinal - 1);
		dNode<T>* q = p->next;
		p->next = p->next->next;
		delete q;
		this->nodeNumber--;

		//add
		p->next->prev = p;
		
		
	
	}
	else
	{
		cout << "error in func deleteNode" << endl;
	}




}

void dlinkList_test()
{
	dlinkList<char> d1;
	for (int i = 0; i <= 9; i++)
	{
		d1.append((char)(65 + i));
		d1.showAllNode();
	}

	d1.deleteNode(0);
	d1.deleteNode(1);
}