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



//1.1 ��������
template<typename T>
bool sortInsert(T* arr, int num, int delta = 1)//ͨ�ò�������,Ĭ�ϼ�Ϊһ���������
{
	//��һ����¼�������

	for (int curRecord = delta; curRecord < num; curRecord += delta)
	{//�ӵڶ�����¼��ʼ�����һ����¼,���β�������������

		//������������������пɲ���λ��
		for (int j = curRecord; j >= delta; j -= delta)
		{
			if (arr[j] < arr[j - delta])
			{
				swap(arr, j, j - delta);
			}
			else
			{//����ǰ��¼�����������¼�����һ��,��������Ϊ�������
				//���ڵ����Ҳ������
				break;
			}

		}

	}

	return 1;



}


//1.2 shell����
template<typename T>
bool sortShell(T*arr, int numArr)
{

	for(int delta=numArr/ INCREMENT_DIVISION; delta >=1; delta /= INCREMENT_DIVISION)
	{//�����ɴ�С
		for (int j=0;j<delta;j++)
		{//�����ǰ����
			sortInsert(&arr[j], numArr-j, delta);//����ǰ���� ��ǰ����� ���� 
			//numArr-i����Ӹ������еļ�¼����(���������)
		}
		
	}
	return 1;

}



//1.3ֱ��ѡ������




//1.4������
template<typename T>
bool shiftDown(T* heap,int pos,int curSize)
{//��pos����������Ϊ��ʱ,��pos shiftDown���ʹ��������ɶ�

	if (pos < 0 || pos >= curSize)
	{//���ڵ�������ų�
		return 0;
	}
	else if (pos >= curSize / 2)
	{//Ҷ�ڵ�������в���
		return 1;
	}


	T temp = heap[pos];//�����λ����ֵ
	int curPos = pos;
	int toCompare = curPos * 2 + 1;//��ڵ� //����һ��cur��������һ��toCompare
	while (toCompare < curSize)
	{



		if (toCompare + 1 < curSize && heap[toCompare] < heap[toCompare + 1])
		{//���ӽڵ���������ӽڵ��С,���ȽϽڵ������л�����
			toCompare++;
		}
		if (temp < heap[toCompare])
		{//���滻
			heap[curPos] = heap[toCompare];//�ϱ��¸���
			curPos = toCompare;
			toCompare = curPos * 2 + 1;
		}
		else if (temp > heap[toCompare])
		{//������
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



//1.5ð������






//1.6��������
template<typename T>
bool sortQuick(T* arr, int start ,int finish,bool isRandom=1)
{
	if (start>=finish||finish<=0||start<0)
	{
		return 1;

	}

	//1.ѡ��ֵ
	int posAxis;
	if (isRandom==1)
	{//���ֵ����ֵ
		srand((unsigned int)time(NULL));
		posAxis = rand() % (finish - start + 1) + start;;
	}
	else if (isRandom==0)
	{//��ֵ����ֵ
		posAxis = start;
	}
	else
	{
		return 0;
	}
	
	//cout << "��ֵΪ" << posAxis << "λ����" << arr[posAxis]<<"    ";

	T valueAxis=arr[posAxis];//������ֵ

	int posL = start;
	int posR = finish;
	int posE = posAxis;

	//2.�ָ�
	if (posR!=posE)
	{
		swap(arr, posR, posE);
		posE = posR;
		posR--;//�����һ����䵽��λ,ʹ���λ��Ϊ��
	}
	

	bool LorR=1;
	while (posL<=posR)//һ��ѭ����������ν���
	{
		if (LorR == 1)
		{//�ұ��п�λ��,���������Ҵ�����ֵ��¼
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
		{//����п�λ��,����������С�ڵ�����ֵ��¼
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










//2.1 �û�ѡ������
template<typename T>
bool permutationSelectionSort(T*keyArray,int keyArrayLength,int maxSize)
{
	
	minHeap<int>heap(maxSize);//���3
	
	int validSize = maxSize;//��Чλ��
	T final = 0;

	//�Ƚ�������
	for (int i = 0; i < maxSize; i++)
	{
		heap.addNode(keyArray[i]);
	}
	heap.buildHeap(validSize);

	//keyֵ����ʣ��length-maxSize��keyֵ,ȫ������С��
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

	//keyֵȫ����������С��,����С��������maxSize���ڵ�
	while (heap.getCurSize()!=0)
	{

		if (validSize == 0)
		{
			cout << endl;
			validSize = maxSize;
			heap.buildHeap(validSize);
		}

		final = heap.removeMin();//�Դ�����
		cout << final << ' ';

		
		//heap.buildHeap(validSize);
	}


	cout << endl;


	return 1;
}



//��������ʼ��
template<typename T>
bool buildLoserTree(int *interArr,T*leafArr,int k)
{
	for (int i = k - 1; i >= k / 2; i--)
	{//��ʼ���ڲ��ڵ�

		int leftLeaf = (i - (k / 2)) * 2;
		int rightLeaf = (i - (k / 2)) * 2 + 1;
		int finalLoser = -1;//���±�


		interArr[i] = leafArr[leftLeaf] >= leafArr[rightLeaf] ? leftLeaf : rightLeaf;
		finalLoser = leafArr[leftLeaf] < leafArr[rightLeaf] ? leftLeaf : rightLeaf;
		int parent = i / 2;
		while (parent != 0)
		{
			if (interArr[parent] == -1)
			{//�����Ƚ�
				interArr[parent] = finalLoser;
				finalLoser = -1;
				break;
			}
			else
			{//�����Ƚ�
				int tempWiner = leafArr[interArr[parent]] >= leafArr[finalLoser] ? interArr[parent] : finalLoser;
				finalLoser = leafArr[interArr[parent]] < leafArr[finalLoser] ? interArr[parent] : finalLoser;
				interArr[parent] = tempWiner;

			}
			parent /= 2;
		}

		if (parent == 0 && finalLoser != -1)
		{
			if (interArr[parent] == -1)
			{//�����Ƚ�
				interArr[parent] = finalLoser;
				finalLoser = -1;
			}
			else
			{
				cout << "����" << endl;

			}
		}
	}
	return 1;

}


//�����ֵ��������������
template<typename T>
bool orderingLoserTree(int* interArr, T* leafArr, int k, int pos)//posΪҶ��������ֵλ��
{

	int finalLoser = -1;//���±�
	int parent = pos / 2 + k / 2;//5



	interArr[parent] = leafArr[pos] >= leafArr[broNode(pos)] ? pos : broNode(pos);
	finalLoser = leafArr[pos] < leafArr[broNode(pos)] ? pos : broNode(pos);
	
	parent /= 2;//2


	while (parent != 0)
	{
		if (interArr[parent] == -1)
		{//�����Ƚ�
			interArr[parent] = finalLoser;
			finalLoser = -1;
			break;
		}
		else
		{//�����Ƚ�
			int tempWiner = leafArr[interArr[parent]] >= leafArr[finalLoser] ? interArr[parent] : finalLoser;
			finalLoser = leafArr[interArr[parent]] < leafArr[finalLoser] ? interArr[parent] : finalLoser;
			interArr[parent] = tempWiner;

		}
		parent /= 2;
	}

	if (parent == 0 && finalLoser != -1)
	{
		if (interArr[parent] == -1)
		{//�����Ƚ�
			interArr[parent] = finalLoser;
			finalLoser = -1;
		}
		else
		{
			cout <<"����"<< endl;
		}
		
	}




	return 1;

}

//2.3 k-·����
template<typename T>
bool kWayMergeSort(int k)
{
	const int largeNumber = 2887;
	int *Size =new int[k]{0};
	T** sequence=new T*[k];

	for (int i=0;i<k;i++)
	{
		
		cout << "��" << i+1 << "·������;  " ;
		cin >> Size[i]; 
		sequence[i] = new T[Size[i]+1];//��С����1

		for (int j=0;j<Size[i];j++)
		{
			cin >> sequence[i][j];
		}
		sequence[i][Size[i]] = largeNumber;//��һ������β
	}

	
	int* curPos = new int[k];//ÿ�����н��е���λ��
	T* leafArr = new T[k];//Ҷ�ڵ�,��keyֵ
	int* interArr = new int[k] ;//�ڲ��ڵ�͹ھ��ڵ�,���±�
	
	
	
	for (int i=0;i<k;i++)
	{
		curPos[i] = 0;
		leafArr[i] = sequence[i][curPos[i]];
		interArr[i] = -1;
		
	}
	cout << endl;


	//��ʼ��������
	buildLoserTree(interArr,leafArr,k);






	/*showArr(interArr, k); cout << endl;
	showArr(leafArr,k);

	cout << endl<<"---------------------------------------"<<endl;*/





	while (leafArr[interArr[0]] != largeNumber)//ֻʣ��ֵ
	{int posM= interArr[0];


		//ȡ����ֵ
		cout << leafArr[posM] << " ";
		
		//������ֵ
		curPos[posM]++;
		leafArr[posM] = sequence[posM][curPos[posM]];
		

		interArr[0] = -1;
	   //���������ֵ��İ���������
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
