#pragma once
#include<iostream>
#include"node.hpp"
using namespace std;

//��������
//ǰ��ǰ��
//����ͷ�ڵ�(����������)


template<typename T>
class linkStack
{
public:
	linkStack();
	~linkStack();
	void clear();
	bool isEmpty();					//ֻ��ͷ�ڵ�
	void push(T date);
	void pop();
	T &getTop();					//����ջ�ڵ������ݲ��ֵ�����
	int &getCurSize();              //����ջ��С������
	Node<T>* getNode(int ordinal);  //����ջָ���ڵ��ָ��
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
	//δ����ͷ�ڵ�

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
	//��delete head
	
	//ջ������,����Ԫ�ظı�
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
	//����(ͷ�ڵ㲻��������)
	Node<T>* temp = new Node<T>(date);
	if (isEmpty())
	{
		this->head->next = temp;
		this->tail = temp;
		
	}
	else 
	{
		//����0λ��
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