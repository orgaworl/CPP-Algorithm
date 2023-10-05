#pragma once
#include"linkStack.hpp"
#include"linkQueue.hpp"
#include"linkList.hpp"
#include<iostream>




using namespace std;
class queueN
{
public:
	int value;
	int ordinal;
	queueN()
	{
		this->value = 0;
		this->ordinal = -1;
	}
	queueN(int value, int ordinal)
	{
		this->value = value;
		this->ordinal = ordinal;
	}

};

void E4T1()
{

	//0接收输入量
	int n, k = 10;
	cin >> n; cin >> k;
	int* arr = new int[n];
	for (int i = 0; i <= n - 1; i++)
	{
		cin >> arr[i];
	}
	if (n < k) { return; }


	//1初始k个进入队列,并选出其中最大值
	linkQueue<queueN> queue;
	int max = arr[0];

	for (int i = 1; i <= k - 1; i++)
	{
		queueN to_en(arr[i], i);//构建将要进入队列的元素
		max = (max >= arr[i]) ? max : arr[i];

		if (!queue.isEmpty())
		{

			while (!queue.isEmpty() && (queue.getRear().value <= arr[i]))
			{
				queue.deRear();

			}

		}
		queue.enQueue(to_en);



	}
	cout << '\n' << max << ' ';//输出第一次结果


	//2移动n-k次
	for (int i = k; i <= n - 1; i++)
	{
		queueN to_en(arr[i], i);//构建将要进入队列的元素


		max = queue.getFront().value;
		if (queue.getFront().ordinal <= i + 1 - k)//对前出进行条件限制-关键
		{
			queue.deQueue();
		}

		while (!queue.isEmpty() && (queue.getRear().value <= arr[i]))
		{
			queue.deRear();
		}

		queue.enQueue(to_en);
		int a = (max >= queue.getFront().value) ? max : (queue.getFront().value);
		cout << a;
		cout << ' ';

	}





	delete[] arr;
}
void E4T2()
{
	//用链表保存输入
	int temp;
	linkList<int> linkList;
	do
	{
		cin >> temp;
		linkList.append(temp);
	} while (cin.peek() != '\n');


	//前n-1个数入栈
	linkStack<int> stack;
	Node<int>* p;
	p = linkList.getHead()->next;
	int max = 0;
	while (p->next != NULL)
	{

		int mark = 1;
		while (1)
		{
			if (stack.isEmpty() || stack.getTop() <= p->getDate())
			{
				stack.push(p->getDate());
				break;
			}
			else
			{
				max = (stack.getTop() * mark > max) ? stack.getTop() * mark : max;
				stack.pop();
				mark++;
			}
		}

		p = p->next;
	}


	//仅剩的一个数入栈
	if (stack.getTop() <= p->getDate())
	{
		//入栈
		stack.push(p->getDate());
	}
	else
	{
		//栈内元素出栈直至该数可入栈
		int mark = 1;
		while (1)
		{
			if (stack.getTop() <= p->getDate() || stack.isEmpty())
			{
				stack.push(p->getDate());
				break;
			}
			else
			{
				max = (stack.getTop() * mark > max) ? stack.getTop() * mark : max;
				stack.pop();
				mark++;
			}
		}


	}

	//对栈的末状态处理
	int mark = 1;
	while (1)
	{
		if (stack.isEmpty())
		{

			break;
		}
		else
		{
			max = (stack.getTop() * mark > max) ? stack.getTop() * mark : max;
			stack.pop();
			mark++;
		}
	}
	//输出最大值
	cout << '\n' << max;
}
void use()
{
	cout << "---------实验四题1---------" << '\n';
	E4T1();

	cout << '\n' << "---------实验四题2---------" << '\n';
	E4T2();
}