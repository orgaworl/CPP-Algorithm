#include"iostream"
#include"linkQueue.hpp"
using namespace std;
void Ex_9()
{
	int length = 0, inputLine = 0;
	cin >> length; cin >> inputLine; cout << endl;
	int storageLength = length + 1;
	int* poiArr = new int[storageLength];
	int temp1 = 0, temp2 = 0;
	for (int i = 1; i <= length; i++)
	{//数组初始化
		poiArr[i] = i;
	}



	int mark = 0;
	linkQueue<int>markNum;
	int* isUsed = new int [storageLength] {0};

	//输入值
	for (int i = 0; i < inputLine; i++)
	{//进行inputLine次输入行
		cin >> temp1; cin >> temp2;
		int higher = temp1 >= temp2 ? temp1 : temp2;
		int lower = temp1 < temp2 ? temp1 : temp2;
		if (poiArr[higher] == higher)
		{
			poiArr[higher] = lower;
		}

	}

	cout << endl;

	//将数组调整成 任意下标对应的值都小于等于下表,且


	for (int i = 1; i <= length; i++)
	{
		if (poiArr[i] != i)
		{
			while (1)
			{

				poiArr[i] = poiArr[poiArr[i]];
				if (mark == poiArr[i])
				{
					break;
				}
				mark = poiArr[i];
			}
		}
		else
		{
			markNum.enQueue(i);
			isUsed[i] = 1;
		}

	}

	int tempMarkNum = -1;

	cout << endl;
	while (!markNum.isEmpty())
	{
		markNum.deQueue(tempMarkNum);
		cout << tempMarkNum << ' ';
		for (int i = 1; i <= length; i++)
		{
			if (isUsed[i] == 0 && poiArr[i] == tempMarkNum)
			{
				cout << i << ' ';
			}



		}
		cout << endl;
	}

}