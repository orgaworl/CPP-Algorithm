#include<iostream>
#include"graphOrt.hpp"
using namespace std;

void Ex_10()
{
	graphOrt graph(4);

	int** matrix = new int* [4];
	for (int i = 0; i <= 3; i++)
	{
		matrix[i] = new int[4]{ 0 };
	}

	matrix[0][1] = 1;
	matrix[0][2] = 1;

	matrix[2][0] = 1;
	matrix[2][3] = 1;

	matrix[3][0] = 1;
	matrix[3][1] = 1;
	matrix[3][2] = 1;

	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{

			cout << matrix[i][j] << ' ';

		}
		cout << endl;
	}

	cout << endl;

	graph.unweiMatToOri(matrix, 4, graph);
	graph.showAll();


}


void Ex_10e()
{
	int N;
	int M;
	cin >> N; cin >> M;
	int temp1 = -1, temp2 = -1;
	int* timesFail = new int[N] {0};


	graphMat<int> graph(N);
	for (int i = 0; i <= M - 1; i++)
	{
		cin >> temp1; cin >> temp2;//若有n个人,则输入需保证在[0,n-1]内
		//arr[temp1] = temp2;
		graph.setEdge(temp1, temp2);//胜者指向败者
		timesFail[temp2] += 1;
	}


	graphOrt<int> graphO(N);
	graphO.unweiMatToOri(graph.getMatrix(), N, graphO);

	graphO.breadthFirst();














	/*int**m=graph.getTransitiveMatrix(graph.getMatrix(),N);
	for (int i=0;i<=N-1;i++)
	{
		for (int j = 0; j <= N - 1; j++)
		{
			cout << m[i][j]<<' ';
		}
		cout << endl;

	}*/


}
