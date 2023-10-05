#include<iostream>
#include"Ex_14.h"
#include"sort.hpp"



void Ex_14_T1()
{

	int length = 9;
	int maxSize = 0;

	int* keyArray = new int[length];
	for (int i = 0; i < length; i++)
	{
		cin >> keyArray[i];

	}
	cin >> maxSize;

	permutationSelectionSort(keyArray, length, maxSize);







}

void Ex_14_T2()
{
	kWayMergeSort<int>(8);

	cout << endl << endl << endl;
}