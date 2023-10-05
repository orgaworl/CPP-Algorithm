

#include<iostream>
#include"linkList.hpp"
#include"arrList.hpp"

//1顺序表用
template<typename T>
void setEquation(arrList<T>& s)//输入转化为顺序表
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

		if (a >= sa.getCurentLenth() && b >= sb.getCurentLenth())//ab链都无
		{
			break;
		}
		else if (a < sa.getCurentLenth() && b >= sb.getCurentLenth())//a链剩节点,b链无
		{
			sc.appendElement(sa.getElement(a));
			sc.appendElement(sa.getElement(a + 1));

			a += 2;
		}
		else if (a >= sa.getCurentLenth() && b < sb.getCurentLenth())//b链剩节点
		{
			sc.appendElement(sb.getElement(b));
			sc.appendElement(sb.getElement(b + 1));
			b += 2;
		}
		else if (a < sa.getCurentLenth() && b < sb.getCurentLenth())//ab链都剩节点
		{
			if (sa.getElement(a + 1) > sb.getElement(b + 1))//此时a链不定项次数大于b链
			{
				sc.appendElement(sa.getElement(a));
				sc.appendElement(sa.getElement(a + 1));

				a += 2;

			}
			else if (sa.getElement(a + 1) < sb.getElement(b + 1))//此时a链不定项次数小于b链
			{
				sc.appendElement(sb.getElement(b));
				sc.appendElement(sb.getElement(b + 1));
				b += 2;

			}
			else if (sa.getElement(a + 1) == sb.getElement(b + 1))//此时a链不定项次数等于b链
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

//2链表用
template<typename T>//将输入转成链表
void setEquation(linkList<T>& link_list)//输入转化为链表
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
template<typename T>//将输入转成链表
void setEquation(linkList<T>& link_list, int* equ, int length)
{
	for (int i = 0; i < length; i++)
	{
		link_list.append(equ[i]);
	}
}

template<typename T>//将两个链表相加
void plusEquation(linkList<T>& la, linkList<T>& lb)
{
	int a = 0;
	int b = 0;


	linkList<T> lc;
	while (1)
	{

		if (a >= la.getNumber() && b >= lb.getNumber())//ab链都无
		{
			break;
		}
		else if (a < la.getNumber() && b >= lb.getNumber())//a链剩节点,b链无
		{
			lc.append(la.getNode(a)->getDate());
			lc.append(la.getNode(a + 1)->getDate());
			a += 2;
		}
		else if (a >= la.getNumber() && b < lb.getNumber())//b链剩节点
		{
			lc.append(lb.getNode(b)->getDate());
			lc.append(lb.getNode(b + 1)->getDate());
			b += 2;
		}
		else if (a < la.getNumber() && b < lb.getNumber())//ab链都剩节点
		{
			if (la.getNode(a + 1)->getDate() > lb.getNode(b + 1)->getDate())//此时a链不定项次数大于b链
			{
				lc.append(la.getNode(a)->getDate());
				lc.append(la.getNode(a + 1)->getDate());

				a += 2;

			}
			else if (la.getNode(a + 1)->getDate() < lb.getNode(b + 1)->getDate())//此时a链不定项次数小于b链
			{
				lc.append(lb.getNode(b)->getDate());
				lc.append(lb.getNode(b + 1)->getDate());
				b += 2;

			}
			else if (la.getNode(a + 1)->getDate() == lb.getNode(b + 1)->getDate())//此时a链不定项次数等于b链
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
	Node<T>* pa = la.getNode(-1);//指向头节点
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
	//1顺序表，多项式相加
	cout << "顺序表实现多项式相加" << endl;
	arrList<int> s1(10);
	setEquation(s1);
	arrList<int> s2(10);
	setEquation(s2);
	plusEquation(s1, s2);
	cout << "--------- 分割线---------" << endl;


	//2链表，多项式相加
	cout << "链表实现多项式相加" << endl;
	linkList<int> L1;
	setEquation(L1);
	linkList<int> L2;
	setEquation(L2);
	plusEquation(L1, L2);
	cout << "--------- 分割线---------" << endl;

	//3链表，合成逆序
	cout << "链表实现两正序合并成正序" << endl;
	linkList<int>L3;
	setEquation(L3);
	linkList<int>L4;
	setEquation(L4);
	merge_reverse(L3, L4);

}

