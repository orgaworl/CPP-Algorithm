#include<iostream>

#pragma once
#include<list>
#define INCREMENT_DIVISION 2
#include <stdlib.h>
#include"minHeap.hpp"

using namespace std;

static int broNode(int pos)
{
	return pos % 2 ? pos - 1 : pos + 1;
}


template<typename T>
bool showArr(T* arr, int lengthArr)
{
	for (int i = 0; i < lengthArr; i++)
	{
		cout << arr[i] << ' ';
	}
	
	return 1;
}

template<typename T>
bool showArr(T* arr, int start,int finish)
{
	for (int i = start; i <=finish; i++)
	{
		cout << arr[i] << ' ';
	}
	
	return 1;
}

template<typename T>
bool swap(T* arr, int num1, int num2)
{
	T temp = arr[num2];
	arr[num2] = arr[num1];
	arr[num1] = temp;

	return 1;
}



//1.1 插入排序
template<typename T>
bool sortInsert(T* arr, int num, int delta = 1)//通用插入排序,默认即为一般插入排序
{
	//第一个记录无需操作

	for (int curRecord = delta; curRecord < num; curRecord += delta)
	{//从第二个记录开始到最后一个记录,依次插入已排序序列

		//倒序查找已排序序列中可插入位置
		for (int j = curRecord; j >= delta; j -= delta)
		{
			if (arr[j] < arr[j - delta])
			{
				swap(arr, j, j - delta);
			}
			else
			{//当当前记录大于已排序记录中最后一个,不操作即为完成排列
				//等于的情况也不操作
				break;
			}

		}

	}

	return 1;



}


//1.2 shell排序
template<typename T>
bool sortShell(T*arr, int numArr)
{

	for(int delta=numArr/ INCREMENT_DIVISION; delta >=1; delta /= INCREMENT_DIVISION)
	{//步长由大到小
		for (int j=0;j<delta;j++)
		{//组别由前到后
			sortInsert(&arr[j], numArr-j, delta);//处理当前步长 当前组别下 该组 
			//numArr-i代表从该组所有的记录数量(包含跨过的)
		}
		
	}
	return 1;

}



//1.3直接选择排序




//1.4堆排序
template<typename T>
bool shiftDown(T* heap,int pos,int curSize)
{//当pos左右子树都为堆时,令pos shiftDown则可使整个树变成堆

	if (pos < 0 || pos >= curSize)
	{//根节点情况不排除
		return 0;
	}
	else if (pos >= curSize / 2)
	{//叶节点无需进行操作
		return 1;
	}


	T temp = heap[pos];//保存该位置数值
	int curPos = pos;
	int toCompare = curPos * 2 + 1;//左节点 //重设一遍cur则须重设一次toCompare
	while (toCompare < curSize)
	{



		if (toCompare + 1 < curSize && heap[toCompare] < heap[toCompare + 1])
		{//右子节点存在且右子节点更小,待比较节点又左切换到右
			toCompare++;
		}
		if (temp < heap[toCompare])
		{//若替换
			heap[curPos] = heap[toCompare];//上被下覆盖
			curPos = toCompare;
			toCompare = curPos * 2 + 1;
		}
		else if (temp > heap[toCompare])
		{//若不变
			break;
		}

	}

	heap[curPos] = temp;
	return 1;
}

template<typename T>
bool buildHeap(T *heap,int curSize)
{
	for (int i = curSize / 2 - 1; i >= 0; i--)
	{
		shiftDown(heap,i,curSize);

	}
	return 1;
}

template<typename T>
bool sortHeap(T*arr,int numArr)
{






}



//1.5冒泡排序






//1.6快速排序
template<typename T>
bool sortQuick(T* arr, int start ,int finish,bool isRandom=1)
{
	if (start>=finish||finish<=0||start<0)
	{
		return 1;

	}

	//1.选轴值
	int posAxis;
	if (isRandom==1)
	{//随机值做轴值
		srand((unsigned int)time(NULL));
		posAxis = rand() % (finish - start + 1) + start;;
	}
	else if (isRandom==0)
	{//左值做轴值
		posAxis = start;
	}
	else
	{
		return 0;
	}
	
	//cout << "轴值为" << posAxis << "位置上" << arr[posAxis]<<"    ";

	T valueAxis=arr[posAxis];//保存轴值

	int posL = start;
	int posR = finish;
	int posE = posAxis;

	//2.分割
	if (posR!=posE)
	{
		swap(arr, posR, posE);
		posE = posR;
		posR--;//将最后一个填充到空位,使最后位置为空
	}
	

	bool LorR=1;
	while (posL<=posR)//一次循环中完成两次交换
	{
		if (LorR == 1)
		{//右边有空位置,从左往右找大于轴值记录
			while (arr[posL] <= valueAxis)
			{
				posL++;
				if (posL == posE)
				{
					break;
				}
			}

			if (posL<posR)
			{
				arr[posE] = arr[posL];
				posE = posL;
				posL++;
			}
			else if (posL==posR)
			{
				arr[posE] = arr[posL];
				posE = posL;


			}
		
		}
		else if (LorR==0)
		{//左边有空位置,从右往左找小于等于轴值记录
			while (arr[posR] > valueAxis)
			{
				posR--;
				if (posR==posE)
				{
					break;
				}
			}

			if (posL < posR)
			{
				arr[posE] = arr[posR];

				posE = posR;
				posR--;
			}
			else if (posL == posR)
			{
				arr[posE] = arr[posR];
				posE = posR;


			}

		}
		LorR = !LorR;

	}

	arr[posE] = valueAxis;
	sortQuick(arr,start,posE-1);
	sortQuick(arr,posE +1,finish);

	
	return 1;

}










//2.1 置换选择排序
template<typename T>
bool permutationSelectionSort(T*keyArray,int keyArrayLength,int maxSize)
{
	
	minHeap<int>heap(maxSize);//最大3
	
	int validSize = maxSize;//有效位置
	T final = 0;

	//先将堆填满
	for (int i = 0; i < maxSize; i++)
	{
		heap.addNode(keyArray[i]);
	}
	heap.buildHeap(validSize);

	//key值队列剩下length-maxSize个key值,全部入最小堆
	for (int i=maxSize;i<keyArrayLength;i++)
	{
		if (validSize==0)
		{
			cout << endl;
			validSize = maxSize;
			heap.buildHeap(validSize);
		}

		final = heap.getMin();
		cout << final<<' ';
		if(keyArray[i]>final)
		{ 
			heap.replaceMin(keyArray[i]);
		}
		else
		{

			heap.replaceMin(heap.getHeap()[validSize-1]);
			heap.getHeap()[int(validSize - 1)] = keyArray[i];
			validSize--;

		}
		heap.buildHeap(validSize);

	}

	//key值全都进入了最小堆,但最小堆中仍有maxSize个节点
	while (heap.getCurSize()!=0)
	{

		if (validSize == 0)
		{
			cout << endl;
			validSize = maxSize;
			heap.buildHeap(validSize);
		}

		final = heap.removeMin();//自带整理
		cout << final << ' ';

		
		//heap.buildHeap(validSize);
	}


	cout << endl;


	return 1;
}



//败者树初始化
template<typename T>
bool buildLoserTree(int *interArr,T*leafArr,int k)
{
	for (int i = k - 1; i >= k / 2; i--)
	{//初始化内部节点

		int leftLeaf = (i - (k / 2)) * 2;
		int rightLeaf = (i - (k / 2)) * 2 + 1;
		int finalLoser = -1;//存下标


		interArr[i] = leafArr[leftLeaf] >= leafArr[rightLeaf] ? leftLeaf : rightLeaf;
		finalLoser = leafArr[leftLeaf] < leafArr[rightLeaf] ? leftLeaf : rightLeaf;
		int parent = i / 2;
		while (parent != 0)
		{
			if (interArr[parent] == -1)
			{//结束比较
				interArr[parent] = finalLoser;
				finalLoser = -1;
				break;
			}
			else
			{//继续比较
				int tempWiner = leafArr[interArr[parent]] >= leafArr[finalLoser] ? interArr[parent] : finalLoser;
				finalLoser = leafArr[interArr[parent]] < leafArr[finalLoser] ? interArr[parent] : finalLoser;
				interArr[parent] = tempWiner;

			}
			parent /= 2;
		}

		if (parent == 0 && finalLoser != -1)
		{
			if (interArr[parent] == -1)
			{//结束比较
				interArr[parent] = finalLoser;
				finalLoser = -1;
			}
			else
			{
				cout << "错误" << endl;

			}
		}
	}
	return 1;

}


//添加新值败者树重新有序化
template<typename T>
bool orderingLoserTree(int* interArr, T* leafArr, int k, int pos)//pos为叶数组中最值位置
{

	int finalLoser = -1;//存下标
	int parent = pos / 2 + k / 2;//5



	interArr[parent] = leafArr[pos] >= leafArr[broNode(pos)] ? pos : broNode(pos);
	finalLoser = leafArr[pos] < leafArr[broNode(pos)] ? pos : broNode(pos);
	
	parent /= 2;//2


	while (parent != 0)
	{
		if (interArr[parent] == -1)
		{//结束比较
			interArr[parent] = finalLoser;
			finalLoser = -1;
			break;
		}
		else
		{//继续比较
			int tempWiner = leafArr[interArr[parent]] >= leafArr[finalLoser] ? interArr[parent] : finalLoser;
			finalLoser = leafArr[interArr[parent]] < leafArr[finalLoser] ? interArr[parent] : finalLoser;
			interArr[parent] = tempWiner;

		}
		parent /= 2;
	}

	if (parent == 0 && finalLoser != -1)
	{
		if (interArr[parent] == -1)
		{//结束比较
			interArr[parent] = finalLoser;
			finalLoser = -1;
		}
		else
		{
			cout <<"错误"<< endl;
		}
		
	}




	return 1;

}

//2.3 k-路排序
template<typename T>
bool kWayMergeSort(int k)
{
	const int largeNumber = 2887;
	int *Size =new int[k]{0};
	T** sequence=new T*[k];

	for (int i=0;i<k;i++)
	{
		
		cout << "第" << i+1 << "路子序列;  " ;
		cin >> Size[i]; 
		sequence[i] = new T[Size[i]+1];//大小增加1

		for (int j=0;j<Size[i];j++)
		{
			cin >> sequence[i][j];
		}
		sequence[i][Size[i]] = largeNumber;//多一个做结尾
	}

	
	int* curPos = new int[k];//每个序列进行到的位置
	T* leafArr = new T[k];//叶节点,存key值
	int* interArr = new int[k] ;//内部节点和冠军节点,存下标
	
	
	
	for (int i=0;i<k;i++)
	{
		curPos[i] = 0;
		leafArr[i] = sequence[i][curPos[i]];
		interArr[i] = -1;
		
	}
	cout << endl;


	//初始化填满树
	buildLoserTree(interArr,leafArr,k);






	/*showArr(interArr, k); cout << endl;
	showArr(leafArr,k);

	cout << endl<<"---------------------------------------"<<endl;*/





	while (leafArr[interArr[0]] != largeNumber)//只剩大值
	{int posM= interArr[0];


		//取出最值
		cout << leafArr[posM] << " ";
		
		//更换新值
		curPos[posM]++;
		leafArr[posM] = sequence[posM][curPos[posM]];
		

		interArr[0] = -1;
	   //将补充后新值后的败者树有序化
		orderingLoserTree(interArr, leafArr, k, posM);
		

		/*showArr(interArr, k); cout << endl;
		showArr(leafArr, k);
		cout <<endl<< "---------------------------------------"<<endl;*/
	}
	

	



	cout << endl;


	/*for (int i = 0; i < k; i++)
	{
		cout << interArr[i] << ' ';
	}cout << endl;
	for (int i = 0; i < k; i++)
	{
		cout << leafArr[interArr[i]] << ' ';
	}cout << endl;*/






	return 1;


}



template<typename T>
void testFunc(int num1 ,int num2)
{

}
