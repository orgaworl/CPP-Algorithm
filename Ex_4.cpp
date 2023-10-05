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

	//0����������
	int n, k = 10;
	cin >> n; cin >> k;
	int* arr = new int[n];
	for (int i = 0; i <= n - 1; i++)
	{
		cin >> arr[i];
	}
	if (n < k) { return; }


	//1��ʼk���������,��ѡ���������ֵ
	linkQueue<queueN> queue;
	int max = arr[0];

	for (int i = 1; i <= k - 1; i++)
	{
		queueN to_en(arr[i], i);//������Ҫ������е�Ԫ��
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
	cout << '\n' << max << ' ';//�����һ�ν��


	//2�ƶ�n-k��
	for (int i = k; i <= n - 1; i++)
	{
		queueN to_en(arr[i], i);//������Ҫ������е�Ԫ��


		max = queue.getFront().value;
		if (queue.getFront().ordinal <= i + 1 - k)//��ǰ��������������-�ؼ�
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
	//������������
	int temp;
	linkList<int> linkList;
	do
	{
		cin >> temp;
		linkList.append(temp);
	} while (cin.peek() != '\n');


	//ǰn-1������ջ
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


	//��ʣ��һ������ջ
	if (stack.getTop() <= p->getDate())
	{
		//��ջ
		stack.push(p->getDate());
	}
	else
	{
		//ջ��Ԫ�س�ջֱ����������ջ
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

	//��ջ��ĩ״̬����
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
	//������ֵ
	cout << '\n' << max;
}
void use()
{
	cout << "---------ʵ������1---------" << '\n';
	E4T1();

	cout << '\n' << "---------ʵ������2---------" << '\n';
	E4T2();
}