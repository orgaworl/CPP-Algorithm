#include<iostream>
#include"unionFind.h"
using namespace std;


unionFind::unionFind(int length)
{
	poiArr = new int[length + 1];
	this->length = length;
	for (int i = 1; i <= length; i++)
	{//数组初始化
		poiArr[i] = i;
	}

}

bool unionFind::union_(int from,int to)
{
	if (from<=0||from>length||to<=0||to>length)
	{
		return 0;
	}
	poiArr[from] = to;
	return 1;
}


int unionFind::find(int toFind)
{
	if (toFind<=0||toFind>length)
	{
		return 0;
	}

	if (poiArr[toFind] != toFind)
	{
		int mark = 0;
		while (1)
		{
			poiArr[toFind] = poiArr[poiArr[toFind]];
			if (mark == poiArr[toFind])
			{
				break;
			}
			mark = poiArr[toFind];
		}
		
	}
	return poiArr[toFind];
		
}

int unionFind::getValue(int ordinal)
{

	return this->poiArr[ordinal];
}

int unionFind::findAll()
{
	for (int i=1;i<=length;i++)
	{
		find(i);
	}
	return 1;
}

void unionFind::showArr()
{
	for (int i=1;i<=length;i++)
	{
		cout << i << ' ' << poiArr[i] << endl;
	}
}

void Ex_09_rewrite()
{
	int length = 0, inputLine = 0;
	cin >> length; cin >> inputLine; cout << endl;
	unionFind unionf(length);


	int temp1 = 0, temp2 = 0;
	for (int i = 0; i < inputLine; i++)
	{//进行inputLine次输入行
		cin >> temp1; cin >> temp2;
		int higher = temp1 >= temp2 ? temp1 : temp2;
		int lower = temp1 < temp2 ? temp1 : temp2;
		if (unionf.getValue(higher) == higher)
		{
			unionf.union_(higher, lower);
		}
	}
	unionf.findAll();




	cout << endl << endl;
	unionf.showArr();


}