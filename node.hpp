#pragma once
#include<iostream>
using namespace std;
//��ͷ�ڵ�,����������
template<typename T>
class Node//�ڵ���
{
public:
	Node* next;
	Node<T>()
	{
		//date = NULL;
		next = NULL;
	}
	Node<T>(T date)
	{
		this->date = date;
		next = NULL;
	}
	T& getDate()
	{
		/*if (this!=NULL)
		{
			return this->date;
		}*/
		return this->date;

	}


protected:

private:
	T date;

};