#pragma once
#include<iostream>
#include<queue>
using namespace std;

#define infinite 2887
//const float infinite = -1;
//��
struct edgeEle
{
	
	float weight = infinite;
	int tailVertex = -1;//��β�������
	int headVertex = -1;//��ͷ�����յ�
	edgeEle* tailNextArc = NULL;//��һ���͵�ǰ�������ͬ�Ļ�������2->3 to 2->4 to2->5      -   //next same tail Arc
	edgeEle* headNextArc = NULL;//��һ���͵�ǰ���յ���ͬ�Ļ�,����2->3 to 3->3 to 4->3     |   //next same head Arc

};
//����
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
	bool unweiMatToOri(int **matrix,int numVertex,graphOrt&graph);//ֻ�Դ����ʮ�������޸�
	
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
	cout << "������" << endl;
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
	cout << "���ϵ���" << endl;
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
bool graphOrt<T>::insertListHead(edgeEle*edge, bool isRow,int ordinal)//����new���ıߵĵ�ַ,ѡ��������������,ѡ�������������
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
	{//�����һ�е���һ��
		for (int j = numVertex - 1; j>= 0; j--)
		{//�����һ�е���һ��
			 int weight = matrix[i][j];
			if (weight !=0&& weight !=infinite)
			{

				//�ȴ������Ҵ�
				edgeEle* tempEdge = new edgeEle{ weight,i,j};
				graph.insertListHead(tempEdge, true, i);
				//�ٴ������´�
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
	{//�����һ�е���һ��
		for (int j = numVertex - 1; j >= 0; j--)
		{//�����һ�е���һ��
			float weight = matrix[i][j];
			if (weight != 0 && weight != infinite)
			{

				//�ȴ������Ҵ�
				edgeEle* tempEdge = new edgeEle{ weight,i,j };
				graph.insertListHead(tempEdge, true, i);
				//�ٴ������´�
				graph.insertListHead(tempEdge, false, j);
			}

		}
	}


	return 1;
}

template<typename T>
void graphOrt<T>::showDate(int ordinal)
{
	//�ݶ�
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
{//���ʸýڵ�,�����ӽڵ�
	showDate(v);
	isVisted[v] = 1;

	edgeEle* curPoi = list[v].firstOutArc;
	if (curPoi == NULL)
	{
		return;
	}
	//����list[v]�����й�ϵԪ��
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
			{//ѭ�������һ����ûbreak;
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
	//���ö����ڽӵ����ж��������
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
	
	//���������Ԫ��:
	while (!edgeQueue.empty())
	{//�������edge�����з��ʶ���list[tail],��tail�ڽӶ���(δ������)�����
		edgeEle* tempEdge = edgeQueue.front();
		edgeQueue.pop();
		





		//�����е�����ڵ�,�ȷ��ʺ������
		if (list[tempEdge->headVertex].firstOutArc==NULL)
		{
			continue;
		}


		curPoi = list[tempEdge->headVertex].firstOutArc;//ָ��ָ������е�edge
		
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
{//�õ�stl�Ķ���;
	
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
			{//ѭ�������һ����ûbreak;
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

			//��ֱ������Ҳ���;




		}
		
		






	}









}

