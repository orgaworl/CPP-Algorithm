
#include<iostream>


using namespace std;

template<typename T>
int sequentialSearch() {




	return 1;
}


template<typename T>
int binSearch(T*list,int listLength,T toSearch)
{
	int leftPoi=0;
	int rightPoi = listLength - 1;

	if (list[leftPoi]==toSearch)
	{
		return leftPoi;
	}
	if (list[rightPoi] == toSearch)
	{
		return rightPoi;
	}


	
	while (list[(leftPoi+rightPoi)/2]!=toSearch&&leftPoi!=rightPoi)
	{
		if (list[(leftPoi + rightPoi) / 2]< toSearch)
		{
			leftPoi = ((leftPoi + rightPoi) / 2);
		}
		else if (list[(leftPoi + rightPoi) / 2] > toSearch)
		{
			rightPoi = ((leftPoi + rightPoi) / 2);
		}




	}
	if (list[(leftPoi + rightPoi) / 2] = toSearch)
	{
		return (leftPoi + rightPoi) / 2;
	}
	else {
		return -1;
	}

	

}



template<typename T>
int blockSearch() {


	return 1;
}



template<typename T>
int hashFunc(T key,int length)
{
	//ʵ�ֹؼ���ֵ��ɢ�е�ַ��ת��
	
	//���෨  x%LENGTH
	//
	//

	return key % length;


}



int openHash()
{
	
	//��������ɢ�б���ÿ���۶���һ�������ͷ
	//Ͳʽɢ�У�
	


	return 1;
}
int closeHash()
{



	return 1;

}

template<typename T>
int hash()
{
	int hashTableLength = 0;
	cin >> hashTableLength;
	T** hashTable = new T* [hashTableLength];//ɢ�б�,ɢ�е�ַ��Ϊ�����±�
	//�ؼ����Ϊ���͡��ַ�����










}
