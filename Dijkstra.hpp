
#include<iostream>
#include"graphMat.hpp"
using namespace std;
float infinite = 99;



template<typename T>
float graphMat<T>::getShorDist(int start, int finish)
{
	//Dijkstra�㷨


	float* shorDist = new float[numVertex];//��start��i�����·����ΪshorDist[i]
	int* pre = new int[numVertex];// �����Vs��������������·������pre[i] = k����ʾ��Vs ��Vi�����·���У�Vi��ǰһ��������Vk�������·��������(Vs, ��, Vk, Vi) ��
	bool* final = new bool[numVertex];// ��ʶһ�������Ƿ��Ѽ���S�С�
	float max = 0;

	for (int i = 0; i <= numVertex; i++)
	{
		shorDist[i] = matrix[start][i];
		pre[i] = start;
		final[i] = false;//����S��

	}
	shorDist[start] = 0;//start���Լ�����Ϊ��Ϊ0
	final[start] = true;//start��S��

	//*******************************

	for (int i = 0; i <= numVertex - 2; i++)
	{//ÿ��ѭ��ʹһ���������S

		float minDistance = infinite;
		int markOne = -1;

		for (int k = 0; k <= numVertex - 1; k++)
		{//�ҵ���ʱ�յ㲻��S��,��·����С�ı� start->k
			if (final[k] == false && shorDist[k] < minDistance)
			{
				markOne = k;
				minDistance = shorDist[k];
			}
		}




		final[markOne] = true;



		for (int j = 0; j <= numVertex - 1; j++)
		{
			if (!final[j] && (shorDist[markOne] + matrix[markOne][j] < shorDist[j]))
			{
				shorDist[j] = shorDist[markOne] + matrix[markOne][j];
				pre[j] = markOne;
			}

		}


	}


	return shorDist[finish];


}



template<typename T>
void graphMat<T>::getShorDistWithShorCost(int start, int finish)
{
	float* shorDist = new float[numVertex];//*��start��i�����·����ΪshorDist[i]*//
	float* shorCost = new float[numVertex];
	int* pre = new int[numVertex];// �����Vs��������������·������pre[i] = k����ʾ��Vs ��Vi�����·���У�Vi��ǰһ��������Vk�������·��������(Vs, ��, Vk, Vi) ��
	bool* final = new bool[numVertex];// ��ʶһ�������Ƿ��Ѽ���S�С�

	//���������ݽ��г�ʼ��
	for (int i = 0; i <= numVertex; i++)
	{
		shorDist[i] = matrix[start][i]; shorCost[i] = matrixCost[start][i];
		pre[i] = start;
		final[i] = false;//����S��

	}
	shorDist[start] = 0; shorCost[start] = 0;//start���Լ�����Ϊ��Ϊ0
	final[start] = true;//start��S��

	//*******************************


	for (int i = 0; i <= numVertex - 2; i++)
	{//ÿ��ѭ��ʹһ���������S

		float minDistance = infinite;
		int markOne = -1;

		for (int k = 0; k <= numVertex - 1; k++)
		{//�ҵ���ʱ�յ㲻��S��,��·����С�ı� start->k
			if (final[k] == false && shorDist[k] < minDistance)
			{
				markOne = k;
				minDistance = shorDist[k];
			}
		}


		final[markOne] = true;


		for (int j = 0; j <= numVertex - 1; j++)
		{
			if (!final[j] && (shorDist[markOne] + matrix[markOne][j] < shorDist[j]))
			{
				shorDist[j] = shorDist[markOne] + matrix[markOne][j]; shorCost[j] = shorCost[markOne] + matrixCost[markOne][j];
				pre[j] = markOne;
			}
			else if (!final[j] && (shorDist[markOne] + matrix[markOne][j] == shorDist[j]))
			{
				if (shorCost[j] <= shorCost[markOne] + matrixCost[markOne][j])
				{//ԭ,cost��С�����

					//�����޸�

				}
				else
				{//��,cost��С

					shorDist[j] = shorDist[markOne] + matrix[markOne][j]; shorCost[j] = shorCost[markOne] + matrixCost[markOne][j];
					pre[j] = markOne;


				}
			}
		}
	}
	cout << endl << shorDist[finish] << ' ' << shorCost[finish];

}