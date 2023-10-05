
#include<iostream>
#include"graphMat.hpp"
using namespace std;
float infinite = 99;



template<typename T>
float graphMat<T>::getShorDist(int start, int finish)
{
	//Dijkstra算法


	float* shorDist = new float[numVertex];//从start到i的最短路径即为shorDist[i]
	int* pre = new int[numVertex];// 保存从Vs到其它顶点的最短路径。若pre[i] = k，表示从Vs 到Vi的最短路径中，Vi的前一个顶点是Vk，即最短路径序列是(Vs, …, Vk, Vi) 。
	bool* final = new bool[numVertex];// 标识一个顶点是否已加入S中。
	float max = 0;

	for (int i = 0; i <= numVertex; i++)
	{
		shorDist[i] = matrix[start][i];
		pre[i] = start;
		final[i] = false;//不在S中

	}
	shorDist[start] = 0;//start与自己距离为设为0
	final[start] = true;//start在S中

	//*******************************

	for (int i = 0; i <= numVertex - 2; i++)
	{//每次循环使一个顶点进入S

		float minDistance = infinite;
		int markOne = -1;

		for (int k = 0; k <= numVertex - 1; k++)
		{//找到此时终点不在S中,且路径最小的边 start->k
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
	float* shorDist = new float[numVertex];//*从start到i的最短路径即为shorDist[i]*//
	float* shorCost = new float[numVertex];
	int* pre = new int[numVertex];// 保存从Vs到其它顶点的最短路径。若pre[i] = k，表示从Vs 到Vi的最短路径中，Vi的前一个顶点是Vk，即最短路径序列是(Vs, …, Vk, Vi) 。
	bool* final = new bool[numVertex];// 标识一个顶点是否已加入S中。

	//对设置数据进行初始化
	for (int i = 0; i <= numVertex; i++)
	{
		shorDist[i] = matrix[start][i]; shorCost[i] = matrixCost[start][i];
		pre[i] = start;
		final[i] = false;//不在S中

	}
	shorDist[start] = 0; shorCost[start] = 0;//start与自己距离为设为0
	final[start] = true;//start在S中

	//*******************************


	for (int i = 0; i <= numVertex - 2; i++)
	{//每次循环使一个顶点进入S

		float minDistance = infinite;
		int markOne = -1;

		for (int k = 0; k <= numVertex - 1; k++)
		{//找到此时终点不在S中,且路径最小的边 start->k
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
				{//原,cost更小或相等

					//不做修改

				}
				else
				{//新,cost更小

					shorDist[j] = shorDist[markOne] + matrix[markOne][j]; shorCost[j] = shorCost[markOne] + matrixCost[markOne][j];
					pre[j] = markOne;


				}
			}
		}
	}
	cout << endl << shorDist[finish] << ' ' << shorCost[finish];

}