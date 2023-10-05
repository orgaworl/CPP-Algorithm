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
	{//�����ʼ��
		poiArr[i] = i;
	}



	int mark = 0;
	linkQueue<int>markNum;
	int* isUsed = new int [storageLength] {0};

	//����ֵ
	for (int i = 0; i < inputLine; i++)
	{//����inputLine��������
		cin >> temp1; cin >> temp2;
		int higher = temp1 >= temp2 ? temp1 : temp2;
		int lower = temp1 < temp2 ? temp1 : temp2;
		if (poiArr[higher] == higher)
		{
			poiArr[higher] = lower;
		}

	}

	cout << endl;

	//����������� �����±��Ӧ��ֵ��С�ڵ����±�,��


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