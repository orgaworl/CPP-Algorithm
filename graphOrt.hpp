#pragma once
#include<iostream>
#include<queue>
using namespace std;

#define infinite 2887
//const float infinite = -1;
//边
struct edgeEle
{
	
	float weight = infinite;
	int tailVertex = -1;//弧尾，即起点
	int headVertex = -1;//弧头，即终点
	edgeEle* tailNextArc = NULL;//下一条和当前弧起点相同的弧，例如2->3 to 2->4 to2->5      -   //next same tail Arc
	edgeEle* headNextArc = NULL;//下一条和当前弧终点相同的弧,例如2->3 to 3->3 to 4->3     |   //next same head Arc

};
//顶点
template<typename T>
struct vertexEle
{
	T date ;
	edgeEle* firstOutArc = NULL;
	edgeEle* firstInArc = NULL;
	

};
template<typename T>
class graphOrt
{
private:
	int numVertex;
	vertexEle<T>* list;


public:
	graphOrt(int);
	~graphOrt();
	bool insertListHead(edgeEle* edge, bool isRow,int ordinal);
	bool unweiMatToOri(int **matrix,int numVertex,graphOrt&graph);//只对传入的十字链表修改
	
	bool unweiMatToOri(float** matrix, int numVertex, graphOrt& graph);
	void showAll();
	void showDate(int ordinal);
	bool setDate(int ordinal, T date);

	vertexEle<T>* getVertexList();
	void depthFirst(int v, int* isVisted);
	void depthFirst();
	void breadthFirst(int v, int* isVisted,queue<edgeEle*>&edgeQueue);
	void breadthFirst();
	void setEdge(int row,int col);
	bool getShortestPath(int start, int finish);
};




template<typename T>
graphOrt<T>::graphOrt(int numVertex)
{
	this->list = new vertexEle<T>[numVertex];
	this->numVertex = numVertex;
	/*for (int i=0;i<=numVertex-1;i++)
	{
		list[i].date = i;
	}*/

}

template<typename T>
vertexEle<T>* graphOrt<T>::getVertexList()
{
	return this->list;
}

template<typename T>
graphOrt<T>::~graphOrt()
{
	delete this->list;
	this->list = NULL;

}

template<typename T>
void graphOrt<T>::showAll()
{
	cout << "从左到右" << endl;
	for (int i=0;i<=this->numVertex-1;i++)
	{
		cout << 'V' << i << "\: ";
		if (list[i].firstOutArc==NULL)
		{
			cout << endl;
			continue;
		}

		edgeEle* curPoi = list[i].firstOutArc;
		while (curPoi->tailNextArc!=NULL)
		{
			cout << curPoi->tailVertex << "->"<< curPoi->headVertex <<" weight"<<(float)curPoi->weight << ' ';
			curPoi = curPoi->tailNextArc;
		}
		cout << curPoi->tailVertex << "->"<< curPoi->headVertex << " weight" << curPoi->weight << endl;

	}


	/*cout << "**********************************" << endl;
	cout << "从上到下" << endl;
	for (int i = 0; i <= this->numVertex - 1; i++)
	{
		cout << 'V' << i << "\: ";
		if (list[i].firstInArc == NULL)
		{
			cout << endl;
			continue;
		}
		edgeEle* curPoi = list[i].firstInArc;
		while (curPoi->headNextArc != NULL)
		{
			cout << curPoi->tailVertex << "->" << curPoi->headVertex << " weight" << curPoi->weight<<'  ';
		}
		cout << curPoi->tailVertex << "->" << curPoi->headVertex << " weight " << curPoi->weight << endl;

	}*/


}

template<typename T>
bool graphOrt<T>::insertListHead(edgeEle*edge, bool isRow,int ordinal)//传入new出的边的地址,选择插入的链表种类,选择插入链表的序号
{
	if (ordinal>=this->numVertex||edge==NULL)
	{
		return 0;
	}
	if (isRow==1)
	{
		if (list[ordinal].firstOutArc!=NULL)
		{
			edgeEle* tempPoi = list[ordinal].firstOutArc;
			list[ordinal].firstOutArc = edge;
			edge->tailNextArc = tempPoi;
		}
		else
		{
			list[ordinal].firstOutArc = edge;
		}
	
	}
	else
	{

		if (list[ordinal].firstInArc != NULL)
		{
			edgeEle* tempPoi = list[ordinal].firstInArc;
			list[ordinal].firstInArc = edge;
			edge->headNextArc = tempPoi;
		}
		else
		{
			list[ordinal].firstInArc = edge;
		}

	}
	return 1;
}


template<typename T>
bool graphOrt<T>::unweiMatToOri(int **matrix, int numVertex, graphOrt<T>& graph)
{
	for (int i=numVertex-1;i>=0;i--)
	{//从最后一行到第一行
		for (int j = numVertex - 1; j>= 0; j--)
		{//从最后一列到第一列
			 int weight = matrix[i][j];
			if (weight !=0&& weight !=infinite)
			{

				//先从左往右串
				edgeEle* tempEdge = new edgeEle{ weight,i,j};
				graph.insertListHead(tempEdge, true, i);
				//再从上往下串
				graph.insertListHead(tempEdge, false, j);
			}
			
		}
	}


	return 1;
}
template<typename T>
bool graphOrt<T>::unweiMatToOri(float** matrix, int numVertex, graphOrt<T>& graph)
{
	for (int i = numVertex - 1; i >= 0; i--)
	{//从最后一行到第一行
		for (int j = numVertex - 1; j >= 0; j--)
		{//从最后一列到第一列
			float weight = matrix[i][j];
			if (weight != 0 && weight != infinite)
			{

				//先从左往右串
				edgeEle* tempEdge = new edgeEle{ weight,i,j };
				graph.insertListHead(tempEdge, true, i);
				//再从上往下串
				graph.insertListHead(tempEdge, false, j);
			}

		}
	}


	return 1;
}

template<typename T>
void graphOrt<T>::showDate(int ordinal)
{
	//暂定
	cout << list[ordinal].date;
}

template<typename T>
bool graphOrt<T>::setDate(int ordinal, T date)
{
	list[ordinal].date = date;
	return 1;
}

template<typename T>
void graphOrt<T>::depthFirst(int v,int*isVisted)
{//访问该节点,访问子节点
	showDate(v);
	isVisted[v] = 1;

	edgeEle* curPoi = list[v].firstOutArc;
	if (curPoi == NULL)
	{
		return;
	}
	//假设list[v]存在有关系元素
	while (curPoi->tailNextArc!=NULL)
	{
		if (isVisted[curPoi->headVertex]==0)
		{
			depthFirst(curPoi->headVertex, isVisted);
		}
		curPoi = curPoi->tailNextArc;
	}

	if (isVisted[curPoi->headVertex] == 0)
	{
		depthFirst(curPoi->headVertex, isVisted);
	}


}

template<typename T>
void graphOrt<T>::depthFirst()
{
	int* isVisted = new int[this->numVertex]{0};
	int isAllVisted = 0;
	while (!isAllVisted)
	{
		for (int i = 0; i <= this->numVertex - 1; i++)
		{
			if (isVisted[i]==0)
			{
				this->depthFirst(i, isVisted);
				break;
			}
			if (i== this->numVertex - 1)
			{//循环到最后一次且没break;
				isAllVisted = 1;
			}

		}
	}
	


}
template<typename T>
void graphOrt<T>::breadthFirst(int v, int* isVisted, queue<edgeEle*>& edgeQueue)
{
	if (list[v].firstOutArc == NULL)
	{
		return;
	}
	//将该顶点邻接的所有顶点入队列
	edgeEle* curPoi = list[v].firstOutArc;
	if (isVisted[curPoi->headVertex]==0)
	{
		showDate(curPoi->headVertex);
		isVisted[curPoi->headVertex] = 1;
		edgeQueue.push(curPoi);
	}
	
	while (curPoi->tailNextArc!=NULL)
	{
		curPoi = curPoi->tailNextArc;
		if (isVisted[curPoi->headVertex] == 0)
		{
			showDate(curPoi->headVertex);
			isVisted[curPoi->headVertex] = 1;
			edgeQueue.push(curPoi);
		}
		
	}
	
	//处理队列内元素:
	while (!edgeQueue.empty())
	{//令队列首edge出队列访问顶点list[tail],后将tail邻接顶点(未被访问)入队列
		edgeEle* tempEdge = edgeQueue.front();
		edgeQueue.pop();
		





		//出队列点的相邻点,先访问后入队列
		if (list[tempEdge->headVertex].firstOutArc==NULL)
		{
			continue;
		}


		curPoi = list[tempEdge->headVertex].firstOutArc;//指针指向出队列的edge
		
		if (isVisted[curPoi->headVertex] == 0)
		{
			//todo
			edgeQueue.push(curPoi);
		}

		while (curPoi->tailNextArc != NULL)
		{
			if (isVisted[curPoi->tailNextArc->headVertex] == 0)
			{
				//todo
				edgeQueue.push(curPoi->tailNextArc);
			}
			curPoi = curPoi->tailNextArc;
		}


	}
	
	








}


template<typename T>
void graphOrt<T>::breadthFirst()
{//用到stl的队列;
	
	queue<edgeEle*>edgeQueue;


	int* isVisted = new int[this->numVertex]{ 0 };
	int isAllVisted = 0;



	while (!isAllVisted)
	{
		for (int i = 0; i <= this->numVertex - 1; i++)
		{
			if (isVisted[i] == 0)
			{
				showDate(i);
				isVisted[i] = 1;
				this->breadthFirst(i, isVisted, edgeQueue);
				break;
			}
			if (i == this->numVertex - 1)
			{//循环到最后一次且没break;
				isAllVisted = 1;
			}

		}
	}




}

template<typename T>
void graphOrt<T>::setEdge(int row, int col)
{
	edgeEle *edge=new edgeEle{ infinite ,row,col };
	if (list[row].firstOutArc==NULL)
	{
		
		this->insertListHead(edge,1,row);
	}
	else
	{
		edgeEle* curPoi = list[row].firstOutArc;
		if (curPoi->tailNextArc == NULL)
		{
			if (curPoi->headVertex > row)
			{
				this->insertListHead(edge, 1, row);
			}
			else if (curPoi->headVertex < row)
			{
				curPoi->tailNextArc = edge;;
			}
			else if (curPoi->headVertex == row)
			{
				return;
			}
		}
		else 
		{
			while (curPoi->tailNextArc!=NULL)
			{
				if (curPoi->headVertex<row&&curPoi->tailNextArc->headVertex>row)
				{

					edge->tailNextArc = curPoi->tailNextArc;
					curPoi->tailNextArc = edge;
					break;
				}
				else {
					curPoi = curPoi->tailNextArc;
				}


			}
			//////////////////////

			//若直到最后都找不到;




		}
		
		






	}









}

