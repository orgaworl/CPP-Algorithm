//最小生成树

#include<iostream>
#include"graphMat.hpp"
using namespace std;


template<typename T>
int Prim(graphMat<T> graph)
{




	cout<<"prim solve min creat tree"<<endl;



	//1
	Selected[k]=1;
	for(int i=0;i<n:i++){
		if(selected[i]==0&&graph[k,i]<minDist[i]){
			minDist[i]=graph[k,i];
			parent[i]=k;
		}
	}



	//2
	int minNode=0;
	int minWeight=infinity;
	for(int i=0;i<n:i++)
	{
		if(selected[i]==0&&parent[i]!=-1&&minDist[i]<minWeight)
		{
			minNode=i;
			minWeight=minDist[i];
		}
	}





	




	return 1;

}
