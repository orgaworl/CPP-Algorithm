#pragma once
#include<iostream>
using namespace std;
//有头节点,不计入总数
template<typename T>
class Node//节点类
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