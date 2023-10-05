

#include<iostream>
#include"linkList.hpp"
#include"arrList.hpp"

//1˳�����
template<typename T>
void setEquation(arrList<T>& s)//����ת��Ϊ˳���
{
	int temp = 0;
	while (cin >> temp)
	{

		s.appendElement(temp);

		if (cin.peek() == '\n')
		{
			break;
		}
		else if (cin.peek() == ' ')
		{
			cin.get();
		}
	}
}

template<typename T>
void plusEquation(arrList<T>& sa, arrList<T>& sb)
{
	int a = 0;
	int b = 0;


	arrList<T> sc(10);
	while (1)
	{

		if (a >= sa.getCurentLenth() && b >= sb.getCurentLenth())//ab������
		{
			break;
		}
		else if (a < sa.getCurentLenth() && b >= sb.getCurentLenth())//a��ʣ�ڵ�,b����
		{
			sc.appendElement(sa.getElement(a));
			sc.appendElement(sa.getElement(a + 1));

			a += 2;
		}
		else if (a >= sa.getCurentLenth() && b < sb.getCurentLenth())//b��ʣ�ڵ�
		{
			sc.appendElement(sb.getElement(b));
			sc.appendElement(sb.getElement(b + 1));
			b += 2;
		}
		else if (a < sa.getCurentLenth() && b < sb.getCurentLenth())//ab����ʣ�ڵ�
		{
			if (sa.getElement(a + 1) > sb.getElement(b + 1))//��ʱa���������������b��
			{
				sc.appendElement(sa.getElement(a));
				sc.appendElement(sa.getElement(a + 1));

				a += 2;

			}
			else if (sa.getElement(a + 1) < sb.getElement(b + 1))//��ʱa�����������С��b��
			{
				sc.appendElement(sb.getElement(b));
				sc.appendElement(sb.getElement(b + 1));
				b += 2;

			}
			else if (sa.getElement(a + 1) == sb.getElement(b + 1))//��ʱa���������������b��
			{
				int sum = sa.getElement(a) + sb.getElement(b);
				if (sum != 0)
				{
					sc.appendElement(sum);
					sc.appendElement(sa.getElement(a + 1));

				}

				a += 2;
				b += 2;

			}
			else
			{
				cout << "error";
			}
		}
		else
		{
			cout << "error";
		}
	}

	sc.showAllElement();
}

//2������
template<typename T>//������ת������
void setEquation(linkList<T>& link_list)//����ת��Ϊ����
{
	int temp = 0;
	while (cin >> temp)
	{

		link_list.append(temp);

		if (cin.peek() == '\n')
		{
			break;
		}
		else if (cin.peek() == ' ')
		{
			cin.get();
		}
	}
}
template<typename T>//������ת������
void setEquation(linkList<T>& link_list, int* equ, int length)
{
	for (int i = 0; i < length; i++)
	{
		link_list.append(equ[i]);
	}
}

template<typename T>//�������������
void plusEquation(linkList<T>& la, linkList<T>& lb)
{
	int a = 0;
	int b = 0;


	linkList<T> lc;
	while (1)
	{

		if (a >= la.getNumber() && b >= lb.getNumber())//ab������
		{
			break;
		}
		else if (a < la.getNumber() && b >= lb.getNumber())//a��ʣ�ڵ�,b����
		{
			lc.append(la.getNode(a)->getDate());
			lc.append(la.getNode(a + 1)->getDate());
			a += 2;
		}
		else if (a >= la.getNumber() && b < lb.getNumber())//b��ʣ�ڵ�
		{
			lc.append(lb.getNode(b)->getDate());
			lc.append(lb.getNode(b + 1)->getDate());
			b += 2;
		}
		else if (a < la.getNumber() && b < lb.getNumber())//ab����ʣ�ڵ�
		{
			if (la.getNode(a + 1)->getDate() > lb.getNode(b + 1)->getDate())//��ʱa���������������b��
			{
				lc.append(la.getNode(a)->getDate());
				lc.append(la.getNode(a + 1)->getDate());

				a += 2;

			}
			else if (la.getNode(a + 1)->getDate() < lb.getNode(b + 1)->getDate())//��ʱa�����������С��b��
			{
				lc.append(lb.getNode(b)->getDate());
				lc.append(lb.getNode(b + 1)->getDate());
				b += 2;

			}
			else if (la.getNode(a + 1)->getDate() == lb.getNode(b + 1)->getDate())//��ʱa���������������b��
			{
				int sum = la.getNode(a)->getDate() + lb.getNode(b)->getDate();
				if (sum != 0)
				{
					lc.append(sum);
					lc.append(la.getNode(a + 1)->getDate());
				}

				a += 2;
				b += 2;

			}
			else
			{
				cout << "error";
			}
		}
		else
		{
			cout << "error";
		}
	}

	lc.showAllNode();
}




template<typename T>
void merge_reverse(linkList<T>& la, linkList<T>& lb)
{
	Node<T>* pa = la.getNode(-1);//ָ��ͷ�ڵ�
	Node<T>* pb = lb.getNode(-1);
	linkList<T> lc;
	while (1)
	{
		if (pa->next != NULL && pb->next != NULL)
		{
			if (pa->next->getDate() == pb->next->getDate())
			{
				lc.insertNode(pa->next->getDate(), 0);
				pa = pa->next;
				pb = pb->next;
			}
			else if (pa->next->getDate() <= pb->next->getDate())
			{
				lc.insertNode(pa->next->getDate(), 0);
				pa = pa->next;

			}
			else if (pa->next->getDate() >= pb->next->getDate())
			{
				lc.insertNode(pb->next->getDate(), 0);
				pb = pb->next;
			}
			else
			{
				cout << "error" << endl;
			}

		}
		else if (pa->next != NULL && pb->next == NULL)
		{
			lc.insertNode(pa->next->getDate(), 0);
			pa = pa->next;
		}
		else if (pa->next == NULL && pb->next != NULL)
		{
			lc.insertNode(pb->next->getDate(), 0);
			pb = pb->next;
		}
		else if (pa->next == NULL && pb->next == NULL)
		{
			break;
		}
		else
		{
			cout << "error" << endl;
		}


	}

	lc.showAllNode();





}

void second_experiment()
{
	//1˳�������ʽ���
	cout << "˳���ʵ�ֶ���ʽ���" << endl;
	arrList<int> s1(10);
	setEquation(s1);
	arrList<int> s2(10);
	setEquation(s2);
	plusEquation(s1, s2);
	cout << "--------- �ָ���---------" << endl;


	//2��������ʽ���
	cout << "����ʵ�ֶ���ʽ���" << endl;
	linkList<int> L1;
	setEquation(L1);
	linkList<int> L2;
	setEquation(L2);
	plusEquation(L1, L2);
	cout << "--------- �ָ���---------" << endl;

	//3�����ϳ�����
	cout << "����ʵ��������ϲ�������" << endl;
	linkList<int>L3;
	setEquation(L3);
	linkList<int>L4;
	setEquation(L4);
	merge_reverse(L3, L4);

}

