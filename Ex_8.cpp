#include"forest.hpp"
#include<iostream>

void test_forest()
{
	//��������
	//0 1 4 -1 5 -1 6 -1 -1 2 -1 3 -1 -1 -1
	//0 1 - 1 2 - 1 - 1 - 1
	//0 1 4 - 1 5 - 1 6 - 1 - 1 2 - 1 3 - 1 - 1 - 1

	forest<int> f;
	cout << "��������ڵ�ֵ" << endl;
	f.CreateForest(f.getRoot());
	system("cls");

	cout << "ǰ������" << endl;
	f.preRootOrderRecursion(f.getRoot());

	cout << endl << "�������" << endl;
	f.postRootOrderRecursion(f.getRoot());



	cout << endl << endl << "Ҷ�ڵ����Ϊ" << f.countLeafR(f.getRoot()) << endl;


	cout << endl << "�߶�Ϊ" << f.countHeightR(f.getRoot()) << endl;


}