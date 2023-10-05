#include"forest.hpp"
#include<iostream>

void test_forest()
{
	//测试样例
	//0 1 4 -1 5 -1 6 -1 -1 2 -1 3 -1 -1 -1
	//0 1 - 1 2 - 1 - 1 - 1
	//0 1 4 - 1 5 - 1 6 - 1 - 1 2 - 1 3 - 1 - 1 - 1

	forest<int> f;
	cout << "请输入根节点值" << endl;
	f.CreateForest(f.getRoot());
	system("cls");

	cout << "前根遍历" << endl;
	f.preRootOrderRecursion(f.getRoot());

	cout << endl << "后根遍历" << endl;
	f.postRootOrderRecursion(f.getRoot());



	cout << endl << endl << "叶节点个数为" << f.countLeafR(f.getRoot()) << endl;


	cout << endl << "高度为" << f.countHeightR(f.getRoot()) << endl;


}